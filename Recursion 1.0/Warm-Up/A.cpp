#include <bits/stdc++.h>
typedef long long ll;
typedef std::vector<ll> vl;
#define nl "\n"
#define zicofarry ios::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

void solve() {
    ll n;
    cin >> n;
    vl a(n);
    for (ll &i : a) cin >> i;

    ll maxi = LLONG_MIN; // Hasil maksimum
    ll tot = 0;
    ll i = 0;

    while (i < n) {
        ll j = i;
        tot = a[j]; // Mulai dari elemen pertama di segmen ini
        maxi = max(maxi, tot); // Update hasil maksimum

        // Loop selama masih ada pola ganjil-genap / genap-ganjil
        while (j + 1 < n && ((a[j] % 2 + 2) % 2 != (a[j + 1] % 2 + 2) % 2)) {
            j++;
            tot += a[j];

            // Jika total jadi negatif, reset segmen
            if (tot < 0) {
                tot = 0;
                break; // Keluar dari loop lebih awal
            }

            maxi = max(maxi, tot); // Update hasil maksimum
        }

        i = j + 1; // Pindah ke elemen berikutnya setelah segmen selesai
    }

    cout << maxi << nl;
}

int main() {
    zicofarry
    solve();
    return 0;
}
