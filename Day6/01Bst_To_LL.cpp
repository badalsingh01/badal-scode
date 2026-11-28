#include<iostream>
#include<climits>
using namespace std;

class node{
	public:
	int data;
	node* left, *right;
	node(int d) {
		data = d;
		left = right = NULL;
	}
};

node* insertInBST(node* root, int d) {
	if(!root) {
		root = new node(d);
		return root;
	}

	if(root->data >= d){
		root->left = insertInBST(root->left, d);
	}
	else {
		root->right = insertInBST(root->right, d);
	}
	return root;
}
// 8 3 10 1 6 14 4 7 13 -1
node* createBST() {
	int data;
	cin >> data;
	if(data == -1) {
		return NULL;
	}
	node* root = NULL;
	while(data != -1) {
		root = insertInBST(root, data);
		cin >> data;
	}
	return root;
}

node* searchBST(node* root, int key) {
	if(!root) return NULL;

	if(root->data == key) {
		return root;
	}
	else if(root->data>key) {
		return searchBST(root->left,key);
	}
	else {
		return searchBST(root->right,key);
	}
 }

 void preorder(node* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder(node* root) {
	if (root == NULL) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

void printRange(node* root, int k1, int k2) {
	if(root == NULL) {
		return;
	}
	printRange(root->left,k1, k2);
	if(root->data >= k1 and root->data <= k2) cout << root->data << " ";
	printRange(root->right, k1, k2);
}

class Pair{
	public:
	int height;
	bool balanced;
};
Pair isBalanced(node* root) {
	Pair p;
	if(!root) {
		p.height = 0;
		p.balanced = true;
		return p;
	}

	Pair left = isBalanced(root->left);
	Pair right = isBalanced(root->right);

	if(left.balanced and right.balanced and abs(left.height-right.height) <= 1) {
		p.balanced = true;
	}
	else {
		p.balanced = false;
	}
	p.height = max(left.height, right.height) + 1;
	return p;
}

bool isBST(node* root, int mi = INT_MIN, int mx = INT_MAX) {
	if(!root) {
		return true;
	}

	if(root->data >= mi and root->data <= mx and isBST(root->left,mi, root->data) == true and isBST(root->right, root->data,mx) == true) {
		return true;
	}
	return false;
}

node* createBalancedBST(int*a, int s, int e) {
	if(s>e) {
		return NULL;
	}
	int m = (s+e)/2;
	node* root = new node(a[m]);
	root->left = createBalancedBST(a,s,m-1);
	root->right=createBalancedBST(a,m+1,e);
	return root;
}
class LL {
	public:
	node* head, *tail;
};

LL BSTtoLL(node* root) {
	LL l;
	if(!root) {
		l.head = l.tail = NULL;
		return l;
	}

	if(root->left and root->right) {
		LL left = BSTtoLL(root->left);
		LL right = BSTtoLL(root->right);
		left.tail->right = root;
		root->right = right.head;
		l.head = left.head;
		l.tail = right.tail;
		return l;
	}
	else if(root->left and !root->right) {
		LL left = BSTtoLL(root->left);
		left.tail->right = root;
		l.head=left.head;
		l.tail = root;
		return l;
	}
	else if(!root->left and root->right) {
		LL right = BSTtoLL(root->right);
		right.tail->left = root;
		l.head=right.head;
		l.tail = root;
		return l;
	}
	else {
		l.head = l.tail = root;
		return l;
	}
}

int main() {

	// node* root = createBST();
	int a[] = {1, 2, 3, 4, 5, 6, 7, 10};
	int n = sizeof(a) / sizeof(int);

	node* root =  createBalancedBST(a, 0, n - 1);
	LL l = BSTtoLL(root);

	node* head = l.head;
	while (head) {
		cout << head->data << "-->";
		head =  head->right;
	}
	cout << "NULL\n";

		return 0;
}