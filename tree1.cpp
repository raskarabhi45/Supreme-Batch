//tree lecture start
//5/5/2023
//friday 
//again same repreated on  saturday 6/5/2023 qki bhaiya ki friday wala lecture achha nhi lga bt bdiya tha O bhi
//node root parent child sibling(same level pe exist kr rhe he) 
//ancestor (node ke upar ke sare) decendant(node ke niche kr sare) 
//leaf (is node la koi bhi child nhi hota)
//interview questions
//formula base questions on trees
//80-90% classical questions repeat krtee hai
//jo bhaiya lene wale hai
//Tree implementation

//sb kuch dry run krna hai firse

#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

//1
Node* buildTree(int data)
{
    // base case
    if(data==-1)
    {
        return NULL;
    }
   // 1 case
    Node* root=new Node(data);

    //recursion
    int leftData;
    cout<<"enter data for left child of "<<data<<endl;
    cin>>leftData;
    root->left=buildTree(leftData);

    int rightData;
    cout<<"enter data for right child of "<<data<<endl;
    cin>>rightData;
    root->right=buildTree(rightData);

    return root;
}

//level order traversal that is printing level wise
//output
// Enter data
// 20
// enter data for left child of 20
// 30
// enter data for left child of 30
// -1
// enter data for right child of 30
// -1
// enter data for right child of 20
// 50
// enter data for left child of 50
// 10
// enter data for left child of 10
// 60
// enter data for left child of 60
// -1
// enter data for right child of 60
// -1
// enter data for right child of 10
// -1
// enter data for right child of 50
// -1
// Answer :
// 20
// 30 50
// 10
// 60
//steps
//1 temp=q.front()
//2 q.pop()
//3 print
//4 child insert

//2
void levelOrderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    queue<Node*> q;
    //initially

    q.push(root);
    q.push(NULL);   //change here for new line
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        if(temp==NULL)  //change here for new line
        {
            cout<<endl;
            if(!q.empty())   ///agr queue me elements presents hai to hi NULL dalo
            {
                q.push(NULL);
            }

        }
        else
        {
            cout<<temp->data<<" ";

        if(temp->left)
        {
            q.push(temp->left);
        }

        if(temp->right)
        {
            q.push(temp->right);
        }

        }  
    }
}

//6/5/2023
//Inorder //preorder //postorder
// LNR        NLR       LRN
//Inorder traversal
//3
void inorderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    //LNR
    inorderTraversal(root->left);
    cout<<root->data;
    inorderTraversal(root->right);
}

//preorder traversal
//NLR
//4
void preorderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    //NLR
    cout<<root->data;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//postorder traversal
//5
void postorderTraversal(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    //LRN
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data;  
}

//6 Height of tree or depth of tree
//longest path ke number of nodes that is height of tree
//root node to farthest node ka distance
int height(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    
    int ans=max(leftHeight,rightHeight)+1;
    return ans;
}

//7 Diameter of a Tree
//longest path between any two nodes weather 
//it contains root or not isi me answer hai dhundo
//return edges not number of nodes   edges=nodes-1
  int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int op1=diameterOfBinaryTree(root->left);
        int op2=diameterOfBinaryTree(root->right);
        int op3=height(root->left)+height(root->right);
        //agr yha pr +1 krenge to hume number of nodes pta chlegi upr me

        int ans=max(op1,max(op2,op3));
        return ans;
    }

    // homework
    //8 check if two trees are identical or not

    // 9 check if two tree are mirror of each other or not

    // 10 balance binary tree


int main()
{
    Node* root;
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;

    root=buildTree(data);

    cout<<"Answer :"<<endl;
    levelOrderTraversal(root);

    return 0;
}