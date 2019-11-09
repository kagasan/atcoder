#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
const ll INF = 1145141919;
const ll MOD = 998244353;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

ll N, v[101010], w[101010];

template< typename T >
T mod_pow(T x, T n, const T &p) {
  T ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= p;
    (x *= x) %= p;
    n >>= 1;
  }
  return ret;
}

ll solve(){
    if(v[1] != 0)return 0;
    if(w[0] > 1)return 0;
    for(ll i = 1; i <= N; i++){
        if(w[i] && w[i - 1] == 0)return 0;
    }
    ll res = 1;
    for(ll i = 1; w[i]; i++){
        ll tmp = mod_pow(w[i - 1], w[i], MOD);
        res = res * tmp % MOD;
    }
    return res;
}

int main(){

    cin >> N;
    rep1(i, N){
        cin >> v[i];
        w[v[i]]++;
    }
    cout << solve() << endl;

    return 0;
}