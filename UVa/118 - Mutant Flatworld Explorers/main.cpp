#include<iostream>
#include<string>

using namespace std;

bool table[55][55];
int main()
{

    char ch;
    int dx[]={1,0,-1,0},dy[]={0,1,0,-1},x,y,X,Y,len,i,cur_dir;
    char dir[]={'E','N','W','S'};
    string str;
    bool flag;
    cin>>X>>Y;
    while(cin>>x>>y>>ch>>str)
    {
        switch(ch)
        {
            case 'E':
            cur_dir=0;
            break;

            case 'N':
            cur_dir=1;
            break;

            case 'W':
            cur_dir=2;
            break;

            case 'S':
            cur_dir=3;
            break;
        }
        len=str.size();
        flag=false;
        for(i=0;i<len;i++)
        {
            switch(str[i])
            {
                case 'L':
                cur_dir=(cur_dir+1)%4;
                break;

                case 'R':
                if(cur_dir==0)
                cur_dir=3;
                else
                cur_dir=(cur_dir-1)%4;
                break;

                case 'F':
                x=x+dx[cur_dir];
                y=y+dy[cur_dir];
                break;
            }
            if(x<0 || y<0 || x>X ||y>Y)
            {
                x=x-dx[cur_dir];
                y=y-dy[cur_dir];
                if(table[x][y]==false)
                {
                    table[x][y]=true;
                    flag=true;
                    break;
                }
            }
        }
        cout<<x<<" "<<y<<" "<<dir[cur_dir];
        if(flag)
        cout<<" LOST";
        cout<<endl;
    }
    return 0;
}
