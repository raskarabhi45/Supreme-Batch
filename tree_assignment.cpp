
// Assignments on trees
// 25/5/2023
#include <iostream>
using namespace std;

// 1 Fast way to find diameter of tree
// will keep track of height on the way of dinding diameter

class Solution
{
public:
    int diameter = 0;

    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        // diameter
        int currDiameter = leftHeight + rightHeight;
        diameter = max(diameter, currDiameter);

        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {

        height(root);
        return diameter;
    }
};

// 2 Fast way to find Height of Balanced tree
// height (lh-rh) <=1

class Solution
{
public:
    bool isbalanced = true;

    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);

        // check for current node is it balanced ?
        if (isbalanced && abs(lh - rh) > 1)
        {
            isbalanced = false;
        }
        return max(lh, rh) + 1;
    }

    bool isBalanced(TreeNode *root)
    {

        // approach 2
        // fastest way
        height(root);
        return isbalanced;
    }
};

// 3 Are 2 trees identical or not  // or two tree mirror or not
// leetcode Same tree
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        if (p == NULL && q != NULL)
        {
            return false;
        }
        if (p != NULL && q == NULL)
        {
            return false;
        }

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        bool value = p->val == q->val;

        if (left && right && value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// 4 Diagonal traversal of the binary tree
// approach 1
// at int lelo d=0 and going left +1 and going right do nothing
//  map<int.vector<int> > mp
//  argument root , map , d
//  0 ke cooresponding val push kroge similarly 1 and 2 ke lia
// done
// tree example
//          8
//      3      10
//  1       6       14
//      4      7 13
// 0 -> 8 10 14
// 1- ->3 5 7 13
// 2 -> 1 4

// approach 2 best one
// jb tk temp null nhi hota tb tk print kro temo ki val
//  then agr temp ka left hai to queue me dalo usko bad me dekh alenge
//  and temp ke right ko print krenege
// GFG
vector<int> diagonalPrint(Node *roo)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        while (temp)
        {
            ans.push_back(temp->data);
            if (temp->left)
            {
                // baad me dekhna hai
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    return ans;
}

// 5 zig zag traversal Binary tree
// level order travsersal just direction reverse krnni hai next level pe
// leetcode
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        vector<vector<int>> ans;
        if (root == NULL)
        {
            return ans;
        }
        bool leftToRight = true; // direction
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int width = q.size(); // hme us level pe kitni node hogi ye pta honi chahia that is q size
            vector<int> onelevel(width);

            // level process
            for (int i = 0; i < width; i++)
            {
                TreeNode *front = q.front();
                q.pop();

                // normal insert or reverse insert
                int index = leftToRight ? i : width - i - 1; // start se nhi to end se insert krenge
                onelevel[index] = front->val;

                if (front->left)
                {
                    q.push(front->left);
                }

                if (front->right)
                {
                    q.push(front->right);
                }
            }

            leftToRight = !leftToRight; // toggle the direction
            ans.push_back(onelevel);
        }
        return ans;
    }
};


//6 transform to sumtree GFG
//that is for each node the root->val should be  equal to 
//root ke left and right subtree ke sum so
//1 leaf nodes will be always zero
//yaad rkho yha pr node ki purani wali bhi use hogi and new value bhi use hogi
int sum(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    //ye niche wala nhi likhoge to bhi chlega
    // //agr leaf node ho to usko 0 krna hai
    // if(root->left==NULL && root->right==NULL)
    // {
    //     int temp=root->data;
    //     root->data=0;  //data update kiya
    //     return temp;   //purani val return ki
    // }

    int leftSum=sum(root->left);
    int rightSum=sum(root->right);
    
    int temp=root->data;
    root->data=leftSum+rightSum;
    return root->data+temp;   // uper wali node niche sari ki sumhai touski sum left right ki temp ki sum hogi
}

void toSumTree(Node* root)
{
    sum(root);
}

//##########################################################DO it againn
//7 Vertical order Traversal of a binary tree
//leetcode
//done but I havent code it coz it seems little bit difficult
//yes seems it is much more difficult


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //too much data structures are needed for this problem thats why it seems difficult
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q ;//Node,{row,col} store
        q.push({root,{0,0}});                           //multiset for sorted order
        map<int,map<int,multiset<int>>>mp; //col ->{row: [x,y,z...]}

        while(!q.empty()){
            auto front=q.front();
            q.pop();
            TreeNode* &node=front.first;
            auto coordinate=front.second;
            int &row=coordinate.first;
            int &col=coordinate.second;
            mp[col][row].insert(node->val);
            if(node->left){
                q.push({node->left,{row+1,col-1}});
            }
            if(node->right){
                q.push({node->right,{row+1,col+1}});
            }
        }

        //store final vertical order into ans vector
        for(auto it:mp){
            auto &colMap=it.second;
            vector<int>vLine;
            for(auto colMapIt:colMap){
                auto &mset=colMapIt.second;
                vLine.insert(vLine.end(),mset.begin(),mset.end());
            }
            ans.push_back(vLine);
        }
        return ans;

    }
};





//8 K sum paths leetcode
//break it down
//Kya root se path aata hai
//preorder traversal krenge

class Solution {
public:
    int ans=0;
    void pathFromOneRoot(TreeNode* root,long long sum){
        if(!root) return ;
        
        if(sum==root->val){
            ans++;  //paths exist count that is ans
        }
        //NLR preorder traversal
        pathFromOneRoot(root->left,sum-root->val);
        pathFromOneRoot(root->right,sum-root->val);
    }

    int pathSum(TreeNode* root, long long targetSum) {
       //preorder traversal
       if(root){
        pathFromOneRoot(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
       }
        return ans;  
    }
};

//9 Morris traversal


//10 Flatten a binary tree into linked list
//means left pointer hmesh null ki trh behave krega
//and right pointer next ki  trh behave krega
//preorder traveersal krna hai
//and ALGORITHM
//jb current ka left avalable hai to
// pred->right=curr->right
// curr->right=curr->left
//curr->left=NULL
//curr=curr->right

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr=root;
        while(curr){
            if(curr->left){
                TreeNode* pred=curr->left;
                while(pred->right){
                    pred=pred->right;
                }

                pred->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;

            }
            curr=curr->right;
        }
        
    }
};

//11 Maximum sumof non adjacent nodes GFG
//sumA include all nodes at that level
//sumB dont include nodes at that level
class Solution{
    public:
    int getMaxSUm(Node* root){

    }
};


//12 Sum of the length bloodline of The tree


//13 Burning Tree


//14 Find duplicates subtrees
 class Solution {
 public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    vector<TreeNode*> ans;
    unordered_map<string, int> count;
    solve(root, count, ans);
    return ans;
  }

 private:
  string solve(TreeNode* root, unordered_map<string, int>& count,
                vector<TreeNode*>& ans) 
    {
    if (root == nullptr)
      return "";

    const string solved = to_string(root->val) + "#" +
                           solve(root->left, count, ans) + "#" +
                           solve(root->right, count, ans);
                           //# for encoding null left and right childs
    if (++count[solved] == 2)//duplicate subtree
      ans.push_back(root);//add the roots
    return solved;
  }
};
