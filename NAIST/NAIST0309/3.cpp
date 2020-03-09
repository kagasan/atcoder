// https://algo-logic.info/bridge-lowlink/
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> V;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

ll N;
V path[101010];
ll used[101010];
ll ord[101010];
ll low[101010];
ll br = 0;

ll dfs(ll id, ll k, ll par){
    used[id] = 1;
    ord[id] = k++;
    low[id] = ord[id];
    bool is_aps = false;
    ll cnt = 0;
    for(auto to : path[id]){
        if(used[to] == 0){
            cnt++;
            k = dfs(to, k, id);
            chmin(low[id], low[to]);
            if (par != -1 && ord[id] <= low[to]) is_aps = true;
            if (ord[id] < low[to])br++;
        }
        else if(to != par){
            chmin(low[id], ord[to]);
        }
    }
    if (par == -1 && cnt >= 2) is_aps = true;
    return k;
}

ll lowlink(){
    ll k = 0;
    ll cnt = 0;
    rep(i, N)if(used[i] == 0){
        k = dfs(i, k, -1);
        cnt++;
    }
    if(cnt == 1)return 1;
    if(cnt == 2 && br == 0)return 1;
    return 0;
}

int main(){

    cin >> N;
    rep(i, N - 1){
        ll a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    if(lowlink())cout << "Bob" << endl;
    else cout << "Alice" << endl;
    
    return 0;
}