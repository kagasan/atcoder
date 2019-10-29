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

map<ll, ll>s2m(set<ll>S){
    map<ll, ll>m;
    ll idx = 0;
    for(set<ll>::iterator it = S.begin(); it != S.end(); it++){
        m[*it] = idx;
        idx++;
    }
    return m;
}

ll dy[4] = {1, 0, -1, 0};
ll dx[4] = {0, 1, 0, -1};
ll path[111][111][4];
ll flg[111][111];

int main(){

	for(ll N; cin >> N, N; ){
        rep(i, 111)rep(j, 111)rep(k, 4)path[i][j][k] = 0;
        rep(i, 111)rep(j, 111)flg[i][j] = 0;
        ll L[55], T[55], R[55], B[55];
        set<ll>X, Y;
        X.insert(-1);
        X.insert(INF);
        Y.insert(-1);
        Y.insert(INF);
        rep(i, N){
            cin >> L[i] >> T[i] >> R[i] >> B[i];
            X.insert(L[i]);
            X.insert(R[i]);
            Y.insert(T[i]);
            Y.insert(B[i]);
        }
        map<ll, ll> XM = s2m(X), YM = s2m(Y);

        rep(i, N){
            ll l = XM[L[i]];
            ll t = YM[T[i]];
            ll r = XM[R[i]];
            ll b = YM[B[i]];
            for(ll x = l; x < r; x++){
                path[t][x][2] = 1;
                path[t - 1][x][0] = 1;
                path[b][x][2] = 1;
                path[b - 1][x][0] = 1;
            }
            for(ll y = b; y < t; y++){
                path[y][l][3] = 1;
                path[y][l - 1][1] = 1;
                path[y][r][3] = 1;
                path[y][r - 1][1] = 1;                
            }
        }
        ll cnt = 0;
        rep(y, 108)rep(x, 108){
            if(flg[y][x])continue;
            cnt++;
            flg[y][x] = cnt;
            queue<P>Q;
            Q.push(P(x, y));
            while(!Q.empty()){
                ll nx = Q.front().first;
                ll ny = Q.front().second;
                Q.pop();
                rep(i, 4){
                    ll tx = nx + dx[i];
                    ll ty = ny + dy[i];
                    if(tx < 0 || ty < 0 || tx >= 108 || ty >= 108)continue;
                    if(flg[ty][tx])continue;
                    if(path[ny][nx][i])continue;
                    flg[ty][tx] = cnt;
                    Q.push(P(tx, ty));
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}