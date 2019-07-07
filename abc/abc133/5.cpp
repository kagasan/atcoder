#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};
const ll MOD = 1000000007;

vector<ll>path[101010];
ll flg[101010];
ll ans = 1;
ll N, K;

void dfs(ll idx, ll lst1, ll lst2){
    ll tmp = K - lst1 - lst2;
    if(tmp <= 0)ans = 0;
    else ans = (ans * tmp) % MOD;
    ll cnt = 0;
    for(ll i = 0; i < path[idx].size(); i++){
        ll to = path[idx][i];
        if(flg[to])continue;
        flg[to] = 1;
        dfs(to, 1, lst1 + cnt);
        cnt++;
    }
}

int main(){

    cin >> N >> K;
    for(ll i = 1; i < N; i++){
        ll a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    flg[1] = 1;
    dfs(1, 0, 0);
    cout << ans << endl;

    return 0;
}