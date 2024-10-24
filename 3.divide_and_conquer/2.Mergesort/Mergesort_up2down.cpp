#include <iostream>
using namespace std;

void print(int *a,int length)
{
    for(int i = 0;i<length;i++) cout<<a[i]<<" ";
}


void Merge(int *a,int start,int mid,int end)
{
    int *tmp = (int *)malloc(sizeof(int)*(end-start+1));
    int tmp_n = 0;
    int i = start,j = mid +1;

    while(i<=mid&&j<=end)
    {
        if(a[i]<=a[j]){tmp[tmp_n] = a[i];tmp_n++;i++;}
        else{tmp[tmp_n] = a[j];tmp_n++;j++;}
    }

    
    while(i!=mid+1){tmp[tmp_n] =  a[i]; tmp_n++; i++;}
    while(j!=end+1){tmp[tmp_n] = a[j]; tmp_n++; j++;}

    tmp_n = 0;
    for(int k = start;k<=end; k++){a[k] = tmp[tmp_n];tmp_n++;}

    free(tmp);
}

void Mergesort(int *a,int start,int end)
{

    if(end - start <=1) 
    {
        if(a[start] > a[end]) {int t = a[start];a[start]=a[end];a[end]=t;}
    
        return;
    }

    int mid = (end -start)/2 + start;

    Mergesort(a,start,mid);
    Mergesort(a,mid+1,end);

    Merge(a,start,mid,end); 
}

int main()
{
    int a[] = {2,45,34,71,1,2,3,6,90,35,64,33};
    int length = sizeof(a)/sizeof(a[0]);

    Mergesort(a,0,length-1);
    print(a,length);
    

}

