#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll N, T;
    cin >> N >> T;
    ll ans = 0;
    ll r = -1;
    for(ll i = 0; i < N; i++){
        ll t;
        cin >> t;
        if(t > r)ans += T;
        else ans += (t + T - r);
        r = t + T;
    }
    cout << ans << endl;

    return 0;
}
