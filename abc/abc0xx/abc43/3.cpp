#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll N;
    cin >> N;
    vector<ll>a(N);
    for(ll i = 0; i < N; i++)cin >> a[i];
    ll ans = 1145141919;
    for(ll x = -100; x <= 100; x++){
        ll tmp = 0;
        for(ll i = 0; i < N; i++)tmp += (x - a[i]) * (x - a[i]);
        ans = min(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}
