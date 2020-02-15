//ABC006D
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

ll LIS_test(const V &v){
    V dp(v.size() + 1, INF);
    for(auto x : dp)cout << ((x == INF) ? "+" : to_string(x)) << " ";
    cout << endl << endl;
    for(auto x : v){
        *lower_bound(dp.begin(), dp.end(), x) = x;
        cout << x << endl;
        for(auto x : dp)cout << ((x == INF) ? "+" : to_string(x)) << " ";
        cout << endl << endl;
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();    
}

ll LIS(const V &v){
    V dp(v.size() + 1, INF);
    for(auto x : v){
        *lower_bound(dp.begin(), dp.end(), x) = x;
    }
    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main(){

    ll N;
    cin >> N;
    V v(N);
    rep(i, N)cin >> v[i];
    LIS_test(v);
    cout << N - LIS(v) << endl;
    
    return 0;
}