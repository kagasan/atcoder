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
const ll INF = 1145141919810893;
const ll MOD = 1000000007;
const ll NUM = 101010;

ll N, M, s, t;
G en(NUM), sn(NUM);
ll tot[NUM], fs[NUM], ans[NUM];

int main(){

    cin >> N >> M >> s >> t;
    rep(i, M){
        ll u, v, a, b;
        cin >> u >> v >> a >> b;
        g_undir(en, u, v, a);
        g_undir(sn, u, v, b);
    }
    rep1(i, N)tot[i] = INF;
    priority_queue<P, vector<P>, greater<P> >Q;
    Q.push(P(0, t));
    while(!Q.empty()){
        ll cost = Q.top().first;
        ll idx = Q.top().second;
        Q.pop();
        if(tot[idx] < INF)continue;
        tot[idx] = cost;
        rep(i, sn[idx].size()){
            ll to = sn[idx][i].first;
            if(tot[to] < INF)continue;
            Q.push(P(sn[idx][i].second + tot[idx], to));
        }
    }
    rep1(i, N)fs[i] = INF;
    Q.push(P(0, s));
    while(!Q.empty()){
        ll cost = Q.top().first;
        ll idx = Q.top().second;
        Q.pop();
        if(fs[idx] < INF)continue;
        fs[idx] = cost;
        rep(i, en[idx].size()){
            ll to = en[idx][i].first;
            if(fs[to] < INF)continue;
            Q.push(P(en[idx][i].second + fs[idx], to));
        }
    }
    rrep1(i, N){
        ans[i] = 1000000000000000LL - fs[i] - tot[i];        
        chmax(ans[i], ans[i + 1]);
    }
    rep1(i, N)cout << ans[i] << endl;
    
    return 0;
}