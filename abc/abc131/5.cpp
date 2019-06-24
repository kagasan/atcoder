#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;
queue<P>Q;

int main(){

    ll N, K;
    cin >> N >> K;
    ll tmp[111] = {};
    ll sum = 0;
    for(ll i = 2; i <= N; i++){
        tmp[i] = i;
        sum += (N - i);
        Q.push(P(1, i));
    }  
    if(sum < K){
        cout << -1 << endl;
        return 0;
    }

    for(ll idx = N; sum > K; sum--){
        if(tmp[idx] == N)idx--;
        Q.push(P(idx, tmp[idx] + 1));
        tmp[idx]++;
    }
    cout << Q.size() << endl;
    while(!Q.empty()){
        cout << Q.front().first << " " << Q.front().second << endl;
        Q.pop();
    }



    return 0;
}