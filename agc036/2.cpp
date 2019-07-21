#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

vector<ll>cnt[202020];

int main(){

    ll N, K;
    cin >> N >> K;
    vector<ll>A(N), nxt(N, -1), cost(N, 0);    
    for(ll i = 0; i < N; i++){
        cin >> A[i];
        cnt[A[i]].push_back(i);
    }
    if(N == 1){
        if(K % 2)cout << A[0] << endl;
        else cout << endl;
        return 0;
    }

    for(ll i = 1; i <= 200000; i++){
        for(ll j = 0; j < cnt[i].size(); j++){
            ll idx = cnt[i][j];
            ll nidx = (cnt[i][(j + 1) % cnt[i].size()] + 1) % N;
            nxt[idx] = nidx;
            if(j + 1 == cnt[i].size() || nidx <= idx)cost[idx] = 1;
            if(nxt[idx] == 0 && j == 0 && idx + 1 == N)cost[idx] = 2;
        }
    }
    ll M = 0;
    for(ll idx = 0; ;){
        M += cost[idx];
        idx = nxt[idx];
        if(idx == 0)break;
    }
    K %= M;
    vector<ll>ans;
    if(K){
        ll idx = 0, k = 0;
        for(;k < K;){
            ll tmpIdx = nxt[idx];
            ll tmpK = k + cost[idx];
            if(tmpK < K || (tmpK == K && tmpIdx == 0)){
                idx = tmpIdx;
                k = tmpK;
                continue;
            }
            // cout << idx << " : " << A[idx] << endl;
            ans.push_back(A[idx]);
            idx++;
            if(idx == N){
                idx = 0;
                k++;
            }
            // cout << idx << ", " << k << endl;
        }
    }
    if(ans.size()){
        for(ll i = 0; i < ans.size(); i++){
            if(i)cout << " ";
            cout << ans[i];
        }
    }
    cout << endl;

    return 0;
}
