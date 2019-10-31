#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> IP;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
ll H, W, T;
ll sx, sy, gx, gy;
char mp[20][20];
ll dy[4] = {0, 1, 0, -1};
ll dx[4] = {1, 0, -1, 0};

bool check(ll p){
    ll flg[20][20];
    rep(i, 20)rep(j, 20)flg[i][j] = -1;
    priority_queue<IP, vector<IP>, greater<IP> >Q;
    Q.push(IP(0, P(sx, sy)));
    while(!Q.empty()){
        ll cost = Q.top().first;
        ll x = Q.top().second.first;
        ll y = Q.top().second.second;
        Q.pop();
        if(flg[y][x] >= 0)continue;
        flg[y][x] = cost;
        if(x == gx && y == gy)return (T >= flg[y][x]);
        rep(i, 4){
            ll n_x = x + dx[i];
            ll n_y = y + dy[i];
            if(mp[n_y][n_x] == '@')continue;
            if(flg[n_y][n_x] >= 0)continue;
            if(mp[n_y][n_x] == '#')Q.push(IP(cost + p, P(n_x, n_y)));
            else Q.push(IP(cost + 1, P(n_x, n_y)));
        }
    }    
    return false;
}

int main(){
    rep(i, 20)rep(j, 20)mp[i][j] = '@';
    cin >> H >> W >> T;
    rep1(y, H)rep1(x, W){
        cin >> mp[y][x];
        if(mp[y][x] == 'S'){
            sx = x;
            sy = y;
        }
        if(mp[y][x] == 'G'){
            gx = x;
            gy = y;
        }
    }
    ll ok = 1, ng = T * 2;
    while(ok + 1 < ng){
        ll p = (ok + ng) / 2;
        if(check(p))ok = p;
        else ng = p;
    }
    cout << ok << endl;
    return 0;
}
