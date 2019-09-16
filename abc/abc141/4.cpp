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

ll A[101010];
ll used[101010];

ll next(ll x){
    ll now = A[x] / (1 << used[x]);
    if(now == 0)return 0;
    ll n = A[x] / (1 << (used[x] + 1));
    return now - n;
}

int main(){

    ll N, M;
    cin >> N >> M;
    ll sum = 0;
    priority_queue<P>Q;
    rep(i, N){
        cin >> A[i];
        sum += A[i];
        Q.push(P(next(i), i));
    }
    for(;!Q.empty() && M > 0; M--){
        ll idx = Q.top().second;
        ll bene = Q.top().first;
        Q.pop();
        if(bene == 0)break;
        // cout << idx << " : " << bene << endl;
        sum -= bene;
        used[idx]++;
        Q.push(P(next(idx), idx));
    }
    cout << sum << endl;

    return 0;
}