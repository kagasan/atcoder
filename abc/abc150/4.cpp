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
    V a(N), b(N);
    set<ll>S;
    rep(i, N){
        cin >> a[i];
        b[i] = a[i] / 2;
        ll cnt = 0;
        for(ll j = b[i]; j % 2 == 0; j /= 2)cnt++;
        S.insert(cnt);
    }
    if(S.size() > 1){
        cout << 0 << endl;
        return 0;
    }
    ll l = 1;
    rep(i, N){
        l = lcm(l, b[i]);
        if(l > M){
            cout << 0 << endl;
            return 0;
        }
    }
    cout << (M + l) / (l * 2) << endl;

    return 0;
}