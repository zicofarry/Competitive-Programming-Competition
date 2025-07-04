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
    for (int &i : a) cin >> i;
    ll total = accumulate(a.begin(), a.end(), 0LL);
    ll maks = LLONG_MIN;
    ll curr = 0;

    for (int i = 0; i < n; i++) {
        curr += a[i];
        ll sumB = total - curr;
        if (sumB != 0) maks = max(maks, curr * sumB);
    }

    vi doa(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        doa[i] = a[i % n];
    }

    curr = 0;
    int left = 0;
    for (int right = 0; right < 2 * n; right++) {
        curr += doa[right];
        while (curr > total / 2 && left <= right) {
            ll sumB = total - curr;
            if (sumB != 0) maks = max(maks, curr * sumB);
            curr -= doa[left];
            left++;
        }
    }
    cout << maks << nl;

}

int main(){zicofarry slv return 0;}