#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll W, H, x, y;
    cin >> W >> H >> x >> y;
    ll ans = 0;
    if(x + x == W && y + y == H)ans = 1;
    printf("%.9f %d\n", 0.5 * W * H, ans);

    return 0;
}