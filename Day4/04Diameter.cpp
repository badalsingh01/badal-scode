#include<iostream>
#include<queue>
using namespace std;

class node{

public:
	int data;
	node*left;
	node*right;
	
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

//Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
node* buildTree(){

	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}

	node* n = new node(d);
	n->left = buildTree();
	n->right = buildTree();

	return n;
}

void levelOrderPrint(node*root){

	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		node* temp = q.front();
		if(temp==NULL){
			cout<<endl;
			q.pop();
			//insert a new null for the next level
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			q.pop();
			cout<<temp->data<<" ";

			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}

	}
	return;
}

int height(node* root) {
    if(root == NULL) {
        return 0;
    }

    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1 + max(h1, h2);
}

// Diameter
// Time Complexity?
int diameter(node* root) {
    if(root == NULL) {
        return 0;
    }

    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);

    return max(D1, max(D2, D3));
}

class HDPair{
public:
	int height;
	int diameter;
};


HDPair optDiameter(node*root){
    HDPair p;

    if(root == NULL) {
        p.height = p.diameter = 0;
        return p;
    }

    HDPair left = optDiameter(root->left);
    HDPair right = optDiameter(root->right);
    p.height = max(left.height, right.height) + 1;

    int D1 = left.height+ right.height;
    int D2 = left.diameter;
    int D3 = right.diameter;

    p.diameter = max(D1, max(D2, D3));
    return p;
}


int main(){
	
	node* root = buildTree();
	levelOrderPrint(root);
	cout << "Diameter is "<<diameter(root) <<endl;

	cout <<" Opt Diameter is " << optDiameter(root).diameter <<endl;


	return 0;
}