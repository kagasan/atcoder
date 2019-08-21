#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;

ll A[202020];
ll nxt[202020];
ll dp[202020];

int main(){

    ll N, M;
    cin >> N >> M;
    for(ll i = 0; i < N; i++)cin >> A[i];
    for(ll i = 0; i < N; i++)nxt[i] = i + 1;
    vector<P>v;
    for(ll i = 0; i < M; i++){
        ll L, R;
        cin >> L >> R;
        v.push_back(P(R, L));
    }
    sort(v.begin(), v.end(), greater<P>());
    for(ll i = 0, idx = N; i < v.size(); i++){
        ll l = v[i].second - 1;
        ll r = v[i].first - 1;
        ll to = v[i].first;
        if(idx < l)continue;
        if(r < idx)idx = r;
        for(; l <= idx; idx--)nxt[idx] = max(nxt[idx], to);
    }
    for(ll i = 0; i < N; i++){
        dp[i + 1] = max(dp[i + 1], dp[i]);
        dp[nxt[i]] = max(dp[nxt[i]], dp[i] + A[i]);
    }
    cout << dp[N] << endl;

    return 0;    
}