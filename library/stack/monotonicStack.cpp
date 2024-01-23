// Problem Link: 

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define MOD 1000000007
#define ll long long


vector<int> findNextGreaterIndices(vector<int> &arr) {
    int len = arr.size();
    vector<int> ngeIndices(len, -1);
    stack<int> s;

    for (int i = 0; i < len; i++) {
        while (s.size() > 0 && arr[s.top()] < arr[i]) {
            int idx = s.top();
            s.pop();

            ngeIndices[idx] = i;
        }

        s.push(i);
    }

    return ngeIndices;
}

vector<int> findPreviousGreaterIndices(vector<int> &arr) {
    int len = arr.size();
    vector<int> pgeIndices(len, -1);
    stack<int> s;

    for (int i = 0; i < len; i++) {
        while (s.size() > 0 && arr[s.top()] <= arr[i]) {
            int idx = s.top();
            s.pop();

        }

        if (s.size() > 0) {
            pgeIndices[i] = s.top();
        }

        s.push(i);
    }

    return pgeIndices;
}

vector<int> findNextSmallerIndices(vector<int> &arr) {
    int len = arr.size();
    vector<int> nseIndices(len, -1);
    stack<int> s;

    for (int i = 0; i < len; i++) {
        while (s.size() > 0 && arr[s.top()] > arr[i]) {
            int idx = s.top();
            s.pop();

            nseIndices[idx] = i;
        }

        s.push(i);
    }

    return nseIndices;
}

vector<int> findPreviousSmallerIndices(vector<int> &arr) {
    int len = arr.size();
    vector<int> pseIndices(len, -1);
    stack<int> s;

    for (int i = 0; i < len; i++) {
        while (s.size() > 0 && arr[s.top()] >= arr[i]) {
            int idx = s.top();
            s.pop();
        }

        if (s.size() > 0) {
            pseIndices[i] = s.top();
        }

        s.push(i);
    }

    return pseIndices;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> arr = {13, 8, 1, 5, 2, 5, 9, 7, 6, 12};
    int len = arr.size();
    cout << "Array:" << endl;
    for (int i = 0; i < len; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < len; i++) {
        cout << i << "\t";
    }
    cout << endl;


    // Next Greater Element Indices
    vector<int> ngeIndices = findNextGreaterIndices(arr);
    cout << "Next Greater Indices:" << endl;
    for (int i = 0; i < len; i++) {
        cout << ngeIndices[i] << "\t";
    }
    cout << endl;


    // Previous Greater Element Indices
    cout << "Previous Greater Indices:" << endl;
    vector<int> pgeIndices = findPreviousGreaterIndices(arr);
    for (int i = 0; i < len; i++) {
        cout << pgeIndices[i] << "\t";
    }
    cout << endl;

    // Next Smaller Element Indices
    cout << "Next Smaller Indices:" << endl;
    vector<int> nseIndices = findNextSmallerIndices(arr);
    for (int i = 0; i < len; i++) {
        cout << nseIndices[i] << "\t";
    }
    cout << endl;

    // Previous Smaller Element Indices
    cout << "Previous Smaller Indices:" << endl;
    vector<int> pseIndices = findPreviousSmallerIndices(arr);
    for (int i = 0; i < len; i++) {
        cout << pseIndices[i] << "\t";
    }
    cout << endl;



    return 0;
}
