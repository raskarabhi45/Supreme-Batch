//Week 4 assignments
#include<iostream>
using namespace std;

//1 Valid anagram
class Solution {
public:
    bool isAnagram(string s, string t) {
       
       //Approach 2
    //    sort(s.begin(),s.end());
    //    sort(t.begin(),t.end());

    //    if(s.length()!=t.length())
    //    {
    //        return false;
    //    }
    //    int i=0;
    //    while(i<s.length())
    //    {
    //        if(s[i]!=t[i])
    //        {
    //            return false;
    //        }
    //        i++;
    //    }
    //    return true;

    // Approach 2
  //best one
    int freqTable[256]={0};
    for(int i=0;i<s.size();i++)
    {
        freqTable[s[i]]++;
    }
    for(int i=0;i<t.size();i++)
    {
        freqTable[t[i]]--;
    }

    for(int i=0;i<256;i++)
    {
        if(freqTable[i]!=0)
        {
            return false;
        }
    }
    return true;
        
    }
};



//2 Reverse Only Letters

class Solution {
public:
    string reverseOnlyLetters(string s)
     {
        int i = 0;
        int j= s.size()-1;
        while (i<j) 
        {
            if(isalpha(s[i]) && isalpha(s[j]))
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(!isalpha(s[i]))
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return s;
    }
};

//3  . Longest Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // int ans = s[0].length(), n = s.size();
        // for(int i=1; i<n; i++){
        //     int j = 0;
        //     while(j<s[i].length() && s[i][j]==s[0][j])j++;
        //     ans = min(ans, j);
        // }
        // return s[0].substr(0, ans);

        //approach
        string ans;
        int i=0;
        while(true)
        {
            char curr_ch=0;
            for(auto str:strs)
            {
                if(i>=str.size())
                {
                    //out of bound
                    curr_ch=0;
                    break;
                }

                //just started
                if(curr_ch==0)
                {
                    curr_ch=str[i];
                }
                else if(str[i]!=curr_ch)
                {
                    curr_ch=0;
                    break;
                }
            }
            if(curr_ch==0)
            {
                break;
            }
            ans.push_back(curr_ch);
            i++;
        }
        return ans;
        
    }
};


//4 Reverse Vowels of a String
class Solution {
public:
     bool isvowel(char x)
    {
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' ||x == 'E' || x == 'I' || x == 'O' || x == 'U')
            return true;
        return false;
    }

    string reverseVowels(string s) {
        
        int start = 0;
        int end = s.length()-1;
        
        while(start<end)
        {
            if(isvowel(s[start]) and isvowel(s[end]))
            {
                swap(s[start],s[end]);
                start++;
                end--;
            }
            else if(isvowel(s[start]))
            {
                end--;
            }
            else
                start++;
        }
        return s;
    }
};


//5 Integer to romans
class Solution {
public:
    string intToRoman(int num) {
        
        int ans[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res="";
        for(int i=0;i<13;i++){
            while(num>=ans[i])
            {
                res.append(roman[i]);
                num=num-ans[i];

                //or
                //ans=ans+roman[i];
                //num=num-values[i];
            }
        }
        return res;
    }
};

//6 zig zag conversion
class Solution {
public:
    string convert(string s, int n) 
    {
      if(n==1)
      {
          return s;
      }

      vector<string>zigzag(n);

      int i=0,row=0;
      bool direction=1;///1->  Top->Bottom

      while(true)
      {
          if(direction)
          {
              while(row<n && i<s.size())
              {
                  zigzag[row++].push_back(s[i++]);
              }
              row=n-2;
          }
          else
          {
              while(row>=0 && i<s.size())
              {
                  zigzag[row--].push_back(s[i++]);
              }
              row=1;
          }

          if(i>=s.size())
          break;

          direction=!direction;
      }
      string ans="";
      for(int i=0;i<zigzag.size();i++)
      {
          ans+=zigzag[i];

      }
      return ans;
    }
};


//7 String compression


class Solution {
public:
    int compress(vector<char>& chars) 
    {
        
        int n = chars.size();
        if (n == 1) {
            return 1;
        }
        
        int i = 0, j = 0;
        while (i < n) 
        {
            int cnt = 1;
            while (i < n - 1 && chars[i] == chars[i + 1])
             {
                cnt++;
                i++;
            }
          
            chars[j++] = chars[i++];
            if (cnt > 1) 
            {
                string cntStr = to_string(cnt);
                for (char c : cntStr) {
                    chars[j] = c;
                    j++;
                }
            }
        }
        
        return j;



    }
};


//8 Strings to integer
class Solution {
public:
    int myAtoi(string s) {
        
        //inbuilt function
        // int ans=atoi(s.c_str());
        // return ans;
        int num=0,i=0,sign=1;  //+ve  //leading white space htadi
        while(s[i]==' ')
        {
            i++;
        }

        if(i<s.size()  && (s[i]=='-' || s[i]=='+') )    //+ve -ve handle kiya
        {
            sign=s[i]=='+'?1:-1;   
            i++;
        }

        while(i<s.size()  && isdigit(s[i]))
        {
            //handled max conditions
            if(num>INT_MAX/10 || (num==INT_MAX/10 && s[i]>'7'))
            {
                return sign==-1?INT_MIN:INT_MAX;
            }

            num=num*10+(s[i]-'0');     //char to number askii
            i++;

        }

        return num*sign; //while loop mai nhi gya to 0 return kiya
    }
};


//9 find the index of first occurance of string
class Solution {
public:
    int strStr(string haystack, string needle) {
        
        //approach 1
        // int pos=haystack.find(needle);
        // if(pos>=0)
        // {
        //     return pos;
        // }
        // else
        // {
        //     return -1;
        // }

        //approach 2 NEED TO REVISE
        int n=haystack.size();
        int m=needle.size();

        for(int i=0;i<=n-m;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(needle[j]!=haystack[i+j])
                {
                    break;
                }
                if(j==m-1) //needle mil chuka hai
                {
                    return i;

                }
            }
        }

        return -1;
    }
};

//10 longest pallindromic substring
class Solution {
public:

    bool isPalindrome(string &s,int start,int end)
    {
        while(start<end)
        {
            if(s[start]!=s[end])
            {
                return false;
            }
            start++;
            end--;
        }

        return true;

    }


    string longestPalindrome(string s) {
        string ans="";

        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                if(isPalindrome(s,i,j))  //i start bta rha hai and j end bta rha hai
                {
                string t=s.substr(i,j-i+1);
                ans=t.size()>ans.size() ? t : ans;
                }
            }
        }
          return ans;
    }
  
};


//11 Group anagrams



int main()
{

    return 0;
}