#include <iostream>

struct Node {
	int data;
	Node* next;
	Node* prev;
};
struct Node* head; // Global head pointer
 
// Create a new node
Node* GetNewNode(int x) {
	Node* temp = new Node();
	temp->data = x;
	temp->next = nullptr;
	temp->prev = nullptr;
	return temp;

}
// Insert a node at a specific position
void InsertAtHead(int x) {
	Node* temp = GetNewNode(x);
	if (head == nullptr) {
		head = temp;
		return;
	}
	head->prev = temp;
	temp->next = head;
	head = temp;
}

void InsertAtTail(int x) {
	Node* temp = GetNewNode(x);  
	if (head == nullptr) {
		head = temp;
		return;
	}
	Node* temp1 = head;
	while (temp1->next != nullptr) {
		temp1 = temp1->next;
	}
	temp1->next = temp;
	temp->prev = temp1;
}
// Print the linked list
void Print() {
	std::cout << "Here is your linked list: \n";
	Node* temp = head;
	while (temp != nullptr) {  // Corrected condition
		std::cout << temp->data << " -> ";
		temp = temp->next;
	}     
	std::cout << "NULL\n";
}
//Reverse Print
void ReversePrint() {
	Node* temp = head;
	if (temp == nullptr) return;
	//Going to last node
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	//Traversing backward using prev pointer
	std::cout << "Reverse: ";
	while (temp != nullptr) {
		std::cout << temp->data << " -> ";
		temp = temp->prev;
	}
	std::cout << "NULL\n";
}

int main() {
	// create list
	head = nullptr;
	InsertAtTail(2); Print(); ReversePrint();
	InsertAtTail(4); Print(); ReversePrint();	
	InsertAtTail(6); Print(); ReversePrint();
	InsertAtHead(1); Print(); ReversePrint();
}