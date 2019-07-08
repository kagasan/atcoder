#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

const ll MOD = 1000000007;

int main(){
    ll N;
    cin >> N;
    vector<ll>vec(N);
    for(ll i = 0; i < N; i++)cin >> vec[i];
    ll ans = 0, tmp = 1;
    for(ll i = N - 1; i >= 0; i--){
        ans = (ans + ((vec[i] * tmp) % MOD)) % MOD;
        for(;vec[i];vec[i] /= 10)tmp = (tmp * 10) % MOD;
    }
    cout << ans << endl;

    return 0;
}