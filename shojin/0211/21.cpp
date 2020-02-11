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

ll N;
ll A[100];

ll ans = -INF;

int main(){

    cin >> N;
    rep1(i, N)cin >> A[i];
    rep1(a, N){
        ll mx = -INF, tmp = -INF;
        rep1(b, N)if(a != b){
            ll l = min(a, b);
            ll r = max(a, b);
            ll sum_a = 0, sum_b = 0;
            for(ll i = l, j = 0; i <= r; i++, j++){
                if(j % 2 == 0)sum_a += A[i];
                else sum_b += A[i];
            }
            if(mx < sum_b){
                mx = sum_b;
                tmp = sum_a;
            }
        }
        chmax(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}