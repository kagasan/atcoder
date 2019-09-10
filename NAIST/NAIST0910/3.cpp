#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
const ll INF = 1145141919;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

ll mp[55][55];
ll cost[55][3];


int main(){

    ll H, W;
    cin >> H >> W;
    ll ans = INF;
    for(ll y = 1; y <= H; y++){
        for(ll x = 1; x <= W; x++){
            char c;
            cin >> c;
            cost[y][0]++;
            if(c == 'W')cost[y][0]--;
            cost[y][1]++;
            if(c == 'B')cost[y][1]--;
            cost[y][2]++;
            if(c == 'R')cost[y][2]--;
        }
    }
    for(ll l = 1; l <= H; l++){
        for(ll r = l + 2; r <= H; r++){
            ll tmp = 0;
            for(ll y = 1; y <= H; y++){
                if(y <= l)tmp += cost[y][0];
                else if(y >= r)tmp += cost[y][2];
                else tmp += cost[y][1];
            }
            chmin(ans, tmp);
        }
    }
    cout << ans << endl;

    return 0;
}