#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

ll A[100], B[100], C[100];

int main(){

    ll N;
    cin >> N;
    for(ll i = 1; i <= N; i++)cin >> A[i];
    for(ll i = 1; i <= N; i++)cin >> B[i];
    for(ll i = 1; i < N; i++)cin >> C[i];
    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        ans += B[A[i]];
        if(A[i] + 1 == A[i + 1])ans += C[A[i]];
    }
    cout << ans << endl;
    return 0;
}