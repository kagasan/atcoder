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

    ll N, M;
    cin >> N >> M;
    ll ans = 0;
    char c[3] = {'!', '!', '!'};
    ll t[3] = {};
    for(ll i = 0; i < M; i++){
        cin >> c[2];
        if(c[0] == 'I' && c[1] == 'O' && c[2] == 'I'){
            t[2] = t[0] + 1;
        }
        else t[2] = 0;
        if(t[2] >= N)ans++;
        t[0] = t[1];
        t[1] = t[2];
        c[0] = c[1];
        c[1] = c[2];
    }
    cout << ans << endl;

    return 0;
}