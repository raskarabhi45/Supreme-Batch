// 17/3/23
// Friday
// Doneeeeeeeeeeeeeeeeeeeeeeeeeee

#include <iostream>
using namespace std;

// 1 merge sort
void merge(int s, int e, int *arr)
{

    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *left = new int[len1];
    int *right = new int[len2];

    int k = s;
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k++];
    }

    int leftindex = 0;
    int rightindex = 0;
    int mainindex = s;

    while (leftindex < len1 && rightindex < len2)
    {
        if (left[leftindex] < right[rightindex])
        {
            arr[mainindex++] = left[leftindex++];
        }
        else
        {
            arr[mainindex++] = right[rightindex++];
        }
    }

    while (leftindex < len1)
    { // jb tk
        arr[mainindex++] = left[leftindex++];
    }
    while (rightindex < len2)
    {
        arr[mainindex++] = right[rightindex++];
    }

    // delete[] left;
    // delete[] right;
}

void mergesort(int s, int e, int *arr)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    mergesort(s, mid, arr);
    mergesort(mid + 1, e, arr);

    merge(s, e, arr);
}

int main()
{
    int arr[13] = {4, 13, 5, 2, 11, 77, 44, 44, 3, 4, 77, 90, 7};
    // op 2 3 4 4 5 7 11 13 44 44 77 77 90
    int s = 0;
    int e = 12;
    mergesort(s, e, arr);

    for (int i = 0; i < 13; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}