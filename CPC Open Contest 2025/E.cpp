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
    int w, h;
    cin >> w >> h;
    vector<vector<int>> grid(h, vector<int> (w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) cin >> grid[i][j];
    }

    int ans = 0;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(grid[i][j] == 1){
                ans++;
                stack<pair<int, int>> st;
                st.push({i, j});
                grid[i][j] = 0;
                while(!st.empty()){
                    auto [x, y] = st.top();
                    st.pop();
                    for(int d = 0; d < 4; d++){
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        if(nx >= 0 && nx < h && ny>= 0 && ny<w && grid[nx][ny] == 1){
                            grid[nx][ny] = 0;
                            st.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    cout << ans << nl;
}

int main(){zicofarry slv return 0;}