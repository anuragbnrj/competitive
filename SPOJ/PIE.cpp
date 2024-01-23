#include <bits/stdc++.h>

using namespace std;

double EPS = 0.00001;

bool possible(int n, int f, double volume, vector<double> volumes) {
    int pies_possible = 0;
    for (int i = 0; i < n; i++) {
        pies_possible += (volumes[i] / volume);     
    }

    if (pies_possible < f) {
        return false;
    } else {
        return true;
    }
}

double volume_pie(double radius) {
    const double PI = acos(-1.0);
    return PI * radius * radius * 1.0;
}

void solve() {
    int n, f;
    cin >> n >> f;
    // Since the one giving the party should also be counted
    f = f + 1;

    vector<double> radii;

    vector<double> volumes;
    double max_vol = 0;

    for (int i = 0; i < n; i++) {
        double radius;
        cin >> radius;
        radii.push_back(radius);

        double vol = volume_pie(radius);
        volumes.push_back(vol);

        max_vol = max(max_vol, vol);
    }

    double start = 0.0;
    double end = max_vol;
    

    // for (int i = 0; i < 100; i++) {
    //     double mid = (start + end) / 2;

    //     if (possible(n, f, mid, volumes)) start = mid;
    //     else end = mid;
    // }

    while (fabs(end - start) > EPS) {
        double mid = start + ((end - start) / 2);

        if (possible(n, f, mid, volumes)) start = mid;
        else end = mid;
    }

    cout << fixed;
    cout << setprecision(4) << start << "\n";
}



int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
