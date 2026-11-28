#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d) {
        data = d;
        left = right = NULL;
    }
};

node* insert(node* root, int data) {
    if(root==NULL) {
        return new node(data);
    }

    if(data < root->data) {
        root->left = insert(root->left,data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
bool search(node* root, int key) {
    if(!root) return false;

    if(root->data == key) {
        return true;
    }
    else if(root->data > key) {
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
}


void printInOrder(node* root) {
    if(root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout << root->data << ",";
    printInOrder(root->right);
}


int main(){

	node * root = NULL;
	int arr[] = {8,3,10,1,6,14,4,7,13};

	for(int x : arr){
		root = insert(root,x);
	}
	printInOrder(root);

	return 0;
}