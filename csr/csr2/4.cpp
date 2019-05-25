#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll N;
    cin >> N;
    vector<ll>A(N), B(N);
    for(ll i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        ans += max(A[i], B[i]);
    }
    cout << ans << endl;

    return 0;
}