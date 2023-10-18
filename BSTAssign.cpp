//Binary Search Tree Assignments 
//##############################Dekhna Pdega 4,7,9,11,12// Baki ho gye

//1 Inorder Predecessor in BST (x)
//method 1
//store inorder traversal in vector 
// linear search or Binary search kro
//find the node just smaller that x
//so just x se choti wali node nikalo

//method 2 
Node* findPredecessor(Node* root, Node* p) {
    // add your logic here
	//yahape hme p ka predecessor nikalna hai
	Node* pred=NULL;
	Node* curr=root;
	
	while(curr){
		if(curr->data<p->data){
			pred=curr;  //ek chota elem mil chuka hai kya pta ye predecor ho
			curr=curr->right;    //fir uske right me check kre ye ya ha nhi
		}
		else{
			curr=curr->left;
		}
		
	}
	return pred;
}




//2 Inorder Successor in BST
// method 1 
//inorder traversal nikalo
// vector me store kro
//or linear search or binary search
//jo bhi first value greate than x node vhi successor hai

//method 2
// use property  of Binary tree
//current node se
//left node ka data right node ke data se hmesha chota hi hota hai BST mai
class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        //yahape x ka inorder successor nikalna hai
        Node* succ=NULL;
        Node* curr=root;
        
        while(curr){
            if(root->data > x->data){ //change
                succ=curr;
                curr=curr->left; //change
            }
            else{
                curr=curr->right;
            }
        }
        return succ;
    }
    
};


//adobe me poocha gya tha ye question Lakshay Bhaiya se
//3 Build BST using Preorder traversal
//method 1 BruteFforce
//start se shuru krengre and insertkrte jayenge NLR
//if u sort preorder u will get inorder of it

// m2
// preorder se inorder nikalo and then BST bnao TC )(nlogn)+o(n)

//m3 best method work in range
//very easyyy solution just range me khelo
class Solution {
public:
    TreeNode* build(int &i,int min,int max,vector<int> &preorder){
        if(i>=preorder.size()){
            return NULL;
        }

        TreeNode* root=NULL;
        if(preorder[i]>min && preorder[i]<max){
            root=new TreeNode(preorder[i++]);
            root->left=build(i,min,root->val,preorder);
            root->right=build(i,root->val,max,preorder);
        }
        return root;
    }


    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int min=INT_MIN,max=INT_MAX;
        int i=0;
        return build(i,min,max,preorder);
    }
};


//4 Brothers from different Roots
//or COunt pair from 2 BST whose sum is equal to given x
//approach 1 Brute force n2 x-root->val check kro bst2 me
//m2
//BST1 incresing order
//and BST2 descresing order
//hum simple 2 vbector me kr skete the ye problem
//but hum vector ki extra space nhi chahte islia m3 use kiya
//reverse inorder traversal
// if(sum<x){
//     bst,pointer ko move kraoge to its successor
// }else{
//     BST2 ke pointer ko move kraoge its predessor
// }

//m3 using stack inorder traversal
//BST1 normal inorder(LNR) and BST2 reverse inorder (RNL)
class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        int ans=0;
        stack<Node*> s1,s2;
        Node* a=root1; //iterators
        Node* b=root2;
        while(1){
            //for simple inorder traversal
            while(a){
                s1.push(a);
                a=a->left;
            }
            //for reverse inorder traversal
            while(b){
                s2.push(b);
                b=b->right;
            }
            
            if(s1.empty() || s2.empty()){ //agr stack se pop hota hai to chize visit hoti hai
            //stack khali pda hai yani inorder traversal hi chuka hai
            break;
            }
            
            auto atop=s1.top();
            auto btop=s2.top();
            
            int sum=atop->data+btop->data;
            if(sum==x){
                ans++;
                s1.pop();
                s2.pop();
                a=atop->right; //simple inorder
                b=btop->left; //cause reverse inorder
            }
            else if(sum<x){
                s1.pop();
                a=atop->right;
            }
            else{
                s2.pop();
                b=btop->left;
            }
        }
        return ans;

    }
};




//5 Convert BST To a balanced BST
//Balance a binary search tree
//means abs(leftHeight-rightHeight<=1)
//approch
//inorder traversal nikalo qki BST ka inorder sorted hota hai
//same as Binary search
//find middle left me jo node hai left me dalo and right me jo node hai wo right me dalo
class Solution {
public:
//inorer store kro in vector me
    void inorder(TreeNode* root,vector<int>&in){
        if(root==NULL){
            return;
        }
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
     //similar approach like binary search
    TreeNode* buildTree(vector<int> &in,int start,int end){
        if(start>end){
            return NULL;
        }

        int mid=(start+end)/2; //mid nikalo
        TreeNode* root=new TreeNode(in[mid]); //middle element ko root bna diya
        root->left=buildTree(in,start,mid-1); //left me call
        root->right=buildTree(in,mid+1,end); //right me call
        return root;
    }


    TreeNode* balanceBST(TreeNode* root) {
        //left and right me same node dalo
        vector<int>in;
        inorder(root,in);

        //build balanced using inorder traversal
        int start=0;
        int end=in.size()-1
        return buildTree(in,start,end);
        
    }
};


//6 Find Median of BST
//median kya hota hai
//1 odd number of elements ke case me
//median=(n+/2)th term
//and even number of elem me
//medain =(n/2)th term+((n/2)-1)th term

//step 1 make vector using inorder traversal'
//step 2 find median using formulas


// mai koi extra space use nhi krunga 
//median using O(n) time and strictky O(1) space
//use morris traversal for inorder
//easy approach
void inorder(struct Node* root,vector<int> &in){
    if(root==NULL){
        return;
    }
    
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

float findMedian(struct Node *root)
{
      //Code here
      vector<int> in;
      inorder(root,in);
      
      int n=in.size();
      
      float ans=0;
      
      if (n % 2 != 0) { // odd number of elements
        ans = in[n / 2]; //to yhi median hoga
    } else { // even number of elements
        int t1 = in[n / 2];
        int t2 = in[(n / 2) - 1];
        ans = (t1 + t2) / 2.0; //bich wale dono ka avg
    }
      
      return ans;
}


//approach 2 remaining.....................#################
//Morris traversal -> find number of nodes
//morris traversal -> dersired element pe pohc jaunga


//7 Check BST has Dead end
//dead end yani Us ek leaf node ke baad hum koi bhi node insert nhi kr skte
//approach 1
//only check  leaf nodes
//Preorder traversal  NLR taki pehle me sari nodes ko visit kru
//x-> if already exists x+1 and x-1 iskamtlab I am  at DEADEND simpleeee
void solve(Node* root,unordered_map<int,bool> &visited,bool &ans){
    if(root==NULL){
        return;
    }
    
    //visit the node
    visited[root->data]=true;
    if(root->left==NULL && root->right==NULL){//yani mai leaf node pe khada hoo
    //check weather that leafnode is deadend or not
    int xp1=root->data+1;  //xp1 yani x+1
    int xm1=root->data-1==0?root->data:root->data-1; //0 nhi chah
    
    if(visited.find(xp1)!=visited.end() && visited.find(xm1)!=visited.end()){//agr dono mile to ye deadend hai
    ans=true;
    }
    return;
        
    }
    solve(root->left,visited,ans);
    solve(root->right,visited,ans);
}

bool isDeadEnd(Node *root)
{
    //Your code here
    bool ans=false; //tells if there was a dead end
    unordered_map<int,bool> visited;
    solve(root,visited,ans);
    return ans;
}


//8 Count BST Nodes Lying in a Range
//or Range Sum of BST
//method 1 O(1)
//simple inorder solution
class Solution {
public:
   void inorder(TreeNode* root,vector<int> &in){
       if(root==NULL){
           return;
       }
       //LNR
       inorder(root->left,in);
       in.push_back(root->val);
       inorder(root->right,in);
   }


    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> in;
        inorder(root,in);
        int sum=0;
        for(int i=0;i<in.size();i++){
            if(in[i]<=high && in[i]>=low){
                sum=sum+in[i];
            }
        }
        return sum;  
    }
};

//method 2
//case 1 if val is in given  range then
//add that node call RE for left and right

//case 2 low se less than val to m,uze left me janeki jroort nhi hai
//RE right subtree me call krnege

//case 3 high se greter than val to muze right me jana nhi hai
//traverasel only leftr subtree that is RE left call
//using recursion
 int rangeSumBST(TreeNode* root, int low, int high) {
        //approach 2
        if(root==NULL){
            return 0;
        }
        int ans=0;
        bool wasInRange=false;
        if(root->val>=low && root->val<=high){
            wasInRange=true;
            ans=ans+root->val;
        }

        if(wasInRange){
            ans=ans+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
        }
        else if(root->val<low){
            ans=ans+rangeSumBST(root->right,low,high);
        }
        else{
              ans=ans+rangeSumBST(root->left,low,high);
        }

        return ans;
    }

//9 Flatten BST to sorted LL
//left pointer ko hmesh null pe point krna hai
//and right pointer ko next ko trh use krna hai bs

//m1  bruteforce
//reconstruct BST from inorder
//inorder nikalo vector
//BST ka insert function call kr dunga ko LL create krega

//m2 TC O(n) and SP O(n0)
// inorder in Node* vector & create the list
//hr node ke left ko NULL kro
//v[i]->left=NULL
//and v[i]->right-v[i+1];

//m3 
//inorder krte krte flatten krnege LL me
//flatten iorder wise on the go
//dummy node -1 pe name is prev
//ye prev always pred pe point krega
//prev->left=NULL
//prev->right=right;
//prev=root;  //ab nya prev root kehlayega

void iorder(Node* root,Node* &prev){ //prev hmesh same reh rha tha
if(root==NULL){
    return;
}
inorder(root->left,prev);
//flatten conditionsss
prev->left=NULL;
prev->right=root;
prev=root;
inorder(root->right,prev);


}

node* flatten(Node* root){
    Node* dummy=new Node(-1);
    Node* prev=dummy;
    inorder(root,prev);
    //jb ye inorder fun sare tree ko flatten krega ko end me 8 prev hoga
    prev->left=prev->right=NULL;
    root=dummy->right;


    return roo;
}


//10 Replace elements with least greater elements to its RIght
//m1 using 2 for loops

//m2
//usse just bda elem hota hai inorder successor
//will go from right to left from array
//ek BST banayehge and 
//fir uska successor wrote krte  rho
//SC O(n)   TC O(nlogn)

class Node{
    public:
    int data;
    Node* left,*right;
    Node(int val):data(val),left(0),right(0){};
};

class Solution{
    public:
    Node* insert(Node* root,int val,int &succ){
        if(root==NULL){
            return new Node(val);
        }
        if(val>=root->data){
            root->right=insert(root->right,val,succ);
        }
        else
        {
            //left me jayanege and succ updatye krenge 
            //latest succ update hoga
            succ=root->data;
            root->left=insert(root->left,val,succ);
        }
        return root;
    }
    
    
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int>ans(arr.size());
        Node* root=NULL;
        //hum right to left move krenge 
        for(int i=arr.size()-1;i>=0;i--){
            int succ=-1;
            root=insert(root,arr[i],succ);
            ans[i]=succ;
        }
        return ans;
    }
};


//11 Valid BST from Preorder
//interviewBit
void build(int &i,int min,int max,vector<int> &arr){
    if(i>=arr.size()){
        return;
    }

    if(arr[i]>min && arr[i]<max){
        int rootData=arr[i];
        build(i,min,rootData,arr);
        build(i,rootData,max,arr);
    }
}

int  solve(vector<int>&arr){
int min=INT_MIN,max=INT_MAX;
int i=0;
build(i,min,max,arr);
return i==arr.size();
}



//12 Merge Two BSTs
//m1 
//BST1 ka sorted vector v1-> that is inorder of BST1
//BST2 v2  sorted vector 
//then simply merge two sorted array
//wo to tumhe achhese aata hai bro

//m2
//SImilar to above problme BROTHER FROM ANOTHER  ROOTS
//inorder traverse using stack qki dono ko sath me traverrse kr skte hum
//and keeping 2 pointers we merge and make ans vector ON THE GO
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> ans;//to store sorted elem of both the trees
       stack<Node*>sa,sb;
       Node* a=root1;
       Node* b=root2;
       
       //like 2 sorted arrays
       while(a||b ||  !sa.empty() || !sb.empty()){
           while(a){
               sa.push(a);
               a=a->left;
           }
           
           while(b){
               sb.push(b);
               b=b->left;
           }
           
           if(sb.empty() || (!sa.empty() && sa.top()->data<=sb.top()->data)){  //a ke andr leme hai
               auto atop=sa.top();
               ans.push_back(atop->data);
               sa.pop();
               a=atop->right;
           }
           else{
               auto btop=sb.top();
               sb.pop();
               ans.push_back(btop->data);
               b=btop->right;
           }
       }
       return ans;
    }
};