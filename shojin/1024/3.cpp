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

template<class T> T ika_max(set<T> &S, const T &x){
    typename set<T>::iterator it = S.lower_bound(x);
    if(it == S.end())it--;
    else if(*it > x)it--;
    return *it;
}

int main(){

    ll N, M;
    cin >> N >> M;
    vector<ll>v(N);
    rep(i, N)cin >> v[i];
    set<ll>S;
    S.insert(0);
    S.insert(-INF);
    rep(i, N)S.insert(v[i]);
    rep(i, N)rep(j, N)S.insert(v[i] + v[j]);
    ll ans = 0;
    for(set<ll>::iterator it = S.begin(); it != S.end(); it++){
        ll x = *it;
        chmax(ans, x + ika_max(S, M - x));
    }
    cout << ans << endl;

    return 0;
}