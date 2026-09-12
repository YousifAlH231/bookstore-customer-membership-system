# Bookstore Customer & Membership System

A university C++ project that demonstrates object-oriented programming and file handling through a bookstore customer and membership system.

## Overview

The program reads customer and book information from text files, identifies the books purchased by each customer using ISBN numbers, calculates the total purchase cost, and applies a discount for customers registered as members.

## Features

* Reads customer information from a text file
* Reads book information including ISBN, title, author, and price
* Matches customer purchases with books using ISBN numbers
* Calculates the total cost of purchased books
* Supports regular customers and members
* Applies percentage-based discounts for members
* Displays customer details, purchased books, total cost, and discounted net cost

## C++ Concepts Used

* Object-Oriented Programming
* Classes and Objects
* Inheritance
* Constructors
* Protected and Private Members
* Structures
* Arrays
* File Input/Output
* `ifstream`
* `stringstream`
* Functions and Member Functions
* Data Parsing

## Class Structure

### Customer

Stores customer information, purchased books, and total cost.

### Member

Inherits from the `Customer` class and adds membership discount functionality and net cost calculation.

### book

A structure used to store:

* ISBN
* Book title
* Author
* Price

## Project Files

* `header.h` – Class and structure declarations
* `headerImp.cpp` – Function and class implementations
* `main.cpp` – Main program used to create and test customer/member objects
* `customer.txt` – Customer information and purchased book ISBNs
* `book.txt` – Book information and prices

## Language

C++

