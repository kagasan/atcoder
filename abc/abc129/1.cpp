#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll P, Q, R;
    cin >> P >> Q >> R;
    ll ans = 333;
    ans = min(ans, P + Q);
    ans = min(ans, R + Q);
    ans = min(ans, P + R);
    cout << ans << endl;

    return 0;
}