#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N, K;
    cin >> N >> K;
    ll one;
    for(ll i = 1; i <= N; i++){
        ll a;
        cin >> a;
        if(a == 1)one = i;
    }
    for(ll i = 1; ; i++){
        if(K * i - (i - 1) >= N){
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}