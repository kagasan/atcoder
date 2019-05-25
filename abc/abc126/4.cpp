#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

class edge{
    public:
    ll to;
    ll weight;
    edge(ll t, ll w){
        to = t;
        weight = w;
    }
};
vector<edge>path[101010];


int main(){

    ll N;
    cin >> N;
    for(ll i = 1; i < N; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        path[u].push_back(edge(v, w));
        path[v].push_back(edge(u, w));
    }
    vector<ll>ans(N + 1, 2);
    stack<ll>S;
    S.push(1);
    ans[1] = 0;
    while(!S.empty()){
        ll idx = S.top();
        S.pop();
        for(int i = 0; i < path[idx].size(); i++){
            int nxt = path[idx][i].to;
            int w = path[idx][i].weight;
            if(ans[nxt] < 2)continue;
            S.push(nxt);
            ans[nxt] = ans[idx];
            if(w % 2)ans[nxt] = (ans[nxt] + 1) % 2;
        }
    }
    for(int i = 1; i <= N; i++)cout << ans[i] << endl;

    return 0;
}