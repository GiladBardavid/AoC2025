/**
* Day 7 task 1
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

    for (int i = 1; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            if (a[i-1][j] == SOURCE
                || (a[i-1][j] == BEAM && a[i][j] != SPLITTER)
                || (j > 0 && a[i][j-1] == SPLITTER && a[i-1][j-1] == BEAM)
                || (j < a[0].size() - 1 && a[i][j+1] == SPLITTER && a[i-1][j+1] == BEAM)) {
                a[i][j] = BEAM;
            }
        }
    }

    int res = 0;
    for (int i = 1; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            if (a[i][j] == SPLITTER && a[i-1][j] == BEAM) {
                res++;
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
