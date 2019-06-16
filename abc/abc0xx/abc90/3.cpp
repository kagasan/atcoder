#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll H, W;
    cin >> H >> W;
    if(H == 1 && W == 1)cout << 1 << endl;
    else if(H == 1)cout << W - 2 << endl;
    else if(W == 1)cout << H - 2 << endl;
    else cout << (H - 2) * (W - 2) << endl;

    return 0;
}