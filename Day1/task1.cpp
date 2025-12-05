/**
* Day 1 task 1
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
    int current = 50;
    int res = 0;
    string rotation;
    while (cin >> rotation) {
        int factor = 1;
        if (rotation[0] == 'L') {
            factor = -1;
        }
        current += factor * stoi(rotation.substr(1, rotation.length()));
        current %= 100;
        if (current == 0) {
            res++;
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
