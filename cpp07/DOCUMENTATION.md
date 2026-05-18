# C++ Module 07 — Documentación de Templates

## Índice

1. [Introducción a los Templates](#introducción-a-los-templates)
2. [Ejercicio 00: Funciones swap, min, max](#ejercicio-00-funciones-swap-min-max)
3. [Ejercicio 01: Iter](#ejercicio-01-iter)
4. [Ejercicio 02: Array<T>](#ejercicio-02-arrayt)
5. [Errores comunes](#errores-comunes)
6. [Preguntas de evaluación](#preguntas-de-evaluación)

---

## Introducción a los Templates

### ¿Por qué existen los templates?

En C, cuando quieres escribir una función que funcione con diferentes tipos, tienes tres opciones:

1. **Escribir la misma función para cada tipo** (duplicación brutal)
2. **Usar `void*`** (pierdes type safety, riesgo de errores en runtime)
3. **Usar macros** (#define) (sin type checking, evaluación múltiple, depuración imposible)

Los templates de C++ resuelven este problema de raíz: **escribes el código una vez, y el compilador genera las versiones específicas para cada tipo que necesitas**. Esto se llama *code generation at compile time*.

```cpp
// Sin templates: tienes que duplicar
int max(int a, int b) { return a > b ? a : b; }
float max(float a, float b) { return a > b ? a : b; }
std::string max(std::string a, std::string b) { return a > b ? a : b; }

// Con templates: una sola definición
template <typename T>
T max(T a, T b) { return a > b ? a : b; }
```

### Tipos de templates

- **Function templates**: Plantillas para funciones (como `swap`, `min`, `max`, `iter`)
- **Class templates**: Plantillas para clases (como `Array<T>`)

### Instanciación de templates

La instanciación puede ser:

- **Implícita**: El compilador deduce el tipo a partir de los argumentos
  ```cpp
  min(3, 5);       // El compilador instancia min<int>
  min(3.5, 2.1);   // El compilador instancia min<double>
  ```
- **Explícita**: Tú especificas el tipo
  ```cpp
  min<int>(3, 5);          // Explícitamente instancia min<int>
  printElement<std::string>(s);  // Necesario cuando la deducción no es posible
  ```

### ¿Por qué los templates DEBEN definirse en headers?

Cuando el compilador ve una llamada a una función template, necesita la **definición completa** para generar el código máquina específico. Si la definición está en un `.cpp` separado, el compilador del archivo que llama solo ve la declaración (en el `.hpp`) y no puede generar la instancia.

Resultado: **linker error — undefined reference**.

La única excepción es la **instanciación explícita** en el `.cpp` donde se define el template, pero eso derrota el propósito de los templates (tendrías que listar todos los tipos posibles).

---

## Ejercicio 00: Funciones swap, min, max

### Concepto central

Este ejercicio introduce los **function templates** — la forma más simple de templates en C++. Aprendes que una sola definición puede generar múltiples funciones para diferentes tipos.

### Conceptos clave

#### 1. Sintaxis de function template

```cpp
template <typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
```

Desglose:
- `template <typename T>` — Declara que `T` es un parámetro de tipo. El compilador sustituirá `T` por el tipo real cuando se invoque la función.
- `T&` — Referencia a `T`. Esto es CRUCIAL: pasamos por referencia porque:
  - Para `swap`: necesitamos modificar los argumentos originales
  - Para `min`/`max`: evitamos copias innecesarias de tipos grandes (como `std::string`)

#### 2. Retorno por referencia const

```cpp
template <typename T>
const T& min(const T& a, const T& b)
{
    return (a < b ? a : b);
}
```

¿Por qué `const T&` y no `T`?

- Si devolvemos `T`, el compilador hace una **copia** del valor. Para `int` no importa, pero para `std::string` o tipos grandes, es desperdicio.
- Si devolvemos `T&` sin `const`, podrías hacer `min(x, y) = 10`, lo cual es un error lógico.
- `const T&` devuelve una referencia al valor existente, sin copia, y sin permitir modificación.

#### 3. Comportamiento con valores iguales

El subject dice: **si son iguales, devuelve el segundo**. Esto se traduce directamente en el operador:

```cpp
// min: si a < b, devuelve a. Si a >= b (incluyendo igual), devuelve b
return (a < b ? a : b);

// max: si a > b, devuelve a. Si a <= b (incluyendo igual), devuelve b  
return (a > b ? a : b);
```

El operador ternario `?:` no tiene comportamiento indefinido aquí: cuando la condición es falsa, siempre devuelve el segundo operando.

#### 4. El operador `::` (scope resolution)

En el `main.cpp` del subject se usa `::swap`, `::min`, `::max`. Esto fuerza la búsqueda en el **namespace global**, evitando conflictos con `std::swap`, `std::min`, `std::max` (que existen en `<algorithm>`).

### Análisis línea por línea de whatever.hpp

```cpp
#ifndef WHATEVER_HPP       // Include guard: evita doble inclusión
# define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b)      // Pasamos por referencia NO-const para poder modificar
{
    T tmp = a;             // Copia temporal (requiere copy constructor de T)
    a = b;                 // Asignación (requiere operator= de T)
    b = tmp;               // Restauramos la copia
}

template <typename T>
const T& min(const T& a, const T& b)  // const T&: no copiamos, no modificamos
{
    return (a < b ? a : b);           // < requiere que T tenga operator<
}

template <typename T>
const T& max(const T& a, const T& b)  // Mismo patrón que min
{
    return (a > b ? a : b);           // > requiere que T tenga operator>
}

#endif
```

**Requisitos sobre el tipo T**:
- Para `swap`: necesita copy constructor y `operator=`
- Para `min`: necesita `operator<`
- Para `max`: necesita `operator>`

Cualquier tipo que soporte estos operadores funcionará: `int`, `float`, `std::string`, tipos definidos por el usuario...

### Conexión con C

En C, la única forma de hacer algo similar sería:

```c
// Con void* — sin type safety, propenso a errores
void swap(void* a, void* b, size_t size) {
    void* tmp = malloc(size);
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
    free(tmp);
}

// Con macros — sin type checking, evaluación múltiple
#define MIN(a, b) ((a) < (b) ? (a) : (b))
// MIN(x++, y++) incrementa DOS veces cada uno!
```

Los templates son **type-safe** y **no tienen overhead en runtime** — el compilador genera el código específico para cada tipo.

---

## Ejercicio 01: Iter

### Concepto central

Este ejercicio enseña a pasar **funciones como parámetros a function templates**. Es el puente entre templates simples y patrones más avanzados como los iterators de la STL.

### Conceptos clave

#### 1. Function pointers como parámetros de templates

```cpp
template <typename T>
void iter(T* array, unsigned int length, void (*func)(T&))
```

- `T* array` — Puntero al primer elemento del array. `T*` porque un array decaído a puntero es `T*`.
- `unsigned int length` — Cantidad de elementos. `const` implícito por ser pasado por valor.
- `void (*func)(T&)` — **Puntero a función** que recibe una referencia a `T` y no devuelve nada.

La sintaxis `void (*func)(T&)` se lee así:
1. `func` es un puntero (`*func`)
2. a una función que recibe `T&`
3. y devuelve `void`

#### 2. Soportando const y non-const

El subject dice: *"The function passed as the third parameter may take its argument by const reference or non-const reference, depending on the context."*

Esto requiere **dos sobrecargas**:

```cpp
// Para arrays non-const: permite modificar elementos
template <typename T>
void iter(T* array, unsigned int length, void (*func)(T&));

// Para arrays const: solo lectura
template <typename T>
void iter(T* array, unsigned int length, void (*func)(const T&));
```

¿Por qué? Cuando pasas un `const int*`, el tipo `T` se deduce como `const int`. Entonces:
- `void (*func)(T&)` se convierte en `void (*func)(const int&)` — correcto
- Pero `void (*func)(T&)` con `T=int` no acepta `const int&` — incorrecto

La sobrecarga con `const T&` garantiza que los arrays const funcionen correctamente.

#### 3. Function templates como callbacks

El subject permite que el tercer parámetro sea un **function template instanciado**:

```cpp
template <typename T>
void printElement(T& x) { std::cout << x << " "; }

// Uso: instanciamos explícitamente el template
iter(strArray, strLen, printElement<std::string>);
```

Aquí `printElement<std::string>` es la **instancia** del template para `std::string`. El compilador genera la función concreta y pasa su dirección a `iter`.

### Análisis línea por línea de iter.hpp

```cpp
#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T* array, unsigned int length, void (*func)(T&))
{
    for (unsigned int i = 0; i < length; ++i)  // Itera sobre cada elemento
    {
        func(array[i]);    // Llama la función con cada elemento
    }
}

template <typename T>
void iter(T* array, unsigned int length, void (*func)(const T&))
{
    for (unsigned int i = 0; i < length; ++i)
    {
        func(array[i]);    // array[i] es const T&, coincide con func(const T&)
    }
}

#endif
```

**Punto importante**: Cuando `length` es 0, el bucle `for` simplemente no ejecuta ninguna iteración — no hay comportamiento indefinido ni acceso fuera de límites. Esto maneja correctamente los arrays vacíos.

### Conexión con C

En C, esta función sería algo como:

```c
void iter(void* array, size_t elem_size, size_t length, void (*func)(void*))
{
    for (size_t i = 0; i < length; ++i)
    {
        func((char*)array + i * elem_size);
    }
}
```

Problemas:
- Sin type safety — puedes pasar un array de `int` y una función que espera `float`
- Aritmética de punteros manual con `char*` — propenso a errores
- El callback receive `void*` — no sabe qué tipo está procesando

Los templates de C++ resuelven TODO esto en compile time.

---

## Ejercicio 02: Array<T>

### Concepto central

Este ejercicio enseña los **class templates** — la forma más poderosa de genericidad en C++. Implementas un contenedor genérico con gestión manual de memoria, copy semantics profundas, y manejo de excepciones.

### Conceptos clave

#### 1. Class template syntax

```cpp
template <typename T>
class Array
{
private:
    T* _array;
    unsigned int _size;
    // ...
};
```

- `template <typename T>` antes de la clase significa que **toda la clase** está parametrizada por `T`.
- Cualquier uso del tipo `Array` fuera de la clase debe ser `Array<T>` (por ejemplo, `Array<int>`, `Array<std::string>`).
- Dentro de la clase, puedes usar simplemente `Array` (sin `<T>`) porque el compilador sabe que te refieres a `Array<T>`.

#### 2. Orthodox Canonical Form en templates

El subject requiere OCF para todas las clases. Los cuatro miembros son:

```cpp
// 1. Constructor por defecto
Array() : _array(NULL), _size(0) {}

// 2. Constructor con parámetro (no es copy constructor)
Array(unsigned int n) : _array(new T[n]()), _size(n) {}

// 3. Copy constructor — deep copy
Array(const Array& other);

// 4. Assignment operator — deep copy con self-assignment check
Array& operator=(const Array& other);

// 5. Destructor
~Array() { delete[] _array; }
```

**NOTA**: El constructor con parámetro `Array(unsigned int n)` NO es el copy constructor. El copy constructor toma `const Array&` (referencia a Array, no unsigned int).

#### 3. Value-initialization con `new T[n]()`

```cpp
Array(unsigned int n) : _array(new T[n]()), _size(n)
```

Los paréntesis `()` después de `new T[n]()` son **fundamentales**:

- `new T[n]` — Los elementos quedan **sin inicializar** (para tipos fundamentales como `int`, contienen basura)
- `new T[n]()` — Los elementos quedan **value-initialized** (para `int` es 0, para `float` es 0.0, para clases se llama el constructor por defecto)

```cpp
int* a = new int();     // *a == 0, no basura!
int* b = new int;       // *b contiene basura indefinida
```

El subject dice: *"Try to compile int * a = new int(); then display *a"* — esto es una pista directa para usar `()`.

#### 4. Deep copy (copia profunda)

```cpp
Array(const Array& other) : _array(NULL), _size(0)
{
    if (other._size > 0)
    {
        _array = new T[other._size]();
        for (unsigned int i = 0; i < other._size; ++i)
            _array[i] = other._array[i];
    }
    _size = other._size;
}
```

**Deep copy** significa que copiamos los **valores** de los elementos, no solo el puntero. Si copiamos solo el puntero (shallow copy), ambos objetos compartirían la memoria — modificar uno afectaría al otro, y el destructor liberaría la memoria dos veces (double free).

La secuencia es:
1. Inicializamos `_array = NULL` y `_size = 0` en la lista de inicialización (estado seguro)
2. Si el original tiene elementos, asignamos nueva memoria
3. Copiamos cada elemento uno por uno
4. Asignamos el tamaño

#### 5. Self-assignment guard

```cpp
Array& operator=(const Array& other)
{
    if (this != &other)  // Guard against self-assignment: a = a
    {
        delete[] _array;
        // ... deep copy ...
    }
    return *this;
}
```

Sin este guard, `a = a` destruiría los datos de `a` antes de copiarlos, dejando memoria liberada y punteros colgantes.

#### 6. operator[] con bounds checking

```cpp
T& operator[](unsigned int index)
{
    if (index >= _size)
        throw std::exception();
    return _array[index];
}

const T& operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::exception();
    return _array[index];
}
```

**Dos versiones necesarias**:
- `T& operator[]` — Para arrays non-const: permite `arr[i] = 42;`
- `const T& operator[] const` — Para arrays const: permite `constArr[i]` para lectura

El check `index >= _size` (en lugar de `index > _size`) maneja correctamente:
- Si `_size` es 0, cualquier índice (incluyendo 0) está fuera de límites
- Si `_size` es 5, los índices válidos son 0-4, y el índice 5 lanzará excepción

#### 7. El destructor

```cpp
~Array()
{
    delete[] _array;
}
```

`delete[]` (con corchetes) es obligatorio cuando usas `new[]`. Usar `delete` (sin corchetes) con memoria asignada con `new[]` es **comportamiento indefinido**.

`delete[] NULL` es seguro — el estándar garantiza que `delete` y `delete[]` con NULL es un no-op.

### Conexión con C

En C, un contenedor genérico se implementaría así:

```c
typedef struct {
    void* data;
    size_t size;
    size_t elem_size;
} Array;

Array array_create(size_t n, size_t elem_size) {
    Array arr;
    arr.data = malloc(n * elem_size);
    arr.size = n;
    arr.elem_size = elem_size;
    return arr;
}

void* array_get(Array* arr, size_t index) {
    if (index >= arr->size) return NULL;  // O manejar error de otra forma
    return (char*)arr->data + index * arr->elem_size;
}
```

Problemas:
- Sin type safety — `void*` acepta cualquier cosa
- Sin destructores automáticos — tienes que gestionar memoria manualmente
- Sin exceptions — manejo de errores torpe (códigos de retorno, NULL, etc.)
- Sin `operator[]` — sintaxis fea y verbosa
- El usuario tiene que recordar el tamaño del elemento

El `Array<T>` de C++ resuelve TODOS estos problemas:
- Type safety garantizada en compile time
- Destructores automáticos (RAII)
- Excepciones para errores
- `operator[]` para sintaxis natural
- Sin casts manuales

---

## Errores comunes

### 1. Olvidar los `()` en `new T[n]()`

```cpp
// MAL — elementos sin inicializar (basura para tipos fundamentales)
_array = new T[n];

// BIEN — value-initialized (0 para int, "" para string, etc.)
_array = new T[n]();
```

### 2. Shallow copy en lugar de deep copy

```cpp
// MAL — ambos objetos comparten la misma memoria
_array = other._array;

// BIEN — copia independiente
_array = new T[other._size]();
for (unsigned int i = 0; i < other._size; ++i)
    _array[i] = other._array[i];
```

### 3. Self-assignment sin protección

```cpp
// MAL — destruye los datos antes de copiar
Array& operator=(const Array& other) {
    delete[] _array;           // Si this == &other, ¡acabamos de destruir our datos!
    _array = new T[other._size]();
    // ... copia desde other._array que ya fue liberado — undefined behavior!
}
```

### 4. Usar `delete` en lugar de `delete[]`

```cpp
// MAL — undefined behavior con new[]
delete _array;

// BIEN
delete[] _array;
```

### 5. Definir templates en archivos .cpp

```cpp
// MAL — template en .cpp causa linker errors
// whatever.cpp
template <typename T>
void swap(T& a, T& b) { ... }  // Solo visible en este archivo

// BIEN — template en header
// whatever.hpp
template <typename T>
void swap(T& a, T& b) { ... }  // Visible para todos los archivos que incluyen el header
```

### 6. No proveer versión const de operator[]

```cpp
// MAL — no funciona con arrays const
T& operator[](unsigned int index) { ... }

// BIEN — ambas versiones
T& operator[](unsigned int index) { ... }
const T& operator[](unsigned int index) const { ... }
```

### 7. Confundir min/max con valores iguales

El subject es claro: **si son iguales, devuelve el segundo**. Esto no es un error tuyo, es una decisión de diseño del subject:

```cpp
min(3, 3)  // Devuelve el segundo 3, no el primero
max(3, 3)  // Devuelve el segundo 3, no el primero
```

La implementación con `<` y `>` lo maneja correctamente:
```cpp
return (a < b ? a : b);  // Si a NO es menor que b, devuelve b
return (a > b ? a : b);  // Si a NO es mayor que b, devuelve b
```

---

## Preguntas de evaluación

### Pregunta 1: ¿Por qué los templates se definen en headers?

**Respuesta**: Porque el compilador necesita la definición completa del template para generar instancias específicas. Si pones la definición en un `.cpp`, otros archivos no pueden verla y el linker reporta "undefined reference". En headers, cada archivo que incluye el `.hpp` puede instanciar el template con los tipos que necesita.

### Pregunta 2: ¿Qué es la instanciación implícita vs explícita?

**Respuesta**:
- **Implícita**: El compilador deduce el tipo. `swap(a, b)` con `int a, int b` instancia `swap<int>`.
- **Explícita**: Especificas el tipo. `swap<int>(a, b)` o `printElement<std::string>(s)`. Necesaria cuando la deducción no es posible (por ejemplo, cuando el tipo del parámetro no aparece en los argumentos).

### Pregunta 3: ¿Por qué `min` y `max` devuelven `const T&` y no `T`?

**Respuesta**: Por dos razones:
1. **Eficiencia**: Para tipos grandes como `std::string`, devolver por valor copia todo el contenido. Devolver por referencia const evita la copia.
2. **Consistencia**: La referencia apunta al valor original en memoria, no a una copia temporal que se destruiría al terminar la expresión.

### Pregunta 4: ¿Qué pasa si haces `Array<int> a; a[0] = 42;`?

**Respuesta**: Lanza `std::exception`. El array vacío tiene `_size = 0`, y `index >= _size` (0 >= 0) es verdadero, así que el `operator[]` lanza la excepción como corresponde.

### Pregunta 5: ¿Por qué `new T[n]()` inicializa a cero pero `new T[n]` no?

**Respuesta**: Los paréntesis `()` indican **value-initialization** en C++. Para tipos fundamentales (`int`, `float`, etc.), value-initialization pone el valor a cero. Sin los paréntesis, la memoria queda **default-initialized**, que para tipos fundamentales significa **sin inicializar** (valores basura).

### Pregunta 6: ¿Qué es la Orthodox Canonical Form y por qué se aplica aquí?

**Respuesta**: Es la forma canónica ortodoxa que exige 42 para las clases en C++. Incluye:
1. Constructor por defecto
2. Copy constructor
3. Assignment operator
4. Destructor

Se aplica porque `Array<T>` gestiona memoria (tiene `_array` como puntero raw). Sin OCF, obtendrías:
- Sin copy constructor → shallow copy → double free
- Sin assignment operator → mismo problema
- Sin destructor → memory leak

### Pregunta 7: ¿Por qué `iter` necesita dos sobrecargas (const y non-const)?

**Respuesta**: Cuando pasas un `const int*`, el tipo deducido de `T` es `const int`. La sobrecarga con `void (*func)(const T&)` coincide correctamente. Si solo tuvieras la versión non-const, `iter` no podría aceptar arrays const porque la función callback recibiría una referencia non-const a datos const — violación de const-correctness.

### Pregunta 8: ¿Qué diferencia hay entre `swap` como template y `std::swap`?

**Respuesta**: Nuestro `swap` es un template simple que hace copia temporal. `std::swap` (de `<algorithm>`, prohibido en este módulo) es más sofisticado:
- Tiene especializaciones para tipos estándar (como contenedores) que hacen swap en O(1) intercambiando punteros internos
- Usa move semantics en C++11
- Soporta ADL (Argument-Dependent Lookup)

Nuestra versión es correcta para los propósitos de este módulo, pero menos eficiente para tipos complejos.

### Pregunta 9: Si cambiaras `Array(unsigned int n)` por `Array(int n)`, ¿qué problema habría?

**Respuesta**: Pasar un `int` negativo causaría comportamiento indefinido. `new T[-1]` interpretaría el valor negativo como un número muy grande (unsigned overflow), intentando asignar gigabytes de memoria y probablemente causando `std::bad_alloc`. Usar `unsigned int` previene esto en compile time.

### Pregunta 10: ¿Puedes instanciar `Array<Array<int> >`? ¿Qué necesitas?

**Respuesta**: Sí, siempre que `Array<int>` soporte todos los requisitos de `T` en el template `Array<T>`: copy constructor, assignment operator, y default constructor. Los espacios entre los `>` `>` son necesarios en C++98 (sin espacio, `>>` se interpreta como el operador de right-shift).