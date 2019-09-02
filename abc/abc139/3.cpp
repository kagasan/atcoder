#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N;
    cin >> N;
    ll ans = 0;
    vector<ll>v(N + 1, 0);
    vector<ll>r(N + 1, 0);
    for(ll i = 1; i <= N; i++)cin >> v[i];
    for(ll i = 1, j = 0; i < N; i++){
        if(v[i] >= v[i + 1]){
            j++;
            ans = max(ans, j);
        }
        else j = 0;
    }
    cout << ans << endl;

    return 0;
}