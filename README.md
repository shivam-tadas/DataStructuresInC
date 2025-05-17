# DataStructuresInC

A collection of data structures implemented in C with a menu-driven interface mostly coded manually, without the use of LLMs.

## Overview

This repository contains implementations of various data structures in C. Each implementation is designed to be  efficient and easy to use through a menu-driven interface that allows you to interact with the data structures directly. No code provided by any LLM is directly used for writing these files. LLMs were used to inspect the programs and report the errors/issues in the source code.

## Features

- **Menu-driven interface**: Interact with data structures through a simple console menu
- **No external dependencies**: Pure C implementation that works with any standard C compiler

## Data Structures Implemented

- **Linked List** (MenuDrivenLL.c): A singly linked list implementation with operations for insertion, deletion and traversal.
- **Queue** (MenuDrivenQueue.c): A queue implementation with enqueue, dequeue, and display operations.
- **Array ADT** (MenuArrayADT.c): An implementation of a simple array ADT with insert, clear and display operations.

## How to Use

1. Clone the repository:
   ```
   git clone https://github.com/shivam-tadas/DataStructuresInC.git
   ```

2. Navigate to the repository directory:
   ```
   cd DataStructuresInC
   ```

3. Compile the code (example):
   ```
   gcc -o MenuDrivenLL MenuDrivenLLc.c
   ```

4. Run the program (same example):
   ```
   ./MenuDrivenLL
   ```

5. Follow the on-screen menu to interact with the implemented data structure in the respective file.

## Code Structure

- `MenuDrivenLLc.c` - Implementation of a linked list with a menu interface
- `MenuDrivenQueue.c` - Implementation of a queue with a menu interface
- `MenuArrayADT.c` - Implementation of array ADT with a menu interface

## Contributing

Contributions are welcome! If you'd like to add a new data structure or improve an existing implementation:

1. Fork the repository
2. Create a new branch (`git checkout -b feature/new-data-structure`)
3. Commit your changes (`git commit -am 'Add binary tree implementation'`)
4. Push to the branch (`git push origin feature/new-data-structure`)
5. Create a new Pull Request

Note: Please do not contribute LLM generated programs.

## Author

[Shivam Tadas](https://github.com/shivam-tadas)
