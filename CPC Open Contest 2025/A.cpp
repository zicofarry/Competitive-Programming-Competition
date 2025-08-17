#include <bits/stdc++.h>
typedef long long ll;
#define nl "\n"
#define sp ' '
#define slv solve();
#define zicofarry\
    ios::sync_with_stdio(false);\
    cin.tie(nullptr);
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(ll &i: a) cin >> i;
    sort(a.begin(), a.end());
    int ans = accumulate(a.begin(), a.end(), 0);
    while(m--){
        int k, l;
        cin >> k >> l;
        ll dis = 0;
        for(int i = n-k; i >= 0; i-=k){
            dis += a[i]*l/100;
        }
        cout << ans-dis << nl;
    }
}

int main(){zicofarry slv return 0;}