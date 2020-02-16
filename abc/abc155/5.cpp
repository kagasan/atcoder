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

ll ok[1010101];
ll ng[1010101];

int main(){

    string s;
    cin >> s;
    s = "0" + s + "0";
    ll ans = 0;
    reverse(s.begin(), s.end());
    rep(i, 1010101)ok[i] = INF;
    rep(i, 1010101)ng[i] = INF;
    ok[0] = 0;
    rep(i, s.size() - 1){
        ll x = s[i + 1] - '0';
        chmin(ok[i + 1], ok[i] + x);
        chmin(ng[i + 1], ok[i] + (10 - x));
        if(x > 0)chmin(ng[i + 1], ng[i] + (10 - x - 1));
        if(x < 9)chmin(ok[i + 1], ng[i] + x + 1);
    }
    cout << ok[s.size() - 1] << endl;


    return 0;
}