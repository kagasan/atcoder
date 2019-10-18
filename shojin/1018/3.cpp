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
    vector<P>v(N);
    set<P>S;
    rep(i, N){
        cin >> v[i].first >> v[i].second;
        S.insert(v[i]);
    }
    ll ans = 0;
    rep(i, N)rep(j, N){
        if(i == j)continue;
        ll x1 = v[i].first, y1 = v[i].second;
        ll x2 = v[j].first, y2 = v[j].second;
        ll A = x2 - x1, B = y2 - y1;
        ll x3 = x2 - B, y3 = y2 + A;
        ll x4 = x3 - A, y4 = y3 - B;
        if(S.find(P(x3, y3)) == S.end())continue;
        if(S.find(P(x4, y4)) == S.end())continue;
        chmax(ans, A * A + B * B);
    }
    cout << ans << endl;

    return 0;
}