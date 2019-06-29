#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N;
    cin >> N;
    ll p[100];
    for(ll i = 1; i <= N; i++)cin >> p[i];
    ll ans = 0;
    for(ll i = 2; i < N; i++){
        if((p[i] < p[i + 1]) && (p[i] < p[i - 1]));
        else if((p[i] > p[i + 1]) && (p[i] > p[i - 1]));
        else ans++;
    }
    cout << ans << endl;

    return 0;
}