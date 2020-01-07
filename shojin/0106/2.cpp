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
G g(NUM);

ll dfs(ll idx, V &depth){
    depth = V(NUM, -1);
    depth[idx] = 0;
    queue<ll>Q;
    Q.push(idx);
    while(!Q.empty()){
        idx = Q.front();
        Q.pop();
        rep(i, g[idx].size()){
            ll to = g[idx][i].first;
            if(depth[to] >= 0)continue;
            depth[to] = depth[idx] + 1;
            Q.push(to);
        }
    }
    idx = 1;
    rep1(i, N)if(depth[idx] < depth[i])idx = i;
    return idx;
}

int main(){

    cin >> N;
    rep(i, N - 1){
        ll a, b;
        cin >> a >> b;
        g_undir(g, a, b);
    }
    V v;
    ll x = dfs(1, v);
    ll y = dfs(x, v);
    cout << x << " " << y << endl;


    return 0;
}