#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    set<ll>S;
    for(ll i = 1; i <= 100000; i *= 6)S.insert(i);
    for(ll i = 1; i <= 100000; i *= 9)S.insert(i);
    ll N;
    cin >> N;
    vector<ll>dp(N+1, N);
    dp[0] = 0;
    for(ll i = 0; i < N; i++){
        for(set<ll>::iterator it = S.begin(); it != S.end(); it++){
            ll nxt = *it + i;
            if(nxt > N)break;
            dp[nxt] = min(dp[nxt], dp[i] + 1);
        }
    }
    cout << dp[N] << endl;

    return 0;
}