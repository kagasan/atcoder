#include "bits/stdc++.h"
using namespace std;

typedef pair<double, int>DI;
typedef pair<int, int>II;
typedef pair<DI, II>DIII;

double dp[33][33][33];
vector<int>path[33];
int length[33][33];
int limit[33][33];
void init(){
    for(int i = 0; i < 33; i++){
        for(int j = 0; j < 33; j++){
            for(int k = 0; k < 33; k++){
                dp[i][j][k] = 5000;
            }
            length[i][j] = -1;
            limit[i][j] = -1;
        }
        path[i].clear();
    }
}

int main(){

    for(int n, m, s, g; cin >> n >> m, n;){
        cin >> s >> g;
        init();
        for(int i = 0; i < m; i++){
            int x, y, d, c;
            cin >> x >> y >> d >> c;
            path[x].push_back(y);
            length[x][y] = d;
            limit[x][y] = c;            
            path[y].push_back(x);
            length[y][x] = d;
            limit[y][x] = c;            
        }
        priority_queue<DIII, vector<DIII>, greater<DIII> >Q;
        Q.push(DIII(DI(0, 1), II(s, -1)));
        double ans = -1;
        while(!Q.empty()){
            double cost = Q.top().first.first;
            int v = Q.top().first.second;
            int now = Q.top().second.first;
            int pre = Q.top().second.second;
            Q.pop();
            if(dp[v][now][pre] < 4900)continue;
            dp[v][now][pre] = cost;
            // cout << "cost["<< v << "][" << now << "][" << pre << "] -> " << cost << endl;
            if(now == g && v==0){
                ans = cost;
                break;
            }
            if(v == 0)continue;
            for(int i = 0; i < path[now].size(); i++){
                int nxt = path[now][i];
                if(nxt == pre)continue;
                if(limit[now][nxt] < v)continue;
                double tim = (double)length[now][nxt] / v;
                for(int dv = -1; dv <= 1; dv++){
                    if(dp[v + dv][nxt][now] >= cost + tim){
                        Q.push(DIII(DI(cost + tim, v + dv), II(nxt, now)));
                    }
                }
            }
        }
        if(ans < 0)cout << "unreachable" << endl;
        else printf("%.9f\n", ans);
    }

    return 0;
}