#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define tpl tuple<ll, ll, ll> // (posisi, waktu, teleportasi)
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
#define zicofarry\
    ios::sync_with_stdio(false);\
    cin.tie(nullptr);
using namespace std;

void solve(){
    ll N, K, L, X, Y, Z;
    cin >> N >> K >> L >> X >> Y >> Z;
    
    vector<ll> A(N);
    for (ll &a : A) cin >> a;
    
    // Priority Queue Min-Heap -> (teleportasi, waktu, posisi)
    priority_queue<tpl, vector<tpl>, greater<tpl>> pq;
    pq.push({0, 0, 0}); // (0 teleportasi, 0 waktu, mulai dari 0)

    // DP table: dp[pos][tele] = waktu minimum untuk mencapai `pos` dengan `tele` teleportasi
    unordered_map<ll, unordered_map<ll, ll>> dp;

    while (!pq.empty()) {
        ll tele = get<0>(pq.top());
        ll time = get<1>(pq.top());
        ll pos  = get<2>(pq.top());
        pq.pop();

        // Jika sudah sampai ke tujuan K dalam waktu yang cukup
        if (pos >= K) {
            if (time <= Y) {
                cout << tele << nl;
                return;
            }
            continue;
        }

        // Jika sudah pernah mengunjungi `pos` dengan `tele` teleportasi lebih optimal, skip
        if (dp[pos].count(tele) && dp[pos][tele] <= time) continue;
        dp[pos][tele] = time;

        // Langkah 1: Berjalan ke depan (pos + 1)
        if (time + 1 <= Y) {
            pq.push({tele, time + 1, pos + 1});
        }

        // Langkah 2: Teleportasi dari portal terdekat
        if (tele < Z) {
            auto it = lower_bound(A.begin(), A.end(), pos);

            // Cek apakah portal sebelumnya lebih dekat
            if (it != A.begin() && (it == A.end() || abs(*prev(it) - pos) < abs(*it - pos))) {
                --it;
            }

            if (it != A.end()) {
                ll idx = it - A.begin();

                // Coba semua portal dalam range L
                for (ll j = idx; j < min(N, idx + L + 1); j++) {
                    ll newPos = A[j];
                    ll newTime = time + X;

                    if (newTime <= Y) {
                        pq.push({tele + 1, newTime, newPos});
                    }
                }
            }
        }
    }

    // Jika tidak bisa mencapai K
    cout << "-1\n";

}

// soal bfs
int main(){zicofarry slv return 0;}