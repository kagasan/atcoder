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

int main(){

    ll N;
    cin >> N;
    vector<ll>v(N);
    ll sum = 0;
    rep(i, N){
        cin >> v[i];
        sum += v[i];
    }
    ll ans = sum;
    for(ll tmp = 0, i = 0; i < N - 1; i++){
        tmp += v[i];
        ll a = tmp;
        ll b = sum - tmp;
        chmin(ans, abs(a - b));
    }
    cout << ans << endl;
    
    return 0;
}