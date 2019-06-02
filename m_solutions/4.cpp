#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

vector<ll>path[10101];
ll ans[10101];

int main(){
    ll N;
    cin >> N;
    ll sum = 0, mx = 0;
    for(ll i = 1; i < N; i++){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    vector<ll>v(N);
    for(ll i = 0; i < N; i++){
        cin >> v[i];
        sum += v[i];
        mx = max(mx, v[i]);
    }
    sort(v.begin(), v.end(), greater<ll>());
    queue<ll>Q;
    Q.push(0);
    for(int cnt = 0; !Q.empty();){
        ll idx = Q.front();
        Q.pop();
        ans[idx] = v[cnt];
        cnt++;
        for(ll i = 0; i < path[idx].size(); i++){
            ll nxt = path[idx][i];
            if(ans[nxt])continue;
            Q.push(nxt);
        }
    }
    cout << sum - mx << endl;
    for(ll i = 0; i < N; i++){
        cout << ans[i];
        if(i+1==N)cout << endl;
        else cout << " ";
    }
    return 0;
}
