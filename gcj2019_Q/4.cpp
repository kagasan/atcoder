#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

vector<int>solve(string s1, string s2, string s3, string s4){
    vector<int>res;


    return res;
}

int main(){

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N, B, F;
        cin >> N >> B >> F;
        int len[64] = {}, cand[64] = {};
        string res[5];
        for(int i = 0; i < N; i++){
            len[i / 16]++;
            cand[i / 16]++;
            string s;
            for(int j = 0; j < 5; j++){
                s += '0' + ((j%32) < 16);
            }
            cout << s << endl << flush;
            cin >> res[i];
        }
        for(int j = 0, k = 0; j < res[0].size(); j++){
            if((k & 1) != (res[0][j] - '0'))k++;
            cand[k]--;
        }
        vector<int>ans;
        for(int i = 0, j = 0; i < 64; i++){
            int offset = i * 16;
            if(offset >= N)break;
            string s1 = res[1].substr(j, len[i]);
            string s2 = res[1].substr(j, len[i]);
            string s3 = res[1].substr(j, len[i]);
            string s4 = res[1].substr(j, len[i]);
            vector<int>tmp = solve(s1, s2, s3, s4);
            for(int k = 0; k < tmp.size(); k++)ans.push_back(offset + tmp[k]);
            j += len[i];
        }
        for(int i = 0; i < ans.size(); i++){
            if(i)cout << " ";
            cout << ans[i];
        }
        cout << endl << flush;
    }
    
    return 0;
}