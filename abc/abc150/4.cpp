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
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
int main(){

    ll N, M;
    cin >> N >> M;
    set<ll>S;
    rep(i, N){
        ll x;
        cin >> x;
        S.insert(x);
    }
    N = S.size();
    V a, b;
    ll even = 0;
    for(set<ll>::iterator it = S.begin(); it != S.end(); it++){
        ll x = (*it);
        a.push_back(x);
        b.push_back(x / 2);
        if((x / 2) % 2 == 0)even++;
    }
    if(even){
        if(N == 1)cout << (M + b[0]) / a[0] << endl;
        else cout << 0 << endl;
        return 0;
    }
    ll hoge = 1;
    rep(i, b.size()){
        hoge = lcm(hoge, b[i]);
        if(hoge > M){
            cout << 0 << endl;
            return 0;
        }
    }
    cout << (M + hoge) / (2 * hoge) << endl;

    
    return 0;
}