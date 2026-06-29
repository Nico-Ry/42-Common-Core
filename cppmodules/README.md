# CPP Modules

CPP Modules is a series of C++ projects from the 42 Common Core.

The goal is to transition from C programming to C++ by learning object-oriented programming, classes, inheritance, polymorphism, templates, exceptions and standard library concepts.

This project series was important because it introduced higher-level software design after many low-level C projects.

---

## Overview

The CPP Modules are organized as progressive exercises.

Each module focuses on a specific part of C++ and object-oriented programming.

The progression moves from basic syntax and classes toward more advanced topics such as inheritance, abstract classes, templates and containers.

```text
C programming foundations
  ↓
C++ syntax
  ↓
classes and objects
  ↓
constructors / destructors
  ↓
operator overloads
  ↓
inheritance
  ↓
polymorphism
  ↓
templates
  ↓
containers and iterators
```

---

## Main Topics

* C++ syntax
* namespaces
* classes
* member functions
* constructors
* destructors
* copy constructors
* assignment operators
* Orthodox Canonical Form
* operator overloading
* inheritance
* polymorphism
* abstract classes
* interfaces
* exceptions
* templates
* STL containers
* iterators

---

## Module Progression

| Module        | Main focus                                                         |
| ------------- | ------------------------------------------------------------------ |
| CPP Module 00 | Basic C++ syntax, classes, member functions                        |
| CPP Module 01 | Memory allocation, references, pointers to members                 |
| CPP Module 02 | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form |
| CPP Module 03 | Inheritance                                                        |
| CPP Module 04 | Subtype polymorphism, abstract classes, interfaces                 |
| CPP Module 05 | Exceptions and error handling                                      |
| CPP Module 06 | C++ casts                                                          |
| CPP Module 07 | Templates                                                          |
| CPP Module 08 | Templated containers, iterators, algorithms                        |
| CPP Module 09 | STL containers and algorithmic exercises                           |

---

## Orthodox Canonical Form

Several modules require classes to follow the Orthodox Canonical Form.

This means implementing:

* default constructor
* copy constructor
* copy assignment operator
* destructor

Example structure:

```cpp
class Example
{
public:
	Example();
	Example(const Example& other);
	Example& operator=(const Example& other);
	~Example();
};
```

This helped me understand object lifecycle, copying behavior and resource management in C++.

---

## Object-Oriented Concepts

The modules introduce core object-oriented ideas:

### Encapsulation

Keeping data and behavior together inside classes.

### Inheritance

Creating new classes from existing classes.

### Polymorphism

Using base class interfaces to interact with derived objects.

### Abstraction

Defining common behavior without exposing implementation details.

---

## Skills Practiced

* writing C++ classes
* organizing header and source files
* understanding constructors and destructors
* managing object lifetime
* overloading operators
* using inheritance correctly
* using virtual functions
* handling exceptions
* writing templates
* working with STL containers
* thinking in object-oriented design

---

## How to Build

Each module usually contains its own exercises and Makefiles.

Example:

```bash
cd cpp00/ex00
make
```

Or depending on the folder naming:

```bash
cd CPP_Module_00/ex00
make
```

The exact paths depend on the structure of this repository.

---

## How to Run

After building an exercise:

```bash
./program_name
```

Each exercise has its own executable and expected behavior.

---

## Why This Project Matters

The CPP Modules were the bridge between procedural C programming and larger C++ software architecture.

They helped me understand how larger projects can be structured around objects, interfaces and reusable components.

This foundation was especially useful for later C++ projects such as `Webserv`.

---

## What I Learned

The most important lessons from the CPP Modules were:

* how C++ differs from C
* how object lifetime works
* why constructors and destructors matter
* how copying objects can create subtle bugs
* how inheritance should be used carefully
* why virtual destructors are important
* how exceptions change error handling
* how templates make code reusable
* how STL containers simplify common data structures
* how object-oriented design can make larger projects easier to organize

---

## Notes

CPP Modules were a major step toward writing more structured and maintainable code.

They introduced concepts that became useful later in Webserv, especially class design, resource management and modular architecture.
