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

ll ans[202020];

int main(){

    ll N, x;
    cin >> N >> x;
    if(x == 1 || x == 2 * N - 1){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    ans[N - 1] = x - 1;
    ans[N] = x;
    ans[N + 1] = x + 1;
    ll nxt = 1;
    rep1(i, 2 * N - 1){
        if(ans[i])continue;
        while(abs(x - nxt) <= 1)nxt++;
        ans[i] = nxt;
        nxt++;
    }
    rep1(i, 2 * N - 1)cout << ans[i] << endl;
    
    return 0;
}