#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P>IP;
typedef vector<ll> V;
typedef vector<V> V2;
typedef vector<vector<P> > G;
void g_dir(G &graph, ll a, ll b, ll w = 1){graph[a].push_back(P(b, w));}
void g_undir(G &graph, ll a, ll b, ll w = 1){g_dir(graph, a, b, w);g_dir(graph, b, a, w);}
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}
const ll INF = 1145141919;
const ll MOD = 1000000007;
const ll NUM = 101010;

V path[111];
ll dep[111];
ll ans[111];

int main(){
    rep(i, 111)dep[i] = INF;
    ll N, M, a, b;
    cin >> N >> a >> b >> M;
    rep(i, M){
        ll x, y;
        cin >> x >> y;
        path[x].push_back(y);
        path[y].push_back(x);
    }
    dep[a] = 0;
    queue<ll>Q;
    Q.push(a);
    priority_queue<P, vector<P>, greater<P> >PQ;
    while(!Q.empty()){
        ll idx = Q.front();
        Q.pop();
        PQ.push(P(dep[idx], idx));
        for(auto to : path[idx]){
            if(dep[to] < INF)continue;
            dep[to] = dep[idx] + 1;
            Q.push(to);
        }
    }

    ans[a] = 1;
    while(!PQ.empty()){
        ll idx = PQ.top().second;
        PQ.pop();
        for(auto to : path[idx]){
            if(dep[to] != dep[idx] + 1)continue;
            ans[to] = (ans[to] + ans[idx]) % MOD;
        }
    }    

    cout << ans[b] << endl;

    return 0;
}