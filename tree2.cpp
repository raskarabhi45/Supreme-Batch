// sunday 7/5/2023
// tree second lecture
//#########################################
//Doneeeeeeeeeeeeeeeeeeeeeeeeeeeeee........
//#########################4th problem

#include <iostream>
using namespace std;

// 1 check if binary tree is balanced or not
// means hr ek node pe left subtree height and right subtree height unka absolute difference less than one hoga
int height(struct TreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int left = height(node->left);
    int right = height(node->right);
    int ans = max(left, right) + 1;

    return ans;
}

bool isBalanced(TreeNode *root)
{
    // base case
    if (root == NULL)
    {
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if (left && right && diff)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// 2 very important question
//  chech weather binary tree is sum tree or not
// or convert binary tree into sum tree
//
int converIntoSumTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftAns = converIntoSumTree(root->left);
    int rightAns = converIntoSumTree(root->right);

    //int temp=node->data   //for gfg
    root->data = leftAns + rightAns + root->data;

    //return temp+root->data;  //for gfg
    return root->data;
}


// 3 lowest common ancestors

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // base case
        if (root == NULL)
        {
            return NULL;
        }
        if (root->val == p->val)
            return p;
        if (root->val == q->val)
            return q;

        TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);

        //here just 4 cases that we have to handled
        if (leftAns == NULL && rightAns == NULL)
        {
            return NULL;
        }
        else if (leftAns != NULL && rightAns == NULL)
        {
            return leftAns;
        }

        else if (leftAns == NULL && rightAns != NULL)
        {
            return rightAns;
        }
        else
        {
            return root;
        }
    }
};


//###################################
// 4  kth ancestor in tree
bool kthAncestor(Node *root, int k, Node *p)
{
    if (root == NULL)
    {
        return false;
    }
    // find p
    if (root->data == p->data)
    {
        return true;
    }

    bool leftAns = kthAncestor(root->left, k, p);
    bool rightAns = kthAncestor(root->right, k, p);

    // waps aa rhe honge
    // check left ye right mai answer mila ya nhi
    if (leftAns || rightAns) //left me ya right me hi tree mila hoga
    {
        k--;
    }
    // means kth node mil gyi
    if (k == 0)
    {
        cout << root->data;
        k=-1;
        
    }
    return leftAns || rightAns;
}


//easyy hai brooo
// 5 path sum 2 leetcode reviseeeeeeeeeeeeeeee
//tree me se O sare path dhundhne hai ki jinki sum target itni aa rhi hai just it is only
class Solution
{
public:
    void solve(TreeNode *root, int targetSum, int currSum, vector<int> &path, vector<vector<int>> ans)
    {
        // base case
        if (root == NULL)
        {
            return;
        }

        // leaf node pe pohche to check kro currsum  target sum ke brabr hue ya nhi 
        if (root->left == NULL && root->right == NULL)
        {
            // include curr node
            path.push_back(root->val);
            currSum = currSum + root->val;
            // check for target
            if (currSum == targetSum)
            {
                ans.push_back(path); ///egr path mil gya to simply ans pe push krdo
            }

            // exclude   //backtracking
            path.pop_back();
            currSum = currSum - root->val;

            return;
        }

        // include curr node
        path.push_back(root->val);
        currSum = currSum + root->val;

        solve(root->left, targetSum, currSum, path, ans);
        solve(root->right, targetSum, currSum, path, ans);
 
        //waps aate vkt 
        // backtrack
        path.pop_back();
        currSum = currSum - root->val;
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {

        vector<vector<int>> ans;
        int sum = 0;
        vector<int> temp;

        solve(root, targetSum, sum, temp, ans);

        return ans;
    }
};

int main()
{

    return 0;