#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N;
    cin >> N;
    vector<ll>A(N+1, 0), B(N, 0);
    for(ll i = 0; i < N + 1; i++)cin >> A[i];
    for(ll i = 0; i < N; i++)cin >> B[i];
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        ll tmp = min(A[i], B[i]);
        ans += tmp;
        A[i] -= tmp;
        B[i] -= tmp;
        tmp = min(A[i+1], B[i]);
        ans += tmp;
        A[i+1] -= tmp;
        B[i] -= tmp;
    }
    cout << ans << endl;

    return 0;
}