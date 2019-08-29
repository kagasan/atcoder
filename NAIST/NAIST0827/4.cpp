#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll N;
ll L[55];
ll sum[55][55];

ll memo[55][55];
ll dfs(ll l , ll r, ll mx){
    if(memo[l][r])return memo[l][r];
    if(sum[l][r] <= mx){
        memo[l][r] = sum[l][r];
        return memo[l][r];
    }
    for(ll i = l; i < r; i++){
        memo[l][r] = max(memo[l][r], min(dfs(l, i, mx) , dfs(i + 1, r, mx)));
    }
    return memo[l][r];
}
int main(){

    cin >> N;
    for(ll i = 1; i <= N; i++){
        cin >> L[i];
    }
    for(ll l = 1; l <= N; l++){
        for(ll r = l; r <= N; r++){
            for(ll i = l; i <= r; i++)sum[l][r] += L[i];
        }
    }
    ll ans = 1145141919;
    for(ll l = 1; l <= N; l++){
        for(ll r = l; r <= N; r++){
            if(l == 1 && r == N)continue;
            ll mx = sum[l][r];
            for(ll i = 1; i <= N; i++){
                if((i < l || r < i) && (L[i] > mx))mx = 0;
            }
            if(mx == 0)continue;
            for(ll i = 1; i <= N; i++){
                for(ll j = 1; j <= N; j++){
                    memo[i][j] = 0;
                }
            }
            ll mn = mx;
            if(l > 1)mn = min(mn, dfs(1, l - 1, mx));
            if(r < N)mn = min(mn, dfs(r + 1, N, mx));
            ans = min(ans, mx - mn);
        }
    }
    cout << ans << endl;

    return 0;    
}