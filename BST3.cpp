// Saturday //20/5/23
// only three questions
// at bottom
//###################################################
//                  Lasts question                 //
//###################################################

#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;

	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

class NodeData
{
public:
	int size;
	int minVal;
	int maxVal;
	bool validBST;

	NodeData() //default constructor
	{
	}

	NodeData(int size, int max, int min, bool valid)
	{
		this->size = size;
		minVal = min;
		maxVal = max;
		validBST = valid;
	}
};


// 1 BST to sorted Doubly Linked List
void convertIntoSortedDLL(Node *root, Node *&head)
{
	// base case
	if (root == NULL)
	{
		return;
	}

	// right subtree into LL
	convertIntoSortedDLL(root->right, head);

	// atach kro root ke  right me right  wali LL
	root->right = head;

 //agr head Null nhi hai
	if (head != NULL)
		head->left = root; 

	// update head
	head = root;

	// left subtree linked List
	convertIntoSortedDLL(root->left, head);
}

void printLinkedList(Node *head)
{
	Node *temp = head;
	cout << endl;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->right;
	}
	cout << endl;
}

// sorted linked list to BST
// left subtree n/2-1
Node *sortedLinkedListIntoBST(Node *&head, int n)
{
	// base case
	if (n <= 0 || head == NULL)
		return NULL;

	Node *leftSubtree = sortedLinkedListIntoBST(head, n / 2); // mid tk

	Node *root = head;
	root->left = leftSubtree;

	head = head->right;

	// right part solve karna h
	root->right = sortedLinkedListIntoBST(head, n - 1 - n / 2);
	return root;
}

// largest BST in a binary tree
// balance BST ka fastest tarika

NodeData *findLargestBST(Node *root, int &ans)
{
	// base case
	if (root == NULL)
	{
		NodeData *temp = new NodeData(0, INT_MIN, INT_MAX, true);
		return temp;
	}

	NodeData *leftKaAns = findLargestBST(root->left, ans);
	NodeData *rightKaAns = findLargestBST(root->right, ans);

	// checking starts here
	NodeData *currNodeKaAns = new NodeData();

	currNodeKaAns->size = leftKaAns->size + rightKaAns->size + 1;
	currNodeKaAns->maxVal = max(root->data, rightKaAns->maxVal);
	currNodeKaAns->minVal = min(root->data, leftKaAns->minVal);

	if (leftKaAns->validBST && rightKaAns->validBST && (root->data > leftKaAns->maxVal && root->data < rightKaAns->minVal))
	{
		currNodeKaAns->validBST = true;
	}
	else
	{
		currNodeKaAns->validBST = false;
	}

	if (currNodeKaAns->validBST)
	{
		ans = max(ans, currNodeKaAns->size);
	}
	return currNodeKaAns;
}

int main()
{

	// int inorder[] = {1,2,3,4,5,6,7,8,9};
	// int s = 0;
	// int e = 8;

	// Node* root = bstUsingInorder(inorder, s,e);
	// levelOrderTraversal(root);

	// cout << "printing sorted linked list:" << endl;
	// Node* head = NULL;
	// convertIntoSortedDLL(root, head);
	// printLinkedList(head);

	// Node* root1 = NULL;
	// root1 =	sortedLinkedListIntoBST(head, 9);
	// cout << "Doping level order traversal for root 1" << endl;
	// levelOrderTraversal(root1);

	// Node* root = NULL;
	// cout << "Enter the data for Node " << endl;
	// takeInput(root);

	Node *root = new Node(50);
	Node *first = new Node(30);
	Node *second = new Node(60);
	Node *third = new Node(5);
	Node *fourth = new Node(20);
	Node *fifth = new Node(45);
	Node *sixth = new Node(70);
	Node *seventh = new Node(65);
	Node *eight = new Node(80);

	root->left = first;
	root->right = second;
	first->left = third;
	first->right = fourth;
	second->left = fifth;
	second->right = sixth;
	sixth->left = seventh;
	sixth->right = eight;

	cout << "Printing the tree" << endl;
	levelOrderTraversal(root);

	int ans = 0;
	findLargestBST(root, ans);
	cout << "Largest BSK ka Size:  " << ans << endl;

	// cout << endl;
	//   cout << "Printing Inorder: " << endl;
	//   inOrderTraversal(root);
	//   cout << endl;
	//   cout << "Printing Preorder: " << endl;
	//   preOrderTraversal(root);
	//   cout << endl;
	//   cout << "Printing Postorder: " << endl;
	//   postOrderTraversal(root);

	// bool ans  = findNodeInBST(root,155);
	// cout << "present or not : " << ans << endl;
	// cout << endl <<" Minimum value: " << minVal(root) << endl;
	// cout << endl << "Maximum value: " << maxVal(root) << endl;

	// root = deleteNodeInBST(root, 100);
	// levelOrderTraversal(root);

	return 0;
}