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
typedef pair<ll, P>IP;
ll dy[4] = {0, 1, 0, -1};
ll dx[4] = {1, 0, -1, 0};

ll H, W;
char mp[500][500];
ll cost[500][500];
ll ry, rx;
ll ax, ay;
int main(){
    rep(i, 500)rep(j, 500)mp[i][j] = '#';
    rep(i, 500)rep(j, 500)cost[i][j] = INF;
    cin >> H >> W;
    rep1(y, H)rep1(x, W){
        cin >> mp[y][x];
        if(mp[y][x] == 'R'){
            ry = y;
            rx = x;
        }
        if(mp[y][x] == 'a'){
            ay = y;
            ax = x;
        }
    }
    // rep1(y, H)rep1(x, W)if(mp[y][x] == '@'){
    //     for(ll i = -2; i <= 2; i++){
    //         for(ll j = -2; j <= 2; j++)cout << mp[y + i][x + j];
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    // return 0;
    priority_queue<IP, vector<IP>, greater<IP> >PQ;
    PQ.push(IP(0, P(rx, ry)));
    while(!PQ.empty()){
        ll cst = PQ.top().first;
        ll x = PQ.top().second.first;
        ll y = PQ.top().second.second;
        PQ.pop();
        if(cost[y][x] < INF)continue;
        cost[y][x] = cst;
        rep(i, 4){
            ll X = x + dx[i];
            ll Y = y + dy[i];
            if(mp[Y][X] == '#')continue;
            if(cost[Y][X] < INF)continue;
            if(mp[Y][X] == '.' || mp[Y][X] == 'a')PQ.push(IP(cst + 1, P(X, Y)));
            if(mp[Y][X] == '@' && mp[y + 2 * dy[i]][x + 2 * dx[i]] == '.' && mp[y + 3 * dy[i]][x + 3 * dx[i]] == '.' && cost[y + 2 * dy[i]][x + 2 * dx[i]] == INF){
                PQ.push(IP(cst + 6, P(x + 2 * dx[i], y + 2 * dy[i])));
            }   
        }
    }
    rep1(i, H){
        rep1(j, W){
            if(mp[i][j] == '#')cout << "#";
            else if(cost[i][j] == INF)cout << "+";
            else cout << cost[i][j] % 10;
        }
        cout << endl;
    }
    cout << cost[ay][ax] + 3 << endl;

    return 0;
}