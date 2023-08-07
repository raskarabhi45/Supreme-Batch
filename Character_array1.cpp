//Doneeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

// 1 Length of a string
int getLength(char name[])
{
    int length = 0;
    int i = 0;
    while (name[i] != '\0')
    {
        length++;
        i++;
    }
    return length;
}

// 2  reverse a string
void reverseCharArray(char name[])
{
    int i = 0;
    int n = getLength(name);
    int j = n - 1;
    while (i <= j)
    {
        swap(name[i], name[j]);
        i++;
        j--;
    }
}

// 3 replace all spaces
void replaceSpaces(char sentence[])
{
    int i = 0;
    int n = strlen(sentence);
    for (int i = 0; i < n; i++)
    {
        if (sentence[i] == ' ')
        {
            sentence[i] = '@';
        }
    }
}

// 4 Pallindrome
// approach 1 using reverse function
bool checkPalindrome(char word[])
{
    int i = 0;
    int n = strlen(word);
    int j = n - 1;

    while (i <= j)
    {
        if (word[i] != word[j])
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

// 5 conver into uppercase
void charUppercase(char arr[])
{
    int n = getLength(arr);
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] - 'a' + 'A';
    }
}

// 6 conver into Lowercase
void charLowercase(char arr[])
{
    int n = getLength(arr);
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] - 'A' + 'a';
    }
}

// 7 compare string
bool compareString(string a, string b)
{
    if (a.length() != b.length())
    {
        return false;
    }
    else
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    // char name[100];
    // cin>>name;

    // for(int i=0;i<=7;i++)
    // {
    //     cout<<"index "<<i<<" value "<<name[i]<<endl;
    // }

    // char arr[100];
    // cin>>arr;   //cin is not able to print the names with spaces or enter or tab so use cin.getline() method
    // cout<<arr;

    ////////////////////////////////////////////////////////////////
    /// Problem solving
    // 1 Length of a string
    // char name[100];
    // cin.getline(name,100);
    // cout<<"length is "<<getLength(name)<<endl;
    // cout<<"Length using inbuilt "<<strlen(name);

    // 2
    //    cout<<"Initially "<<name<<endl;
    //    reverseCharArray(name);
    //    cout<<"After reversal "<<name<<endl;

    // 3
    //  char name[100];
    //  cin.getline(name,100);
    // 4
    //  replaceSpaces(name);
    //  cout<<"Printing sentence "<<name<<endl;

    // char name[100];
    // cin.getline(name,100);
    // cout<<" palindrome check "<<checkPalindrome(name)<<endl;

    // 5
    //  char name[100];
    //  cin.getline(name,100);
    //  charUppercase(name);
    //  cout<<name<<endl;
    // 6
    //   char name[100];
    //  cin.getline(name,100);
    //  charLowercase(name);
    //  cout<<name<<endl;

    // 1.30 pm
    /////////////////////////////////////////////////////////////
    // String started
    string str = "Abhishek";
    // cin>>str;
    // getline(cin,str);
    cout << str;
    cout << "length" << str.length() << " " << endl;
    cout << "islength" << str.empty() << " " << endl;
    str.push_back('A');
    cout << str << endl;
    str.pop_back();
    cout << str << endl;
    // substr very important
    cout << str.substr(0, 4) << endl; // SUbstring of string from where to where and its length
    string a = "love";
    string b = "lover";
    if (a.compare(b) == 0)
    {
        cout << " a and b are exactly same strings" << endl;
    }
    else
    {
        cout << "a and b are not same" << endl;
    }

    // find very important
    cout << str.find("abhi") << endl;
    // replace

    return 0;
}