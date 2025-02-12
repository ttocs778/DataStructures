#include <stdio.h>
#include <iostream>
#define MAX_SIZE 5

int A[MAX_SIZE];
int top = -1;
void Push(int x) {
	if (top == MAX_SIZE - 1) {
		std::cout << "Error: Stack Overflow\n";
		return;
	}
	A[++top] = x;
}
void Pop() {
	if (top == -1) {
		std::cout << "Error: No element to pop\n";
		return;
	}
	top--;
}

bool IsEmpty() {
	if (top == -1) {
		return true;
	}
	else
		return false;
}

int Top() {
	return A[top];
}

int main() {
	Push(1);
	Push(2);
	Push(3);
	Pop();
	Push(4);
	for (int i = 0; i <= top; i++) {
		std::cout << A[i];
	}

}