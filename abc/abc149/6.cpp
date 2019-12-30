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

ll N;
V path[202020];
ll depth[202020];
ll parent[202020];
ll sz[202020];

int main(){

    cin >> N;  
    rep(i, N - 1){
        ll a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }  
    ll rt = -1;
    rep1(i, N)if(path[i].size() == 1)rt = i;
    depth[rt] = 1;
    queue<ll>Q;
    Q.push(rt);
    while(!Q.empty()){
        ll idx = Q.front();
        Q.pop();
        rep(i, path[idx].size()){
            ll to = path[idx][i];
            if(depth[to])continue;
            depth[to] = depth[idx] + 1;
            parent[to] = idx;
            Q.push(to);
        }
    }
    priority_queue<P>PQ;
    rep1(i, N)PQ.push(P(depth[i], i));
    while(!PQ.empty()){
        ll idx = PQ.top().second;
        PQ.pop();
        sz[idx] = 1;
        rep(i, path[idx].size()){
            ll to = path[idx][i];
            if(parent[idx] == to)continue;
            sz[idx] += sz[to];
        }
    }
    

    return 0;
}