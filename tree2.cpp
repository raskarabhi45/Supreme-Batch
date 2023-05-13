//sunday 7/5/2023
//tree second lecture
#include<iostream>
using namespace std;

//1 check if binary tree is balanced or not
//means hr ek node pe left subtree height and right subtree height unka absolute difference less than one hoga
   int height(struct TreeNode* node)
   {
       if(node==NULL)
       {
           return 0;
       }

       int left=height(node->left);
       int right=height(node->right);
       int ans=max(left,right)+1;

       return ans;
   }

    bool isBalanced(TreeNode* root) {
        //base case
        if(root==NULL)
        {
            return true;
        }

        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        bool diff=abs(height(root->left)-height(root->right))<=1;

        if(left && right && diff)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }


//2 very important question
// chech weather binary tree is sum tree or not 
//or convert binary tree into sum tree
//
int converIntoSumTree(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int leftAns=converIntoSumTree(root->left);
    int rightAns=converIntoSumTree(root->right);

    root->data=leftAns+rightAns+root->data;

    return root->data;
}

//3 lowest common ancestors
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root==NULL)
        {
            return NULL;
        }

         if(root->val == p->val)
         return p;
         if ( root->val == q->val) 
         return q;

        TreeNode* leftAns= lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns= lowestCommonAncestor(root->right,p,q);

        if(leftAns==NULL && rightAns==NULL)
        {
            return NULL;
        }
        else if(leftAns!=NULL && rightAns==NULL)
        {
            return leftAns;
        }

        else if(leftAns==NULL && rightAns!=NULL)
        {
            return rightAns;
        }
         else
        {
            return root;
        }

    }
};

//4  kth ancestor in tree
bool kthAncestor(Node* root,int k,Node* p)
{
if(root==NULL)
{
    return false;
}
//find p
if(root->data==p->data)
{
    return true;
}

bool leftAns=kthAncestor(root->left,k,p);
bool rightAns=kthAncestor(root->right,k,p);

//waps aa rhe honge
//check left ye right mai answer mila ya nhi
if(leftAns|| rightAns)
{
    k--;
}
//means kth node mil gyi
if(k==0)
{
    cout<<root->data;
    return leftAns || rightAns;
}
}


//5 path sum 2 leetcode reviseeeeeeeeeeeeeeee
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,int targetSum,int currSum,vector<int>&path,vector<vector<int>> ans)
    {
        //base case
        if(root==NULL)
        {
            return;
        }

        //leaf node
        if(root->left==NULL && root->right==NULL)
        {
            //include curr node
             path.push_back(root->val);
             currSum=currSum+root->val;
             //check for target
            if(currSum==targetSum)
            {
                ans.push_back(path);
            }
            //exclude
             path.pop_back();
             currSum=currSum-root->val;

            return ;
        }

        //include curr node
        path.push_back(root->val);
        currSum=currSum+root->val;

        solve(root->left,targetSum,currSum,path,ans);
        solve(root->right,targetSum,currSum,path,ans);

        //backtrack
        path.pop_back();
        currSum-=root->val;


    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>ans;
        int sum=0;
        vector<int> temp;

        solve(root,targetSum,sum,temp,ans);

        return ans;
    }
};



int main()
{

    return 0;