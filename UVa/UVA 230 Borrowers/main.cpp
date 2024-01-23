#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Book{
    string author, title;
    bool borrowed, returned;
    Book(string a, string b) {
        title = a;
        author = b;
        borrowed = returned = false;
    }
};

bool cmpa(Book a, Book b) {
    return a.author < b.author;
}

bool cmpb(Book a, Book b) {
    return a.title < b.title;
}

vector<Book>  All;
string cmd, in, req;

void shelve() {
    int j;
    for(int i = 0; i < All.size(); i++)
        if(All[i].returned == true) {
            for(j = i; j >= 0; j--)
                if(All[j].borrowed == false)
                    break;
            if(j == -1)
                printf("Put %s first\n", All[i].title.c_str());
            else
                printf("Put %s after %s\n",All[i].title.c_str(), All[j].title.c_str());

            All[i].borrowed = All[i].returned = false;
        }
    cout << "END\n";
}

void borrow() {
    getline(cin,req);

    for(int i = 0; i < All.size(); i++)
        if(All[i].title == req) {
            All[i].borrowed = true;
            return ;
        }
}

void back() {
    getline(cin,req);

    for(int i = 0; i < All.size(); i++)
        if(All[i].title == req) {
            All[i].returned = true;
            return ;
        }
}

int main() {
    while(getline(cin,in) && in != "END")
        All.push_back(Book(in.substr(0,in.find_last_of("\"") + 1),in.substr(in.find_last_of("\"") + 1) ) );
    stable_sort(All.begin(),All.end(),cmpb);
    stable_sort(All.begin(),All.end(),cmpa);

    while(cin >> cmd)
        if(cmd == "BORROW")
            cin.get(), borrow();
        else if(cmd == "RETURN")
            cin.get(), back();
        else if(cmd == "SHELVE")
            cin.get(), shelve();

    return 0;
}
