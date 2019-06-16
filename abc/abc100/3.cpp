#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N;
    cin >> N;
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        ll a;
        cin >> a;
        for(;a % 2 == 0; a /= 2)ans++;
    }
    cout << ans << endl;

    return 0;
}