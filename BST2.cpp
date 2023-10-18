// 17/5/2023
// wednesday BST second lecture
//####################################
//Almost Done last 2 dekhne honge
//###########################
#include <iostream>
using namespace std;

// 1 Height and diameter of binary tree same as BST

// 2 Validate Binary tree
// approach 1 inorder  that is sorted hona chahia bs
// qki binary search ka inorder always sorted hota hai
// approach 2 using intmin and intmax

class Solution
{
public:
    bool isBST(TreeNode *root, long long int min, long long int max)
    {
        if (root == NULL)
        {
            return true;
        }
        // root ka data in range
        if (root->val > min && root->val < max)
        {
            bool left = isBST(root->left, min, root->val);   // left me upperBound change hota hai
            bool right = isBST(root->right, root->val, max); // right me lowerBound change hota hai
            return left && right;
        }
        else
        {
            return false;
        }
    }

    bool isValidBST(TreeNode *root)
    {
        long long int lowerBound = -4294967296; // intmin
        long long int upperBound = 4294967296;  // intmax
        return isBST(root, lowerBound, upperBound);
    }
};

// 3 Lowest common ancestors
// 236. Lowest Common Ancestor of a Binary Tree
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
        // case 1  dono chote hai p and q to left mai hi milega ancestors
        if (p->val < root->val && q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        // case 2  bde hai to right me milega ans
        if (p->val > root->val && q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        // case 3 and 4
        return root;
    }
};

//Bhai easy hai e to bs LNR dekhlo and k-- krlo
// 4 kth smallest element in BST
// approach 1 inorder approach
//approach 2
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        // base case
        if (root == NULL)
        {
            //-1 leflects base condition reached
            return -1;
        }
        // inorder
        // LNR
        int leftAns = kthSmallest(root->left, k);
        if (leftAns != -1)
        {
            return leftAns;
        }
        // N->root
        k--;
        if (k == 0)
        {
            return root->val;
        }
        // right
        int rightAns = kthSmallest(root->right, k);
        return rightAns;
    }
};

// 5 create BST from inorder traversal
// BST ka in order sorted hota hai
Node *bstUsingInorder(int inorder[], int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    // mid ke lia ek node create kro qki inorder LNR
    int element = inorder[mid];
    Node *root = new Node[element];

    root->left = bstUsingInorder(inorder, s, mid - 1);
    root->right = bstUsingInorder(inorder, mid + 1, e);

    return root;
}

// 6 convert BST into balanced BST
// Homework

// 7 Two Sum
// 653. Two Sum IV - Input is a BST
// kya koi 2 number aise he ki jinka sum target ke equal aa rha hai
class Solution
{
public:
    void storeInorder(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
        {
            return;
        }
        // LNR
        storeInorder(root->left, inorder);
        inorder.push_back(root->val);
        storeInorder(root->right, inorder);
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inorder;
        storeInorder(root, inorder);

        int s = 0;
        int e = inorder.size() - 1;

        while (s < e)
        {
            int sum = inorder[s] + inorder[e];

            if (sum == k)
            {
                return true;
            }

            if (sum > k)
            {
                e--;
            }
            else
            {
                s++;
            }
        }

        return false;
    }
};

int main()
{

    return 0;
}