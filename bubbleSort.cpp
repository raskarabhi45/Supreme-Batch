#include<iostream>
#include<vector>
using namespace std;
//###########################
// DOneeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
//#####################

int main()
{
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

return 0;
}