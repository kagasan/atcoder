#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;
typedef pair<ll, P>IP;
const ll INF = 1145141919;
ll N, M, X;
ll room[10101];
vector<P>path[10101];
ll score[10101][444];

int main(){
    for(ll i = 0; i < 10101; i++){
        for(ll j = 0; j < 444; j++){
            score[i][j] = INF;
        }
    }

    ll N, M, X;
    cin >> N >> M >> X;
    for(ll i = 1; i <= N; i++)cin >> room[i];
    for(ll i = 1; i <= M; i++){
        ll a, b, d;
        cin >> a >> b >> d;
        path[a].push_back(P(b, d));
        path[b].push_back(P(a, d));
    }
    
    priority_queue<IP, vector<IP>, greater<IP> >Q;
    Q.push(IP(0, P(1, -X)));
    while(!Q.empty()){
        ll s = Q.top().first;
        ll r = Q.top().second.first;
        ll t = Q.top().second.second;
        Q.pop();
        if(r == N){
            cout << s << endl;
            break;
        }
        if(score[r][210 + t] < INF)continue;
        score[r][210 + t] = s;
        for(ll i = 0; i < path[r].size(); i++){
            ll nr = path[r][i].first;
            ll d = path[r][i].second;
            ll nt = 0;
            ll ns = s + d;
            if(t < 0)nt = min(0LL, t + d);
            else if(t > 0)nt = max(0LL, t - d);
            if(room[nr] == 2 && nt < 0)continue;
            if(room[nr] == 0 && nt > 0)continue;
            if(room[nr] == 2)nt = X;
            if(room[nr] == 0)nt = -X;
            if(score[nr][210 + nt] < INF)continue;
            Q.push(IP(ns, P(nr, nt)));
        }
    }

    return 0;    
}