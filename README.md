In this module I had to demonstrate repetitions and exceptions in C++98 OOP. I had to structure my files as header files and source files.  

**TASKS**

---

**Ex00:**

We start by designing artificial offices, corridors, forms, and waiting queues. First, start by the smallest cell: the Bureaucrat. A Bureaucrat must have:

- A constant name.
- And a grade that ranges from 1 (highest possible grade) to 150 (lowest possible
grade).

Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception:
either a 

```Bureaucrat::GradeTooHighException```
or a 
```Bureaucrat::GradeTooLowException```.

You will provide getters for both these attributes: getName() and getGrade(). Implement also two member functions to increment or decrement the bureaucrat grade. If the grade is out of range, both of them will throw the same exceptions as the constructor.

You will implement an overload of the insertion («) operator to print something like
(without the angle brackets):

```<name>, bureaucrat grade <grade>```


---

**Ex01:**

Now that we have bureaucrats, lets assign them with completing forms. Let’s make a Form class that has:

- A constant name.
- A boolean indicating whether it is signed (at construction, it’s not).
- A constant grade required to sign it.
- And a constant grade required to execute it.

All these attributes are private, not protected.

The grades of the Form follow the same rules that apply to the Bureaucrat. Thus, the following exceptions will be thrown if a form grade is out of bounds:

```Form::GradeTooHighException``` and 
```Form::GradeTooLowException```.

Same as before, write getters for all attributes and an overload of the insertion («) operator that prints the form information.

---

**Ex02:**

Since we now have basic forms, we can can derive different typos of forms.

In all cases, the base class Form must be an abstract class, and therefore should be renamed AForm. Form’s attributes need to remain private and that they are in the base class.

Add the following concrete classes:

- ShrubberyCreationForm: Required grades: sign 145, exec 137. Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it.
- RobotomyRequestForm: Required grades: sign 72, exec 45. Makes some drilling noises. Then, informs that <target> has been robotomized successfully 50% of the time. Otherwise, informs that the robotomy failed.
- PresidentialPardonForm: Required grades: sign 25, exec 5. Informs that <target> has been pardoned by Zaphod Beeblebrox.

All of them take only one parameter in their constructor: the target of the form. For example, "home" if you want to plant shrubbery at home.

Now, add the 

```execute(Bureaucrat const & executor) const```

member function to the base form and implement a function to execute the form’s action of the concrete classes. You have to check that the form is signed and that the grade of the bureaucrat attempting to execute the form is high enough. Otherwise, throw an appropriate exception.

Whether you want to check the requirements in every concrete class or in the base class (then call another function to execute the form) is up to you. Lastly, add the 

```executeForm(Form const & form)```

member function to the Bureaucrat. It must attempt to execute the form. If it’s successful, print something like:

```<bureaucrat> executed <form> ```

If not, print an explicit error message.

---

**Ex03:**

We will assign interns to fill out forms for bureaucrats. In this exercise, you have to implement the Intern class. The intern has no name, no grade, no unique characteristics. 

The intern has one important capacity: the makeForm() function. It takes two strings. The first one is the name of a form and the second one is the target of the form. It return a pointer to a Form object (whose name is the one passed as parameter) whose target will be initialized to the second parameter.

It will print something like:

```Intern creates <form> ```

If the form name passed as parameter doesn’t exist, print an explicit error message.

You must avoid unreadable solutions like using a if/elseif/else forest. This kind of things won’t be accepted during the evaluation process.

---
