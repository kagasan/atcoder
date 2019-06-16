#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll ans = 0;
    ll N, M;
    cin >> N;
    vector<string>A(N);
    for(ll i = 0; i < N; i++)cin >> A[i];
    cin >> M;
    vector<string>B(M);
    for(ll i = 0; i < M; i++)cin >> B[i];
    for(ll i = 0; i < N; i++){
        ll tmp = 0;
        for(ll j = 0; j < N; j++)if(A[i] == A[j])tmp++;
        for(ll j = 0; j < M; j++)if(A[i] == B[j])tmp--;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    
    return 0;
}