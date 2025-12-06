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
    int current = 50;
    int res = 0;
    string command;
    while (cin >> command) {
        char dir = command[0];
        int stride = stoi(command.substr(1));

        int factor = 1;
        if (dir == 'L') {
            factor = -1;
        }
        bool startedAt0 = current == 0;
        current += factor * stride;
        res += abs(current / 100);
        if (current <= 0 && !startedAt0) {
            res++;
        }

        current = ((current % 100) + 100) % 100;
    }
    cout << res << endl;
}


signed main() {
    if(db) freopen("../in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
