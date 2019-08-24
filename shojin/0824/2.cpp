#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

const ll MOD = 1000000007;

int main(){

    ll N, K;
    cin >> N >> K;
    vector<ll>v(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> v[i];
    }
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        ll A = 0;
        ll B = 0;
        for(ll j = 0; j < N; j++){
            if(v[j] <= v[i])continue;
            if(j < i)A++;
            B++;
        }
        ll tmp = (A * K) % MOD;
        ans = (ans + tmp) % MOD;
        tmp = ((K - 1) * (K) / 2) % MOD;
        tmp = (tmp * B) % MOD;
        ans = (ans + tmp) % MOD;
    }
    cout << ans << endl;

    return 0;
}