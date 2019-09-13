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
vector<ll>node[101010];
ll flg[101010];
ll A[101010];
ll cnt = 0;

int main(){

    ll N, M;
    cin >> N >> M;
    rep(i, N)cin >> A[i];
    rep(i, M){
        ll x, y;
        cin >> x >> y;
        path[x].push_back(y);
        path[y].push_back(x);
    }
    rep(i, N){
        if(flg[i])continue;
        cnt++;
        flg[i] = cnt;
        stack<ll>S;
        S.push(i);
        while(!S.empty()){
            ll idx = S.top();
            S.pop();
            node[cnt].push_back(A[idx]);
            rep(j, path[idx].size()){
                ll to = path[idx][j];
                if(flg[to])continue;
                flg[to] = cnt;
                S.push(to);
            }
        }
    }
    if(cnt == 1){
        cout << 0 << endl;
        return 0;
    }
    ll sum = 0;
    vector<ll>v;
    rep1(i, cnt){
        sort(node[i].begin(), node[i].end());
        sum += node[i][0];
        for(ll j = 1; j < node[i].size(); j++)v.push_back(node[i][j]);
    }
    ll req = cnt - 2;
    if(v.size() < req){
        cout << "Impossible" << endl;
        return 0;
    }
    sort(v.begin(), v.end());
    rep(i, req)sum += v[i];
    cout << sum << endl;
    
    return 0;
}