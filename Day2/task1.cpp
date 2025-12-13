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


int f(int x) {
    int numDigits = 0;
    int cpy = x;
    while (cpy > 0) {
        cpy /= 10;
        numDigits++;
    }
    return x * (pow(10, numDigits) + 1);
}

void solve() {
    // idea: loop from 1 to maxint, produce the value (perhaps we can go to the next one in a smart way) and count in how many pairs does it appear in
    string in;
    cin >> in;
    stringstream ss(in);
    string s;
    vector<int> a, b;
    while (getline(ss, s, ',')) {
        int dashPos = s.find('-');
        int x = stoll(s.substr(0, dashPos));
        int y = stoll(s.substr(dashPos + 1));
        a.pb(x);
        b.pb(y);
    }
    int res = 0;
    for (int i = 1; i < 1e5; i++) {
        int fi = f(i);
        for (int j = 0; j < a.size(); j++) {
            if (a[j] <= fi && fi <= b[j]) {
                res += fi;
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
