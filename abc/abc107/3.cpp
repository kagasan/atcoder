#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N, K;
    cin >> N >> K;
    vector<ll>A, B;
    B.push_back(0);
    for(ll i = 0; i < N; i++){
        ll x;
        cin >> x;
        if(x == 0)K--;
        if(x < 0)A.push_back(-x);
        if(x > 0)B.push_back(x);
    }
    A.push_back(0);
    reverse(A.begin(), A.end());
    ll ans = 1000000000;
    for(ll i = 0; i <= K; i++){
        ll j = K - i;
        if(i >= A.size() || j >= B.size())continue;
        ans = min(ans, 2 * A[i] + B[j]);
        ans = min(ans, A[i] + 2 * B[j]);
        
    }
    cout << ans << endl;
    
    return 0;
}