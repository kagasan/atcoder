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

string s;
ll N, K, ans;
ll imos[111];
ll cnt(ll l, ll r){
    if(l > r)return 0;
    if(l == 0)return imos[r];
    return imos[r] - imos[l - 1];
}

ll ika(ll a, ll x){
    if(x)return 1;
    if(s[0] >= a + '0')return 1;
    return 0;
}

ll ika(ll a, ll x, ll b, ll y){
    if(x)return 1;
    if(s[0] > a + '0')return 1;
    if(s[0] < a + '0')return 0;
    if(cnt(x + 1, y - 1))return 1;
    if(s[y] >= b + '0')return 1;
    return 0;
}

ll ika(ll a, ll x, ll b, ll y, ll c, ll z){
    if(x)return 1;
    if(s[0] > a + '0')return 1;
    if(s[0] < a + '0')return 0;
    if(cnt(x + 1, y - 1))return 1;
    if(s[y] > b + '0')return 1;
    if(s[y] < b + '0')return 0;
    if(cnt(y + 1, z - 1))return 1;
    if(s[z] >= c + '0')return 1;
    return 0;
}

int main(){

    cin >> s;
    cin >> K;
    N = s.size();
    rep(i, N)if(s[i] != '0')imos[i] = 1;
    rep1(i, N)imos[i] += imos[i - 1];
    ll ans = 0;
    if(K == 1){
        rep1(a, 9)rep(x, N)if(ika(a, x))ans++;
    }
    if(K == 2){
        rep1(a, 9)rep(x, N)rep1(b, 9)for(ll y = x + 1; y < N; y++)if(ika(a, x, b, y))ans++;
    }
    if(K == 3){
        rep(x, N)for(ll y = x + 1; y < N; y++)for(ll z = y + 1; z < N; z++)rep1(a, 9)rep1(b, 9)rep1(c, 9)if(ika(a, x, b, y, c, z))ans++;
    }
    

    cout << ans << endl;

    return 0;
}