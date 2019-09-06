#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N, M;
    cin >> N >> M;
    ll ans = 0;
    for(ll i = 0; i < N * M; i++){
        char c;
        cin >> c;
        if(c == 'W')ans++;
    }
    cout << ans << endl;

    return 0;
}