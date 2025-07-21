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

ll n, nn = 0, a[100005],fz[269], inf = 1e18;

void solve(){
    ll t, r, i, k, l, gd = 0, mn = inf;

    scanf("%lld", &n);
    for(i = 1; i <= n; i++){
        scanf("%lld", a+i);
        mn = min(mn, a[i]);
    }
    for(i = 1; i <= n; i++){
        gd = __gcd(gd, a[i]-mn);
    }
    for(i = 1; i*i <= gd; i++){
        if(gd%i == 0){
            fz[nn+1] = i;
            fz[nn+2] = gd/i;
            nn+=2;
        }
    }

    sort(fz + 1, fz + nn + 1);
    scanf("%lld", &t);
    for(r = 0; r < t; r++){
        scanf("%lld %lld", &k, &l);
        k += mn;
        l += mn;
        if(gd){
            for(i = nn; i; i--){
                if(l/fz[i] - (k - 1)/fz[i]){
                    break;
                }
            }
            printf("%lld\n", fz[i]);
        }else{
            printf("%lld\n", l);
        }
    }
}

int main(){zicofarry; slv; return 0;}