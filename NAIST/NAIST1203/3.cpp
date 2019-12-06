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

ll D;
ll A[202020];
ll B[202020];

int main(){

    cin >> D;
    rep(i, D)cin >> A[i];
    rep(i, D)cin >> B[i];
    ll ans = -1;
    ll sum = 0;
    rep(i, D){
        sum += A[i];
        if(B[i] <= sum){
            if(ans < 0)ans = B[i];
            chmin(ans, B[i]);
        }
    }
    cout << ans << endl;

    return 0;
}