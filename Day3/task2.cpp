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

const int LENGTH_LIMIT = 12;

int solve_row(string s) {
    int res = 0;
    int l = 0;
    for (int r = s.length() - LENGTH_LIMIT; r < s.length(); r++) {
        int mx = -1;
        int idx_of_first_max = 0;
        for (int i = l; i <= r; i++) {
            int cur = s[i] - '0';
            if (cur > mx) {
                mx = cur;
                idx_of_first_max = i;
            }
        }

        res *= 10;
        res += mx;
        l = idx_of_first_max + 1;
    }
    return res;
}

void solve() {
    vector<string> inputs;
    string s;
    while (cin >> s) {
        inputs.push_back(s);
    }
    int res = 0;
    for (int i = 0; i < inputs.size(); i++) {
        res += solve_row(inputs[i]);
    }
    cout << res << endl;
}



signed main() {
    if(db) freopen("../in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
