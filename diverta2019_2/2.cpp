#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N;
    cin >> N;
    ll ans = 100;
    vector<ll>X(N), Y(N);
    for(ll i = 0; i < N; i++){
        cin >> X[i] >> Y[i];
    }
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            ll p = X[j] - X[i];
            ll q = Y[j] - Y[i];
            ll cnt = 0;
            vector<ll>flg(N, 0);
            for(ll k = 0; k < N; k++){
                if(flg[k])continue;
                queue<ll>Q;
                cnt++;
                flg[k] = 1;
                Q.push(k);
                while(!Q.empty()){
                    ll idx = Q.front();
                    Q.pop();
                    for(ll l = 0; l < N; l++){
                        if(flg[l])continue;
                        if(X[idx] + p == X[l] && Y[idx] + q == Y[l]){
                            flg[l] = 1;
                            Q.push(l);
                        }
                        if(X[idx] - p == X[l] && Y[idx] - q == Y[l]){
                            flg[l] = 1;
                            Q.push(l);
                        }
                        
                    }
                }
            }
            ans = min(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}