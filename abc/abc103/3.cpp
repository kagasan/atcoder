#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N, ans = 0;
    cin >> N;
    for(ll i = 0; i < N; i++){
        ll a;
        cin >> a;
        ans += (a - 1);
    }
    cout << ans << endl;

    return 0;
}