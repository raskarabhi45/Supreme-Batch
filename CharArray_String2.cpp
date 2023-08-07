// Sunday 26/02/2023
//###########################################################
//2-3  problems remainingg
//###########################################################

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// //////////////////////////////////////////// very important->
//problem solving
//1 Remove all duplicate adjacent   leetcode
//ip :s= abbcddcssscddc
//op: as:
// class Solution {        
// public:
//     string removeDuplicates(string s) {   
//         string ans="";
//         int i=0;
         //int n=ans.length();
//         while(i<s.length()) //will travserse that string
//         {
               // before popback check whether there is element in the array or not ...      
//             if(ans.length()>0 && ans[n-1]==s[i]) //ans string ke end ka last element ko s string ke curr eleme se compare kro
//             {
//                 ans.pop_back();
//             }
//              else
//             {
//                 ans.push_back(s[i]);
//             }
//             i++;
//          }
//               return ans;
//         }
// };


//2  Remove all occurance of substring     
// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//         int pos=s.find(part);
//         while(pos!=string::npos)  //until we find the part of string in main string traverse
//         {
//             s.erase(pos,part.length());     //remove occurance
//             pos=s.find(part);  //update position
//         }
//         return s;
//     }
// };


//###################################
//3 valid palindrome 2
// class Solution {
// public:
//    bool checkPalindrome(string s,int i,int j)
//    {
//        while(i<=j)
//        {
//            if(s[i]!=s[j])
//            {
//                return false;
//            }
//            i++;
//            j--;
//        }
//        return true;
//    }

//     bool validPalindrome(string s) {
//         int i=0;
//         int j=s.length()-1;

//         while(i<=j)
//         {
//             if(s[i]!=s[j])
//             {
//                 //ek baar i ko remove and ek bar j ko remove
//                 return checkPalindrome(s,i+1,j) ||  checkPalindrome(s,i,j-1);                     //remember++
//             }
//             else
//             {
//                 //s[i]==s[j]
//                 i++;
//                 j--;
//             }
//         }
//         return true;
//     }
// };


//Easy hai bs dhyan se dekh0
//4  Minimum time difference leetcode 
// Input: timePoints = ["23:59","00:00"]
// Output: 1

// class Solution {
// public:
//     int findMinDifference(vector<string>& timePoints) {
//         //step1 : convert time string to minute integer value
//         vector<int>minutes;
//         for(int i=0;i<timePoints.size();i++)
//         {
//             string curr=timePoints[i];
//             int hours=stoi(curr.substr(0,2));
//             int min=stoi(curr.substr(3,2));
//             int totalMinutes=hours*60+min;
//             //pure array ko minutes mai convert kr diya
//             minutes.push_back(totalMinutes);  //total minutes ko minutes waly array me push kr diya
//         }

//         //step 2 : sort 
//         sort(minutes.begin(),minutes.end());

//         //step 3: calculate minimum difference 
//         int mini=INT_MAX;
//         int n=minutes.size();
//         for(int i=0;i<n-1;i++)
//         {
//             int diff=minutes[i+1]-minutes[i];
//             mini=min(mini,diff);

//         }
//         Tum yahape fsoge                                             //remember++
//         // important 
//         //compare 1st and last cause watch is circular
//         int lastdiff=(minutes[0]+1440)-minutes[n-1];  //#####
//         mini=min(mini,lastdiff);

//         return mini;
//     }
// };

//#######################
//5 palindromic substrings leetcode                                 AGAIN and AGAIN
// class Solution {
// public:

// int expandAroundIndex(string s,int i,int j)                           //REVISE
// {
//     //jab tk match krega tab tk cnt inceement kro and i-- and  j++
//     int cnt=0;
//     while(i>=0 && j<s.length() && s[i]==s[j])                                                                                           
//     {
//         cnt++;
//         i--;
//         j++;
//     }
//     return cnt;
// }


//     int countSubstrings(string s) {
//         //approach 1
//         //find all substrings
//         // check palindrome and count

//         //approach 2 best way
//         int cnt=0;
//         int n=s.length();

//         for(int i=0;i<n;i++)
//         {
//             //odd case  //i ki val i and jj ki val i
//             int oddKaAns=expandAroundIndex(s,i,i);
//             cnt=cnt+oddKaAns;

//             //even case //i ki val i and jj ki val i+1
//             int evenKaAns=expandAroundIndex(s,i,i+1);
//             cnt=cnt+evenKaAns;

//         }
//         return cnt; 
//     }
// };


////////////////////////////HOMEWORK///////////////////////////////
//do it
//1 valid anagrams 242              done
//2 reverse only letters 917        done
//3 longest common prefix 14         ok
//4 reverse vowels of string 245     done
//5 isomorfic strings               ok
//6 reorganise strings
//7 group anagrams
//8 longest pallindromic subsequence
//9 find index of first occurance in a string
//10 string to integer
//11 string compression
//12 integer to roman
//13 zigzag conversion

//14 largest number 170
//15 custom sort string 791
//16 verify aliean dictionary 953
//17 longest word in dictionary through deleting



int main()
{

    return 0;
}