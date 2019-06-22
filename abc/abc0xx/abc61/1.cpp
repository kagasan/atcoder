#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Yes(bool Yes){cout << (Yes ? "Yes" : "No") << endl;};
void YES(bool YES){cout << (YES ? "YES" : "NO") << endl;};


int main(){
    
    ll a, b, c;
    cin >> a >> b >> c;
    Yes(a <= c && c <= b);

    return 0;
}
