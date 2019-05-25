#include <bits/stdc++.h>
using namespace std;

int hoge[5] = {5, 7, 5, 7, 7};

int main(){
    
    for(int n; cin >> n, n;){
        vector<int>vec(n, 0);
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            vec[i] = s.size();
        }
        for(int i = 0;;i++){
            int f = 0;
            int cnt = 0;
            int idx = 0;
            for(int j = i; j < n; j++){
                cnt += vec[j];
                if(cnt > hoge[idx])break;
                if(cnt == hoge[idx]){
                    cnt = 0;
                    idx++;
                }
                if(idx == 5){
                    f = 1;
                    break;
                }
            }
            if(f){
                cout << i + 1 << endl;
                break;
            }
        }
    }
    
    return 0;    
}