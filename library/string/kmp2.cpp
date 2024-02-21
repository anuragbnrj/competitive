// Problem Link: 

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007

typedef long long ll;

vector<int> generateKMPArray(string str) {
    int len = str.size();

    vector<int> kmp(len + 1);
    kmp[0] = -1;
    
    int i = 0, j = -1;
    while (i < len) {
        while (j != -1 && str[i] != str[j]) {
            j = kmp[j];
        }
        j++;
        i++;
        kmp[i] = j;
    }

    return kmp;
}  

int main() {
    string str;
    cin >> str;

    vector<int> kmp = generateKMPArray(str);

    for (int i = 0; i < (int)kmp.size(); i++) {
        cout << kmp[i] << " ";
    }
    cout << endl;

    return 0;
}
