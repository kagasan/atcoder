#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){
    
    ll ans = 1145141919;
    ll L1, L2, L3;
    cin >> L1 >> L2 >> L3;
    ll R, B, Y;
    cin >> R >> B >> Y;
    ans = min(ans, R * (L3 + L1) + B * (L1 + L2) + Y * (L2 + L3));
    ans = min(ans, R * (L3 + L1) + Y * (L1 + L2) + B * (L2 + L3));
    ans = min(ans, B * (L3 + L1) + R * (L1 + L2) + Y * (L2 + L3));
    ans = min(ans, B * (L3 + L1) + Y * (L1 + L2) + R * (L2 + L3));
    ans = min(ans, Y * (L3 + L1) + R * (L1 + L2) + B * (L2 + L3));
    ans = min(ans, Y * (L3 + L1) + B * (L1 + L2) + R * (L2 + L3));
    cout << ans * 2 << endl;

    return 0;
}