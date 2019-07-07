#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N;
    cin >> N;
    vector<ll>A(N), B(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> A[i];
        if(i % 2 == 0)B[0] += A[i];
        else B[0] -= A[i];
    }
    for(ll i = 0; i < N; i++){
        if(i)B[i] = A[i-1] * 2 - B[i-1];
        cout << B[i];
        if(i + 1 == N)cout << endl;
        else cout << " ";
    }


    return 0;
}