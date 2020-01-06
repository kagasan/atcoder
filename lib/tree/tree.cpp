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

void roottree(const G &graph, ll root, V &depth, V &leaf, V2 &parent){
    ll n = graph.size();
    depth = V(n, INF);
    leaf = V(n, 0);
    parent = V2(n, V(30, INF));
    priority_queue<IP, vector<IP>, greater<IP> >PQ;
    PQ.push(IP(0, P(root, INF)));
    while(!PQ.empty()){
        ll cost = PQ.top().first;
        ll idx = PQ.top().second.first;
        ll from = PQ.top().second.second;
        PQ.pop();
        depth[idx] = cost;
        parent[idx][0] = from;
        ll leaf_flg = 1;
        rep(i, graph[idx].size()){
            ll to = graph[idx][i].first;
            ll w = graph[idx][i].second;
            if(depth[to] == INF){
                PQ.push(IP(cost + w, P(to, idx)));
                leaf_flg = 0;
            }
        }
        if(leaf_flg)leaf[idx] = 1;
    }
    rep(i, 24)rep(j, n){
        ll p = parent[j][i];
        if(p != INF)parent[j][i + 1] = parent[p][i];
    }    
}

ll ancestor(ll idx, ll d, const V &depth, const V2 &parent){
    if(d < 0 || d > depth[idx])return INF;
    ll diff = depth[idx] - d;
    if(diff == 0)return idx;
    ll tmp = idx;
    for(ll i = 0, j = 1;; i++, j += j){
        if(depth[idx] - j >= d)tmp = parent[idx][i];
        else break;
    }
    return ancestor(tmp, d, depth, parent);
}

ll lca(ll a, ll b, const V &depth, const V2 &parent){
    if(a == b)return a;
    ll ok = 0, ng = depth[a];
    if(depth[a] < depth[b])ng = depth[b];
    while(ok + 1 < ng){
        ll p = (ok + ng) / 2;
        if(ancestor(a, p, depth, parent) == ancestor(b, p, depth, parent)){
            ok = p;
        }
        else ng = p;
    }
    return ancestor(a, ok, depth, parent);
}

ll distance_tree(ll a, ll b, const V &depth, const V2 &parent){
    ll c = lca(a, b, depth, parent);
    return depth[a] + depth[b] - depth[c] - depth[c];
}

G g(NUM);

void ABC014D(){
    ll N;
    cin >> N;
    rep1(i, N - 1){
        ll a, b;
        cin >> a >> b;
        g_undir(g, a, b);
    }

    V depth, leaf;
    V2 parent;
    roottree(g, 1, depth, leaf, parent);

    ll Q;
    cin >> Q;
    rep(i, Q){
        ll a, b;
        cin >> a >> b;
        cout << distance_tree(a, b, depth, parent) + 1 << endl;
    }
}

void ABC148F(){
    ll N, u, v;
    cin >> N >> u >> v;
    rep1(i, N - 1){
        ll a, b;
        cin >> a >> b;
        g_undir(g, a, b);
    };
    V depth, leaf;
    V2 parent;
    roottree(g, v, depth, leaf, parent);
    ll cnt = 0;
    for(;;){
        ll p = parent[u][0];
        if(depth[p] == cnt + 1){
            cnt++;
            break;
        }
        if(depth[p] == cnt)break;
        cnt++;
        u = p;
    }
    ll tmp = 0;
    rep1(i, N)if(lca(i, u, depth, parent) == u)chmax(tmp, depth[i] - depth[u]);
    cout << cnt + tmp << endl;
}

int main(){

    ABC148F();

    return 0;
}