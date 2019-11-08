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

    ll N, K, flg[10] = {};
    cin >> N >> K;
    rep(i, K){
        ll x;
        cin >> x;
        flg[x] = 1;
    }
    for(ll i = N; ; i++){
        ll f = 1;
        string s = to_string(i);
        for(ll j = 0; j < s.size(); j++)if(flg[s[j] - '0'])f = 0;
        if(f){
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}