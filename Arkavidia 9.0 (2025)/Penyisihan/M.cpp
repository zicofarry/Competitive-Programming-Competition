#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;
const int MAXA = 200005;

ll N;
vector<int> A;
vector<int> freq(MAXA, 0);
vector<ll> cnt(MAXA, 0);

ll mod_pow(ll a, ll b, ll mod) {
    ll res = 1;
    a = a % mod;
    while (b > 0) {
        if (b % 2 == 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b = b / 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        freq[A[i]]++;
    }

    for (ll d = MAXA - 1; d >= 1; d--) {
        ll total = 0;
        for (ll multiple = d; multiple < MAXA; multiple += d) {
            total += freq[multiple];
        }
        cnt[d] = (1LL * total * (total - 1) / 2);
    }

    for (ll d = MAXA - 1; d >= 1; d--) {
        for (ll multiple = 2 * d; multiple < MAXA; multiple += d) {
            cnt[d] -= cnt[multiple];
        }
        if (cnt[d] < 0) cnt[d] = 0;
    }

    ll result = 1;
    for (ll d = 1; d < MAXA; d++) {
        if (cnt[d] > 0 && d > 0) {
            result = (result * mod_pow(d, cnt[d], MOD)) % MOD;
        }
    }

    cout << result << '\n';
    return 0;
}