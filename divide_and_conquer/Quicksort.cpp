#include <iostream>
using namespace std;

void ArrayPrint(int *a)
{
    int num = sizeof(a)/sizeof(a[0]);//ten numbers,num is ten.
    
    for(int i = 0;i<10 ; i++)
    {
        cout<< a[i] <<" ";
    }
}

int Partition(int* a,int s, int t)
{
   int s0 = s;
   for(int i = s0 + 1; i<=t; i++)
   {
       if(a[i]>=a[s]) continue;
       else
       {
           int tmp = a[i];
           for(int j = i-1; j>=s0; j--)/*diff:for(int j = i-1; j>=0; j--),the"j>=0"is bad,It will make the smallest one on the right (but definitely larger than the left) and put it on the far left.*/
                a[j+1] = a[j];
  
           a[s0] = tmp;//diff:a[0] = tmp
           s++;
  
       }
    }
    cout<<"the i is : a["<<s<<"]. And the result sorted is :";
    ArrayPrint(a);
    cout<<endl;
    return s;
 
}

void Quicksort(int*a,int s,int t)
{
    if(t-s<1) return;
    else
    {
        int i = Partition(a,s,t);
 
        Quicksort(a,s,i-1);
        Quicksort(a,i+1,t);
    }
}

int main()
{
    int a[10]={2,5,1,7,10,6,9,4,3,8};
    cout<<"the original array is : ";
    ArrayPrint(a);
    cout<<endl;

    cout<<"******************PROCESS_BEGIN*******************"<<endl;
    Quicksort(a,0,9);
    cout<<"******************PROCESS_END*********************"<<endl;

    cout<<"the final array is : ";
    ArrayPrint(a);
    cout<<endl;
    return 0;

}

