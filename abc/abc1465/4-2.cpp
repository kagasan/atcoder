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
template<class T> T choka_min(set<T> &S, const T &x){
    return *S.upper_bound(x);
}
template<class T> T miman_max(set<T> &S, const T &x){
    typename set<T>::iterator it = S.lower_bound(x);
    it--;
    return *it;
}
ll N;
ll s[30303];
set<ll>S[10];
ll flg[1000];

int main(){
    rep(i, 10){
        S[i].insert(-INF);
        S[i].insert(INF);
    }

    cin >> N;
    rep1(i, N){
        char c;
        cin >> c;
        s[i] = c - '0';
        S[s[i]].insert(i);
    }
    rep1(i, N)rep(j, 10)rep(k, 10)if(choka_min(S[j], i) != INF && miman_max(S[k], i) != -INF){
        flg[j * 100 + s[i] * 10 + k] = 1;
    }
    ll ans = 0;
    rep(i, 1000)ans += flg[i];
    cout << ans << endl;

    return 0;
}