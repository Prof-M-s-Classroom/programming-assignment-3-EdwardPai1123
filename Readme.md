[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Edward Pai

## Description
This program implements Prim's algorithm to find the Minimum Spanning Tree of a connected, undirected, weighted graph. The graph is represented using an adjacency matrix, and a built of MinHeap is used to efficiently track the minimum edge weights during the algorithm

## Files
- graph.h / graph.cpp - The Graph class with Prim's MST implementation
- heap.h / heap.cpp  - The MinHeap class used ti find the smallest edge during MSt construction
- main.cpp (unchanged) - Builds a sample graph and runs the MST algorithm
- README.md - Project documentation

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | Olog(n)         |
| Extract Min          | Olog(n)         |
| Decrease Key         | Olog(n)         |
| Prim’s MST Overall   | O(n^2logn)      |

_Explain why your MST implementation has the above runtime._
The MinHeap supports efficient operations such as extractMin() and decreaseKey() in logarithmic time
Each insert, extract, and decreaseKey operation on the heap takes Olog(n) time
I looped through all vertices and edges in an adjacency matrix and perform heap operations as needed, the total runtime becomes O(n^2logn)

## Test Case Description

Input:  
The input follows the main.cpp which gives out an output of Edge 0-1, 1-2, 0-3, 1-4 and Weight 2, 3, 6, 5, got Total weigth of MST: 16