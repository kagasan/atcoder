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

    ll X, N, M, ans = 0;
    cin >> X >> N >> M;
    rep(i, N){
        ll x;
        cin >> x;
        if(x == X)ans |= 1;
    }
    rep(i, M){
        ll x;
        cin >> x;
        if(x == X)ans |= 2;
    }
    string s;
    if(ans == 0)s = "-1";
    if(ans == 1)s = "MrMax";
    if(ans == 2)s = "MaxValu";
    if(ans == 3)s = "MrMaxValu";
    cout << s << endl;
    
    return 0;
}