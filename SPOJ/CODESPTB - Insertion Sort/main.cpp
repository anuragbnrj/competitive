#include <iostream>
#include <cstdio>
using namespace std;

long long invc;

void merg(int arr[],int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1], R[n2];

    for(i=0;i<n1;i++)
        L[i]=arr[l+i];
    for(j=0;j<n2;j++)
        R[j]=arr[m+1+j];
    i=0;j=0;k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
            arr[k++]=L[i++];
        else
        {
            invc+=(n1-i);
            arr[k++]=R[j++];
        }
    }
    while(i<n1)
        arr[k++]=L[i++];

    while(j<n2)
        arr[k++]=R[j++];
}


void merge_sort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);

        merg(arr,l,m,r);
    }

}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int sz, arr[200002], i;
        scanf("%d",&sz);
        for(i=0; i<sz; i++)
        {
            scanf("%d",&arr[i]);
        }
        invc=0;
        merge_sort(arr,0,sz-1);
        printf("%lld\n",invc);
    }
    return 0;
}
