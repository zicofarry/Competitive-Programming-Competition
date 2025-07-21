#include <bits/stdc++.h>
#define nl "\n"
#define sp ' '
#define ll long long
#define slv solve();
#define zicofarry                \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using namespace std;

void solve(){
    ll n, k, w, ans = LLONG_MAX; // declare
    cin >> n >> k; 
    for(ll i = 0; i < n; i++){
        cin >> w;
        ll tmp = k, sihir = 0;
        while(tmp > w){
            tmp /= 2;
            sihir++;
        }
        sihir += (w - tmp);
        ans = min(ans, sihir);
    }
    cout << ans << nl;
}

int main(){zicofarry slv return 0;}