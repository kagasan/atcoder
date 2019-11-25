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

ll N;
vector<ll>path[101010];
ll flg[101010];
ll a[101010], b[101010];
map<P, ll>ans;
ll mx = 1;
int main(){

    cin >> N;
    for(ll i = 1; i < N; i++){
        cin >> a[i] >> b[i];
        path[a[i]].push_back(b[i]);
    }
    queue<ll>Q;
    Q.push(1);
    flg[1] = -1;
    while(!Q.empty()){
        ll idx = Q.front();
        Q.pop();
        ll nxt = 1;
        rep(i, path[idx].size()){
            ll to = path[idx][i];
            if(flg[to])continue;
            if(nxt == flg[idx])nxt++;
            flg[to] = nxt;
            Q.push(to);
            ans[P(idx, to)] = nxt;
            ans[P(to, idx)] = nxt;
            chmax(mx, nxt);
            nxt++;
        }
    }

    cout << mx << endl;
    for(ll i = 1; i < N; i++){
        cout << ans[P(a[i], b[i])] << endl;
    }
    

    return 0;
}