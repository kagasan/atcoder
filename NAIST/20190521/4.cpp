#include "bits/stdc++.h"
using namespace std;
typedef pair<int, int> P;
typedef pair<P, P> PP;


// 0 : left, 1 : right
int dx[2][9] = {
    {1,1,1,1,1,2,2,2,3}, 
    {-1,-1,-1,-1,-1,-2,-2,-2,-3}
};
int dy[2][9] = {
    {2,1,0,-1,-2,1,0,-1,0},
    {2,1,0,-1,-2,1,0,-1,0}
};

char mp[100][100];
int cost[2][100][100];
void init(){
    for(int y = 0; y < 100; y++){
        for(int x = 0; x < 100; x++){
            mp[y][x] = 'X';
            cost[0][y][x] = 11451419;
            cost[1][y][x] = 11451419;
        }
    }
}

int main(){

    for(int w, h; cin >> w >> h, w; ){
        init();
        priority_queue<PP, vector<PP>, greater<PP> >Q;
        for(int y = 1 + 10; y <= h + 10; y++){
            for(int x = 1 + 10; x <= w + 10; x++){
                cin >> mp[y][x];
                if(mp[y][x] == 'S'){
                    Q.push(PP(P(0, 0), P(x, y)));
                    Q.push(PP(P(0, 1), P(x, y)));
                }
            }
        }
        int ans = 11451419;
        while(!Q.empty()){
            int cst = Q.top().first.first;
            int lr = Q.top().first.second;
            int x = Q.top().second.first;
            int y = Q.top().second.second;
            Q.pop();
            if(cost[lr][y][x] < 11451419)continue;
            cost[lr][y][x] = cst;
            if(mp[y][x] == 'T'){
                ans = cst;
                break;
            }
            for(int i = 0; i < 9; i++){
                int nx = x + dx[lr][i];
                int ny = y + dy[lr][i];
                if(mp[ny][nx] == 'X')continue;
                if(cost[lr ^ 1][ny][nx] < 11451419)continue;
                int ncst = cst;
                if('0' <= mp[ny][nx] && mp[ny][nx] <= '9'){
                    ncst += mp[ny][nx] - '0';
                }
                Q.push(PP(P(ncst, lr ^ 1), P(nx, ny)));
            }
        }
        if(ans == 11451419)cout << -1 << endl;
        else cout << ans << endl;
    }

    return 0;
}