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

ll tmp[202020];

int main(){

    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    map<ll, ll>cnt;
    tmp[0] = 0;
    cnt[0] = 1;
    rep1(i, N){
        if(i - K >= 0)cnt[tmp[i - K]]--;
        ll a;
        cin >> a;
        tmp[i] = (tmp[i - 1] + a + K - 1) % K;
        ans += cnt[tmp[i]];
        cnt[tmp[i]]++;
    }
    cout << ans << endl;

    return 0;
}