#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

const ll MOD = 1000000007;

int main(){

    ll N, K;
    cin >> N >> K;
    set<ll>S;
    for(ll i = 1; i * i <= N; i++){
        S.insert(i);
        S.insert(N / i);
    }
    vector<ll>v;
    for(set<ll>::iterator it = S.begin(); it != S.end(); it++)v.push_back(*it);
    ll V = v.size();
    for(ll i = V - 1; i > 0; i--)v[i] -= v[i - 1];
    for(ll i = 0; i < V; i++)v[i] %= MOD;
    vector<vector<ll> >dp(K + 2, vector<ll>(V, 0));
    dp[0][0] = 1;
    for(ll i = 1; i <= K + 1; i++){
        for(ll j = V - 1; j >= 0; j--){
            ll k = V - j - 1;
            dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
        }
        for(ll j = V - 1 - 1; j >= 0; j--){
            dp[i][j] = (dp[i][j] + dp[i][j + 1]) % MOD;
        }
        for(ll j = 0; j < V; j++){
            dp[i][j] = (dp[i][j] * v[j]) % MOD;
        }
    }
    cout << dp[K + 1][0] << endl;
    return 0;
}