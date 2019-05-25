#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll N;
    cin >> N;
    vector<ll>A(N), B(N);
    for(ll i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }
    ll ans = 0;
    vector<ll>v;
    for(ll i = 1; i * i <= A[0]; i++){
        if(A[0] % i == 0){
            v.push_back(i);
            if(A[0] == i * i)continue;
            v.push_back(A[0] / i);
        }
    }
    for(ll i = 1; i * i <= B[0]; i++){
        if(B[0] % i == 0){
            v.push_back(i);
            if(B[0] == i * i)continue;
            v.push_back(B[0] / i);
        }
    }
    for(ll i = 0; i < v.size(); i++){
        ll flg = 1;
        for(ll j = 0; j < N; j++){
            if((A[j] % v[i]) && (B[j] % v[i])){
                flg = 0;
                break;
            }
        }
        if(flg)ans = max(ans, v[i]);
    }
    cout << ans << endl;

    return 0;
}
