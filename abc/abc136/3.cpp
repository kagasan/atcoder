#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll ans = 1;
    ll N;
    cin >> N;
    vector<ll>H(N);
    for(ll i = 0; i < N; i++)cin >> H[i];
    for(ll i = N - 2; i >= 0; i--){
        if(H[i] - 1 > H[i + 1])ans = 0;
        else if(H[i] - 1 == H[i + 1])H[i]--;
    }

    Say(ans);

    return 0;
}