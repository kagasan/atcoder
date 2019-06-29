#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

typedef pair<ll, ll> P;

vector<ll>path[101010];
ll cost[101010][3];

int main(){

    for(ll i = 0; i < 101010; i++){
        for(ll j = 0; j < 3; j++){
            cost[i][j] = -3;
        }
    }

    ll N, M, S, T;
    cin >> N >> M;
    for(ll i = 0; i < M; i++){
        ll u, v;
        cin >> u >> v;
        path[u].push_back(v);
    }
    cin >> S >> T;
    queue<P>Q;
    Q.push(P(S, 0));
    cost[S][0] = 0;
    while(!Q.empty()){
        ll A = Q.front().first;
        ll B = Q.front().second;
        Q.pop();
        if(A == T && B == 0)break;
        for(ll i = 0; i < path[A].size(); i++){
            ll a = path[A][i];
            ll b = (B + 1) % 3;
            if(cost[a][b] >= 0)continue;
            Q.push(P(a, b));
            cost[a][b] = cost[A][B] + 1;
        }
    }
    cout << cost[T][0] / 3 << endl;

    return 0;
}