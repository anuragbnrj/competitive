#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int main()
{
    long long num,siz=0,i;
    vector <long long> vec;
    map<long long , long long> freq;

    while(cin >> num)
    {
        if(freq.count(num)== 0)
        {
            freq[num]=1;
            vec.push_back(num);
        }
        else {freq[num]+=1;}
    }
    siz=vec.size();
    for (i=0;i<siz;i++)
    {
        printf("%lld %lld\n",vec[i],freq[vec[i]]);
    }
    return 0;
}
