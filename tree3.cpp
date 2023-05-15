// 12/5/2023
//friday
//tree 3rd lecture
#include<iostream>
using namespace std;
#include<queue>
#include<map>

//1  build tree from inorder and preorder 
//root create kro
// root ka left recursive call
//root ka right recursive call
//output

// printing tree
// 10
// 20 30
// 40 50 60 70
class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

int findPosition(int arr[],int n,int element)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==element)
        {
            return i;
        }
    }

    return -1;
}

                    ///LNR    //NLR
//build tree from inorder and preorder traversal
Node* buildTreeFromPreorderinorder(int inorder[],int preorder[],int size,int &preIndex,int inorderStart,int inorderEnd)
{
    //base case
    if(preIndex>=size  || inorderStart>inorderEnd)
    {
        return NULL;
    }
    {
        //step A create node
        int element=preorder[preIndex++];
        Node* root=new Node(element);
        int pos=findPosition(inorder,size,element);

        //step B root ka left
        root->left=buildTreeFromPreorderinorder(inorder,preorder,size,preIndex,inorderStart,pos-1);

        //step C root ka right
        root->right=buildTreeFromPreorderinorder(inorder,preorder,size,preIndex,pos+1,inorderEnd);

        return root;
}
}

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


//2 create tree using inorder and postorder
                    //LRN    LNR
Node* buildTreeFromPostOrderInOrder(int inorder[],int postorder[],int &postIndex,int size,int inorderStart,int inorderEnd)
{
    //base case;
    if(postIndex<0 || inorderStart>inorderEnd)
    {
        return NULL;
    }

    //A
    int element=postorder[postIndex];
    postIndex--;
    Node* root=new Node(element);

    int pos=findPosition(inorder,size,element);
     
     //step B root ka left
     root->left=buildTreeFromPostOrderInOrder(inorder,postorder,size,postIndex,pos+1,inorderEnd);

    //step C root ka right
     root->right=buildTreeFromPostOrderInOrder(inorder,preorder,size,postIndex,inorderStart,pos-1);

    return root;
}

//3 vertical 

//3 homeword
// build tree from preorder and postorder 


//homework
//zigzag
//boundary
//vertical
//morris
//top left bottom 



int main()
{
     // int inorder[] = {40,20,50,10,60,30,70};
        // int preorder[] = {10,20,40,50,30,60,70};
        // int size = 7;
        // int preIndex = 0;
        // int inorderStart = 0;
        // int inorderEnd = size-1;

        // cout << "Building Tree: " << endl;
        // Node* root = buildTreeFromPreOrderInOrder(inorder, preorder,size, preIndex, inorderStart, inorderEnd );

        // cout<< endl << "Printing level order traversal " << endl;
        // levelOrderTraversal(root);

        int inorder[] = {40,20,10,50,30,60};
        int postorder[] = {40,20,50,60,30,10};
        int size = 6;
        int postIndex = size-1;
        int inorderStart = 0;
        int inorderEnd = size-1;

        unordered_map<int,int> mapping;

        createMapping(mapping, inorder, size);

        cout << "Building the tree: " << endl;
        Node* root = buildTreeFromPostOrderInOrder(inorder, postorder,postIndex,size, inorderStart, inorderEnd, mapping);

        cout << "Printing the tree " << endl;
        levelOrderTraversal(root);
    return 0;
}