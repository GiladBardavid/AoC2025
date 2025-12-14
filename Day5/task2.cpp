/**
* Day 5 task 2
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
#define pii pair<int, int>

struct {
    bool operator()(pii a, pii b) const {return a.first < b.first || (a.first == b.first && a.second < b.second);}
} comp;

void solve() {
    vector<pii> ranges;
    string row;
    while (cin >> row && row.find('-') != string::npos) {
        int dash_pos = row.find('-');
        int l = stoll(row.substr(0, dash_pos));
        int r = stoll(row.substr(dash_pos + 1));
        ranges.push_back({l, r});
    }

    sort(ranges.begin(), ranges.end(), comp);

    int res = 0;
    int max_seen = 0;
    for (int i = 0; i < ranges.size(); i++)
        res += ranges[i].second - ranges[i].first + 1;
        int overlap = max_seen - ranges[i].first + 1;
        if (max_seen > ranges[i].second) {
            overlap = ranges[i].second - ranges[i].first + 1;
        }
        if (overlap > 0) {
            res -= overlap;
        }
        max_seen = max(max_seen, ranges[i].second);
    }
    cout << res << endl;
}


signed main() {
    if(db) freopen("../in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
