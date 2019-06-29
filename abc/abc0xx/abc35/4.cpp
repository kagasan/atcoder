#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};
typedef pair<ll, ll>P;

ll A[101010];
ll from1[101010];
ll to1[101010];
vector<P>path[101010];
vector<P>rpath[101010];

int main(){
    for(ll i = 0; i < 101010; i++){
        from1[i] = 1145141919;
        to1[i] = 1145141919;
    }    
    ll N, M, T;
    cin >> N >> M >> T;
    for(ll i = 1; i <= N; i++)cin >> A[i];
    for(ll i = 0; i < M; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        path[a].push_back(P(b, c));
        rpath[b].push_back(P(a, c));
    }
    priority_queue<P, vector<P>, greater<P> >Q;
    Q.push(P(0, 1));
    while(!Q.empty()){
        ll cost = Q.top().first;
        ll pos = Q.top().second;
        Q.pop();
        if(from1[pos] < cost)continue;
        from1[pos] = cost;
        for(ll i = 0; i < path[pos].size(); i++){
            ll nxt = path[pos][i].first;
            ll w = path[pos][i].second;
            if(from1[nxt] < cost + w)continue;
            Q.push(P(cost + w, nxt));
        }
    }
    priority_queue<P, vector<P>, greater<P> >Q2;
    Q2.push(P(0, 1));
    while(!Q2.empty()){
        ll cost = Q2.top().first;
        ll pos = Q2.top().second;
        Q2.pop();
        if(to1[pos] < cost)continue;
        to1[pos] = cost;
        for(ll i = 0; i < rpath[pos].size(); i++){
            ll nxt = rpath[pos][i].first;
            ll w = rpath[pos][i].second;
            if(to1[nxt] < cost + w)continue;
            Q2.push(P(cost + w, nxt));
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        ll tmp = T - from1[i] - to1[i];
        if(tmp < 0)continue;
        ans = max(ans, tmp * A[i]);
    }
    cout << ans << endl;
    

    return 0;
}
