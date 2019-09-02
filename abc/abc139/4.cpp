#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){
    ll N;
    cin >> N;
    ll M = N - 1;
    ll ans = 0;
    // for(ll i = 1; i < N; i++){
    //     ans += i % (i + 1);
    // }
    ans = M * (M - 1) / 2 + (N - 1);
    cout << ans << endl;


    return 0;
}