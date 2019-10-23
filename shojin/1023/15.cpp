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

char mp[3030][3030];
ll O[3030], I[3030];

int main(){

    ll H, W, ans = 0;
    cin >> H >> W;
    rep1(y, H)rep1(x, W)cin >> mp[y][x];
    rrep1(y, H)rrep1(x, W){
        if(mp[y][x] == 'J'){
            ans += O[y] * I[x];
        }
        else if(mp[y][x] == 'O')O[y]++;
        else I[x]++;
    }
    cout << ans << endl;

    return 0;
}