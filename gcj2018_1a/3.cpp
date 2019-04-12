#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

void solve(int t){
    cout << "Case #" << t << ": ";
    int N, P;
    cin >> N >> P;
    double ans = 0;
    int base = 0;
    vector<int>mn(N);
    vector<double>mx(N);
    for(int i = 0; i < N; i++){
        int W, H;
        cin >> W >> H;
        base += 2 * (W + H);
        mn[i] = 2 * min(W, H);
        mx[i] = 2.0 * hypot((double)W, (double)H);
    }
    vector<double>dp(50505, 0);
    int cap = P - base;
    for(int i = 0; i < N; i++){
        for(int to = 50500; to; to--){
            int from = to - mn[i];
            if(from < 0)break;
            dp[to] = max(dp[to], dp[from] + mx[i]);
        }
    }
    for(int i = 0; i < 50500; i++){
        if(cap >= i){
            ans = max(ans, base + min((double)cap, dp[i]));
        }
    }
    printf("%.9f\n", ans);
}

int main(){

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        solve(t);
    }

    return 0;
}