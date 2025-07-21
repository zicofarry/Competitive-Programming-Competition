#include <bits/stdc++.h>
#define DEBUG(str, var) cout << str << " = " << var << nl;
#define DEBAR(arr, n)                        \
    for(int i = 0; i < n; i++){              \
        cout << "arr[" << i << "] = " << arr[i] << nl;    \
    }
#define nl "\n"
#define sp ' '
#define ll long long
#define dig0(n) setw(n) << setfill('0')
#define vi vector<int>
#define vs vector<string>
#define sin(str)       \
    string str;        \
    cin >> str;
#define din(n)         \
    int n;             \
    cin >> n;
#define pb push_back
#define pob pop_back
#define slv solve();
#define zicofarry                \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using namespace std;

const int N = 100005;
vi adj[N], a(N), mn(N);

void trv(int p, int i, int pv){
    mn[i] = min(pv, a[i]);
    for(ll n : adj[i]){
        if(n == p) continue;
        trv(i, n, mn[i]);
    }
}

void solve(){
    ll n, x;
    cin >> n >> x;
    x--;

    for(ll i = 0 ; i < n; i++){
        cin >> a[i];
    }

    ll u, v;
    for(ll i = 0; i < n - 1; i++){
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    trv(-1, x, 1000000005);
    for(ll i = 0; i < n; i++) cout << mn[i] << sp;

}

int main(){zicofarry slv return 0;}