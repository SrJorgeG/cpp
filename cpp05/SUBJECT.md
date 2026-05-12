# C++ - Module 05

## Repetition and Exceptions

# Chapter IV

# Exercise 00: Mommy, when I grow

# up, I want to be a bureaucrat!

```
Exercise: 00
```
```
Mommy, when I grow up, I want to be a bureaucrat!
Directory: ex 00 /
Files to Submit: Makefile, main.cpp, Bureaucrat.{h, hpp}, Bureaucrat.cpp
Forbidden: None
```
```
Please note that exception classes do not have to be designed in
Orthodox Canonical Form. However, every other class must follow it.
```
Let’s design an artificial nightmare of offices, corridors, forms, and waiting queues.
Sounds fun? No? Too bad.

```
First, start with the smallest cog in this vast bureaucratic machine: the Bureaucrat.
```
```
A Bureaucrat must have:
```
- A constant name.
- A grade that ranges from **1** (highest possible grade) to **150** (lowest possible grade).

Any attempt to instantiate a Bureaucrat with an invalid grade must throw an excep-
tion:
either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.


C++ - Module 05 Repetition and Exceptions

You will provide getters for both attributes: getName() and getGrade(). You must
also implement two member functions to increment or decrement the bureaucrat’s grade.
If the grade goes out of range, both functions must throw the same exceptions as the
constructor.

```
Remember, since grade 1 is the highest and 150 the lowest,
incrementing a grade 3 should result in a grade 2 for the bureaucrat.
```
```
The thrown exceptions must be catchable using try and catch blocks:
```
```
try
{
/* do some stuff with bureaucrats */
}
catch (std::exception & e)
{
/* handle exception */
}
```
You must implement an overload of the insertion («) operator to print output in the
following format (without the angle brackets):

```
<name>, bureaucrat grade <grade>.
```
```
As usual, submit some tests to prove that everything works as expected.
```

# Chapter V

# Exercise 01: Form up, maggots!

```
Exercise: 01
```
```
Form up, maggots!
Directory: ex 01 /
Files to Submit: Files from the previous exercise + Form.{h, hpp}, Form.cpp
Forbidden: None
```
Now that you have bureaucrats, let’s give them something to do. What better activity
could there be than filling out a stack of forms?

```
Let’s create a Form class. It has:
```
- A constant name.
- A boolean indicating whether it is signed (at construction, it is not).
- A constant grade required to sign it.
- A constant grade required to execute it.

```
All these attributes are private , not protected.
```
The grades of the **Form** follow the same rules as those of the Bureaucrat. Thus, the
following exceptions will be thrown if a form’s grade is out of bounds:
Form::GradeTooHighException and Form::GradeTooLowException.

As before, write getters for all attributes and overload the insertion («) operator to
print all the form’s information.


C++ - Module 05 Repetition and Exceptions

Also, add a beSigned() member function to the Form that takes a Bureaucrat as a
parameter. It changes the form’s status to signed if the bureaucrat’s grade is high enough
(greater than or equal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a Form::GradeTooLowException.

Then, add a signForm() member function in the Bureaucrat class. This function must
call Form::beSigned() to attempt to sign the form. If the form is signed successfully, it
will print something like:
<bureaucrat> signed <form>

```
Otherwise, it will print something like:
```
```
<bureaucrat> couldn’t sign <form> because <reason>.
```
```
Implement and submit some tests to ensure everything works as expected.
```

# Chapter VI

# Exercise 02: No, you need form 28B,

# not 28C...

```
Exercise: 02
```
```
No, you need form 28B, not 28C...
Directory: ex 02 /
Files to Submit: Makefile, main.cpp, Bureaucrat.[{h, hpp},cpp], +
AForm.[{h, hpp},cpp], ShrubberyCreationForm.[{h, hpp},cpp], +
RobotomyRequestForm.[{h, hpp},cpp], PresidentialPardonForm.[{h, hpp},cpp]
Forbidden: None
```
Now that you have basic forms, it’s time to create a few more that actually do some-
thing.

In all cases, the base class Form must be an abstract class and should therefore be
renamed AForm. Keep in mind that the form’s attributes need to remain private and
that they belong to the base class.

```
Add the following concrete classes:
```
- **ShrubberyCreationForm** : Required grades: sign 145, exec 137
    Creates a file <target>_shrubbery in the working directory and writes ASCII trees
    inside it.
- **RobotomyRequestForm** : Required grades: sign 72, exec 45
    Makes some drilling noises, then informs that <target> has been robotomized
    successfully 50% of the time. Otherwise, it informs that the robotomy failed.
- **PresidentialPardonForm** : Required grades: sign 25, exec 5
    Informs that <target> has been pardoned by Zaphod Beeblebrox.

All of them take only one parameter in their constructor: the target of the form. For
example, "home" if you want to plant shrubbery at home.


C++ - Module 05 Repetition and Exceptions

Now, add the execute(Bureaucrat const & executor) const member function to
the base form and implement a function to execute the form’s action in the concrete
classes. You must check that the form is signed and that the grade of the bureaucrat at-
tempting to execute the form is high enough. Otherwise, throw an appropriate exception.

Whether you check the requirements in every concrete class or in the base class (and
then call another function to execute the form) is up to you. However, one way is more
elegant than the other.

Lastly, add the executeForm(AForm const & form) const member function to the
Bureaucrat class. It must attempt to execute the form. If successful, print something like:

```
<bureaucrat> executed <form>
```
```
If not, print an explicit error message.
```
```
Implement and submit some tests to ensure everything works as expected.
```

# Chapter VII

# Exercise 03: At least this beats

# coffee-making

```
Exercise: 03
```
```
At least this beats coffee-making
Directory: ex 03 /
Files to Submit: Files from previous exercises + Intern.{h, hpp}, Intern.cpp
Forbidden: None
```
Since filling out forms all day would be too cruel for our bureaucrats, interns exist to
take on this tedious task. In this exercise, you must implement the **Intern** class. The
intern has no name, no grade, and no unique characteristics. The only thing bureaucrats
care about is that they do their job.

However, the intern has one key ability: the makeForm() function. This function
takes two strings as parameters: the first one represents the name of a form, and the
second one represents the target of the form. It returns a pointer to a **AForm** object
(corresponding to the form name passed as a parameter), with its target initialized to
the second parameter.

```
It should print something like:
```
```
Intern creates <form>
```
```
If the provided form name does not exist, print an explicit error message.
```

C++ - Module 05 Repetition and Exceptions

You must avoid unreadable and messy solutions, such as using an excessive if/el-
seif/else structure. This kind of approach will not be accepted during the evaluation
process. You’re not in the Piscine (pool) anymore. As usual, you must test everything
to ensure it works as expected.

For example, the following code creates a **RobotomyRequestForm** targeted at
"Bender":

```
{
Intern someRandomIntern;
AForm* rrf;
rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}
```

# Chapter VIII

# Submission and Peer Evaluation

Submit your assignment to your Git repository as usual. Only the work inside your
repository will be evaluated during the defense. Make sure to double-check the names of
your folders and files to ensure they are correct.

During the evaluation, a brief **modification of the project** may occasionally be re-
quested. This could involve a minor behaviour change, a few lines of code to write or
rewrite, or an easy-to-add feature.

While this step may **not be applicable to every project** , you must be prepared for it
if it is mentioned in the evaluation guidelines.

This step is meant to verify your actual understanding of a specific part of the project.
The modification can be performed in any development environment you choose (e.g.,
your usual setup), and it should be feasible within a few minutes — unless a specific time
frame is defined as part of the evaluation.
You can, for example, be asked to make a small update to a function or script, modify a
display, or adjust a data structure to store new information, etc.

The details (scope, target, etc.) will be specified in the **evaluation guidelines** and may
vary from one evaluation to another for the same project.


