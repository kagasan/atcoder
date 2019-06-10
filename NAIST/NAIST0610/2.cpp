#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main(){
    
    for(ll N, M;cin>>N>>M,N;){
        vector<ll>vec(M + 1, 0);
         for(ll i = 0; i < N; i++){
            ll d, v;
            cin >> d >> v;
            vec[d] = max(vec[d], v);
        }
        ll ans = 0;
        for(ll i = 1; i <= M; i++)ans += vec[i];
        cout << ans << endl;
    }
    
    return 0;    
}