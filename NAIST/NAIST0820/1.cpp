#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll A, B, C;
    cin >> A >> B >> C;
    ll ans = 0;
    for(; C > 0;){
        C -= A;
        ans++;
        if(ans % 7 == 0)C -= B;
    }
    cout << ans << endl;
    
    return 0;    
}