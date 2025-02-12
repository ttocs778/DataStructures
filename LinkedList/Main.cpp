#include <iostream>

struct Node {
	int data;
	Node* next;
};

Node* head = nullptr; // Global head pointer

// Insert a node at a specific position
void Insert(int data, int place) {
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = nullptr;

	if (place == 1) {
		temp1->next = head;
		head = temp1;
		return;
	}

	Node* temp2 = head;
	for (int i = 0; i < place - 2; i++) {
		if (temp2 == nullptr) return; // Prevent segmentation fault
		temp2 = temp2->next;
	}

	temp1->next = temp2->next;
	temp2->next = temp1;
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

/* Recursive Print function
void Print(Node* head) {
	if (head == nullptr) return;
	std::cout << head->data;
	Print(head->next);
}
*/

// Reverse the linked list
Node* Reverse(Node* head) {
	Node* current = head;
	Node* prev = nullptr;
	Node* next = nullptr;

	while (current != nullptr) {
		next = current->next;   // Store next node
		current->next = prev;   // Reverse current node's pointer
		prev = current;         // Move prev forward
		current = next;         // Move current forward
	}

	return prev; // Return new head
}

// 1, 2, 3, 4, 5
/* Recursive Reverse function
void Reverse(Node* p) {
	if (p->next == nullptr) {
		head = p;
		return;
	}
	Reverse(p->next);
	Node* q = p->next;
	q->next = p;
	p->next = nullptr;
}
*/

int main() {
	Insert(1, 1);
	Insert(2, 2);
	Insert(4, 3);
	Insert(6, 4);
	Insert(8, 5);

	Print(); // Print original list

	head = Reverse(head); // Reverse the linked list

	Print(); // Print reversed list

	return 0;
}
