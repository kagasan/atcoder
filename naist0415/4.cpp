#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    ll W;
    cin >> W;
    vector<ll>A(W), R(W, 0), L(W, 0);
    for(int i = 0; i < W; i++)cin >> A[i];
    for(ll i = 0, mx = 0; i < W; i++){
        mx--;
        if(A[i] == 0){
            mx = 202020;
            continue;
        }
        if(A[i] < 0){
            mx = min(mx, -A[i]);
            continue;
        }
        L[i] = min(A[i], mx);
    }
    for(ll i = W - 1, mx = 0; i >= 0; i--){
        mx--;
        if(A[i] == 0){
            mx = 202020;
            continue;
        }
        if(A[i] < 0){
            mx = min(mx, -A[i]);
            continue;
        }
        R[i] = max(min(A[i], mx), 0LL);
    }

    ll ans = 0;
    for(int i = 0; i < W; i++)ans += max(R[i], L[i]);
    cout << ans << endl;

    return 0;
}