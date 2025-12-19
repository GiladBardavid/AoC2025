/**
* Day 9 task 2
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

vector<pii> get_input() {
    vector<pii> res;
    string s;
    while (cin >> s) {
        int dash_pos = s.find(',');
        int x = stoll(s.substr(0, dash_pos));
        int y = stoll(s.substr(dash_pos + 1, s.length() - dash_pos - 1));
        res.push_back({x, y});
    }
    return res;
}

int get_rectangle_size(pii a, pii b) {
    return (abs(a.first - b.first) + 1) * (abs(a.second - b.second) + 1);
}

bool is_rectangle_valid(vector<pii> a, int i, int j) {
    int n = a.size();
    int min_row = min(a[i].first, a[j].first);
    int max_row = max(a[i].first, a[j].first);
    int min_col = min(a[i].second, a[j].second);
    int max_col = max(a[i].second, a[j].second);
    for (int k = 0; k < n; k++) {
        int next = (k + 1) % n;
        if (k == i || next == i || k == j || next == j) {
            continue;
        }
        if (a[k].first > min_row && a[k].first < max_row && a[next].first > min_row && a[next].first < max_row
            && ((a[k].second <= min_col && a[next].second > min_col) || (a[next].second <= min_col && a[k].second > min_col)
                || (a[k].second >= max_col && a[next].second < max_col) || (a[next].second >= max_col && a[k].second < max_col))) {
            return false;
        }
        if (a[k].second > min_col && a[k].second < max_col && a[next].second > min_col && a[next].second < max_col
            && ((a[k].first <= min_row && a[next].first > min_row) || (a[next].first <= min_row && a[k].first > min_row)
                || (a[k].first >= min_row && a[next].first < max_row) || (a[next].first >= max_row && a[k].first < min_row))) {
            return false;
        }
    }
    return true;
}

void solve() {
    vector<pii> a = get_input();
    int res = 1;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            if (is_rectangle_valid(a, i, j)) {
                res = max(res, get_rectangle_size(a[i], a[j]));
            }
        }
    }
    cout << res << endl;
}


signed main() {
    if(db) freopen("../in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
