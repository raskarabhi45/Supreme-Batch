
//Assignments on trees
//25/5/2023
#include<iostream>
using namespace std;


//1 Fast way to find diameter of tree
//will keep track of height on the way of dinding diameter

class Solution {
public:

    int diameter=0;

    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        //diameter
        int currDiameter=leftHeight+rightHeight;
        diameter=max(diameter,currDiameter);

        return max(leftHeight,rightHeight)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
       
        height(root);
        return diameter;
    }
};


//2 Fast way to find Height of Balanced tree
//height (lh-rh) <=1

class Solution {
public:
bool isbalanced=true;

   int height(TreeNode* root)
   {
       if(root==NULL)
       {
           return 0;
       }
       int lh=height(root->left);
       int rh=height(root->right);

       //check for current node is it balanced ?
       if(isbalanced && abs(lh-rh)>1)
       {
           isbalanced=false;
       }
       return max(lh,rh)+1;
   }


    bool isBalanced(TreeNode* root) {

       //approach 2
        //fastest way
        height(root);
        return isbalanced;
        
    }
};

//3 Are 2 trees identical or not  // or two tree mirror or not
//leetcode Same tree
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
        {
            return true;
        }
        if(p==NULL && q!=NULL)
        {
            return false;
        }
        if(p!=NULL && q==NULL)
        {
            return false;
        }

        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);

        bool value=p->val==q->val;

        if(left && right && value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    return 0;
}