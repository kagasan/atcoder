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
const ll INF = 1000000000000000001;
const ll MOD = 1000000007;
const ll NUM = 101010;

int main(){


    ll N, K;
    cin >> N >> K;
    V v(N);
    rep(i, N)cin >> v[i];
    sort(v.begin(), v.end());
    ll ng = -INF, ok = INF;
    while(ng + 1 < ok){
        ll mid = (ng + ok) / 2;
        ll cnt = 0;
        rep(i, N){
            if(i + 1 == N)continue;
            ll x = v[i];
            if(x < 0){
                if(x * v[i + 1] <= mid)cnt += N - (i + 1);
                else if(x * v[N - 1] > mid);
                else{
                    ll ng2 = i + 1, ok2 = N - 1;
                    while(ng2 + 1 < ok2){
                        ll mid2 = (ng2 + ok2) / 2;
                        if(x * v[mid2] <= mid)ok2 = mid2;
                        else ng2 = mid2;
                    }
                    cnt += N - ok2;
                }
            }
            if(x == 0){
                if(mid >= 0)cnt += N - i - 1;
            }
            if(x > 0){
                if(x * v[i + 1] > mid);
                else if(x * v[N - 1] <= mid)cnt += N - (i + 1);
                else{
                    ll ok2 = i + 1, ng2 = N - 1;
                    while(ok2 + 1 < ng2){
                        ll mid2 = (ok2 + ng2) / 2;
                        if(x * v[mid2] <= mid)ok2 = mid2;
                        else ng2 = mid2;
                    }
                    cnt += ok2 - i;
                }
            }
        }
        if(cnt >= K)ok = mid;
        else ng = mid;
    }
    cout << ok << endl;

    return 0;
}