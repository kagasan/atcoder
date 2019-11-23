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

ll H, W, K;
char mp[333][333];

ll row_flg[333];
ll nxt = 1;
ll ans[333][333];

int main(){
    rep(i, 333)rep(j, 333)mp[i][j] = '@';
    rep(i, 333)rep(j, 333)ans[i][j] = INF;

    cin >> H >> W >> K;
    rep1(y, H)rep1(x, W){
        cin >> mp[y][x];
        ans[y][x] = 0;
        if(mp[y][x] == '#')row_flg[y] = 1;
    }
    rep1(y, H)if(row_flg[y]){
        rep1(x, W)if(mp[y][x] == '#'){
            ans[y][x] = nxt;
            for(ll nx = x - 1; ans[y][nx] == 0 && mp[y][nx] == '.'; nx--)ans[y][nx] = nxt;
            for(ll nx = x + 1; ans[y][nx] == 0 && mp[y][nx] == '.'; nx++)ans[y][nx] = nxt;
            nxt++;
        }
    }
    rep1(y, H)if(row_flg[y]){
        rep1(x, W){
            for(ll ny = y - 1; ans[ny][x] == 0; ny--)ans[ny][x] = ans[y][x];
            for(ll ny = y + 1; ans[ny][x] == 0; ny++)ans[ny][x] = ans[y][x];
        }
    }
    rep1(y, H){
        rep1(x, W){
            cout << ans[y][x];
            if(x < W)cout << " ";
            else cout << endl;
        }
    }


    return 0;
}