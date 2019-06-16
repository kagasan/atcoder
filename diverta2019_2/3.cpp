#include "bits/stdc++.h"
using namespace std;
typedef long long ll;



int main(){

    ll N;
    cin >> N;
    vector<ll>A(N);
    for(ll i = 0; i < N; i++)cin >> A[i];
    A.push_back(-191919);
    sort(A.begin(), A.end());
    A[0] = A[N];
    A[N] = -1;
    ll M = A[0];
    vector<ll>X, Y;
    for(ll i = 1; i < N; i++){
        if(A[i + 1] > 0){
            X.push_back(min(M, A[i]));
            Y.push_back(max(M, A[i]));
            M = -abs(M - A[i]);
        }
        else{
            X.push_back(max(M, A[i]));
            Y.push_back(min(M, A[i]));
            M = abs(M - A[i]);
        }
    }
    cout << M << endl;
    for(ll i = 0; i < X.size(); i++){
        cout << X[i] << " " << Y[i] << endl;
    }
    
    return 0;
}