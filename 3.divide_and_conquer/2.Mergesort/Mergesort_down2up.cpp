#include <iostream>
#include <cmath>
using namespace std;

void print(int *a,int length)
{
    for(int i = 0;i<length;i++) cout<<a[i]<<" ";
}

void Merge(int *a,int start,int mid,int end)
{
    int * tmp = (int *)malloc(sizeof(int)*(end-start+1));
    int tmp_index = 0;

    int i = start,j = mid;

    while( (i<=mid - 1)&&(j<=end) )
    {
        if(a[i]<=a[j]){tmp[tmp_index]=a[i];tmp_index++;i++;}
        if(a[i]>a[j]){tmp[tmp_index]=a[j];tmp_index++;j++;} 
    }

    while(i!=mid){tmp[tmp_index] = a[i];tmp_index++;i++;}
    while(j!=end+1){tmp[tmp_index] = a[j];tmp_index++;j++;}

    int t = 0;
    for(int e = start;e<=end;e++) {a[e] = tmp[t];t++;} 

    free(tmp);
    
}


void MergeOnce(int *a,int length,int nums)
{
    int i;
    for( i = 0; i+2*length<=nums; i+=2*length)
    {
        Merge(a,i,i+length,i+2*length-1);
    }
    if(i+length <= nums-1)
        Merge(a,i,i+length,nums-1);
}

void Mergesort(int *a,int nums)
{
    
    for(int length = 1;length<=nums; length*=2)
    {
        MergeOnce(a,length,nums);
    }
}
int main()
{
    int a[] = {2,4,3,34,5,2,90,56,45,61,1};
    int nums = sizeof(a)/sizeof(a[0]);
    Mergesort(a,nums);    
    print(a,nums);
}
