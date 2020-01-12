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


int main(){

    ll N;
    cin >> N;
    V v(N);
    rep(i, N)cin >> v[i];
    sort(v.begin(), v.end(), greater<ll>());
    if(N % 2){
        ll ans = 0;
        rep(i, N / 2)ans += v[i] * 2;
        for(ll i = N / 2, j = 0; i < N; i++, j++){
            ans -= v[i];
            if(j >= 2)ans -= v[i];
        }
        ll ans2 = 0;
        for(ll i = N / 2, j = 0; i >= 0; i--, j++){
            ans2 += v[i];
            if(j >= 2)ans2 += v[i];
        }
        for(ll i = (N + 1) / 2; i < N; i++){
            ans2 -= v[i] * 2;
        }
        cout << max(ans, ans2) << endl;
    }
    else{
        ll ans = 0;
        for(ll i = 0; i < N / 2; i++){
            ans += v[i];
            if(i + 1 < N / 2)ans += v[i];
        }
        for(ll i = N / 2; i < N; i++){
            ans -= v[i];
            if(i > N / 2)ans -= v[i];
        }
        cout << ans << endl;
    }
    
    return 0;
}