#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){
    ll N;
    cin >> N;
    vector<ll>A(N + 1, 0), B(N + 1, 0);
    for(ll i = 1; i <= N; i++)cin >> A[i] >> B[i];
    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        ans = max(ans, A[i] + B[i]);
    }
    cout << ans << endl;

    return 0;
}