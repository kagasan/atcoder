#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N, P;
    cin >> N >> P;
    if(N == 1){
        cout << P << endl;
        return 0;
    }
    ll ans = 1;
    for(ll i = 2; i * i <= P; i++){
        ll cnt = 0;
        while(P % i == 0){
            P /= i;
            cnt++;
            if(cnt >= N){
                cnt = 0;
                ans *= i;
            }
        }
    }
    cout << ans << endl;

    return 0;
}