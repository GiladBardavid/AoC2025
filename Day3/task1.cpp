/**
* Day 1 task 2
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

void solve() {
    vector<string> inputs;
    string s;
    while (cin >> s) {
        inputs.push_back(s);
    }
    int res = 0;
    int mx = 0;
    for (int row = 0; row < inputs.size(); row++) {
        for (int i = 0; i < inputs[0].size(); i++) {
            for (int j = i + 1; j < inputs[0].size(); j++) {
                int current = (inputs[row][i] - '0') * 10 + inputs[row][j] - '0';
                mx = max(mx, current);
            }
        }
        res += mx;
        mx = 0;
    }
    cout << res << endl;
}



signed main() {
    if(db) freopen("../in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
