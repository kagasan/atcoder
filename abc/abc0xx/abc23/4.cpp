#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll N;
    cin >> N;
    vector<ll>H(N), S(N);
    ll ng = -1, ok = 0;
    for(ll i = 0; i < N; i++){
        cin >> H[i] >> S[i];
        ok = max(ok, H[i] + S[i] * (N - 1));
    }
    while(ng + 1 < ok){
        ll p = (ng + ok) / 2;
        ll flg = 1;
        vector<ll>tmp(N);
        for(ll i = 0; i < N; i++){
            if(p - H[i] < 0)tmp[i] = -1;
            else tmp[i] = (p - H[i]) / S[i];
        }
        sort(tmp.begin(), tmp.end());
        for(ll i = 0; i < N; i++)if(tmp[i] < i)flg = 0;
        if(flg)ok = p;
        else ng = p;
    }
    cout << ok << endl;

    return 0;
}
