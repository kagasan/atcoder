#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll N;
    cin >> N;
    vector<ll>A(N), B(N);
    for(ll i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }
    set<pair<int, int> >S;
    for(ll i = 0; i < N; i++){
        S.insert(pair<int, int>(min(A[i], B[i]), max(A[i], B[i])));
    }
    cout << S.size() << endl;

    return 0;
}