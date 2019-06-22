#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll N, M;
    cin >> N >> M;
    ll path[9][9] = {};
    for(ll i = 0; i < M; i++){
        ll a, b;
        cin >> a >> b;
        path[a][b] = 1;
        path[b][a] = 1;
    }
    ll ans = 0;
    vector<ll>v;
    for(ll i = 1; i <= N; i++)v.push_back(i);
    do{
        ll flg = 1;
        if(v[0] != 1)flg = 0;
        for(ll i = 1; i < N; i++){
            if(path[v[i - 1]][v[i]] == 0)flg = 0;
        }
        if(flg)ans++;
    }while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;

    return 0;
}
