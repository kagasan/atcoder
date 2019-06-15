#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N, M;
    cin >> N >> M;
    ll ans = 0;
    ll tmp = 0;
    map<ll, ll>cnt;
    cnt[0] = 1;
    for(ll i = 0; i < N; i++){
        ll x;
        cin >> x;
        tmp = (tmp + x) % M;
        ans += cnt[tmp];
        cnt[tmp]++;
    }
    cout << ans << endl;

    return 0;
}
