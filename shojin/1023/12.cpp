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

    ll N, M;
    cin >> N >> M;
    vector<ll>v(N + 10, 0);
    ll p;
    cin >> p;
    for(ll i = 1; i < M; i++){
        ll x;
        cin >> x;
        v[min(p, x)]++;
        v[max(p, x)]--;
        p = x;
    }
    for(ll i = 1; i < v.size(); i++)v[i] += v[i - 1];
    ll ans = 0;
    rep1(i, N - 1){
        ll a, b, c;
        cin >> a >> b >> c;
        ans += min(v[i] * a, v[i] * b + c);
    }
    cout << ans << endl;

    return 0;
}