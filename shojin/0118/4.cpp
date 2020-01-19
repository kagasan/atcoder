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

ll N;
ll A[20], B[20];

ll ans = INF;

int main(){

    cin >> N;
    rep(i, N)cin >> A[i];
    rep(i, N)cin >> B[i];
        
    ll EV = (N + 1) / 2;
    ll OD = N / 2;
    rep(i, 1 << N){
        ll e = 0, o = 0;
        V v(N), f(N, 0);
        vector<P>w(N);
        for(ll j = 0; j < N; j++){
            if(i & (1 << j)){
                o++;
                f[j] = 1;
                if(j % 2 == 0)v[j] = B[j];
                if(j % 2 == 1)v[j] = A[j];
            }
            else{
                e++;
                f[j] = 0;
                if(j % 2 == 0)v[j] = A[j];
                if(j % 2 == 1)v[j] = B[j];
            }
        }
        if(EV != e || OD != o)continue;
        // cout << endl;
        // rep(j, N)cout << f[j];
        // cout << endl;
        // rep(j, N)cout << v[j] << " ";
        // cout << endl;
        
        ll cnt = 0;
        rep(j, N){
            ll val = INF, idx = -1;
            rep(k, N)if(v[k] < val && f[k] == j % 2){
                val = v[k];
                idx = k;
            }
            w[idx].first = j;
            w[idx].second = v[idx];
            v[idx] = INF;
        }
        // rep(j, N)cout << w[j].first;
        // cout << endl;
        rep(j, N)rep(k, N - 1)if(w[k] > w[k+1]){
            swap(w[k], w[k + 1]);
            cnt++;
        }
        rep(j, N - 1)if(w[j].second > w[j + 1].second)cnt = INF;
        // cout << cnt << endl;
        chmin(ans, cnt);
    }

    if(ans == INF)cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}