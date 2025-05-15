#ifndef GRAPH_H
#define GRAPH_H
#include "heap.h"
#include <iostream>
#include <climits>

class Graph {
public:
    Graph(int vertices);
    ~Graph();
    void addEdge(int u, int v, int weight);
    void primMST();  // Must print MST edges and total weight

private:
    int** adjMatrix;
    int numVertices;
};

Graph::Graph(int vertices) { // Creates an adjMatrix and initializes all values to 0, indicating no edges
    numVertices = vertices;
    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; ++j)
            adjMatrix[i][j] = 0;
    }
}

Graph::~Graph() { // deletes the matrix to free up memory
    for (int i = 0; i < numVertices; ++i)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}

void Graph::addEdge(int u, int v, int weight) { // Adds an edge between u and v in an undirected graph by setting weights in both directions
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

void Graph::primMST() { // Prim's algorithm to find and print the Minimum Spanning Tree
    int * parent = new int[numVertices]; // Stores MST structure
    int * key = new int[numVertices]; // Stores weights to pick the minimum edge
    MinHeap minHeap(numVertices); // Our custom heap to always get the smallest weight edge

    for (int v = 0; v < numVertices; ++v) { // Initialize all vertices with max weight
        key[v] = INT_MAX;
        parent[v] = -1; // No parent yet
        minHeap.insert(v, key[v]); // Add to heap
    }

    key[0] = 0; // Start from vertex 0
    minHeap.decreaseKey(0, key[0]);

    while (!minHeap.isEmpty()) {
        int u = minHeap.extractMin(); // Get vertex with smallest weight

        for (int v = 0; v < numVertices; ++v) { // Go through all vertices connected to u
            if (adjMatrix[u][v] && minHeap.isInMinHeap(v) && adjMatrix[u][v] < key[v]) { // If v is connected to u and is still in heap, and has a better weight
                key[v] = adjMatrix[u][v]; // Update key value
                parent[v] = u; // Sat u as parent of v in MST
                minHeap.decreaseKey(v, key[v]); // Update heap with better weight
            }
        }
    }

    int totalWeight = 0;
    std::cout << "Edge   Weight\n";
    for (int i = 1; i < numVertices; ++i) {
        std::cout << parent[i] << " - " << i << "    " << adjMatrix[i][parent[i]] << "\n";
        totalWeight += adjMatrix[i][parent[i]];
    }
    std::cout << "Total weight of MST: " << totalWeight << "\n";

    delete[] parent;
    delete[] key;
}

#endif