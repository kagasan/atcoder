#include "bits/stdc++.h"
using namespace std;

int L[5][1024], R[5][1024];
char res[5][1024];

void solve(int N, int B, int F){
    for(int i = 0, j = 16; i < 5; i++, j /= 2){
        for(int k = 0; k < N; k++){
            if(k % (j + j) < j)cout << 0;
            else cout << 1;
        }
        cout << endl << flush;
        for(int j = 0; j < N - B; j++)cin >> res[i][j];
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 1024; j++){
            L[i][j] = 10000;
            R[i][j] = -10000;
        }
    }
    for(int i = 0, j = 0; i < N - B; i++){
        if((j & 1) != (res[0][i] - '0'))j++;
        if(L[0][j * 16] > i)L[0][j * 16] = i;
        if(R[0][j * 16] < i)R[0][j * 16] = i;
    }

    for(int i = 0, j = 8; i < 4; i++, j /= 2){
        for(int k = 0; k < 1024; k += (j + j)){
            for(int p = L[i][k]; p <= R[i][k]; p++){
                if(res[i + 1][p] == '0'){
                    if(L[i + 1][k] > p)L[i + 1][k] = p;
                    if(R[i + 1][k] < p)R[i + 1][k] = p;
                }
                else{
                    if(L[i + 1][k + j] > p)L[i + 1][k + j] = p;
                    if(R[i + 1][k + j] < p)R[i + 1][k + j] = p;
                }
            }
        }
    }
    for(int i = 0, j = 0; i < N; i++){
        if(L[4][i] != 10000)continue;
        if(j)cout << " ";
        cout << i;
        j = 1;
    }
    cout << endl << flush;
    cin >> N;
}

int main(){

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N, B, F;
        cin >> N >> B >> F;
        solve(N, B, F);
    }
    
    return 0;
}