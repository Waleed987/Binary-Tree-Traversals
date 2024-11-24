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

//you can make binary tree in level order traversal manner using this function.
node* buildTreeUsingLevelOrderTrav(node* root) {
	queue<node*> q;
	cout << "\nEnter data : ";
	int data;
	cin >> data;
	root = new node(data);
	q.push(root);

	while (!q.empty()) {
		node* temp = q.front();
		q.pop();

		cout << "\nEnter data to insert to left of " << temp->data << " : ";
		int leftdata;
		cin >> leftdata;
		if (leftdata != -1) {
			temp->left = new node(leftdata);
			q.push(temp->left);
		}
		
		cout << "\nEnter data to insert to right of " << temp->data << " : ";
		int rightdata;
		cin >> rightdata;
		if (rightdata != -1) {
			temp->right = new node(rightdata);
			q.push(temp->right);
		}
	}
	return root;
}

node* minValNode(node* root) {
	node* temp = root;
	while (temp && temp->left != nullptr) {
		temp = temp->left;
	}
	return temp;
}

node* deleteNode(node* root, int val) {
	if (root == NULL) {
		return root;
	}

	if (val < root->data) {
		root->left = deletenode(root->left, val);
	}
	else if (val > root->data) {
		root->right = deletenode(root->right, val);
	}
	else {
		if (root->left == nullptr) {
			node* temp = root->right;
			delete(root);
			return temp;
		}
		else if (root->right == nullptr) {
			node* temp = root->left;
			delete(root);
			return temp;
		}
		
		node* temp = minValNode(root->right);

		root->data = temp->data;

		root->right = deletenode(root->right, temp->data);

	}

	return root;

}

node* insertInBinaryTree(node* root , int val) {
	if (root == NULL) {
		node* newNode = new node(val);
		return newNode;
	}

	else if (root->data > val) {
		root->left = insertbt(root->left, val);
	}

	else if (root->data < val) {
		root->right = insertbt(root->right, val);
	}
	return root;
}

int main() {

	node* root = NULL;
	
	root = buildtree(root);

	return 0;
}
