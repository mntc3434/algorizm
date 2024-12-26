#include <iostream>
using namespace std;

// Define a node structure
struct Node {
    int data; // Data part of the node
    Node* next; // Pointer to the next node

    Node(int value) {
        data = value;
        next = nullptr;
    }
};
