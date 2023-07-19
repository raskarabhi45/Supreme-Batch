// 5/7/2023 wednseday
// Greedy algorithm
// lalchiii

// questions

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
// n trains and 1 plaftform problem arrival time and departure train
// algo
// sort basis on descending order
// analyse kon kon si train possible hai
// agr next wali train ka arrival time >= prev wali departure time se

// output
//  4,5
//  5,7
//  8,11
//  Ans is 3
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int solve(int n, int arr[], int dept[])
{
    vector<pair<int, int>> data;
    for (int i = 0; i < n; i++)
    {
        data.push_back({arr[i], dept[i]});
    }

    sort(data.begin(), data.end(), cmp);

    int cnt = 1; // first train to chlegi hi
    cout << data[0].first << "," << data[0].second << endl;
    ;
    int lastDept = data[0].second;
    for (int i = 1; i < n; i++)
    {
        // curr arrival  >= purani departure
        if (data[i].first >= lastDept)
        {
            // current train can be include
            cnt++;
            lastDept = data[i].second;
            cout << data[i].first << "," << data[i].second << endl;
            ;
        }
    }

    return cnt;
}

// DEFKIN
// 3 Defence of a Kingdom

// 4  min cost of ropes
// minimum walo ki fetch krke merge kr rhe hai
// mean heap best for this


//5 Huffman Encoding



//6 Fractional knapsack 

//val/wt sort kiya dec order
//one by one item pick entire item and fravtional item picking

bool cmp(pair<int,int>a,pair<int,int>b){
    double ratio1=((1.0)a.first)/a.second;
    double ratio2=((1.0)b.first)/b.second;

    return ratio1> ratio2;

    
}

//7 chocolcate distribution problem



int main()
{
    // //1
    //     int n = 4;
    //     int arr[] = {5, 8, 2, 4};
    //     int dept[] = {7, 11, 6, 5};

    //     int ans = solve(n, arr, dept);
    //     cout << "Ans is " << ans << endl;



    // 2 //shop candies
    // 2 lolipop ->offer
    // 1 lolly pop pe 2 lolly pop free
    // tumhe minimum paise kharch krke sari ki sari lollypop buy krni hai
    // prices[]={2,9,8,4,6,7}
    // 2 pointer approach buy and free
    // int prices[] = {2, 8, 6, 9, 4, 7};
    // int n = 6;

    // // algo start here
    // sort(prices, prices + n);

    // int amount = 0;
    // int buy = 0;
    // int free = n - 1;

    // while (buy <= free)
    // {
    //     amount += prices[buy];
    //     buy++;
    //     free--;
    //     free--;
    // }
    // cout << "ans is " << amount << endl;

    // check once
    // 3rd problem

     int x, y, n;
  cin >> x >> y >> n;
  int t = n;
  vector<int> rowC;
  vector<int> colC;

  rowC.push_back(0);
  colC.push_back(0);

  while(t--) {
    int a, b;
    cin >> a >> b;
    rowC.push_back(a);
    colC.push_back(b);
  }

  //size of 2D grid
  rowC.push_back(x+1);
  colC.push_back(y+1);

  sort(rowC.begin(), rowC.end());
  sort(colC.begin(), colC.end());

  int maxLen = INT_MIN;
  for(int i=1; i<rowC.size(); i++) {
      int a = rowC[i-1];
      int b = rowC[i];

      maxLen = max(maxLen, b-a-1);
  }

  int maxWidth = INT_MIN;
  for(int i=1; i<colC.size(); i++) {
      int a = colC[i-1];
      int b = colC[i];

      maxWidth = max(maxWidth, b-a-1);
  }

  cout << "answer is " << maxLen * maxWidth << endl;




    // 4  min cost of ropes
     int arr[] = {4,3,2,6};
  int n = 4;

  priority_queue<int, vector<int>, greater<int> > pq;
  for(int i=0; i<n; i++) {
    pq.push(arr[i]);
  }
  int cost = 0;
  while(pq.size() != 1) {
    int first = pq.top();
    pq.pop();
    int second = pq.top();
    pq.pop();

    cost += first + second;
    int newLength = first + second;
    pq.push(newLength);

  }
  cout << "Cost is: " << cost << endl;


    //5///

    //6 fractional knapsack
    #include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
  double ratio1 = ((1.0)*a.first) / a.second;
  double ratio2 = ((1.0)*b.first) / b.second;
  return ratio1 > ratio2;
}

int main() {
  int val[] = {60, 100, 120};
  int wt[] = {10, 20, 30};
  int n= 3;
  int capacity = 50;

  vector<pair<int,int> > data;
  for(int i=0; i<n; i++) {
    data.push_back({val[i], wt[i]});
  }

  sort(data.begin(), data.end(), cmp);
  int totalValue = 0;
  //check eac items k entire itm lelu ya frraction lu
  for(int i=0;i<n; i++) {
    pair<int,int> item = data[i];
    int itemValue = item.first;
    int itemWeight = item.second;
    //entire inclusioon wala case
    if(itemWeight <= capacity) {
      //add kardo value ko
      totalValue += itemValue;
      //update krdo capacity ko
      capacity = capacity - itemWeight;
    }
    else {
      //fraction include krdo
      //update value
      double ratio = ((1.0)*itemValue) / itemWeight;
      int valueToAdd = ratio * capacity;
      totalValue += valueToAdd;

      //udpate capacity;
      capacity = 0;
    }
  }
  cout << "Answer is: "<< totalValue << endl;
  return 0;
}



//6
 int n = 7;
  int m = 3;
  int arr[] = {7,3,2,4,9,12,56};
  //sort
  sort(arr, arr + n);

  //check differences in m-size window
  int i = 0;
  int j = m-1;
  int diff = INT_MAX;
  while(j<n) {
    int newDiff = arr[j] - arr[i];
    diff = min(diff, newDiff);
    j++;
    i++;
  } 
  cout << "Answer is: " << diff << endl;


    return 0;
}