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
