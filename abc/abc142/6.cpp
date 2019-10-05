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

vector<ll>path[1010];


int main(){

    ll N, M;
    cin >> N >> M;
    rep(i, M){
        ll a, b;
        cin >> a >> b;
        path[a].push_back(b);
    }
    vector<ll>ans;

    rep1(i, N){
        vector<ll>flg(N + 1, INF);
        flg[i] = -1;
        queue<ll>Q;
        Q.push(i);
        ll goal = -1;
        while(!Q.empty() && goal == -1){
            ll idx = Q.front();
            Q.pop();
            rep(j, path[idx].size()){
                ll to = path[idx][j];
                if(to == i){
                    goal = idx;
                    break;
                }
                if(flg[to] != INF)continue;
                flg[to] = idx;
                Q.push(to);
            }
        }
        if(goal == -1)continue;
        vector<ll>tmp;
        for(;;){
            tmp.push_back(goal);
            if(goal == i)break;
            goal = flg[goal];
        }
        if(ans.empty() || ans.size() > tmp.size())ans = tmp;
    }

    if(ans.size()){
        cout << ans.size() << endl;
        rrep(i, ans.size())cout << ans[i] << endl;
    }
    else cout << -1 << endl;

    return 0;
}
