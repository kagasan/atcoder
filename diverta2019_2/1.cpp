#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N, K;
    cin >> N >> K;
    if(K == 1){
        cout << 0 << endl;
        return 0;
    }
    N -= K;
    cout << N << endl;

    return 0;
}