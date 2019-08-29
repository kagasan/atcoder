#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    ll ans = 0;
    for(ll n = N; n > 0; n -= A)ans += B;
    ll ans2 = 0;
    for(ll n = N; n > 0; n -= C)ans2 += D;
    cout << min(ans, ans2) << endl;
    
    return 0;    
}