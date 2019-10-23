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

set<ll>S[1050];

int main(){
    rep(i, 1050)S[i].insert(INF);
    ll A, B;
    cin >> A >> B;
    rep1(i, A){
        ll x;
        cin >> x;
        S[x].insert(i);
    }
    vector<ll>v(B + 1, 0);
    rep1(i, B){
        cin >> v[i];
    }
    ll ans = 0;
    rep1(i, B){
        ll pos = 0;
        ll cnt = 0;
        for(ll j = i; j <= B; j++){
            ll x = v[j];
            ll t = choka_min(S[x], pos);
            if(t == INF)break;
            cnt++;
            pos = t;
        }
        chmax(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}