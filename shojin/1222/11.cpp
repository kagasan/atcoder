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

string first, last;
ll N;
string v[1010];
ll cost[1010];
ll from[1010];
ll path[1010][1010];
map<string, ll>mp;

int main(){

    cin >> v[0] >> v[1];
    ll len = v[0].size();
    cin >> N;
    rep(i, N)cin >> v[i + 2];
    N += 2;
    rep(i, N)cost[i] = INF;
    rep(i, N)from[i] = -1;
    cost[0] = -1;
    rep(i, N)rep(j, i){
        ll cnt = 0;
        rep(k, len)if(v[i][k] != v[j][k])cnt++;
        if(cnt <= 1){
            path[i][j] = 1;
            path[j][i] = 1;
        }
    }
    queue<ll>Q;
    Q.push(0);
    while(!Q.empty()){
        ll idx = Q.front();
        Q.pop();
        if(idx == 1)break;
        rep(i, N)if(path[idx][i] && cost[i] == INF){
            cost[i] = cost[idx] + 1;
            from[i] = idx;
            Q.push(i);
        }

    }
    if(from[1] < 0){
        cout << -1 << endl;
        return 0;
    }
    cout << cost[1] << endl;
    stack<ll>S;
    for(ll i = 1; i >= 0; i = from[i]){
        S.push(i);
    }
    for(;!S.empty(); S.pop())cout << v[S.top()] << endl;
    return 0;
}