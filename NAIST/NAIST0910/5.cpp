#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
const ll INF = 114514191900LL;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

ll N, M, K, S;
ll A, B;
vector<ll>path[101010];
ll depth[101010];
ll tmp_depth[101010];
ll cost[101010];
ll tmp_cost[101010];

int main(){
    for(ll i = 0; i < 101010; i++){
        depth[i] = INF;
        tmp_depth[i] = INF;
        cost[i] = INF;
        tmp_cost[i] = INF;
    }
    scanf("%lld %lld %lld %lld", &N, &M, &K, &S);
    scanf("%lld %lld", &A, &B);
    queue<ll>que;
    for(ll i = 1; i <= K; i++){
        ll c;
        scanf("%lld", &c);
        que.push(c);
        depth[c] = 0;
    }
    for(ll i = 1; i <= M; i++){
        ll a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    while(!que.empty()){
        ll idx = que.front();
        que.pop();
        if(depth[idx] >= S)continue;
        for(ll i = 0; i < path[idx].size(); i++){
            ll to = path[idx][i];
            if(depth[to] < INF)continue;
            depth[to] = depth[idx] + 1;
            que.push(to);
        }
    }
    depth[1] = INF;
    depth[N] = INF;
    priority_queue<P, vector<P>, greater<P> >Q;
    Q.push(P(0, 1));
    while(!Q.empty()){
        ll idx = Q.top().second;
        ll cst = Q.top().first;
        Q.pop();
        if(cost[idx] < INF)continue;
        cost[idx] = cst;
        if(idx == N){
            cout << cst << endl;
            break;
        }
        for(ll i = 0; i < path[idx].size(); i++){
            ll to = path[idx][i];
            if(cost[to] < INF)continue;
            if(depth[to] == 0)continue;
            ll n_cost = cst;
            if(to == N);
            else if(depth[to] <= S)n_cost += B;
            else n_cost += A;
            if(n_cost >= tmp_cost[to])continue;
            tmp_cost[to] = n_cost;
            Q.push(P(n_cost, to));
        }
    }
    return 0;
}