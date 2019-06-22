#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Yes(bool Yes){cout << (Yes ? "Yes" : "No") << endl;};
void YES(bool YES){cout << (YES ? "YES" : "NO") << endl;};


int main(){
    
    string a, b, c;
    cin >> a >> b >> c;
    YES(a[a.size()-1] == b[0] && b[b.size()-1] == c[0]);

    return 0;
}
