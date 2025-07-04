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

void solve(){
    int n; cin >> n;
    vi a(n);
    for(int &i : a) cin >> i;
    ll total = accumulate(a.begin(), a.end(), 0LL);
    ll maks = LLONG_MIN;
    vl doa(2*n);
    for(int i = 0; i < n; i++){
        doa[i] = a[i];
        doa[i+n] = a[i];
    }
    vl pref(2*n+1, 0);
    for(int i = 0; i < n*2; i++){
        pref[i+1] = pref[i] + doa[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < i+n; j++){
            ll sumA = pref[j] - pref[i];
            ll sumB = total - sumA;
            // DEBUG("a", sumA);
            // DEBUG("b", sumB);
            maks = max(maks, sumA*sumB);
        }
    }
    cout << maks << nl;

}

int main(){zicofarry slv return 0;}