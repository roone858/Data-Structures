#include <iostream>
using namespace std;
class Node {
public:

	int data;
	Node *left;
	Node *right;
	Node(int item) {
		data = item;
		left = NULL;
		right = NULL;
	}


};
class BST {
public:
	Node *root;
	BST() {
		root = NULL;
	}
	Node *insert(Node*root, int item)
	{
		if (root == NULL)
		{
			Node*newnode = new Node(item);
			root = newnode;
		}
		else if (item < root->data)
			root->left = insert(root->left, item);
		else
			root->right = insert(root->right, item);
		return root;
	}
	void insert(int item)
	{
		root = insert(root, item);

	}
	bool isEmpty()
	{
		return root == NULL;
	}
	Node *search(Node*node, int item)
	{
		if (node == NULL)
			return NULL;
		else if (node->data == item)
			return node;
		else if (node->data > item)
			return search(node->left, item);
		else
			return search(node->right, item);
	}
	bool search(int item)
	{
		Node*result = search(root, item);
		return result != NULL;
	}
	void preOrder(Node*root)
	{
		if (root == NULL)
			return;
		cout << root->data << "\t";
		preOrder(root->left);
		preOrder(root->right);
	}
	void inOrder(Node*node)
	{
		if (node == NULL)
			return;

		inOrder(node->left);
		cout << node->data << "\t";
		inOrder(node->right);
	}
	void postOrder(Node*r)
	{
		if (r == NULL)
			return;
		postOrder(r->left);
		postOrder(r->right);
		cout << r->data << "\t";
	}
	Node* findmin(Node*r)
	{
		if (r == NULL)
			return NULL;
		else if (r->left == NULL)
			return r;
		else
			return findmin(r->left);
	}
	int findmin()
	{
		Node*min = root;
		min = findmin(min);
		return min->data;
	}
	Node* findmax(Node*r)
	{

		if (r == NULL)
			return NULL;
		else if (r->right == NULL)
			return r;
		else
			return findmax(r->right);
	}
	int findmax()
	{
		Node*max = root;
		max = findmax(max);
		return max->data;
	}
	Node* Delete(Node*root, int item)
	{
		if (root == NULL)
			return NULL;
		else if (item < root->data)
			root->left = Delete(root->left, item);
		else if (item > root->data)
			root->right = Delete(root->right, item);
		else
		{
			if (root->left == NULL && root->right == NULL)
				root = NULL;
			else if (root->left != NULL && root->right == NULL)
			{
				root->data = root->left->data;
				delete root->left;
				root->left = NULL;
			}
			else if (root->left == NULL && root->right != NULL)
			{
				root->data = root->right->data;
				delete root->right;
				root->right = NULL;
			}
			else
			{
				Node*max = findmax(root->left);
				root->data = max->data;
				root->left = Delete(root->left, max->data);
			}
		}
		return root;
	}
	void Delete(int item) {
		root = Delete(root, item);
	}

};
int main() {
	BST tree;
	tree.insert(45);
	tree.insert(15);
	tree.insert(79);
	tree.insert(90);
	tree.insert(10);
	tree.insert(55);
	tree.insert(12);
	tree.insert(20);
	tree.insert(50);
	cout << "The tree contains : \n";
	tree.preOrder(tree.root);
	cout << "\nChoose a process by typing the process number : \n";
	cout << "\n1.insert        2.search        3.find min      4.find max      5.delete \n";
	int pNum ;
	int  item;
	cin >> pNum;
	switch (pNum)
	{
	case 1 :
		cout << "\nEnter item to insert : ";
		cin >> item;
		tree.insert(item);
		break;
	case 2:
		cout << "\nEnter item to search : ";
		cin >> item;
		if (tree.search(item))
			cout << "the num is found";
		else
			cout << "sorry we didn't find this num";
		break;
	case 3:
		cout << "The min num = "<< tree.findmin();
		break;

	case 4:
		cout << "The max num = " << tree.findmax();
		break;
	case 5:
		cout << "\nEnter item to  delete : ";
		cin >> item;
		if (tree.search(item))
			tree.Delete(item);
		else
			cout << "sorry we didn't find this item";
		break;
	default:
		break;
	}
	cout << "\n  inORDER display  \n";
	tree.inOrder(tree.root);
	cout << "\n  preORDER display  \n";
	tree.preOrder(tree.root);
	cout << "\n  postORDER display  \n";
	tree.postOrder(tree.root);
	

	
}
