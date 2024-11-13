//you can build your own tree before traversal using linked list and queue data structures
//level ,pre , post ,In order traversals available   
#include <iostream>
#include <queue>
using namespace std;

class node {
public:
	int data;
	node* right;
	node* left;

	node(int x) {
		data = x;
		right = nullptr;
		left = nullptr;
	}
};

//function to build binary tree before traversal 
node* buildtree(node* root) {
	cout << "Enter data : ";
	int data;
	cin >> data;
	if (data == -1) {
		return NULL;
	}

	root = new node(data);

	cout << "Enter data to insert to the left of " << data << endl;
	root->left = buildtree(root->left);

	cout << "Enter data to insert to the right of " << data << endl;
	root->right = buildtree(root->right);

	return root;
}

//Level Order Traversal of given binary tree
void levelOrderTraversal(node* root) {
	cout << endl;
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node* temp = q.front();
		q.pop();

		if (temp == NULL) {
			cout << endl;
			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			cout << temp->data << " ";

			if (temp->left != nullptr) {
				q.push(temp->left);
			}
			if (temp->right != nullptr) {
				q.push(temp->right);
			}
		}
	}

}

//Pre Order Traversal of given binary tree
void preOrderTraversal(node* temp) {
	if (temp == NULL) {
		return;
	}
	cout << temp->data << "  ";
	preOrderTraversal(temp->left);
	preOrderTraversal(temp->right);
}

//Post Order Traversal of given binary tree
void postOrderTraversal(node* temp) {
	if (temp == NULL) {
		return;
	}
	postOrderTraversal(temp->left);
	postOrderTraversal(temp->right);
	cout << temp->data << "  ";
}

//In Order Traversal of given binary tree
void inOrderTraversal(node* temp) {
	if (temp == NULL) {
		return;
	}
	inOrderTraversal(temp->left);
	cout << temp->data << "  ";
	inOrderTraversal(temp->right);
}

int main() {

	node* root = NULL;
	root = buildtree(root);

	levelOrderTraversal(root);
	cout << endl;
	
	preOrderTraversal(root);
	cout << endl;
  
	postOrderTraversal(root);
	cout << endl;
  
	inOrderTraversal(root);

	return 0;
}
