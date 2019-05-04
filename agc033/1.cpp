#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;


typedef pair<int, int>P;
typedef pair<int, P>IP;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int H, W;
char mp[1010][1010];
int ans = 0;
int cnt = 0;
int main(){
    for(int i = 0; i < 1010; i++){
        for(int j = 0; j < 1010; j++){
            mp[i][j] = '@';
        }
    }
    cin >> H >> W;
    queue<IP>Q;
    for(int y = 1; y <= H; y++){
        for(int x = 1; x <= W; x++){
            cin >> mp[y][x];
            if(mp[y][x] == '#'){
                mp[y][x] = '.';
                Q.push(IP(0, P(x, y)));
            }
        }
    }
    while(cnt < H * W){
        while(!Q.empty()){
            int cost = Q.front().first;
            int x = Q.front().second.first;
            int y = Q.front().second.second;
            Q.pop();
            if(mp[y][x] == '#')continue;
            mp[y][x] = '#';
            cnt++;
            ans = cost;
            for(int i = 0; i < 4; i++){
                int xx = x + dx[i];
                int yy = y + dy[i];
                if(mp[yy][xx] == '.'){
                    Q.push(IP(cost + 1, P(xx, yy)));
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
