//tries lecture
//data structure used for auto suggestions
#include<iostream>
using namespace std;


class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d)
    {
        this->data=d;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        this->isTerminal=false;

    }
};


//insertion in tries
void insertWord(TrieNode* root,string word)
{
    cout<<"Inserting"<<word<<endl;
    //base case
    //last charcter aaye to rukna hai
    if(word.length()==1)
    {
        root->isTerminal=true;
        return;
    }

    char ch=word[0];
    int index= ch- 'A';
    TrieNode* child;

    //present
    if(root->children[index]!=NULL)
    {
        child=root->children[index];
    }
    else
    {
        //not present
        child=new TrieNode(ch);
        root->children[index]=child;
    }

    //baki recursion sambhal lega
    insertWord(child,word.substr(1));

}

//searching
bool searchWord(TrieNode* root,string word)
{
    if(word.length()==0)
    {
        return root->isTerminal;
    }

    char ch=word[0];
    int index= ch- 'A';
    TrieNode* child;

    //present
    if(root->children[index]!=NULL)
    {
        child=root->children[index];
    }
    else
    {
        return false;
    }

    //recursion call
    return searchWord(child,substr(1));
}


//deletion or removal



int main()
{

    TrieNode* root=new TrieNode('-');
    
    
    // root->insertWord("coding");
    insertWord(root,"coding");
     insertWord(root,"code");
      insertWord(root,"coder");
       insertWord(root,"babu");
        insertWord(root,"baby");
         insertWord(root,"here");
          insertWord(root,"bhaiya");

  if(searchWord(root,"coding"))
  {
    cout<<"present"<<endl;
  }
  else
  {
    cout<<"absent"<<endl;
  }



    return 0;
}