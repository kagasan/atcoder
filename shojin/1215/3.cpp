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
ll mp[3030][3030];
ll D[3030][3030];
ll DR[3030][3030];
ll U[3030][3030];
ll UL[3030][3030];

ll A[3030][3030];
ll B[3030][3030];

ll solve(ll X, ll Y){
    ll ret = 0;
    priority_queue<P, vector<P>, greater<P> >Q;
    for(ll i = 0;; i++){
        ll x = X + i, y = Y + i;
        if(x > W || y > W)break;
        Q.push(P(i, A[y][x]));
        while(!Q.empty()){
            if(Q.top().first + Q.top().second <= i)Q.pop();
            else if(i - Q.top().first + 1 > Q.top().second)Q.pop();
            else break;
        }
        if(!Q.empty())chmax(ret, min(B[y][x], min(i - Q.top().first + 1, Q.top().second)));
    }
    return ret;
}

int main(){
    
    rep(i, 3030)rep(j, 3030)mp[i][j] = 1;

    cin >> H >> W >> K;
    rep(i, K){
        ll y, x;
        cin >> y >> x;
        mp[y][x] = 0;
    }
    
    rep1(x, W)rep1(y, H)U[y][x] = (mp[y][x] ? U[y - 1][x] + 1 : 0);
    rep1(x, W)rrep1(y, H)D[y][x] = (mp[y][x] ? D[y + 1][x] + 1 : 0);
    rep1(x, W)rep1(y, H)UL[y][x] = (mp[y][x] ? UL[y - 1][x - 1] + 1 : 0);
    rrep1(y, H)rep1(x, W)DR[y][x] = (mp[y][x] ? DR[y + 1][x + 1] + 1 : 0);

    rep1(x, W)rep1(y, H)A[y][x] = min(D[y][x], DR[y][x]);
    rep1(x, W)rep1(y, H)B[y][x] = min(U[y][x], UL[y][x]);
    
    ll ans = 0;
    rep1(y, H)chmax(ans, solve(1, y));
    rep1(x, W)chmax(ans, solve(x, 1));
    cout << ans << endl;

    return 0;
}