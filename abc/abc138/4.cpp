#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

typedef pair<ll, ll>P;

ll N, M;
vector<ll>path[202020];
ll parent[202020];
ll depth[202020];

ll cnt[202020];

int main(){

    cin >> N >> M;
    for(ll i = 0; i < N - 1; i++){
        ll a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    queue<ll>Q;
    Q.push(1);
    depth[1] = 1;
    while(!Q.empty()){
        ll idx = Q.front();
        Q.pop();
        for(ll i = 0; i < path[idx].size(); i++){
            ll nxt = path[idx][i];
            if(depth[nxt])continue;
            depth[nxt] = depth[idx] + 1;
            parent[nxt] = idx;
            Q.push(nxt);
        }
    }
    vector<P>v;
    for(ll i = 1; i <= N; i++){
        v.push_back(P(depth[i], i));
    }
    sort(v.begin(), v.end());

    for(ll i = 0; i < M; i++){
        ll p, x;
        cin >> p >> x;
        cnt[p] += x;
    }
    for(ll i = 0; i < v.size(); i++){
        ll idx = v[i].second;
        for(ll j = 0; j < path[idx].size(); j++){
            ll nxt = path[idx][j];
            if(nxt == parent[idx])continue;
            cnt[nxt] += cnt[idx];
        }
    }

    for(ll i = 1; i <= N; i++){
        cout << cnt[i];
        if(i == N)cout << endl;
        else cout << " ";
    }


    return 0;
}