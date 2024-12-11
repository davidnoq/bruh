# In-Memory Database with Transaction Support

This is a C++ implementation of an in-memory key-value database with support for transactions. It allows for atomic operations with features like `commit` and `rollback`.

## Features

- **Key-Value Storage**: Stores keys (strings) and values (integers).
- **Transaction Support**:
  - `begin_transaction`: Starts a new transaction.
  - `put`: Adds or updates key-value pairs within a transaction.
  - `commit`: Applies changes made in a transaction to the main database.
  - `rollback`: Discards all changes made in a transaction.
- **Isolation**: Changes in a transaction are not visible until `commit` is called.

## Usage

### Compilation
To compile the program, use the following command:
```bash
g++ -std=c++17 -o in_memory_db in_memory_db_transactions.cpp

after compilation, run ./in_memory_db

### Write up
I believe that this assignment has the potential to really help understand enterprise practices. I feel like this assignment if given enough instructions and guidance, can become a project. For example, Imagine taking this class and actually implementing a project (not as advanced as real tech companies), and being able to understand in a way how enterprise companies would implement these applications. In order to become official, I think this assignment should specify more about maybe making the student pretend to be an enterprise business, and create an application that allows their business to scale like this one does. You could even add a part that says it can be made in any language, framework, or script they want. Grading should take into effect creativity of the programming language or framework they used to display this application.
