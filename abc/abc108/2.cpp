#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

void rot(ll &vx, ll &vy){
    ll tx = -vy;
    ll ty = vx;
    vx = tx;
    vy = ty;
}

int main(){
    
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll vx = x2 - x1;
    ll vy = y2 - y1;
    rot(vx, vy);
    ll x3 = x2 + vx, y3 = y2 + vy;
    rot(vx, vy);
    ll x4 = x3 + vx, y4 = y3 + vy;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;

    return 0;
}