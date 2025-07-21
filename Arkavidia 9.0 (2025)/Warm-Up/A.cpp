#include <bits/stdc++.h>
#define ll long long 
#define ull unsigned long long
#define vi vector<int>
#define vs vector<string>
#define pi pair<int,int>;
#define DEBUG(str, var) cout << str << " = " << var << nl;
#define DEBAR(arr, n)                        \
    for(int i = 0; i < n; i++){              \
        cout << "arr[" << i << "] = " << arr[i] << nl;    \
    }
#define nl "\n"
#define sp ' '
#define dig0(n) setw(n) << setfill('0')
#define sin(str)       \
    string str;        \
    cin >> str;
#define din(n)         \
    int n;             \
    cin >> n;
#define pb push_back
#define pob pop_back
#define slv solve();
#define tc        						\
    freopen("input.txt", "r", stdin); 	\
    freopen("output.txt", "w", stdout); \
    int t;        						\
    cin >> t;     						\
    while (t--) { 						\
        solve();  						\
    }
#define zicofarry                \
    ios::sync_with_stdio(false); \
    cin.tie(0);
using namespace std;

void solve(){
    ll n;
    ll a[100005];
    cin >> n;
    ll ans = n*(n-1)/2;

    for(ll i = 0; i < n; i++){
        ll m, c;
        cin >> m >> c;
        a[i] = m;
    }

    sort(a, a+n);
    ll count = 1;
    for(int i = 1; i < n; i++){
        if(a[i] != a[i-1]){
            ans -= count * (count-1)/2;
            count = 0;
        }
        count++;
    }

    ans -= count * (count-1)/2;
    cout << ans << nl;
}

int main(){zicofarry slv return 0;}