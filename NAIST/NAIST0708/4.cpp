#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

vector<ll>path[101010];
ll depth[2][101010];

ll cnt[2][101010];

int main(){
    for(ll i = 0; i < 101010; i++){
        depth[0][i] = -1;
        depth[1][i] = -1;
    }
    ll N, M, s, t;
    cin >> N >> M >> s >> t;
    for(ll i = 0; i < M; i++){
        ll x, y;
        cin >> x >> y;
        path[x].push_back(y);
        path[y].push_back(x);
    }
    for(ll i = 0; i < 2; i++){
        queue<ll>Q;
        if(i==0){
            Q.push(s);
            depth[i][s] = 0;
        }
        else{
            Q.push(t);
            depth[i][t] = 0;
        }
        while(!Q.empty()){
            ll idx = Q.front();
            Q.pop();
            cnt[i][depth[i][idx]]++;
            for(ll j = 0; j < path[idx].size(); j++){
                ll nxt = path[idx][j];
                if(depth[i][nxt] >= 0)continue;
                depth[i][nxt] = depth[i][idx] + 1;
                Q.push(nxt);
            }
        }
    }
    ll mn = depth[1][s];
    ll ans = 0;
    for(ll a = 0; a <= N; a++){
        ll b = mn - a - 2;
        if(b < 0)continue;
        ans += cnt[0][a] * cnt[1][b];
    }
    cout << ans << endl;
    
    return 0;    
}