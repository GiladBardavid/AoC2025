/**
* Day 10 task 1
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
#define pii pair<int, int>


int min_xors(vector<int> vals, int target) {
    int n = vals.size();
    int res = INT32_MAX;
    for (int b = 0; b < (1<<n); b++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (b&(1<<i)) {
                subset.push_back(i);
            }
        }
        int xored = 0;
        for (int idx_to_xor : subset) {
            xored ^= vals[idx_to_xor];
        }
        if (xored == target) {
            res = min(res, (int)__builtin_popcount(b));
        }
    }
    return res;
}


int solve_line(string line) {
    stringstream ss(line);
    string goals;
    ss >> goals;
    int n = goals.size() - 2;
    int target = 0;
    for (int i = 0; i < n; i++) {
        if (goals[i + 1] == '#') {
            target |= 1 << i;
        }
    }
    vector<int> xor_candidates;
    string xor_candidate;
    while (ss >> xor_candidate) {
        int xor_candidate_val = 0;
        if (xor_candidate[0] == '{') {
            break;
        }

        stringstream ss2(xor_candidate.substr(1, xor_candidate.size() - 2));
        string value_to_xor;
        while (getline(ss2, value_to_xor, ',')) {
            xor_candidate_val += 1LL << stoll(value_to_xor);
        }

        xor_candidates.push_back(xor_candidate_val);
    }

    return min_xors(xor_candidates, target);
}


void solve() {
    int res = 0;
    string line;
    while (getline(cin, line)) {
        res += solve_line(line);
    }
    cout << res << endl;
}


signed main() {
    if(db) freopen("../in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
