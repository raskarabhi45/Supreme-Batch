//Dnc class 5
//25/03/2023
//Sunday

// 1 Generate parynthesis leetcodef
class Solution {
public:
   
   void solve(int open,int close,string op,vector<string> &v)
   {
    //base case maine sare brackets use krlia hai
       if(open==0 && close==0)
       {
           v.push_back(op);
           return;
       }
      //include open bracket
       if(open!=0)
       {
           string op1=op;
           op1.push_back('(');
           solve(open-1,close,op1,v);
           //backtrack
           op.pop_back();
       }
       //include close bracket
       if(close>open)
       {
           string op2=op;
           op2.push_back(')');
           solve(open,close-1,op2,v);
           //backtrack
           op.pop_back();
       }
   }

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int open=n;
        int close=n;
        string op="";
        solve(open,close,op,v);
        return v;
        
    }
};


//letter combinations of phone nmumber leetcode
class Solution {
    private:
    void solve(string digits,string output,int index,vector<string> &ans,string mapping[])
    {
        //  base case
        if(index>=digits.length())
        {
            ans.push_back(output);
            return;
        }

        // recursion
        int number=digits[index]-'0';  //to convert char to int
        string value=mapping[number];
        
        for(int i=0;i<value.length();i++)
        {
            output.push_back(value[i]);
            solve(digits,output,index+1,ans,mapping);

            //backtrack
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)
        {
            return ans;
        }
        string output;
        int index=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,index,ans,mapping);
        return ans;
        
    }
};



