/**
* Day 8 task 1
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

map<int, vector<int>> idx_to_point;

struct {
    bool operator()(pair<vector<int>, vector<int>> a, pair<vector<int>, vector<int>> b) const {
        float dist_a = pow(a.first[0] - a.second[0], 2) + pow(a.first[1] - a.second[1], 2) + pow(a.first[2] - a.second[2], 2);
        float dist_b = pow(b.first[0] - b.second[0], 2) + pow(b.first[1] - b.second[1], 2) + pow(b.first[2] - b.second[2], 2);
        return dist_a < dist_b;
    }
} comp;

vector<vector<int>> get_input() {
    vector<vector<int>> res;
    string s;
    while (cin >> s) {
        int dash_1_pos = s.find(',');
        int dash_2_pos = s.find(',', dash_1_pos + 1);
        int x = stoll(s.substr(0, dash_1_pos));
        int y = stoll(s.substr(dash_1_pos + 1, dash_2_pos));
        int z = stoll(s.substr(dash_2_pos + 1, s.length() - dash_2_pos - 1));
        res.push_back({x, y, z});
    }
    return res;
}

vector<pair<vector<int>, vector<int>>> get_all_pairs_sorted(vector<vector<int>> a) {
    vector<pair<vector<int>, vector<int>>> res;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            res.push_back({a[i], a[j]});
        }
    }
    sort(res.begin(), res.end(), comp);
    return res;
}

void initialize_idx_to_point_map(vector<vector<int>> a) {
    for (int i = 0; i < a.size(); i++) {
        idx_to_point.insert({i, a[i]});
    }
}

void solve() {
    vector<vector<int>> a = get_input();
    initialize_idx_to_point_map();
    vector<pair<vector<int>, vector<int>>> pairs_sorted = get_all_pairs_sorted(a);
    vector<vector<int>>

    for (auto p : pairs_sorted) {
        cout << p.first[0] << " " << p.first[1] << " " << p.first[2] << " " << p.second[0] << " " << p.second[1] << " " << p.second[2] << endl;
    }
}


signed main() {
    if(db) freopen("../in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
