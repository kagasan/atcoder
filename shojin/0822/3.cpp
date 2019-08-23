#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll x, y, d;
    cin >> x >> y >> d;
    if(x + y < d){
        cout << 0 << endl;
        return 0;
    }
    cout << d + 1 - max(d - x, 0LL) - max(d - y, 0LL) << endl;
    return 0;
}