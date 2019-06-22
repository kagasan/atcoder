#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Yes(bool Yes){cout << (Yes ? "Yes" : "No") << endl;};
void YES(bool YES){cout << (YES ? "YES" : "NO") << endl;};


int main(){
    
    ll A, B;
    cin >> A >> B;
    if(A == B)cout << "Draw" << endl;
    else if(A == 1 || (A > B && B != 1))cout << "Alice" << endl;
    else cout << "Bob" << endl;

    return 0;
}
