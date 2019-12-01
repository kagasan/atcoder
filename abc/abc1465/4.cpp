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

ll N;
char s[30303];

ll L[30303][10];
ll R[30303][10];

ll flg[1000];

int main(){

    cin >> N;
    rep1(i, N)cin >> s[i];
    for(ll i = 2; i <= N; i++){
        rep(j, 10)L[i][j] = L[i - 1][j];
        L[i][s[i - 1] - '0'] = 1;
    }
    for(ll i = N - 1; i >= 1; i--){
        rep(j, 10)R[i][j] = R[i + 1][j];
        R[i][s[i + 1] - '0'] = 1;
    }
    rep1(i, N){
        rep(j, 10)rep(k, 10)if(L[i][j] && R[i][k]){
            flg[j * 100 + (s[i] - '0') * 10 + k] = 1;
        }
    }
    ll ans = 0;
    for(ll i = 0; i <= 999; i++){
        if(flg[i]){
            ans++;
            // cout << i << endl;
        }
    }
    cout << ans << endl;

    return 0;
}