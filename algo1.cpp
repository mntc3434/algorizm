#include <iostream>
using namespace std;
...
// Define a node structure
struct Node {
    int data; // Data part of the node
    Node* next; // Pointer to the next node

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head; // Pointer to the head of the list this is the pointer that poits to the head of the node

public:
    LinkedList() {
        head = nullptr; // Initialize the head to nullptr
    }

    // Function to add a node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to add a node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty, cannot delete " << value << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value " << value << " not found in the list." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};
// Main function
int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtBeginning(5);
    list.insertAtEnd(30);

    cout << "Linked list after insertions:" << endl;
    list.display();

    list.deleteNode(20);
    cout << "Linked list after deleting 20:" << endl;
    list.display();

    list.deleteNode(40);
    cout << "Linked list after trying to delete 40 (not in the list):" << endl;
    list.display();

    return 0;
}
