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

void solve(){
    ll N, K;
    cin >> N >> K;
    ll max_value = N;
    ll min_value = 2 - N;
    if (K < min_value || K > max_value) {
        cout << "NO" << nl;
    } else if ((max_value - K) % 2 == 0) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
    }
}

int main(){zicofarry slv return 0;}