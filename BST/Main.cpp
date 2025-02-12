#include <iostream>

struct Node {
	int data;
	Node* left;
	Node* right;
};



void Insert(Node** root, int x) {
	if (*root == nullptr) {
		*root = new Node();
		(*root)->data = x;
		(*root)->left = nullptr;
		(*root)->right = nullptr;
	}
	else if (x <= (*root)->data) {
		Insert(&((*root)->left), x);
	}
	else {
		Insert(&((*root)->right), x);
	}
}

void Delete(int x) {


}

int FindMin(Node* root) {
	if ((root) == nullptr) {
		std::cout << "Errot: Tree is empty \n";
		return -1;
	}
	while(root->left != nullptr) {
		root = root->left;
	}
	return root->data;
}

int FindMax(Node* root) {
	if (root == nullptr) {
		std::cout << "Errot: Tree is empty \n";
		return -1;
	}
	while (root->right != nullptr) {
		root = root->right;
	}
	return root->data;
}

int FindHeight(Node* root) {
	if (root == nullptr) {
		return -1;
	}
	return std::max(FindHeight(root->left), FindHeight(root->right))+1;
}

bool Search(Node** root, int x) {
	if ((*root) == nullptr) {
		return false;
	}
	else if ((*root)->data == x) {
		return true;
	}
	else if (x <= (*root)->data) {
		return Search(&(*root)->left, x);
	}
	else {
		return Search(&(*root)->right, x);
	}
}

// Preorder traversal (Root, Left, Right)
void Preorder(Node* root) {
	if (root == NULL) return;
	printf("%c ", root->data);
	Preorder(root->left);
	Preorder(root->right);
}

// Inorder traversal (Left, Root, Right)
void Inorder(Node* root) {
	if (root == NULL) return;
	Inorder(root->left);
	printf("%c ", root->data);
	Inorder(root->right);
}


// Postorder traversal (Left, Root, Right)
void Postorder(Node* root) {
	if (root == NULL) return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%c ", root->data);
}

int main() {
	Node* root = nullptr; //create a empty tree
	Insert(&root, 15);
	Insert(&root, 10);
	Insert(&root, 20);
	Insert(&root, 25);
	Insert(&root, 8);
	Insert(&root, 12);
	int number;
	std::cout << "Enter the number to be searched \n";
	std::cin >> number;
	if (Search(&root, number) == true) std::cout << "Found\n";
	else std::cout << "Not Found\n";

	std::cout << "Min Number is: " << FindMin(root) << std::endl;
	std::cout << "Max Number is: " << FindMax(root) << std::endl;
}