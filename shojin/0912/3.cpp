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

vector<ll>path[101010];
ll flg[101010][2];
ll A, B, C;
ll A_cnt, B_cnt;

int main(){

    ll N, M;
    cin >> N >> M;
    rep(i, M){
        ll x, y;
        cin >> x >> y;
        path[x].push_back(y);
        path[y].push_back(x);
    }
    rep1(i, N){
        if(flg[i][0] || flg[i][1])continue;
        if(path[i].empty()){
            C++;
            continue;
        }
        flg[i][0] = 1;
        queue<P>Q;
        Q.push(P(i, 0));
        while(!Q.empty()){
            ll idx = Q.front().first;
            ll v = Q.front().second;
            Q.pop();
            rep(j, path[idx].size()){
                ll to = path[idx][j];
                if(flg[to][v ^ 1])continue;
                flg[to][v ^ 1] = 1;
                Q.push(P(to, v ^ 1));
            }
        }
        if(flg[i][1])B++;
        else A++;
    }
    rep1(i, N){
        if(flg[i][0] && flg[i][1])A_cnt++;
        else if(flg[i][0] || flg[i][1])B_cnt++;
    }

    cout << B * B + 2 * A * B + 2 * A * A + 2 * B_cnt * C + 2 * A_cnt * C + C * C << endl;

    return 0;
}