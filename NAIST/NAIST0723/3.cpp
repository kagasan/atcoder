#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;

ll N, M, T;
ll st[3] = {1, 0, 0};
vector<P>path[2020];
ll cost[3][2020];

int main(){

    cin >> N >> M >> st[1] >> st[2] >> T;
    for(ll i = 0; i < M; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        path[a].push_back(P(b, c));
        path[b].push_back(P(a, c));
    }
    for(ll i = 0; i < 3; i++){
        for(ll j = 0; j < 2020; j++)cost[i][j] = -1;
        priority_queue<P, vector<P>, greater<P> >Q;
        Q.push(P(0, st[i]));
        while(!Q.empty()){
            ll idx = Q.top().second;
            ll cst = Q.top().first;
            Q.pop();
            if(cost[i][idx] >= 0)continue;
            cost[i][idx] = cst;
            for(ll j = 0; j < path[idx].size(); j++){
                ll nxt = path[idx][j].first;
                ll w = path[idx][j].second;
                if(cost[i][nxt] < 0){
                    Q.push(P(cst + w, nxt));
                }
            }
        }
    }
    ll ans = -1;
    for(ll a = 1; a <= N; a++){
        for(ll b = a; b <= N; b++){
            ll tmp = cost[0][a] + cost[0][b];
            ll P = cost[1][a] + cost[1][b];
            ll Q = cost[2][a] + cost[2][b];
            if(tmp + P + Q <= T)ans = T;
            else if(tmp + max(P, Q) <= T)ans = max(ans, T - max(P, Q));
        }
    }
    cout << ans << endl;
    
    return 0;    
}