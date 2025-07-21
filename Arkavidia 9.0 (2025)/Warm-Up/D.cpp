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

ll gcd(ll x, ll y){
    if (y == 0) return x;
    else return gcd(y, x % y);
}

ll lcm(ll x, ll y){
    return x * y/gcd(x, y);
}

void solve(){
    ll n, m, a, b, c;
    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        m = a/lcm(b,c);
        cout << (a/b) - m << sp << (a/c) - m << nl;
    }
}

int main(){zicofarry slv return 0;}