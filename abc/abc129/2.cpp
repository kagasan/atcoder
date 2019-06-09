#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll ans = 1145141919;
    ll N;
    cin >> N;
    vector<ll>vec(N, 0);
    for(ll i = 0; i < N; i++)cin >> vec[i];
    for(ll i = 0; i + 1 < N; i++){
        ll a = 0, b = 0;
        for(ll j = 0; j < N; j++){
            if(j <= i)a += vec[j];
            else b += vec[j];
        }
        ans = min(ans, abs(a - b));
    }
    cout << ans << endl;

    return 0;
}