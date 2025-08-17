#include <bits/stdc++.h>
typedef long long ll;
#define nl "\n"
#define sp ' '
#define slv solve();
#define zicofarry\
    ios::sync_with_stdio(false);\
    cin.tie(nullptr);
using namespace std;

ll p, q;
unordered_map<ll, ll> memo;

ll attack(ll n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(memo.count(n)) return memo[n];

    ll res = n;
    if(n%2 == 0){
        res = min(res, attack(n/2) + p);
    }else{
        res = min(res, attack(n/2) + p + (n%2));
    }
        // cout << i << " - " << res << nl;
    if(n%3 == 0){
        res = min(res, attack(n/3) + q);
    }else{
        res = min(res, attack(n/3) + q + (n%3));
    }
    // cout << j << " - " << res << nl;
    // res = min(res, attack(n-1) +1);
    return memo[n] = res;
}

void solve(){
    int n;
    cin >> n >> p >> q;
    vector<ll> a(n);
    for(ll &i: a) cin >> i;
    for(int i = 0; i < n; i++){
        ll ans = attack(a[i]);
        if(ans >= a[i]){
            cout << "TIDAK SELAMAT" << nl;
            break;
        }else{
            cout << ans << nl;
        }
    }
}

int main(){zicofarry slv return 0;}