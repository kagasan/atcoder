#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

vector<ll>X[101010], Y[101010];

int main(){

    ll N;
    cin >> N;
    vector<ll>x(N), y(N), flg(N, 0);
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        cin >> x[i] >> y[i];
        X[x[i]].push_back(i);
        Y[y[i]].push_back(i);
    }    
    for(ll i = 0; i < N; i++){
        if(flg[i])continue;
        ll cnt = 1;
        flg[i] = 1;
        set<ll>XS;
        set<ll>YS;
        XS.insert(x[i]);
        YS.insert(y[i]);
        queue<ll>Q;
        Q.push(i);
        while(!Q.empty()){
            ll xx = x[Q.front()];
            ll yy = y[Q.front()];
            Q.pop();
            for(ll j = 0; j < X[xx].size(); j++){
                ll k = X[xx][j];
                if(flg[k])continue;
                cnt++;
                flg[k] = 1;
                YS.insert(y[k]);
                Q.push(k);
            }
            for(ll j = 0; j < Y[yy].size(); j++){
                ll k = Y[yy][j];
                if(flg[k])continue;
                cnt++;
                flg[k] = 1;
                XS.insert(X[k]);
                Q.push(k);
            }
        }
        ans += XS.size() * YS.size() - cnt;
    }
    cout << ans << endl;

    return 0;
}