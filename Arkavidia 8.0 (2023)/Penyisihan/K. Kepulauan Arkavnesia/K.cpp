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

const int MAX = 100005;
ll parent[MAX], sz[MAX], telCost[MAX];
multiset<ll> compMin[MAX]; // Multiset untuk menyimpan nilai terkecil

// Fungsi DSU: Find dengan Path Compression
ll find(ll u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

// DSU Union dengan Union by Size
void unionSets(ll u, ll v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (sz[u] < sz[v]) swap(u, v); // Union by size
        parent[v] = u;
        sz[u] += sz[v];

        // Gabungkan multiset dengan lebih aman
        for (ll x : compMin[v]) {
            compMin[u].insert(x);
        }
        compMin[v].clear();
    }
}

void solve(){
    ll n; cin >> n;
    ll m; cin >> m;
    ll q; cin >> q;
    for (ll i = 1; i <= n; i++) {
        cin >> telCost[i];
        parent[i] = i;
        sz[i] = 1;
        compMin[i].insert(telCost[i]); // Set harga awal dalam multiset
    }
    for(ll i = 0; i < m; i++){
        ll u; cin >> u;
        ll v; cin >> v;
        unionSets(u, v);
    }

    while(q--){
        ll t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            // Update harga teleportasi di node u
            int root = find(u);
            compMin[root].erase(compMin[root].find(telCost[u])); // Hapus harga lama di node u
            telCost[u] = v;
            compMin[root].insert(v); // Masukkan harga baru
        } else if (t == 2) {
            if (find(u) == find(v)) {
                cout << 0 << "\n";
            } else {
                cout << (*compMin[find(u)].begin()) + (*compMin[find(v)].begin()) << "\n";
            }
        }
    }
}

// soal djikstra / dsu
int main(){zicofarry slv return 0;}