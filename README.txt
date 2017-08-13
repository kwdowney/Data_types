Compile instructions:

g++ -g llistint.cpp llist_tester.cpp -o llist_tester

llistint.cpp  
Implements a linked list for ints. Functions to insert a node at a specified location in a list, remove a specified node, overwrite an existing node's value, return a node given a location, return a node's value given a location, erase a populated list, check if a list is empty, and return a list's size are included.

llist_tester.cpp
A program to test the efficacy of llistint.cpp. This program populates a linked list and then tests the functions we wrote to insert, remove, return, and delete a linked list of ints.