#include <bits/stdc++.h>
using namespace std;

int main(){
    
    for(int n; cin >> n, n;){
        vector<int>dep(n, 0);
        vector<int>val(n, 0);
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < s.size(); j++){
                if(s[j] == '.')dep[i]++;
                else if(s[j] == '+')val[i] = -1;
                else if(s[j] == '*')val[i] = -2;
                else val[i] = s[j] - '0';
            }
        }
        for(;;){
            int idx = -1;
            for(int i = 0; i < val.size(); i++){
                if(val[i] == -1 || val[i] == -2){
                    idx = i;
                }
            }
            if(idx == -1)break;
            if(val[idx] == -1){
                val[idx] = 0;
                for(int i = idx + 1; i < val.size();){
                    if(dep[i] != dep[idx] + 1)break;
                    val[idx] += val[i];
                    val.erase(val.begin() + i);
                    dep.erase(dep.begin() + i);
                }
            }
            else{
                val[idx] = 1;
                for(int i = idx + 1; i < val.size();){
                    if(dep[i] != dep[idx] + 1)break;
                    val[idx] *= val[i];
                    val.erase(val.begin() + i);
                    dep.erase(dep.begin() + i);
                }
            }
        }
        cout << val[0] << endl;
    }
    
    return 0;    
}