#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

vector<ll>path[101010];
ll flg[101010];

int main(){

    ll N, M;
    cin >> N >> M;
    ll ans = 0;
    for(ll i = 0; i < M; i++){
        ll x, y, z;
        cin >> x >> y >> z;
        path[x].push_back(y);
        path[y].push_back(x);
    }
    for(ll i = 1; i <= N; i++){
        if(flg[i])continue;
        ans++;
        flg[i] = 1;
        stack<ll>S;
        S.push(i);
        while(!S.empty()){
            ll idx = S.top();
            S.pop();
            for(ll i = 0; i < path[idx].size(); i++){
                ll nxt = path[idx][i];
                if(flg[nxt])continue;
                flg[nxt] = 1;
                S.push(nxt);
            }
        }
    }

    cout << ans << endl;

    return 0;
}