//
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

ll N, M;
vector<ll>path[101010];

ll ans = -1;
ll flg[101010];

int main(){

    cin >> N >> M;
    rep(i, M){
        ll a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }   
    rep1(i, N)if(flg[i] == 0){
        flg[i] = 1;
        queue<ll>Q;
        Q.push(i);
        ans++;
        while(!Q.empty()){
            ll idx = Q.front();
            Q.pop();
            for(auto to : path[idx])if(flg[to] == 0){
                flg[to] = 1;
                Q.push(to);
            }
        }
    }
    cout << ans << endl;

    return 0;
}