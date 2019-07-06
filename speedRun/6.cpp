#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){
    ll N;
    cin >> N;
    vector<ll>vec(N);
    for(ll i = 0; i < N; i++)cin >> vec[i];
    ll ans = 0, mx = 0;
    for(ll i = 0; i < N; i++){
        if(vec[i] > mx)ans++;
        mx = max(mx, vec[i]);
    }
    cout << ans << endl;
    return 0;
}