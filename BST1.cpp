// sunday 14/5/2023
// Binary search tree started
// for every node values at left of node are lesser than main node
// and for right side it is greater than node val
// inorder of BST is always sorted IMPPPPPPPPPPPPPP
// BST ke deletion ka varition  for sure pucha jata hai interview me
#include <iostream>
#include <queue>
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

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    // initially

    q.push(root);
    q.push(NULL); // change here for new line
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL) // change here for new line
        {
            cout << endl;
            if (!q.empty()) /// agr queue me elements presents hai to hi NULL dalo
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// 1 creation of BST Binary Search Tree

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not the first node
    // then decide left me insert krna hai ya rigth me
    if (root->data > data)
    {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        // insert into right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;

    while (data != -1)
    {
        cin >> data;
        root = insertIntoBST(root, data);
    }
}

void preOrderTraversal(Node *root)
{
    // NLR
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// inorder of BST is always sorted
void inOrderTraversal(Node *root)
{
    // LNR
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    // LRN
    if (root == NULL)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// 2 Searching in BST
// assuming there are only unique values in tree
Node *findNodeInBST(Node *root, int target)
{
    // base case
    if (root == NULL)
    {
        return NULL; // answer nhi mila
    }

    if (root->data == target)
    {
        return root; // targte mil gya
    }

    if (target > root->data)
    {
        // right subtree m,e search kro
        return findNodeInBST(root->right, target);
    }
    else
    {
        return findNodeInBST(root->left, target);
    }
}

// 3 minimum and maximum value in binary search tree
// approach 1) simply using inorder
// approach 2) BST me left left left jao Min mil jayegi

int minValBST(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
    {
        return -1;
    }

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->data;
}

// right right right jao max mil jayega
// 4 maximum val in BST
int maxValBST(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
    {
        return -1;
    }

    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp->data;
}

// homework
// 5 inorder predeccor(left subtree ka maximum val)

// 6 inorder successor(right subtree ka minimum val)

// 7 deletion in BST
// 4 cases to delete node
// case 1 leaf node no left and no right null lga do
// case 2 left null and right not null  create link to child
// case 3 left not null and right null
// case 4 both left and right exists

Node *deleteNodeInBST(Node *root, int target)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == target)
    {
        // iso ko delete krna hai
        // 4 cases

        if (root->left == NULL && root->right == NULL)
        {
            // leaf node
            delete root;
            return NULL;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *child = root->right;
            delete root;
            return child;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *child = root->left;
            delete root;
            return child;
        }
        else
        {
            // dono child honge
            // inoder predessor of left subtree->left subtree me max val
            int inorderpre = maxValBST(root->left); // left me se max val nikal di
            // replace root->data with inorder predessor
            root->data = inorderpre;
            root->left = deleteNodeInBST(root->left, inorderpre);
            return root;
        }
    }
    else if (target > root->data)
    {
        // right me jao
        root->right = deleteNodeInBST(root->right, target);
    }
    else if (target < root->left)
    {
        roor->left = deleteNodeInBST(root->left, target);
    }

    return root;
}

int main()
{
    Node *root = NULL;
    cout << "Enter data for node " << endl;
    takeInput(root);
    cout << "Printing levelorder" << endl;
    levelOrderTraversal(root);

    // cout<<"Printing inorder"<<endl;  //inorder of BST is always sorted
    // inOrderTraversal(root);
    // cout<<endl;

    // cout<<"Printing preorder"<<endl;
    // preOrderTraversal(root);
    // cout<<endl;

    // cout<<"Printing postorder"<<endl;
    // postOrderTraversal(root);

    // bool ans=findNodeInBST(root,15);
    // cout<<endl;
    // cout<<"present or not "<<ans <<endl;
    // cout<<"Minimum value is "<<minValBST(root);cout<<endl;
    // cout<<"Maximum value is "<<maxValBST(root);

    deleteNodeInBST(root, 150);
    levelOrderTraversal(root);

    return 0;
}