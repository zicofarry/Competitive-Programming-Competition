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

void solve(){
    ll n, x;
    cin >> n >> x;
    ll a[n];
    for(ll i = 0 ; i < n; i++){
        cin >> a[i];
    }

    ll u[n-1];
    ll v[n-1];
    for(ll i = 0; i < n - 1; i++){
        cin >> u[i]>> v[i];
    }

    for(ll i = 0; i < n; i++){
        int min;
        if(i < x){
            min = a[x-1];
            for(ll j = i; j < x; j++){
                if(min > a[j]) min = a[j];
            }
        }else{
            min = a[x-1];
            for(ll j = i; j >= x - 1; j--){
                if(min > a[j]) min = a[j];
            }
        }
        if(i != n - 1){
            cout << min << sp;
        }else{
            cout << min << nl;
        }
    }

}

int main(){zicofarry slv return 0;}