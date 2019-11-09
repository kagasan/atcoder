#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
const ll INF = 1145141919810893LL;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

ll N, M;
ll L[101010];
ll R[101010];
ll C[101010];

vector<P>path[101010];

ll cost[101010];

ll solve(){
    rep(i, 101010)cost[i] = INF;
    priority_queue<P, vector<P>, greater<P> >Q;
    Q.push(P(0, 1));
    ll r = 1;
    while(!Q.empty()){
        ll cst = Q.top().first;
        ll idx = Q.top().second;
        Q.pop();
        if(r > idx)continue;
        if(cost[idx] < INF)continue;
        cost[idx] = cst;
        for(; r <= idx; r++){
            rep(i, path[r].size()){
                Q.push(P(cst + path[r][i].first, path[r][i].second));
            }
        }
    }
    if(cost[N] < INF)return cost[N];
    return -1;
}

int main(){

    cin >> N >> M;
    rep(i, M){
        cin >> L[i] >> R[i] >> C[i];
        path[L[i]].push_back(P(C[i], R[i]));
    }
    cout << solve() << endl;

    return 0;
}