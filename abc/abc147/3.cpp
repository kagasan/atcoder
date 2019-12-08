#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
const ll INF = 1145141919;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

ll A[20];
ll x[20][20];
ll y[20][20];

int main(){

    ll N;
    cin >> N;
    rep(i, N){
        cin >> A[i];
        rep(j, A[i]){
            cin >> x[i][j] >> y[i][j];
            x[i][j]--;
        }
    }
    ll ans = 0;
    rep(i, 1 << N){
        ll flg = 1;

        rep(j, N)if(i & (1 << j))rep(k, A[j]){
            ll p = x[j][k];
            ll s = y[j][k];
            ll t = (0 != (i & (1 << p)));
            if(s != t)flg = 0;
        }
        
        ll cnt = 0;
        rep(j, N)if(i & (1 << j))cnt++;
        if(flg)chmax(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}