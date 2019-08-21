#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N;
    cin >> N;
    vector<ll>X(N + 1);
    vector<ll>flg(2020, 0);
    for(ll i = 1; i <= N; i++){
        cin >> X[i];
        flg[X[i]] = 1;
    }
    ll M;
    cin >> M;
    for(ll i = 0; i < M; i++){
        ll A;
        cin >> A;
        if(X[A] == 2019)continue;
        if(flg[X[A] + 1])continue;
        flg[X[A] + 1] = 1;
        flg[X[A]] = 0;
        X[A]++;
    }
    for(ll i = 1; i <= N; i++){
        cout << X[i] << endl;
    }
    
    
    return 0;    
}