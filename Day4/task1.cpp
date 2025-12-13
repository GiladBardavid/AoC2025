/**
* Day 4 task 1
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

const char TARGET = '@';

int valid(vector<string> s, int i, int j) {
    int good = 0;

    if (i > 0 && s[i - 1][j] == TARGET) good++;
    if (i < s.size() - 1 && s[i + 1][j] == TARGET) good++;
    if (j > 0 && s[i][j - 1] == TARGET) good++;
    if (j < s[0].length() - 1 && s[i][j + 1] == TARGET) good++;

    if (i > 0 && j > 0 && s[i - 1][j - 1] == TARGET) good++;
    if (i < s.size() - 1 && j > 0 && s[i + 1][j - 1] == TARGET) good++;
    if (i > 0 && j < s[0].length() - 1 && s[i - 1][j + 1] == TARGET) good++;
    if (i < s.size() - 1 && j < s[0].length() - 1 && s[i + 1][j + 1] == TARGET) good++;

    return good < 4;
}


void solve() {
    vector<string> input;
    string row;
    while (cin >> row) {
        input.push_back(row);
    }

    int res = 0;
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[0].length(); j++) {
            if (input[i][j] == TARGET) {
                res += valid(input, i, j);
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
