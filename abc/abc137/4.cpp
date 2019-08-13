#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

vector<ll>X[101010];

int main(){

    ll N, M;
    cin >> N >> M;
    for(ll i = 0; i < N; i++){
        ll a, b;
        cin >> a >> b;
        X[a].push_back(b);
    }
    ll ans = 0;
    priority_queue<ll>Q;
    for(ll i = 1; i <= M; i++){
        for(ll j = 0; j < X[i].size(); j++)Q.push(X[i][j]);
        if(Q.empty())continue;
        ans += Q.top();
        Q.pop();
    }
    cout << ans << endl;

    return 0;
}