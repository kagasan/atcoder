#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const ll L = 1000000000;

int main(){

    ll s;
    cin >> s;
    if(s < 10000){
        cout << 0 << " " << 0 << " ";
        cout << s << " " << 0 << " ";
        cout << 0 << " " << 1 << endl;
        return 0;
    }
    ll r = ceil(sqrt(s));
    ll red = r * r - s;
    ll x1 = 0, y1 = 0;
    ll x2 = r, y2 = -1;
    ll x3 = -1, y3 = r;
    for(ll i = 2; i * i <= red; i++){
        if(red % i == 0 && i <= L && red / i <= L){
            y2 = i;
            x3 = red / i;
            break;
        }
    }
    if(y2 < 0){
        y2 = red;
        x3 = 1;
    }
    // if(x1 > L)cout << "x1" << endl;
    // if(y1 > L)cout << "y1" << endl;
    // if(x2 > L)cout << "x2" << endl;
    // if(y2 > L)cout << "y2" << endl;
    // if(x3 > L)cout << "x3" << endl;
    // if(y3 > L)cout << "y3" << endl;
    cout << x1 << " " << y1 << " ";
    cout << x2 << " " << y2 << " ";
    cout << x3 << " " << y3 << endl;



    return 0;
}
