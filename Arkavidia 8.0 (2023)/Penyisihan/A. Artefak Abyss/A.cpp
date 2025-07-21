#include <bits/stdc++.h>
#define DEBUG(str, var) cout << str << " = " << var << nl;
#define DEBAR(arr, n)                        \
    for(int i = 0; i < n; i++){              \
        cout << "arr[" << i << "] = " << arr[i] << nl;    \
    }
#define nl "\n"
#define sp ' '
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

int cury(int b, int y, int hasil){
    return hasil += b - y;
}

int curz(int c, int z, int hasil){
    return hasil = (hasil + c)/ z;
}

int sequentialSearch(int n, int arr[], int target)
{
    // deklarasi found dan idx
    int found = 0;      // buat flag
    int idx = 0;        // buat index


    // loop sampai ketemu elemen
    while(idx < n && found == 0)
    {
        // jika elemen ketemu maka set found ke 1
        if(arr[idx] == target)
        {
            found = 1;
        }
        // jika tidak maka iterasi index
        else
        {
            idx++;
        }
    }
    // return found (bisa juga return indexnya)
    return idx;
}


void solve(){
    din(n);
    din(m);
    din(k);
    din(p);
    din(y);
    din(z);
    int hasil = 0;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int b[m];
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    int c[k];
    for(int i = 0; i < k; i++){
        cin >> c[i];
    }

    if(!p){
        int ha = -1;
        for(int i = 0; i < n; i++){
            if(ha < a[i]){
                ha = a[i];
            }
        }

        int hc = -1;
        for(int i = 0; i < k; i++){
            if(hc < curz(c[i], z, hasil)){
                hc = curz(c[i], z, hasil);
            }
        }
        
        int hb = -1;
        for(int i = 0; i < m; i++){
            if(hb < cury(b[i], y, hasil)){
                hb = cury(b[i], y, hasil);
            }
        }
        
        DEBUG("ha", ha);
        DEBUG("hb", hb);
        DEBUG("hc", hc);
        if(ha > hb && ha > hc){
            hasil += ha;
        }else if(hb > ha && hb > hc){
            hasil += hb;
        }else if(hc > ha && hc > hb){
            hasil += hc;
        }
    }else{
        while(p > 0){
            int max = 0;
            for(int i = 0; i < k; i++){
                if(max < c[i]){
                    max = c[i];
                }
            }
            hasil += max;
            c[sequentialSearch(k, c, max)] = -1;
            p--;
        }
    }

    DEBUG("h", hasil);
}

int main(){zicofarry slv return 0;}