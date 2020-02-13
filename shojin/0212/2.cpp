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

int main(){

    ll N, M;
    cin >> N >> M;
    // 2, 3, 4
    for(ll z = 0; z <= N; z++){
        ll asi = M - 4 * z;
        if(asi < 0)continue;
        ll n = N - z;
        // 1x + 1y = n
        // 2x + 3y = asi
        // 2x + 2y = 2n
        // y = asi - 2n
        ll y = asi - 2 * n;
        if(y < 0)continue;
        ll x = n - y;
        if(x < 0)continue;
        cout << x << " " << y << " " << z << endl;
        return 0;
    }
    cout << "-1 -1 -1" << endl;
    
    return 0;
}