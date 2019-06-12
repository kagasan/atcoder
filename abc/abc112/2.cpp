#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;

int main(){
    
    ll N, T;
    cin >> N >> T;
    ll ans = 1919;
    for(ll i = 0; i < N; i++){
        ll c, t;
        cin >> c >> t;
        if(t <= T)ans = min(ans, c);
    }
    if(ans == 1919)cout << "TLE" << endl;
    else cout << ans << endl;

    return 0;
}