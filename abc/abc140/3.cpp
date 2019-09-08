#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

ll B[200];

int main(){
    for(ll i = 0; i < 200; i++)B[i] = 1145141919;
    ll N;
    cin >> N;
    for(ll i = 1; i < N; i++){
        cin >> B[i];
    }
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        ans += min(B[i], B[i + 1]);
    }
    cout << ans << endl;

    return 0;
}