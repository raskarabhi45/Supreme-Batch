//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        // code here
        vector<int> ans;
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        int ans1 = 0;
        // repeated number logic
        for (auto i : mp)
        {
            if (i.second == 2)
            {
                ans1 = i.first; // means i got the repeated element
                break;
            }
        }

        int i = 0;
        while (i < n)
        {
            int index = arr[i] - 1;
            if (arr[i] != arr[index])
            {
                swap(arr[i], arr[index]);
            }
            else
            {
                i++;
            }
        }
        int ans2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != i + 1)
                ans2 = i + 1;
        }

        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends