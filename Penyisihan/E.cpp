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

const ll INF = 1e18;

struct Line{
    ll m, b;
    ll eval(ll x) const {return m * x + b;}
};

struct Node{
    Line line;
    Node *l, *r;
    Node(Line _line) : line(_line), l(nullptr), r(nullptr) {}
};

struct act{
    Node* root;
    ll x_left, x_right;

    act(ll _l, ll _r) : x_left(_l), x_right(_r){ root = nullptr;}

    void insert(Line newLine){ insert(root, x_left, x_right, newLine);}

    void insert(Node*& node, ll l, ll r, Line newLine){
        if (!node) {
            node = new Node(newLine);
            return;
        }
        ll mid = (l + r)/2;
        bool leftBetter = newLine.eval(l) < node->line.eval(l);
        bool midBetter = newLine.eval(mid) < node->line.eval(mid);

        if(midBetter) swap(node->line, newLine);

        if(r - l == 1) return;
        if(leftBetter != midBetter) insert(node->l, l, mid, newLine);
        else insert(node->r, mid, r, newLine);
    }

    ll inp(ll x){ return inp(root, x_left, x_right, x);}

    ll inp(Node* node, ll l, ll r, ll x){
        if (!node) return INF;
        if (r - l == 1) return node->line.eval(x);
        ll mid = (l + r) / 2;
        if (x < mid) return min(node->line.eval(x), inp(node->l, l, mid, x));
        else return min(node->line.eval(x), inp(node->r, mid, r, x));
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    vector<ll> dp(n);
    act cht(0, n + 1);

    dp[0] = 0;
    cht.insert({a[0], 0});

    for(int i = 1; i < n; i++){
        dp[i] = cht.inp(i);
        cht.insert({a[i], dp[i] - 1LL * a[i] * i});
    }

    cout << dp[n - 1] << nl;
}

int main(){zicofarry slv return 0;}