/**
* Day 4 task 2
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

bool valid(vector<string>& s, int i, int j) {
    int good = 0;

    if (i > 0 && s[i - 1][j] == TARGET) good++;
    if (i < s.size() - 1 && s[i + 1][j] == TARGET) good++;
    if (j > 0 && s[i][j - 1] == TARGET) good++;
    if (j < s[0].length() - 1 && s[i][j + 1] == TARGET) good++;

    if (i > 0 && j > 0 && s[i - 1][j - 1] == TARGET) good++;
    if (i < s.size() - 1 && j > 0 && s[i + 1][j - 1] == TARGET) good++;
    if (i > 0 && j < s[0].length() - 1 && s[i - 1][j + 1] == TARGET) good++;
    if (i < s.size() - 1 && j < s[0].length() - 1 && s[i + 1][j + 1] == TARGET) good++;

    if (good < 4) {
        s[i][j] = '.';
        return true;
    }
    return false;
}


void solve() {
    vector<string> input;
    string row;
    while (cin >> row) {
        input.push_back(row);
    }

    int res = 0;
    bool foundOne = true;
    while (foundOne) {
        foundOne = false;
        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < input[0].length(); j++) {
                if (input[i][j] == TARGET && valid(input, i, j)) {
                    foundOne = true;
                    res++;
                }
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
