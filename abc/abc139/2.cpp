#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll A, B;
    cin >> A >> B;
    ll tmp = 1;
    ll ans = 0;
    while(tmp < B){
        ans++;
        tmp += (A - 1);
    }
    cout << ans << endl;

    return 0;
}