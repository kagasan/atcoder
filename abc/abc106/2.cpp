#include "bits/stdc++.h"
using namespace std;
typedef long long ll;


int main(){
    
    ll N;
    cin >> N;
    ll ans = 0;
    for(ll i = 1; i <= N; i+=2){
        ll cnt = 0;
        for(ll j = 1; j <= i; j++){
            if(i % j == 0)cnt++;
        }
        if(cnt == 8)ans++;
    }
    cout << ans << endl;
    
    return 0;
}