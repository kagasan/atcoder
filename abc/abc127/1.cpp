#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll A, B;
    cin >> A >> B;
    if(A <= 5)cout << 0 << endl;
    else if(A <= 12)cout << B / 2 << endl;
    else cout << B << endl;
    return 0;
}