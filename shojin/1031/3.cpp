#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}

ll N, ans = 0, lst = -1;
ll dp[101010][3];

int main(){

    cin >> N;
    rep1(i, N){
        ll x;
        cin >> x;
        if(lst == -1 || lst == x){
            dp[i][0] = 1;
            dp[i][1] = 1 + dp[i - 1][0];
            dp[i][2] = 1 + dp[i - 1][1];
        }
        else{
            dp[i][0] = 1 + dp[i - 1][0];
            dp[i][1] = 1 + dp[i - 1][1];
            dp[i][2] = 1 + dp[i - 1][2];
        }
        lst = x;
        chmax(ans, dp[i][0]);
        chmax(ans, dp[i][1]);
        chmax(ans, dp[i][2]);
    }
    cout << ans << endl;
    // for(ll i = 0; i < 3; i++){
    //     rep1(j, N)cout << dp[j][i];
    //     cout << endl;
    // }
    return 0;
}