*This project has been created as part of the 42 curriculum by tle-rhun*

## Description

Push_swap is a project that challenges students to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. The goal is to write a C program named push_swap which calculates and displays on the standard output the smallest program, made of Push_swap instruction language, that sorts the integers received as arguments.

For this implementation, I used two different strategies based on the size of the input:

    Small Sort: A specific algorithm for 5 numbers or fewer to ensure minimal operations for small sets.

    Radix Sort: For sets larger than 5 numbers, I implemented a Radix Sort algorithm using binary representation. This approach sorts the stack by comparing bits (0s and 1s) from the least significant to the most significant, efficiently moving numbers between Stack A and Stack B.

Performance

The efficiency of the algorithm is measured by the number of operations:

    100 numbers: ~1084 operations.

    500 numbers: ~6784 operations.

## Instructions
Compilation

The project includes a Makefile with the standard rules. To compile the program, run the following command in your terminal: "make".

This will generate the push_swap executable. Other available rules are:

    make clean: Removes object files.

    make fclean: Removes object files and the executable.

    make re: Recompiles the entire project.

Execution

To run the program, provide a list of integers as arguments. The program will output the sequence of operations required to sort them in ascending order. 
For example: ./push_swap 4 67 3 87 23

You can also use a string of numbers:
ARG="4 67 3 87 23"; ./push_swap $ARG

## Resources
Documentation & Tutorials

    GeeksforGeeks - Radix Sort: Used to understand the theoretical foundation of the Radix algorithm.->https://www.geeksforgeeks.org/dsa/radix-sort/

    Medium - Push_swap Tutorial: Provided guidance on the project structure and logic.->https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e

    Koor.fr - Binary Operators: Used to master the bitwise operations necessary for the binary Radix implementation.->https://koor.fr/Java/Tutorial/java_operateurs_binaires.wp

Use of AI

In this project, Artificial Intelligence was used as a debugging assistant. Specifically:

    Task: Troubleshooting circular linked lists.

    Description: Since this was my first time manipulating circular linked lists, I used AI to identify logic errors in my pointer assignments and to help debug memory-related issues during the integration of the Radix algorithm.