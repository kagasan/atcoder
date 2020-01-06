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

// 1indexed1dimention[l,r]
class bit1d{
  public:
  vector<ll>v;
  ll num;
  bit1d(ll NUM = 0){
      num = NUM + 5;
      v = vector<ll>(num + 5, 0);
  }
  void add(ll idx, ll x){
      if(idx == 0)return;
      while(idx <= num){
          v[idx] += x;
          idx += idx & -idx;
      }
  }
  ll sum_of_1_to_idx(ll idx){
      if(idx <= 0)return 0;
      ll s = 0;
      while(idx > 0){
          s += v[idx];
          idx -= idx & -idx;
      }
      return s;
  }
  ll sum(ll l, ll r){
      return sum_of_1_to_idx(r) - sum_of_1_to_idx(l - 1);
  }
};

int main(){

    ll N;
    cin >> N;
    V v(N + 2, 0);
    bit1d bit(N);
    rep1(i, N){
        ll x;
        cin >> x;
        v[x] = i;
        bit.add(i, 1);
    }
    ll ans = -N;
    rep1(i, N){
        ll idx = v[i];
        ans += min(bit.sum(1, idx), bit.sum(idx, N));
        bit.add(idx, -1);
    }
    cout << ans << endl;


    return 0;
}