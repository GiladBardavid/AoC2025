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
    /*
     * Idea: greedy over digits from highest to lowest. Then we have the digits of the resulting 12 digit number.
     * For all digits other than the smallest one we choose as part of out 12, we just take them all.
     * Then for the smallest one we need to loop from right to left and take greedily while every time we pass a larger
     * digit we keep track of that then insert the small digit into the right position in the resulting integer.
     */
    int digit_to_occurrences_in_largest[10] = {0};
    int smallest_included_digit = 9;
    int included_digits = 0;
    for (int i = 9; i >= 0; i--) {
        for (char c : s) {
            if (c - '0' == i) {
                digit_to_occurrences_in_largest[i]++;
                included_digits++;
                smallest_included_digit = i;
            }
            if (included_digits == LENGTH_LIMIT) {
                break;
            }
        }
        if (included_digits == LENGTH_LIMIT) {
            break;
        }
    }

    cout << "smallest digit = " << smallest_included_digit << endl;
    cout << "occurrences of it = " << digit_to_occurrences_in_largest[smallest_included_digit] << endl;

    int smallest_digit_occurrences = 0;
    int res_digits[LENGTH_LIMIT] = {0};
    int idx_in_res = 0;

    for (int i = s.length() - 1; i >= 0; i--) {
        int curr = s[i] - '0';
        if (curr < smallest_included_digit) {
            continue;
        }

        if (curr > smallest_included_digit) {
            res_digits[idx_in_res] = curr;
            idx_in_res++;
            continue;
        }

        // curr == smallest_included_digit
        if (smallest_digit_occurrences < digit_to_occurrences_in_largest[smallest_included_digit]) {
            res_digits[idx_in_res] = curr;
            idx_in_res++;
            smallest_digit_occurrences++;
        }
    }

    int res = 0;
    for (int i = LENGTH_LIMIT - 1; i >= 0; i--) {
        res *= 10;
        res += res_digits[i];
    }

    cout << "row res = " << res << endl;

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
