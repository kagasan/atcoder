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

int main(){

    ll N;
    cin >> N;
    vector<ll>dp(101010, 0);
    rep(i, N){
        ll v, w;
        cin >> v >> w;
        rrep1(to, 100000){
            ll from = to - w;
            if(from < 0)break;
            chmax(dp[to], dp[from] + v);
        }
    }
    ll V;
    cin >> V;
    ll mn = 0, mx = 0;
    for(ll i = 0; i <= 100000; i++){
        if(dp[i] == V && mn == 0){
            mn = 1;
            if(i == 0)cout << 1 << endl;
            else cout << i << endl;
        }
        if(dp[i] > V && mx == 0){
            mx = 1;
            cout << i - 1 << endl;
        }
    }
    if(mx == 0)cout << "inf" << endl;

    return 0;
}