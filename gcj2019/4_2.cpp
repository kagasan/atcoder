#include "bits/stdc++.h"
using namespace std;

int main(){

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N, B, F;
        cin >> N >> B >> F;
        vector<int>ans;
        string res[5];
        for(int i = 0, j = 16; i < 5; i++, j /= 2){
            for(int k = 0; k < N; k++){
                char code = '1';
                if(k % (j + j) < j)code = '0';
                cout << code;
            }
            cout << endl << flush;
            cin >> res[i];
        }
        
        vector<int>L(64, 10000), R(64, -10000);
        for(int i = 0, j = 0; i < res[0].size(); i++){
            if((j & 1) != (res[0][i] - '0'))j++;
            L[j] = min(L[j], i);
            R[j] = max(R[j], i);
        }
        for(int i = 0; i < 64; i++){
            int treeL[5][16];
            int treeR[5][16];
            for(int j = 0; j < 5; j++){
                for(int k = 0; k < 16; k++){
                    treeL[j][k] = 10000;
                    treeR[j][k] = -10000;
                }
            }
            treeL[0][0] = L[i];
            treeR[0][0] = R[i];
            for(int j = 0, k = 8; j < 4; j++, k /= 2){
                for(int l = 0; l < 16; l += (k + k)){
                    for(int m = treeL[j][l]; m <= treeR[j][l]; m++){
                        if(res[j + 1][m] == '0'){
                            treeL[j + 1][l] = min(treeL[j + 1][l], m);
                            treeR[j + 1][l] = max(treeR[j + 1][l], m);
                        }
                        else{
                            treeL[j + 1][l + k] = min(treeL[j + 1][l + k], m);
                            treeR[j + 1][l + k] = max(treeR[j + 1][l + k], m);
                        }
                    }
                }
            }
            int offset = i * 16;
            for(int j = 0; j < 16; j++){
                if(treeL[4][j] == 10000 && offset + j < N)ans.push_back(offset + j);
            }
        }
        for(int i = 0; i < ans.size(); i++){
            if(i)cout << " ";
            cout << ans[i];
        }
        cout << endl << flush;
        int ok;
        cin >> ok;
    }
    
    return 0;
}