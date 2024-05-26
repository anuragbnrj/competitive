// Problem Link: 

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;

long double PI = acos(-1.0);
ll mod = 1e9 + 7;

ll binPowMod(ll base, ll pow) {
    if (pow == 0) return 1;

    if (pow % 2 == 1) {
        return (base * binPowMod(base, pow - 1)) % mod;
    } else {
        ll temp = binPowMod(base, pow / 2);
        return (temp * temp) % mod;
    }

}

struct cmp {
	bool operator()(const pair<int, ll>& p1, const pair<int, ll>& p2) const {
		if (p1.first == p2.first) {
			return p1.second > p2.second;
		}

		return p1.first < p2.first;
	}
};

struct customDS {
    // mean
    ll sum = 0;
    ll count = 0;

    // median
    multiset<ll> low, high;

    // mode
    map<ll, int> freq;
    multiset<pair<int, ll>, cmp> freqOrder;

    void balance() {
        if ((int)high.size() > (int)low.size()) {
            ll el = *high.begin();
            high.erase(high.find(el));
            low.insert(el);
        }

        if ((int)low.size() - (int)high.size() > 1) {
            ll el = *low.rbegin();
            low.erase(low.find(el));
            high.insert(el);
        }
    }

    void insert(ll x) {
        sum = (sum + x) % mod;
        count++;


        if (low.size() == 0 || high.size() == 0) {
            low.insert(x);
        } else {
            if (x <= *low.rbegin()) {
                low.insert(x);
            } else {
                high.insert(x);
            }
        }
        balance(); 


        if (freqOrder.find(make_pair(freq[x], x)) != freqOrder.end()) {
            freqOrder.erase(freqOrder.find(make_pair(freq[x], x)));
        }
        freq[x]++;
        freqOrder.insert(make_pair(freq[x], x));
    }

    void remove(ll x) {
        sum = (((sum - x) % mod) + mod) % mod;
        count--;


        if (low.find(x) != low.end()) {
            low.erase(low.find(x));
        } else {
            high.erase(high.find(x));
        }
        balance();


        if (freqOrder.find(make_pair(freq[x], x)) != freqOrder.end()) {
            freqOrder.erase(freqOrder.find(make_pair(freq[x], x)));
        }
        freq[x]--;
        freqOrder.insert(make_pair(freq[x], x));
    }

    ll getMean() {
        if (count == 0) return -1LL;

        ll mean = (sum * binPowMod(count, mod - 2)) % mod;
        return mean;
    }

    ll getMedian() {
        if (count == 0) return -1LL;

        if (count % 2 == 1) {
            return *low.rbegin();
        } else {
            ll median = (((*low.rbegin() + *high.begin()) % mod) * binPowMod(2, mod - 2)) % mod;
            return median;
        }
    }

    ll getMode() {
        if (count == 0) return -1LL;
        // int modeFreq = (*freqOrder.rbegin()).first;
        // auto lb = freqOrder.lower_bound(make_pair(modeFreq, -1));

        return (*freqOrder.rbegin()).second;
    }

};

void solve() {
    int q;
    cin >> q;

    customDS ds;
    while (q--) {
        string s;
        cin >> s;

        ll x;
        if (s == "insert") {
            cin >> x;
            ds.insert(x);
        } else if (s == "remove") {
            cin >> x;
            ds.remove(x);
        } else if (s == "getMean") {
            cout << ds.getMean() << endl;
        } else if (s == "getMedian") {
            cout << ds.getMedian() << endl;
        } else {
            cout << ds.getMode() << endl;
        }
    }

}  

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1; 
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
