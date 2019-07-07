#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){
    
    ll a, b, c;
    cin >> a >> b >> c;
    cout << 2 * (a*b + b*c + c*a) << endl;

    return 0;
}
