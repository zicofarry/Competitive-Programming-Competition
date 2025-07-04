#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define DEBUG(str, var) cout << str << " = " << var << nl;
#define DEBAR(arr, n)\
    for(int i = 0; i < n; i++){\
        cout << "arr[" << i << "] = " << arr[i] << nl;\
    }
#define DEVEC(vec)\
    for(const auto &i : vec) cout << i << sp;\
    cout << nl;
#define sr(v, order)\
        sort(v.begin(), v.end(), order);
#define srtype(v, based, order)\
        sort(v.begin(), v.end(),[] (const auto &a, const auto &b){\
        return a.based order b.based;\
        });
#define nl "\n"
#define sp ' '
#define dig0(n) setw(n) << setfill('0')
#define pb push_back
#define pob pop_back
#define slv solve();
#define zicofarry\
    ios::sync_with_stdio(false);\
    cin.tie(nullptr);
using namespace std;

int n, k;
vi a;
map<tuple<int, int, int>, int> memo;

int dp(int pos, int mask, int size) {
    if (pos == n) return 0;
    auto key = make_tuple(pos, mask, size);
    if (memo.count(key)) return memo[key];

    int cur = a[pos];
    int res = 0;

    res = max(res, dp(pos + 1, mask, size));

    if (mask & (1 << cur)) {
        res = max(res, 1 + dp(pos + 1, mask, size));
        // DEBUG("res", res);
    } else {
        if (size < k) {
            res = max(res, dp(pos + 1, mask | (1 << cur), size + 1));
        } else {
            for (int val = 1; val <= 10; val++) {
                if (mask & (1 << val)) {
                    int newMask = (mask ^ (1 << val)) | (1 << cur);
                    // DEBUG("res", res);
                    res = max(res, dp(pos + 1, newMask, size));
                }
            }
        }
    }

    return memo[key] = res;
}

void solve(){
    cin >> n >> k;
    a.resize(n);
    for(auto &i : a) cin >> i;
    cout << dp(0, 0, 0) << nl;
}

int main(){zicofarry slv return 0;}