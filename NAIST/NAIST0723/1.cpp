#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll mn = -1, mx = 1000000000000000010;
    ll A[4] = {};
    for(ll i = 1; i <= 3; i++)cin >> A[i];
    ll B[4] = {};
    for(ll i = 1; i <= 3; i++){
        cin >> B[i];
        B[i] += B[i - 1];
    }
    for(ll i = 1; i <= 3; i++){
        ll m = A[i] * B[i];
        ll n = m + 1 - A[i];
        mx = min(mx, m);
        mn = max(mn, n);
    }
    if(mn <= mx)cout << mn << " " << mx << endl;
    else cout << -1 << endl;

    return 0;    
}