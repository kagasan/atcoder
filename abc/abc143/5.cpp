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
typedef pair<ll, P>LP;


ll cost[330][330];
ll cost2[330][330];
ll N, M, L;


int main(){

    rep(i, 330)rep(j, 330)cost[i][j] = INF;
    rep(i, 330)rep(j, 330)cost2[i][j] = INF;
    cin >> N >> M >> L;
    rep(i, M){
        ll a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = c;
        cost[b][a] = c;
    }
    rep1(i, N)rep1(j, N)rep1(k, N){
        chmin(cost[j][k], cost[j][i] + cost[i][k]);
    }
    rep1(i, N)rep1(j, N)if(cost[i][j] <= L)cost2[i][j] = 1;
    rep1(i, N)rep1(j, N)rep1(k, N){
        chmin(cost2[j][k], cost2[j][i] + cost2[i][k]);
    }
    ll Q;
    cin >> Q;
    rep(q, Q){
        ll s, t;
        cin >> s >> t;
        if(cost2[s][t] == INF)cout << -1 << endl;
        else cout << cost2[s][t] - 1<< endl;
    }


    return 0;
}