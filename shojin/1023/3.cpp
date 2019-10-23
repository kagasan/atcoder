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

ll op[1010][20];
ll wa[1010][20];
ll ac[1010][20];

int main(){

    rep(i, 1010)rep(j, 20)op[i][j] = -1;
    rep(i, 1010)rep(j, 20)ac[i][j] = -1;

    ll N, M, T, X, Y;
    cin >> N >> M >> T >> X >> Y;
    vector<ll>p(M + 1, 0);
    rep1(i, M)cin >> p[i];
    rep1(i, Y){
        ll t, n, m;
        string s;
        cin >> t >> n >> m >> s;
        if(t < 0)continue;
        if(t > T)continue;
        if(s[0] == 'o'){
            if(op[n][m] < 0)op[n][m] = t;
        }
        else if(s[0] == 'c'){
            if(op[n][m] >= 0 && ac[n][m] < 0)ac[n][m] = t;
        }
        else{
            if(op[n][m] >= 0 && ac[n][m] < 0)wa[n][m]++;
        }
    }
    rep1(i, N){
        ll ans = 0;
        rep1(j, M){
            if(ac[i][j] < 0)continue;
            ans += max(X, (p[j] - (ac[i][j] - op[i][j]) - 120 * wa[i][j]));
        }
        cout << ans << endl;
    }

    return 0;
}