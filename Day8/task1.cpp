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
#define pii pair<int, int>

map<int, vector<int>> idx_to_point;

struct {
    bool operator()(pii a, pii b) const {
        vi ax = idx_to_point[a.first];
        vi ay = idx_to_point[a.second];
        vi bx = idx_to_point[b.first];
        vi by = idx_to_point[b.second];
        float dist_a = pow(ax[0] - ay[0], 2) + pow(ax[1] - ay[1], 2) + pow(ax[2] - ay[2], 2);
        float dist_b = pow(bx[0] - by[0], 2) + pow(bx[1] - by[1], 2) + pow(bx[2] - by[2], 2);
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

vector<pii> get_all_pairs_sorted(vector<vector<int>> a) {
    vector<pii> res;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            res.push_back({i, j});
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

int n;
vector<vector<int>> adj;
vector<bool> used;
vector<int> component;

void dfs(int v) {
    stack<int> st;
    st.push(v);

    while (!st.empty()) {
        int curr = st.top();
        st.pop();
        if (!used[curr]) {
            used[curr] = true;
            component.push_back(curr);
            for (int i = adj[curr].size() - 1; i >= 0; i--) {
                st.push(adj[curr][i]);
            }
        }
    }
}

vi find_comps() {
    // Returns the lengths of the components
    vi res;
    fill(used.begin(), used.end(), 0);
    for (int v = 0; v < n ; ++v) {
        if (!used[v]) {
            component.clear();
            dfs(v);
            res.push_back(component.size());
        }
    }
    return res;
}

void solve() {
    vector<vector<int>> a = get_input();
    n = a.size();
    adj.assign(n, {});
    used.assign(n, false);

    initialize_idx_to_point_map(a);
    vector<pii> pairs_sorted = get_all_pairs_sorted(a);

    int edges_to_edd = 1000;
    for (int i = 0; i < edges_to_edd; i++) {
        int x, y;
        tie(x, y) = pairs_sorted[i];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vi comp_lengths = find_comps();
    sort(comp_lengths.begin(), comp_lengths.end(), greater<int>());

    int to_mult = 3;
    int res = 1;
    for (int i = 0; i < to_mult; i++) {
        res *= comp_lengths[i];
    }
    cout << res << endl;
}


signed main() {
    if(db) freopen("../in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
