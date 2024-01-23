#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1, s2;
        char ch;
        int arr1[27], arr2[27], i, flag=0;
        cin>>s1;
        cin>>s2;
        for(i=0;i<=26;i++)
        {
            arr1[i]=0;
            arr2[i]=0;
        }
        for(i=0;i<s1.length();i++)
        {
            ch=s1[i];
            arr1[ch-96]=1;
        }
        for(i=0;i<s2.length();i++)
        {
            ch=s2[i];
            arr2[ch-96]=1;
        }
        for(i=1;i<=26;i++)
        {
            if(arr1[i]==arr2[i] && arr1[i]!=0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1){cout<<"Yes"<<endl;}
        else{cout<<"No"<<endl;}
    }
    return 0;
}
