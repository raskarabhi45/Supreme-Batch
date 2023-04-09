#include<iostream>
using namespace std;

int main()
{
    //1
    // int i=0;
	// i=i+1;
	// cout<<i;
	// /*print i i=i+1*/
	// cout<<++i;

    //2
    // short i=2300, j=4322;
	// cout<<"i+j="<<-(i+j);

    //3 Find perimeter of a rectangle.
    // float l, b;
	// float P = 2*(l+b);
	// printf("Perimeter= %f", P);

    //4 Print solid square pattern.
    // int n;
    // cin>>n;
    // for (int i=0; i<n; i++) {
    //     for (int j=0; j<n; j++) {
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    //5 Check given number is Prime or not.
// 	int n;
// 	cin >> n;
// 	bool isPrime = true;
//    for(int i=2;i<n;i++){
//       if(n%i == 0){
//           isPrime = false; break;
//       }
//   }
// 	if(isPrime){
// 		cout<<"Prime"<<endl;	
// 	}
// 	else{
// 		cout<<"Not Prime"<<endl;	
// 	}
    
    //6 Print Numeric Hollow Inverted Half Pyramid 
// 12345
// 2  5
// 3 5
// 45
// 5
//      int n;
//     cin>>n;
//     for(int i=0;i<n;++i){
//         for(int j=i+1;j<=n;j++){
//             if(j==i+1 || j == n  || i == 0){
//                 cout<<j;
//             }
//             else{
//                 cout<<" ";
//             }
//         }
//         cout<<endl;
//     }

  //7 full pyramid
  
//         1
//       2 3 2
//     3 4 5 4 3
//   4 5 6 7 6 5 4
// 5 6 7 8 9 8 7 6 5
//   int n;
//   std::cin>>n;
//   for (int i = 1; i <= n; i++) {
//     for (int j = 1; j <= n - i ; j++) {
//       printf("  ");
//     }
//     for (int j = i; j < 2*i; j++) {
//       printf("%d ", j);
//     }
//     int ele = 2 * ( i - 1);
//     for (int j = 1; j <= i - 1; j++) {
//       printf("%d ", ele--);
//     }
//     printf("\n");
//   }



    return 0;
}