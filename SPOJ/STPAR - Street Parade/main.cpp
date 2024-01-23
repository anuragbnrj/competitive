#include <cstdio>
#include <stack>
using namespace std;

int main()
{
	int n, i, a[1001], k, tp, c;
	while(scanf("%d",&n)==1 && n)
	{
		stack<int> s;
		k=0;c=0;tp=0;
		for(i=0; i<n; i++) {scanf("%d", &a[i]);}
		for(i=1; i<=n; i++)
        {
            if(!s.empty()){tp=s.top();}
            if(tp==i){s.pop();c++;continue;}
            while(k<n)
            {
                if(a[k]==i){k++;c++;break;}
                else
                {
                    s.push(a[k]);
                    k++;
                }
            }
        }
        if(c==n){printf("yes\n");}
        else {printf("no\n");}
	}
	return 0;
}
