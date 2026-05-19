# CPP05 — Repetición y Excepciones: Explicación Completa

---

## Ejercicio 00: "Mommy, when I grow up, I want to be a bureaucrat!"

**Concepto central: Excepciones personalizadas**

Este ejercicio crea la clase `Bureaucrat`, un funcionario con un nombre constante y un grado (1 = máximo, 150 = mínimo). Lo crítico aquí es el **manejo de errores con excepciones**.

### ¿Qué se aprende?

1. **Clases de excepción anidadas**: Dentro de `Bureaucrat` se declaran dos clases internas: `GradeTooHighException` y `GradeTooLowException`, ambas heredando de `std::exception`. Esto es un patrón CANÓNICO en C++: las excepciones son "ciudadanas de primera clase" dentro de la clase que las genera. Así quien las atrapa sabe EXACTAMENTE de dónde viene el error.

2. **`what()` virtual**: Cada excepción implementa `virtual const char* what() const throw()`, que devuelve el mensaje de error. Al heredar de `std::exception`, puedes atraparlas con `catch (std::exception& e)` genérico o con el tipo específico.

3. **Validación en constructores y setters**: Si intentas crear un `Bureaucrat` con grado 0 o 200, el constructor **lanza la excepción** y el objeto NUNCA se crea. Este es un principio fundamental: **un objeto no debería existir en un estado inválido**. Si el grado es ilegal, la construcción falla.

4. **La inversa contraintuitiva**: `incrementGrade()` DECREMENTA el número (`_grade--`) porque grado 1 es el MÁS alto. Esto simula cómo funciona en la vida real: "ascender" te sube en la jerarquía pero te baja el número de grado.

5. **Operador `<<` sobrecargado**: Permite imprimir un `Bureaucrat` directamente: `std::cout << b;` → `"Alice, bureaucrat grade 42."`. Esto es un friend no-miembro que respeta el formato exigido.

---

## Ejercicio 01: "Form up, maggots!"

**Concepto central: Interacción entre objetos + propagación de excepciones**

Sobre la base del ejercicio anterior, se agrega la clase `Form` y se establece una **relación bidireccional** entre `Bureaucrat` y `Form`.

### ¿Qué se aprende?

1. **Dos clases que interactúan**: `Form` tiene su propio par de excepciones (`GradeTooHighException`, `GradeTooLowException`) para validar los grados de firma y ejecución. Cada clase es RESPONSABLE de sus propias invariantes.

2. **`beSigned()`**: `Form::beSigned(const Bureaucrat&)` es el método que realmente firma el formulario. Verifica que el grado del burócrata sea suficiente (recuerda: número menor = grado mayor). Si no lo es, lanza `GradeTooLowException`.

3. **`signForm()`**: `Bureaucrat::signForm(Form&)` es el método de "conveniencia" que envuelve a `beSigned()` en un `try/catch`. Este es un patrón MUY importante: **quien llama intenta la acción y maneja el error de forma amigable**. Si la firma funciona, imprime `"Alice signed Form42"`. Si falla, imprime `"Alice couldn't sign Form42 because Grade is too low!"`.

4. **La excepción NO se pierde**: `beSigned()` lanza la excepción, `signForm()` la atrapa y traduce el error a un mensaje legible. Esto es wrapeo de excepciones en su forma más simple.

5. **Dependencia circular (forward declaration)**: `Bureaucrat.hpp` incluye `Form.hpp`, y `Form.hpp` incluye `Bureaucrat.hpp`. Esto crearía una inclusión circular. La solución es usar **forward declaration**: `class Bureaucrat;` en `Form.hpp` y solo incluir el header completo en el `.cpp`. Tu código lo hace correctamente con `#include "Form.hpp"` en `Bureaucrat.hpp`.

---

## Ejercicio 02: "No, you need form 28B, not 28C..."

**Concepto central: Clases abstractas + polimorfismo + Template Method Pattern**

Este es el ejercicio más rico. `Form` se convierte en `AForm` (clase abstracta) y se crean tres formularios concretos que hacen cosas completamente distintas.

### ¿Qué se aprende?

1. **Clase abstracta con método puro**: `AForm` declara `virtual void action() const = 0;` en la sección `protected`. Esto hace que `AForm` sea **ininstanciable** directamente. Solo las clases derivadas que implementen `action()` pueden ser instanciadas. La "A" en `AForm` sigue la convención de 42 para indicar "Abstract".

2. **Template Method Pattern**: Este es el patrón ESTRELLA del ejercicio. `AForm::execute()` es un método `const` que:
   - Verifica si el formulario está firmado
   - Verifica si el burócrata tiene grado suficiente para ejecutarlo
   - Si todo OK, llama a `this->action()` (el método virtual puro)
   
   Esto es brillante porque **la lógica de validación se escribe UNA sola vez** en la base, y cada formulario concreto solo implementa su `action()`. No hay duplicación de validaciones en cada subclase. Es la forma "elegante" que menciona el subject.

3. **Tres formularios concretos**:
   - **ShrubberyCreationForm** (sign: 145, exec: 137): Crea un archivo `<target>_shrubbery` con árboles ASCII. Usa `std::ofstream`.
   - **RobotomyRequestForm** (sign: 72, exec: 45): Hace ruidos de taladro y tiene 50% de probabilidad de éxito (`std::rand() % 2`).
   - **PresidentialPardonForm** (sign: 25, exec: 5): Imprime que `<target>` fue perdonado por Zaphod Beeblebrox.

4. **Nueva excepción**: `AForm::FormNotSignedException` se lanza cuando se intenta ejecutar un formulario no firmado. Esto agrega una nueva regla de negocio a las ya existentes.

5. **`Bureaucrat::executeForm()`**: Análogo a `signForm()`, este método envuelve `form.execute(*this)` en un try/catch e imprime si tuvo éxito o no.

6. **Herencia con miembros `const`**: Cada subclase pasa los valores fijos de grado al constructor de `AForm` y guarda su propio `_target`. La composición/herencia funciona a pesar de que `AForm` tiene miembros `const`.

---

## Ejercicio 03: "At least this beats coffee-making"

**Concepto central: Factory Pattern + lookup con array de function pointers**

La clase `Intern` actúa como una **fábrica** (Factory): dado un string, devuelve un puntero al tipo correcto de `AForm`.

### ¿Qué se aprende?

1. **Factory Pattern**: `Intern::makeForm(name, target)` es un factory method. Recibe el nombre del formulario como string y devuelve un `AForm*` al objeto concreto correcto. Esto desacopla al cliente (quien pide el formulario) de la creación específica.

2. **Punteros a función miembro estáticos (function pointer table)**: En lugar de un feo `if/else if/else` cadena, tu Intern usa un **array de structs** `FormType` que mapea nombres a creadores:
   ```cpp
   static FormType formTypes[] = {
       {"shrubbery creation", &Intern::createShrubberyCreationForm},
       {"robotomy request",  &Intern::createRobotomyRequestForm},
       {"presidential pardon", &Intern::createPresidentialPardonForm}
   };
   ```
   El loop recorre el array, compara nombres, y si coincide, invoca el creador. Esto es **extensible y limpio**: agregar un nuevo formulario significa agregar UNA entrada al array y UNA función estática, sin tocar la lógica de `makeForm()`.

3. **`typedef` para legibilidad**: `typedef AForm* (*FormCreator)(const std::string& target)` define un alias de tipo para el puntero a función. Hace que la declaración del struct sea legible.

4. **Miembros `static`**: Los creadores y el array son `static` porque no dependen de ninguna instancia de `Intern`. Un intern no tiene estado — todos son iguales, así que las funciones de creación pueden ser estáticas.

5. **Retorno `NULL` y manejo de errores**: Si el nombre no existe, `makeForm` imprime un mensaje de error y devuelve `NULL`. El llamador (el `main`) es responsable de verificar y hacer `delete` del puntero devuelto.

6. **Gestión manual de memoria**: El factory devuelve `new` (memoria dinámica), y el llamador hace `delete`. Esto es lo que en módulos posteriores se resolverá con smart pointers.

---

## Explicación Final: Cómo se Relacionan los Conceptos

```
Ex00 (Excepciones) → Ex01 (Interacción) → Ex02 (Polimorfismo) → Ex03 (Factory)
```

### La progresión es INTENCIONAL y CADA ejercicio builda sobre el anterior:

| Concepto | Ex00 | Ex01 | Ex02 | Ex03 |
|---|---|---|---|---|
| Excepciones personalizadas | ✅ Básico | ✅ En dos clases | ✅ +++ FormNotSigned | ✅ Heredado |
| Orthodox Canonical Form | ✅ | ✅ | ✅ | ✅ |
| Encapsulación e invariantes | ✅ Grado 1-150 | ✅ + Grades en Form | ✅ + isSigned | ✅ |
| Interacción entre objetos | — | ✅ beSigned/signForm | ✅ + execute | ✅ |
| Clase abstracta + puro virtual | — | — | ✅ Template Method | ✅ Heredado |
| Polimorfismo | — | — | ✅ action() override | ✅ Factory returns AForm* |
| Factory Pattern | — | — | — | ✅ Array de function pointers |

### La cadena conceptual:

1. **Ex00** te enseña que las EXCEPCIONES son la manera correcta de manejar errores en C++. Un objeto NUNCA debería existir en estado inválido. Si el grado está fuera de rango, SE LANZA y el objeto no se crea. Esto es FUNDAMENTAL.

2. **Ex01** agrega una segunda clase (`Form`) y muestra que DOS objetos pueden interactuar con validación cruzada usando excepciones. `Bureaucrat::signForm()` es un **wrapper** que intenta la operación y traduce el error. Esto es el puente entre "lanzar excepciones" y "manejarlas con gracia".

3. **Ex02** es el salto conceptual más grande: transforma `Form` en `AForm` (abstracta) y aplica el **Template Method Pattern**. La validación general (firmado + grado suficiente) vive en la base, la acción específica vive en cada subclase. Esto es polimorfismo aplicado: `execute()` siempre funciona igual, pero el comportamiento cambia según el tipo real del formulario. Es la diferencia entre "repetir código" y "diseñar para extensibilidad".

4. **Ex03** cierra el círculo: si tienes una jerarquía polimórfica, NECESITAS una forma de crear objetos sin acoplarte a los tipos concretos. El **Factory Pattern** con la tabla de function pointers es la solución elegante que evita el `if/else` cadena. Y observa: `makeForm` devuelve `AForm*` — el llamador SOLO conoce la interfaz abstracta, nunca los tipos concretos.

### En resumen:

**CPP05 te enseña que un buen diseño OO no es "hacer que compile", sino diseñar jerarquías donde:**

- Las invariantes se protegen con excepciones (no silenciosamente)
- La lógica común sube a la base (Template Method)
- La lógica específica baja a las derivadas (polimorfismo)
- La creación de objetos se desacopla del uso (Factory)

Cada ejercicio AGREGA complejidad, no la reemplaza. Sin excepciones (Ex00) no puedes validar la firma (Ex01). Sin la interfaz abstracta (Ex02) no puedes tener un factory que devuelva polimórficamente (Ex03). Es arquitectura en capas, cada una depende de la anterior.