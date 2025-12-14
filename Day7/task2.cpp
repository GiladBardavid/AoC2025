/**
* Day 7 task 2
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

const char SOURCE = 'S';
const char SPLITTER = '^';
const char BEAM = '|';
const char SPACE = '.';

void solve() {
    vector<string> a;
    string s;
    while (cin >> s) {
        a.push_back(s);
    }

    vector<vector<int>> dp(a.size(), vector<int>(a[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < a[i].size(); i++) {
        dp[0][i] = a[0][i] == SOURCE;
    }
    for (int i = 1; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            if (a[i][j] == SPLITTER) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i-1][j];
        }
        for (int j = 0; j < a[0].size(); j++) {
            if (j > 0 && a[i][j-1] == SPLITTER) {
                dp[i][j] += dp[i-1][j-1];
            }
            if (j < a[0].size() && a[i][j+1] == SPLITTER) {
                dp[i][j] += dp[i-1][j+1];
            }
        }
    }

    int res = 0;
    for (int i = 0; i < a[0].size(); i++) {
        res += dp[a.size() - 1][i];
    }
    cout << res << endl;
}


signed main() {
    if(db) freopen("../in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
