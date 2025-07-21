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
#define sz size
#define slv solve();
#define zicofarry\
    ios::sync_with_stdio(false);\
    cin.tie(nullptr);
using namespace std;
const int N = 1e5;
vl adj[N+1], a(N+1), mn(N+1);

void trv(ll p, ll i, ll pv){
    mn[i] = min(pv, a[i]);
    for(ll n : adj[i]){
        if(n == p) continue;
        trv(i, n, mn[i]);
    }
}

void solve(){
    ll n; cin >> n;
    ll x; cin >> x;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    
    for(ll i = 1; i <= n-1; i++){
        ll u; cin >> u;
        ll v; cin >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    trv(-1, x, LLONG_MAX);
    for(ll i = 1; i <= n; i++) cout << mn[i] << sp;
    cout << nl;
}

int main(){zicofarry slv return 0;}