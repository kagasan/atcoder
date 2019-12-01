#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
const ll INF = 1145141919;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

ll dp[101010];

int main(){

    dp[0] = 1;
    for(ll i = 0; i <= 100000; i++){
        if(dp[i] == 0)continue;
        for(ll j = 100; j <= 105; j++)dp[i + j] = 1;
    }
    ll X;
    cin >> X;
    cout << dp[X] << endl;

    return 0;
}