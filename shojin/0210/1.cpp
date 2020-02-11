#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> V;
typedef vector<V> V2;
const ll INF = 1145141919;
const ll NUM = 1010;

ll solve(ll M){
    if(M < 1)return -1;
    if(M == 1)return 1;
    V2 flg(NUM, V(NUM, INF));
    ll tmp = 1, sum = 1, N = 1;
    for(;;){
        if(flg[tmp][sum] < INF)return -1;
        flg[tmp][sum] = N;
        if(sum == 0)return N;
        tmp = (tmp * 10) % M;
        sum = (sum + tmp) % M;
        N++;
    }
    return N;
}


int main(){

    ll M;
    cin >> M;
    cout << solve(M) << endl;

    return 0;
}