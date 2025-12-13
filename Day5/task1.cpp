/**
* Day 5 task 1
* @author Gilad B.
 */

#ifdef local
const bool db = true;
#else
const bool db = false;
#endif
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define pb push_back
#define vi vector<int>

bool check(vector<pair<int, int>> valid_ranges, int to_check) {
    for (auto [l, r] : valid_ranges) {
        if (l <= to_check && to_check <= r) {
            return true;
        }
    }
    return false;
}

void solve() {
    vector<pair<int, int>> fresh_ranges;
    vector<int> to_check;
    string row;
    while (cin >> row && row.find('-') != string::npos) {
        int dash_pos = row.find('-');
        int l = stoll(row.substr(0, dash_pos));
        int r = stoll(row.substr(dash_pos + 1));
        fresh_ranges.push_back({l, r});
    }
    to_check.push_back(stoll(row));
    while (cin >> row) {
        to_check.push_back(stoll(row));
    }

    int res = 0;
    for (int i = 0; i < to_check.size(); i++) {
        res += check(fresh_ranges, to_check[i]);
    }
    cout << res << endl;
}


signed main() {
    if(db) freopen("../in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
