#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll N, ans = 1;
    double T, A, H[1010];
    cin >> N >> T >> A;
    for(ll i = 1; i <= N; i++)cin >> H[i];
    for(ll i = 2; i <= N; i++){
        if(abs(A - (T - H[ans] * 0.006)) > abs(A - (T - H[i] * 0.006))){
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}