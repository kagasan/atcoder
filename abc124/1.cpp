#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    int A, B;
    int ans = 0;
    cin >> A >> B;
    if(A > B){
        ans += A;
        A--;
    }
    else{
        ans += B;
        B--;
    }
    if(A > B){
        ans += A;
        A--;
    }
    else{
        ans += B;
        B--;
    }
    cout << ans << endl;

    return 0;
}