//Heap lecture 1
//###################################
//almost doneeeeeeeeeee
//################################
//sunday 21/5/2023
#include<iostream>
using namespace std;
//jo chij tum O(n) se krte the vo O(1) se bhi kroge heap se
// Heap Data Structure
// Complete binary Tree + heap property (either max heap tree of min heap tree)
// CBT
//All levels are completely field except last one
//filing is from left to right
//hum heap ki creation array se krenge and
//uska visualization trees ki trh krenge
//max heap property
//current node apne child se bdi hogi

//mean heap property
//current node apne child se choti hogi

///formulas
//parent to child
// index 1 
//parent i pe hoga tb
//leftchild= 2*i;
//rightchild= 2*i+1

// index 0
//parent i pe hoga tb
//leftchild= 2*i+1
//rightchild= 2*i+2

// child to parent 
// i/2  i/2-1  

  //1 insertion in heap //child to parent

  //2 deletion in heap  //parent to child

  //3 heap creation from array
  //  using  heapify  function
  //  index largest ek pe point krna chahia


class heap
{
    public:
    int arr[101];
    int size;

    heap()
    {
        size=0;
    }

//1 insertion in heap
//1 add node at the end of array
//2 sahi jgh pr leke jao
//example
//inserting 110
// -1 100 50 60 -40 45 
// Printing heap
// -1 110 50 100 -40 45 60
    void insert(int value)
    {
        //val insert kro end me
        size=size+1; //size bdha do
        int index=size;
        arr[index]=value;

        //is value ko place at correct position
        while(index>1)  //jb tk index greater than one hei means parent tk chekc krenege
        {
            int parentIndex=index/2;

            if(arr[index]>arr[parentIndex])
            {
                swap(arr[index],arr[parentIndex]);
                index=parentIndex; //update the index
            }
            else
            {//means curr elem parentIndex se chota hai
                break;
            }
        }
    }
    //jb bhi hum heap me delete operation krte hai to hum root ko hi delete krte haiii 
      //too easy just understood by visualizing BST
      //deletion in heap
      //1 replace last val with root node
      //delete krne ke baaad
     //2 root node curr position
     //pehle walo ko delete krna hai
     public:
     int delete()
     {
        //step 1 replace node val with last node data
        arr[1]=arr[size];
        size--;  //last node hta di

        //place root node ka data on its correct position
        int index=1;
        while(index<size)
        {
            int ans=arr[1]; //yani root node
            int left=2*index; //left child
            int right=2*index+1; //right child

            int largest=index; //starting me index ko hi largest assume krlo
//hmnw jo lwdt right parent me se jo bda hai uska index store kr diya
            if(left<size && arr[left]> arr[index])  //means left me jo element hai vo bda hoga index se
            {
               largest=left;
            }

            if(right<size && arr[right]> arr[index]) ///means right me jo element hai vo bda hoga index se
            {
               largest=right;
            }

            if(largest ==index) //agr index hi large hai no deed to update
            {
                //val is at corrrect position
                break;
            }
            else
            { //
                swap(arr[index],arr[largest]);
                index=largest;
            }
            return ans;


        }
     }

};

//YAAD RKHNA YAHI HEAPIFY WALA FUNCTION BHOOLNA NHI HAI
//HEAPIFY  hum kisi bhi array ko heap me convert kr skte
//is node ko uske shi jgh pr pohcha do
//for heap creation
//build heap from array
//1 no need to heapify leafnodes
// n/2+1 -> no heafify
//1 to n/2  ->heapify 
//heap creation //heapify
//ologn
void heapify(int arr[],int n,int i)
{
    int index=i;
    int leftIndex=2*i;
    int rightIndex=2*i+1;
    int largest=index;

//largest ko update kr diya
        if(leftIndex<=n && arr[leftIndex]>arr[largest])
            {
               largest=leftIndex;
            }

            if(rightIndex<=n && arr[rightIndex]>arr[largest])
            {
               largest=rightIndex;
            }

              //
            if(largest!=index)
            {
                //left ya right child me se koi greater trhan hogya currentnode se
                swap(arr[index],arr[largest]);
                index=largest;
                heapify(arr,n,index);  //just to create max heao from given data 

            }

}
//n/2+1 se nth node sari leaf node hogi

void buildheap(int arr[],int n)
{
    for(int i=n/2;i>0;i--)
    {
        heapify(arr,n,i);
    }
}

//Heap sort
//inside loop
//swap first element to last
//heapify 

//heaSort very simple
void heapSort(int arr[],int n)
{
    //tb tk process krna hai element ko jbtk ek elemnt na bche
    while(n!=1)
    {
        swap(arr[1],arr[n]);
        n--;  //size minus
        //heapify
        heapify(arr,n,1);
    }
}



int main()
{
    // heap h;
    // h.arr[0]=-1;
    // h.arr[1]=100;
    // h.arr[2]=50;
    // h.arr[3]=60;
    // h.arr[4]=-40;
    // h.arr[5]=45;

    // h.size=5;

    // cout<<"Printing heap"<<endl;
    // for(int i=0;i<=h.size;i++)
    // {
    //     cout<<h.arr[i]<<" ";
    // }
    // cout<<endl;

    // h.insert(110);
    //  cout<<"Printing heap"<<endl;
    // for(int i=0;i<=h.size;i++)
    // {
    //     cout<<h.arr[i]<<" ";
    // }
    // cout<<endl;

    //heapify
    int arr[]={-1,12,15,13,11,14};
    int n=5;

    buildheap(arr,n);

    cout<<"Printing heap"<<endl;
    for(int i=0;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;






    return 0;
}
