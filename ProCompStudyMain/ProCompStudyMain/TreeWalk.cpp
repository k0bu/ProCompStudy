#include "pch.h"

#define MAX 10000
#define NIL -1

using namespace std;

struct Node {
	int parent, left, right;
};

Node *binaryTree;

void PreParse (int id) {
	if (id == NIL) {
		return;
	}

	printf(" %d",id);

	PreParse(binaryTree[id].left);
	PreParse(binaryTree[id].right);
}

void InParse (int id) {
	if (id == NIL) {
		return;
	}

	InParse (binaryTree[id].left);
	printf (" %d", id);
	InParse (binaryTree[id].right);
}

void PostParse (int id) {
	if (id == NIL) {
		return;
	}

	PostParse (binaryTree[id].left);
	PostParse (binaryTree[id].right);
	
	printf (" %d", id);
}

void TreeWalk () {
	int n;
	cin >> n;
	binaryTree = new Node[n];

	for (int i = 0; i < n; i++) {
		binaryTree[i].parent = NIL;
	}

	int id, left, right;
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d %d", &id, &left, &right);

		binaryTree[id].left = left;
		binaryTree[id].right = right;

		if (left != NIL) {
			binaryTree[left].parent = id;
		}
		if (right != NIL) {
			binaryTree[right].parent = id;
		}
	}

	int root = 0;
	for (int i = 0; i < n; i++) {
		if (binaryTree[i].parent == NIL) {
			root = i;
		}
	}

	printf("Preorder\n");
	PreParse(root);
	cout << endl;
	printf ("Inorder\n");
	InParse (root);
	cout << endl;
	printf ("Postorder\n");
	PostParse (root);
	cout << endl;


	return;
}
