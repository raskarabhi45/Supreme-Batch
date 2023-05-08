#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    printf("hello ji kaise he aap\n");
    int *arr=new int[5];
    
    // int *arr;
    // arr=(int*)malloc(sizeof(int)*5);

    *arr=1;
    *(arr+sizeof(int))=2;

    for(int i=0;i<5;i++)
    {
        // printf("%d\n", *(arr+(i*sizeof(int))));
        cout<<*(arr+(i*sizeof(int)))<<endl;
    }

    delete(arr);

    // free(arr);

    void *mem=malloc(67108864);
    printf("%d",mem);
    printf("SUccessful");
    free(mem);




    return 0;
}