#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N, M;
    cin >> N >> M;
    ll ans = 0;
    for(ll i = 1; i * i <= M; i++){
        if(M % i)continue;
        ll a = M / i;
        ll b = i;
        if(N <= a)ans = max(ans, b);
        if(N <= b)ans = max(ans, a);
    }
    cout << ans << endl;

    return 0;
}