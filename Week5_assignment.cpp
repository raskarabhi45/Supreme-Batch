//Week 4 assignments stringggg
//reviseeeeeeeeeeeeeeeeeeeeeeeeeeeeee
//#############################################
// 14. Longest Common Prefix
//#############################################



#include<iostream>
using namespace std;

//done
//1 Valid anagram
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word
//  or phrase, typically using all the original letters exactly once.
// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true

class Solution {
public:
    bool isAnagram(string s, string t) {
       
       //Approach 2 simple
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

  //best one  //
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


//done
//2 Reverse Only Letters
// Example 1:
// Input: s = "ab-cd"
// Output: "dc-ba"

// Example 2:
// Input: s = "a-bC-dEf-ghIj"
// Output: "j-Ih-gfE-dCba"

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


//#######################################REVISEE
//3  . Longest Common Prefix
// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
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
                    curr_ch=str[i]; //pehle f aaya
                }
                else if(str[i]!=curr_ch)
                {
                    curr_ch=0; //match nhi lr pa ra to break
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


//done
//4 Reverse Vowels of a String
// Input: s = "hello"
// Output: "holle"

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


//5 Isomorphic strings    easyyyyyyyyyyyyyy

// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving 
// the order of characters. No two characters may map to the same character, but a character 
// may map to itself.

// Example 1:
// Input: s = "egg", t = "add"
// Output: true
// Example 2:
// Input: s = "foo", t = "bar"
// Output: false
// Example 3:

//approach 
//mapping to krni hai hme pr ye bhi dekhna hai ki double mapping nhi honi chahia
//length to same hi honi chahia

class Solution {
public:
    bool isIsomorphic(string s, string t) {
       int hash[256]={0}; //mapping of each character of language 's to language 't'; 
       bool isTCharsMapped[256]={0}; //stores if t[i] char already mapped with s[i] 

       for(int i=0;i<s.size();i++){ 
            //agr  e ke correspong mapping avalable nhi hai
        if(hash[s[i]]==0 && isTCharsMapped[t[i]]==0) { //agr map nhi hai   //s = "egg", t = "add"
             hash[s[i]]=t[i]; //to hme e ke corresponding a ko map kr diya
             isTCharsMapped[t[i]]=true; //qki use hme dubara map nhi kr skte
           }
       }      

       for(int i=0;i<s.size();i++){
           if(char(hash[s[i]])!=t[i]){ //rememeber
               return false;
           }
       }
       return true;
    }
};


///################################
//6 Reorganize string
// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
// Return any possible rearrangement of s or return "" if not possible.
// Example 1:
// input: s = "aab"
// Output: "aba"
// Example 2:
// Input: s = "aaab"
// Output: ""

//approach
//most occurance char and fit it non-adjency
//fill the rest character
//when i am placing most occurance elem in should be placed in one go
//ek hi iteration me
//cnt hash and try to place most occurance in one go
//place other cahr in remain index
class Solution {
public:
    string reorganizeString(string s) {
        int hash[26]={0};   //97 to 122 

        for(int i=0;i<s.size();i++)
        {
            hash[s[i]-'a']++;
        }

        //find most freq char
        char max_freq_char;
        int max_freq=INT_MIN;
        for(int i=0;i<26;i++)
        {
            if(hash[i]>max_freq)
            {
                max_freq=hash[i];  //kitni baar aaya hai o elem
                max_freq_char=i+'a'; //conversion to char
            }
        }
        //yahapr muze max frequent elem mil gya hoga
        //to use place kro pehle
        int index=0;
        while(max_freq >0 && index <s.size())
        {
            s[index]=max_freq_char;
            max_freq--;
            index=index+2; //alternatively place kr diya
        }

        if(max_freq!=0) //agr sare place nhi kr paye to out of bound hoga retunr empty string
        {
            return "";
        }

       //agr place kr paye most freq char
        hash[max_freq_char-'a']=0;

        //lets place rest of the characters
        for(int i=0;i<26;i++)
        {
            while(hash[i]>0)
            {
                index=index>=s.size() ? 1: index;
                s[index]=i+'a';
                 hash[i]--;
                index=index+2;
            }
        }

        return s;


//easyyy  O(nklogk)   approach to is remaining using hash
//7 Group anagrams //simply ho anagrams hai unka group krna hai bs
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
// typically using all the original letters exactly once.
// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

//agr mai do anagram string ko sort krta hoo na tb O dono same hoti hai
//entries will ke grouped with the help of a map

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;

        for(auto str:strs){
            string s=str;
            //muze s ko sort krna hai
            sort(s.begin(),s.end());
            mp[s].push_back(str); //isse s kr corresponig str ki entry bnayi
        }
        //iske baad map me sri entry bn ygi hai
        vector<vector<string>>ans;
        for(auto it=mp.begin();it!=mp.end();it++){ //map pe iterate krenge
           ans.push_back(it->second) ;//key val muze val ka vector store krna haoi

        }
        return ans;
    }
};

//easy
//8 longest pallindromic substring
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:
// Input: s = "cbbd"
// Output: "bb"

// i want maximim kength string from all pallindome string 

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
                //yaha hum palindromic subtring nikal rhe hai
                if(isPalindrome(s,i,j))  //i start bta rha hai and j end bta rha hai
                {
                string t=s.substr(i,j-i+1); //length=i-k+1
                ans=t.size()>ans.size() ? t : ans;
                }
            }
        }
          return ans;
    }
  
};



//9 find the index of first occurance of string
// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:
// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.
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

        //approach 2 NEED TO REVISE DRY RUN kro bs smjme aa jayega
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


//10 Strings to integer
//bs five dia gye conditions handle krne hai acchese 
class Solution {
public:
    int myAtoi(string s) {
        
        //inbuilt function
        // int ans=atoi(s.c_str());
        // return ans;

        //leading white space htadi
        int num=0,i=0,sign=1;  //+ve  
        while(s[i]==' ')
        {
            i++;
        }
         
             //+ve -ve handle kiya
        if(i<s.size()  && (s[i]=='-' || s[i]=='+') )
        {
            sign=s[i]=='+'?1:-1;   
            i++;
        }

        while(i<s.size()  && isdigit(s[i]))
        {
            //handled max conditions
            if(num>INT_MAX/10 || (num==INT_MAX/10 && s[i]>'7'))
            {
                return sign==-1?INT_MIN:INT_MAX; //remember ++
            }
             //qki '0'=48 and '1'=49 in akii
             //so '1'-'0'=1 in integer
            num=num*10+(s[i]-'0');     //char to number askii
            i++;

        }

        return num*sign; //while loop mai nhi gya to 0 return kiya
    }
};

//###########################
//11 String compression
// Input: chars = ["a","a","b","b","c","c","c"]
// Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
// Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

class Solution {
public:
    int compress(vector<char>& s) 
    {
        int index=0;
        int cnt=1;
        char prev=s[0];

        for(int i=0;i<s.size();i++){
            if(s[i]==prev){
                cnt++;
            }
            else{
                s[index++]=prev;
                if(cnt>1){
                    int start=index;
                    while(cnt){
                        s[index++]=(cnt%10)+'0';
                        cnt/=10;
                    }
                    reverse(s.begin()+start,s.begin()+index);
                }
                prev=s[i];
                cnt=1;
            }
        }

        s[index++]=prev;
        if(cnt>1){
                    int start=index;
             while(cnt){
                        s[index++]=(cnt%10)+'0';
                        cnt/=10;
                    }
                    reverse(s.begin()+start,s.begin()+index);

        }
        return index;
    
    }
};




//12 Integer to romans
// Input: num = 58
// Output: "LVIII"
// Explanation: L = 50, V = 5, III = 3.
// Example 3:
// Input: num = 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

class Solution {
public:
    string intToRoman(int num) {
        //mai larger to smaller ja rha hoo
        int ans[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res="";
        for(int i=0;i<13;i++){
            while(num>=ans[i])
            {
                // res.append(roman[i]);
                // num=num-ans[i];
                //or
                ans=ans+roman[i];
                num=num-values[i];
            }
        }
        return res;
    }
};

//###########REVIsE
//13 zig zag conversion
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
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

          direction=!direction; //change direction
      }
      string ans="";
      for(int i=0;i<zigzag.size();i++)
      {
          ans+=zigzag[i];

      }
      return ans;
    }
};



//14 largest number
// Input: nums = [10,2]
// Output: "210"
// Example 2:
// Input: nums = [3,30,34,5,9]
// Output: "9534330"

//approach 1 find permutations and return max  inefficent trika

//approach 2
class Solution {
public:
 
   static bool mycomp(string a,string b){  ///Understand neatly this
       string t1=a+b;
       string t2=b+a;
       return t1 > t2;
   }


    string largestNumber(vector<int>& nums) {
        vector<string>snums;
        for(auto n:nums){
            snums.push_back(to_string(n));
        }
        //for sorting in desc  (lexicographicalyy sorted like a,b,c,d alohabet wise)
        sort(snums.begin(),snums.end(),mycomp); 
        if(snums[0]=="0"){
            return "0";
        }
        string ans="";
            for(auto str:snums){
                //last se check krenge
                ans+=str;
            }
        
         return ans;
    }
};



int main()
{

    return 0;
}