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
#define ttc\
    int tc;\
    cin >> tc;\
    precomputeFactorial();\
    while (tc--){\
        solve();\
    }
#define zicofarry\
    ios::sync_with_stdio(false);\
    cin.tie(nullptr);
using namespace std;

// Konstanta global
const ll maxn = 2e6 + 5; // Maksimum nilai n untuk faktorial
const ll mod = 1e9 + 7;  // Modulo untuk menghindari overflow

// Variabel global untuk input
ll k, xa, ya, xb, yb;
ll fac[maxn]; // Array untuk menyimpan faktorial dengan modulo

// **Precom Faktorial**
void precomputeFactorial() {
    fac[0] = 1; // 0! = 1
    for (ll i = 1; i < maxn; i++) {
        fac[i] = (fac[i - 1] * i) % mod; // Menghitung faktorial dengan modulo
    }
}

// **Perpangkatan Modular (b^e % mod) menggunakan Eksponensiasi Biner**
ll expoModular(ll b, ll e) {
    ll ans = 1;
    while (e > 0) {
        if (e % 2 == 1) { // Jika pangkat ganjil, kalikan hasil dengan b
            ans = (ans * b) % mod;
        }
        b = (b * b) % mod; // Kuadratkan b dan ambil modulo
        e /= 2; // Bagi pangkat e dengan 2
    }
    return ans;
}

// **invers Modular menggunakan Teorema Fermat**
ll inversModular(ll x) {
    return expoModular(x, mod - 2); // Menghitung x^(-1) mod mod
}

// **Kombinasi C(n, k) = n! / (k! * (n-k)!) menggunakan modular inversModularerse**
ll C(ll n, ll k) {
    if (k > n) return 0; // Jika k lebih besar dari n, hasilnya 0
    return (fac[n] * inversModular(fac[k]) % mod * inversModular(fac[n - k]) % mod) % mod;
}

// **Fungsi utama untuk menyelesaikan satu test case**
void solve() {
    cin >> k >> xa >> ya >> xb >> yb; // Input nilai k dan koordinat (xa, ya) -> (xb, yb)
    
    // Koreksi posisi koordinat dengan mengurangi k
    ya -= k;
    yb -= k;
    k = 0; // Reset nilai k agar tidak mempengaruhi perhitungan

    // **Kasus yang tidak valid, langsung print 0**
    if (xa == ya || xb == yb || xa > xb || ya > yb || (xa > ya) - (xb > yb) != 0) {
        cout << 0 << nl;
        return;
    }

    // Swap koordinat agar ya selalu lebih kecil
    if (ya > xa){swap(xa, ya); swap(xb, yb);}

    // **Hitung jumlah jalur yang mungkin menggunakan kombinasi**
    ll result = C(xb - xa + yb - ya, xb - xa);

    // Jika yb lebih besar atau sama dengan xa, perlu dikoreksi dengan mengurangkan jalur tidak valid
    if (yb >= xa) {
        result = (result - C(xb - ya + yb - xa, xb - ya) + mod) % mod;
    }

    cout << result << nl; // Output hasil akhir
}


int main(){zicofarry ttc return 0;}