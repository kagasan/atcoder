#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;

// ベルマンフォード
class BF{
    public:
    ll N;
    ll INF;
    vector<vector<P> >path;
    vector<vector<ll> >rev;
    vector<ll>dist;
    vector<ll>flg;
    BF(ll n, ll inf){
        N = n + 1;
        INF = inf;
        path = vector<vector<P> >(N);
        rev = vector<vector<ll> >(N);
        dist = vector<ll>(N, INF);
        flg = vector<ll>(N, 1);
    }
    void add(ll a, ll b, ll c){
        path[a].push_back(P(b, c));
        rev[b].push_back(a);
    }
    // loopがあったらtrue(目標ノードに到達できないところでloopする可能性あり)
    // 無関係なノードはadjust()で消しておくと良い
    bool make(ll s){
        dist[s] = 0;
        for(ll i = 0; i < N; i++){
            for(ll v = 0; v < N; v++){
                if(dist[v] == INF)continue;
                for(ll k = 0; k < path[v].size(); k++){
                    ll to = path[v][k].first;
                    ll w = path[v][k].second;
                    if(dist[to] > dist[v] + w){
                        dist[to] = dist[v] + w;
                        if(i == N - 1 && flg[to])return true;
                    }
                }
            }
        }
        return false;
    }
    // 目標ノードに到達できないノードのフラグを0にする
    void adjust(ll t){
        flg = vector<ll>(N, 0);
        queue<ll>Q;
        flg[t] = 1;
        Q.push(t);
        while(!Q.empty()){
            ll q = Q.front();
            Q.pop();
            for(ll i = 0; i < rev[q].size(); i++){
                ll j = rev[q][i];
                if(flg[j])continue;
                flg[j] = 1;
                Q.push(j);
            }
        }
    }
    ll get(ll t){
        return dist[t];
    }
};

int main(){

    ll N, M;
    cin >> N >> M;
    BF bf(N + 1, 1e16);
    for(ll i = 0; i < M; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        bf.add(a, b, -c);
    }
    bf.adjust(N);
    if(bf.make(1))cout << "inf" << endl;
    else cout << -bf.get(N) << endl;

    return 0;
}
