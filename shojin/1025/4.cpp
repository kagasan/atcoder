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

    ll N, L;
    cin >> N >> L;
    vector<ll>v(N + 2, 0), w(N + 2, 0);
    priority_queue<P>Q;
    rep1(i, N){
        cin >> v[i];
        Q.push(P(v[i], i));
    }
    ll ans = 0;
    while(!Q.empty()){
        ll idx = Q.top().second;
        Q.pop();
        w[idx] = L - v[idx] + max(w[idx - 1], w[idx + 1]);
        chmax(ans, w[idx]);
    }
    cout << ans << endl;

    return 0;
}