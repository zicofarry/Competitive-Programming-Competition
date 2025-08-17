#include <bits/stdc++.h>
typedef long long ll;
#define nl "\n"
#define sp ' '
#define slv solve();
#define zicofarry\
    ios::sync_with_stdio(false);\
    cin.tie(nullptr);
using namespace std;

void solve(){
    string s;
    ll l;
    cin >> s >> l;
    string r1, r2;
    cin >> r1 >> r2;
    
    ll iq = 0;
    for(int i = 0; i+1 < (int)s.size(); i++){
        int a = s[i] - 'A' +1;
        int b = s[i+1] - 'A' +1;
        if(a!=b) iq += 1LL*a*b;
    }

    if(iq>=l) cout << r1 << nl;
    else cout << r2 << nl;
}

int main(){zicofarry slv return 0;}