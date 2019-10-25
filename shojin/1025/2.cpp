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
template<class T> T ijo_min(set<T> &S, const T &x){
    return *S.lower_bound(x);
}

int main(){

    ll D, N, M;
    cin >> D >> N >> M;
    set<ll>S;
    S.insert(0);
    S.insert(D);
    rep(i, N - 1){
        ll x;
        cin >> x;
        S.insert(x);
    }
    ll ans = 0;
    rep(i, M){
        ll x;
        cin >> x;
        ans += min(abs(x - ika_max(S, x)), abs(x - ijo_min(S, x)));
    }
    cout << ans << endl;

    return 0;
}