#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    int M, K;
    cin >> M >> K;
    if(K >= (1 << M)){
        cout << -1 << endl;
        return 0;
    }
    if(M == 1 && K == 1){
        cout << -1 << endl;
        return 0;
    }
    set<int>S;
    for(int i = 1;K;i+=i){
        if(K & i){
            K -= i;
            S.insert(i);
        }
    }
    vector<int>A, B;
    for(int i = 0; i < (1 << M); i++){
        if(S.find(i) != S.end())A.push_back(i);
        else B.push_back(i);
    }
    vector<int>ans;
    int flg = 1;
    for(int i = 0; i < A.size(); i++){
        if(flg)flg = 0;
        else cout << " ";
        cout << A[i];
    }
    for(int i = 0; i < B.size(); i++){
        if(flg)flg = 0;
        else cout << " ";
        cout << B[i];
    }
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    for(int i = 0; i < A.size(); i++){
        if(flg)flg = 0;
        else cout << " ";
        cout << A[i];
    }
    for(int i = 0; i < B.size(); i++){
        if(flg)flg = 0;
        else cout << " ";
        cout << B[i];
    }

    cout << endl;

    return 0;
}