/**
* Day 6 task 1
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
    vector<vector<string>> s;
    string line;
    while (getline(cin, line)) {
        vector<string> words;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        s.push_back(words);
    }

    int res = 0;
    for (int j = 0; j < s[0].size(); j++) {
        char op = s[s.size() - 1][j][0];
        if (op == '+') {
            for (int i = 0; i < s.size() - 1; i++) {
                res += stoll(s[i][j]);
            }
            continue;
        }
        int mult = 1;
        for (int i = 0; i < s.size() - 1; i++) {
            mult *= stoll(s[i][j]);
        }
        res += mult;
    }
    cout << res << endl;
}


signed main() {
    if(db) freopen("../in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
