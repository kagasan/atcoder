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

ll N, u, v;
vector<ll>path[101010];
ll U[101010], V[101010], parent[101010];
ll V2[101010];
ll ha[101010];

void dep(){
    rep1(i, N)U[i] = INF;
    rep1(i, N)V[i] = INF;
    rep1(i, N)parent[i] = -1;
    queue<ll>Q;
    priority_queue<P>PQ;
    U[u] = 0;
    Q.push(u);
    for(; !Q.empty(); Q.pop()){
        ll idx = Q.front();
        rep(i, path[idx].size()){
            ll to = path[idx][i];
            if(U[to] < INF)continue;
            U[to] = U[idx] + 1;
            Q.push(to);
        }
    }
    V[v] = 0;
    Q.push(v);
    for(; !Q.empty(); Q.pop()){
        ll idx = Q.front();
        ll flg = 1;
        rep(i, path[idx].size()){
            ll to = path[idx][i];
            if(V[to] < INF)continue;
            V[to] = V[idx] + 1;
            Q.push(to);
            parent[to] = idx;
            flg = 0;
        }
        if(flg){
            PQ.push(P(V[idx], idx));
            ha[idx] = 1;
        }
    }
    for(; !PQ.empty(); ){
        ll d = PQ.top().first;
        ll idx = PQ.top().second;
        PQ.pop();
        if(V2[idx])continue;
        V2[idx] = d;
        ll to = parent[idx];
        if(to < 0)continue;
        if(V2[to])continue;
        if(V[to] > V[idx])continue;
        PQ.push(P(V2[idx], to));
    }
}

int main(){

    cin >> N >> u >> v;
    rep1(i, N - 1){
        ll a, b;
        cin >> a >> b;        
        path[a].push_back(b);
        path[b].push_back(a);
    }
    dep();
    // rep1(i, N)cout << i << " : " << U[i] << ", " << V[i] << ", " << V2[i] << endl;

    ll cnt = 0;
    ll idx = u;
    for(;;){
        ll p = parent[idx];
        if(ha[idx] && V[p] <= cnt)break;
        if(ha[idx] && V[p] <= cnt + 1){
            cnt++;
            break;
        }
        if(ha[idx]){
            idx = p;
            cnt++;
            continue;
        }
        if(V[p] > cnt + 1){
            idx = p;
            cnt++;
            continue;
        }
        ll tmp = -1;
        rep(i, path[idx].size()){
            ll to = path[idx][i];
            if(V2[to] == V2[idx] && V[to] > V[idx])tmp = to;
        }
        idx = tmp;
        cnt++;

    }
    cout << cnt << endl;

    return 0;
}
