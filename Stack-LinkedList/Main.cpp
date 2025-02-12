#include <iostream>

struct Node {
    int data;
    Node* link;
};

Node* top = nullptr;

// Push an element onto the stack
void Push(int x) {
    Node* temp = new Node();
    temp->data = x;
    temp->link = top;
    top = temp;
}

// Pop an element from the stack
void Pop() {
    if (top == nullptr) {
        std::cout << "Stack is empty, cannot pop.\n";
        return;
    }
    Node* temp = top;
    top = top->link;
    delete temp;
}

// Check if the stack is empty
bool isEmpty() {
    return top == nullptr;
}

// Get the top element of the stack
int Top() {
    if (top == nullptr) {
        std::cerr << "Stack is empty, no top element.\n";
        return -1;  // Indicate an error
    }
    return top->data;
}

// Print the stack elements
void Print() {
    Node* temp = top;
    std::cout << "Stack: ";
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->link;
    }
    std::cout << "\n";
}

// Main function for testing
int main() {
    Push(10);
    Push(20);
    Push(30);
    Print();  // Stack: 30 20 10

    std::cout << "Top element: " << Top() << "\n";  // Should print 30

    Pop();
    Print();  // Stack: 20 10

    std::cout << "Top element: " << Top() << "\n";  // Should print 20

    return 0;
}
