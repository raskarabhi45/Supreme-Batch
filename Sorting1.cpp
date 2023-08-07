// 24/02/2024 friday
//Doneeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1 selection sort
//(n-1) rounds are required for sorting
// time complexity    O(n^2)
// space complexity O(1)

// 2 Bubble sort
// hr ith round mai ith largest element ko uske right jgh pr pohch deta hai

// 3 insertion sort
// fetch compare shift copy

int main()
{
    vector<int> arr{5, 4, 3, 2, 1};
    int n = arr.size();
    // 1  selection sort
    // outer loop n-1 rounds
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        // usse right mai dekho koi min element hai ya nahi
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                // new minimum then store
                minIndex = j;
            }
        }
        // swap
        swap(arr[i], arr[minIndex]);
    }

    cout << "Selection Sort" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // hr ith round mai ith largest element ko uske right jgh pr pohch deta hai
    // 2 Bubble sort  O(n^2) O(n)
    vector<int> brr{5, 4, 3, 2, 1, 8, 9, 7, 6};
    int n1 = brr.size();

    for (int round = 0; round < n1 - 1; round++)  //or 1 se n tk lga skte hum loop
    {
        bool swapped = false;
        for (int j = 0; j < n1 - round - 1; j++) //n-round-1 qki last me bda elem pohch rha hai hr ek round ke baad
        {
            if (brr[j] > brr[j + 1])
            {
                swapped = true;
                swap(brr[j], brr[j + 1]);
            }
        }
        // optimization
        if (swapped == false)
        {
            // sort ho chuka hai no need to check furher round
            break;
        }
    }

    cout << endl;
    cout << "Bubble Sort" << endl;
    for (int i = 0; i < n1; i++)
    {
        cout << brr[i] << " ";
    }
    cout << endl;


    // 3 insertion sort

    // fetch compare shift copy
    vector<int> crr{10, 1, 7, 6, 14, 9};
    int n3 = crr.size();
    int j;
    // insertion sort
    // starting this loop from one cause we are consdering first element as aleady sorted
    for (int round = 1; round < n3; round++)
    {
        // step 1: fetch
        int val = crr[round];
        // step 2: compare
        for (j = round - 1; j >= 0; j--)
        {
            if (crr[j] > val)
            {
                // step 3 : shift
                crr[j + 1] = crr[j];
            }
            else
            {
                // rukma hai
                break;
            }
        }
        // step 4: copy
        crr[j + 1] = val;
    }

    cout << "Insertion Sort" << endl;
    for (int i = 0; i < n3; i++)
    {
        cout << crr[i] << " ";
    }
    cout << endl;

    // sort using inbuilt methods

    vector<int> v{3, 6, 8, 6, 5, 3, 1, 2, 9, 8};
    int n4 = v.size();
    sort(v.begin(), v.end());
    cout << "Insertion Sort" << endl;
    for (int i = 0; i < n4; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}