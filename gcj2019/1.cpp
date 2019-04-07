#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        cout << "Case #" << t << ": ";
        string N, A, B;
        cin >> N;
        A = N;
        B = N;
        int bIdx = 19191919;
        for(int i = 0; i < A.size(); i++){
            if(A[i] == '4'){
                A[i] = '2';
                B[i] = '2';
                bIdx = min(bIdx, i);
            }
            else{
                B[i] = '0';
            }
        }
        cout << A << " " << B.substr(bIdx, B.size() - bIdx) << endl;

    }

    return 0;
}