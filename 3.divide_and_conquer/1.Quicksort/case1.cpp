#include <iostream>
using namespace std;

int Partition(int a[],int s,int t)
{
    int tmp = s;
    for(int i = s+1; i<=t; i++)
    {
        if(a[i]>=a[tmp]) continue;
        else
        {
            int tmp0 = a[i];
            for(int j = i; j>s; j--)
            {
                a[j] = a[j-1];
            }

            a[s] = tmp0;
            tmp++;
        }
    }
    return tmp;
}

void Quicksort(int a[],int s,int t,int k)
{
    int i = Partition(a,s,t);

    if(k == i+1) return;

    else if(k < i+1)
    {
        Quicksort(a,s,i-1,k);
    }

    else
    {
        Quicksort(a,i+1,t,k);
    }
}

int main()
{
    int a[] = {2,8,12,4,35,1,87,3,2,90,12};
    int k = 7;
    Quicksort(a,0,10,k);
    for(int i = 0; i<=6; i++) cout<<a[i]<<" ";

    return 0;
    
}
