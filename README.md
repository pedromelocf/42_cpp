# 42 C++

This repository contains solutions for the C++ modules (cpp00 to cpp09) of the 42 curriculum. Each module introduces and reinforces important C++ and OOP concepts, starting from the basics to more advanced topics like templates and the STL.

---

## cpp00

**Topics:** Classes, member functions, `std::cout`, `std::string`, structs, static variables

### ex00 – Megaphone

* **Description:** Program that takes strings from the command line and outputs them in uppercase.
* **How to use:**

  ```bash
  ./megaphone "Hello world!"
  ```
* **Expected result:**

  ```
  HELLO WORLD!
  ```

### ex01 – PhoneBook

* **Description:** Simple contact manager that allows adding, searching, and displaying contacts.
* **How to use:**

  ```bash
  ./phonebook
  ```
* **Commands:** `ADD`, `SEARCH`, `EXIT`
* **Expected result:** Nicely formatted contact info table on `SEARCH`.

### ex02 – References vs Pointers

* **Description:** Demonstrates how pointers and references work on a string.
* **Expected result:** Shows same string via pointer and reference.

### ex03 – HarlFilter

* **Description:** A class with logging methods for `DEBUG`, `INFO`, `WARNING`, `ERROR`.
* **How to use:**

  ```bash
  ./harlFilter WARNING
  ```
* **Expected result:** Outputs messages from the matching level and more severe levels.

---

## cpp01

**Topics:** File IO, memory allocation, references, constructors/destructors

### ex00 – FileReplace

* **Description:** Replaces all occurrences of a string in a file with another string.
* **How to use:**

  ```bash
  ./replace input.txt s1 s2
  ```
* **Expected result:** Creates `input.txt.replace` with `s1` replaced by `s2`.

### ex01 – Zombie Event

* **Description:** Allocates Zombie instances on the heap and stack to show the difference.

### ex02 – Pointers to Class Members

* **Description:** Practice with pointers to member functions and variables.

### ex03 – Harl 2.0

* **Description:** Same as `cpp00/ex03` but implemented using function pointer array for filtering.

---

## cpp02

**Topics:** Orthodox Canonical Form, constructors/destructors, copy semantics, operator overloading

### ex00 – Fixed Point Number Class

* **Description:** Implements a fixed-point class with constructors and overloaded operators.

### ex01 – More Fixed Point

* **Description:** Add arithmetic and comparison operators to `Fixed`.

### ex02 – Min/Max

* **Description:** Add static methods `min` and `max` to compare `Fixed` objects.

---

## cpp03

**Topics:** Inheritance, protected/private attributes, constructors/destructors

### ex00 – ClapTrap

* **Description:** Simple base class to simulate a game character.

### ex01 – ScavTrap

* **Description:** Derived class with its own methods and behavior (`guardGate`).

### ex02 – FragTrap

* **Description:** Another derived class that adds a special `highFivesGuys()` method.

### ex03 – DiamondTrap

* **Description:** Inherits from both `ScavTrap` and `FragTrap` to demonstrate diamond inheritance.

---

## cpp04

**Topics:** Abstract classes, interfaces, dynamic dispatch

### ex00 – Animal Hierarchy

* **Description:** Base class `Animal` with derived `Dog` and `Cat`.

### ex01 – Deep Copy

* **Description:** Ensures that copies of animals do not share brain data (deep copy with copy constructor).

### ex02 – Abstract Class

* **Description:** Make `Animal` abstract and define virtual methods to enforce interfaces.

---

## cpp05

**Topics:** Exceptions, try/catch, nested class exceptions

### ex00 – Bureaucrat

* **Description:** Class with grade-based validation and exceptions on invalid values.

### ex01 – Form Signing

* **Description:** Add `Form` class that can be signed by a `Bureaucrat`.

### ex02 – ShrubberyCreationForm

* **Description:** Forms can execute tasks like writing ASCII trees to files.

### ex03 – More Forms

* **Description:** Add more form types like `RobotomyRequestForm` and `PresidentialPardonForm`.

---

## cpp06

**Topics:** Type conversion, `dynamic_cast`, `static_cast`, `reinterpret_cast`

### ex00 – ScalarConverter

* **Description:** Convert a string literal to `char`, `int`, `float`, and `double`.

---

## cpp07

**Topics:** Templates, function/class templates, generic programming

### ex00 – Template Swap

* **Description:** Implement generic `swap`, `min`, and `max` functions.

### ex01 – Template Class

* **Description:** Create a template `Array` class with bounds checking.

---

## cpp08

**Topics:** STL, iterators, algorithms

### ex00 – EasyFind

* **Description:** Template function that searches for a value in a container.

### ex01 – Span

* **Description:** Class that stores integers and computes shortest and longest span between elements.

### ex02 – MutantStack

* **Description:** Extend `std::stack` to allow iteration (by exposing iterators).

---

## cpp09

**Topics:** Algorithms, containers, performance, complexity

### ex00 – BitcoinExchange

* **Description:** Implement a bitcoin exchange using `std::map`.
* **How to use:**

  ```bash
  ./btc input.txt
  ```
* **Expected result:** Price for each value for date specified in input.txt file.

---

### ex01 – ReversePolishNotation

* **Description:** Implement reverse polish notation using both `std::stack`.
* **How to use:**

  ```bash
  ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
  ```
* **Expected result:** Correct output using the RPN.

---

### ex02 – PmergeMe

* **Description:** Implement Ford-Johnson sorting algorithm using both `std::vector` and `std::deque`.
* **How to use:**

  ```bash
  ./PmergeMe 3 2 1 5 8
  ```
* **Expected result:** Sorted output and time taken for each container type.

---

## Compilation & Execution

```bash
cd cppXX/exXX     # Replace XX with the module number
make           # Compile the appropriate exercise
./executable         # Run the corresponding executable
```
