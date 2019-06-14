#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N, K;
    cin >> N >> K;
    vector<ll>cnt(K, 0);
    for(ll i = 1; i <= N; i++)cnt[i % K]++;
    ll ans = 0;
    for(ll a = 1; a <= N; a++){
        ll b = (K - (a % K)) % K;
        if((b + b) % K == 0){
            ans += cnt[b] * cnt[b];
        }
    }
    cout << ans << endl;

    return 0;
}