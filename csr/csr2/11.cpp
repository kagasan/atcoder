#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    map<ll, vector<ll> >path;
    map<ll, ll>cnt;
    ll N;
    cin >> N;
    for(ll i = 0; i < N; i++){
        ll A, B;
        cin >> A >> B;
        path[A].push_back(B);
        path[B].push_back(A);
        cnt[A]++;
        cnt[B]++;
    }
    queue<ll>Q;
    for(map<ll, ll>::iterator it = cnt.begin(); it != cnt.end(); it++){
        ll idx = (*it).first;
        ll num = (*it).second;
        if(num == 1)Q.push(idx);
    }
    ll ans = 0;
    while(!Q.empty()){
        ll idx = Q.front();
        Q.pop();
        if(cnt[idx] == 0)continue;
        ans++;
        cnt[idx]--;
        for(ll i = 0; i < path[idx].size(); i++){
            ll nxt = path[idx][i];
            if(cnt[nxt] == 0)continue;
            cnt[nxt]--;
            if(cnt[nxt] == 1)Q.push(nxt);
            break;
        }
    }
    for(map<ll, ll>::iterator it = cnt.begin(); it != cnt.end(); it++){
        ll idx = (*it).first;
        ll num = (*it).second;
        if(num > 0)ans++;
    }
    cout << ans << endl;

    return 0;
}