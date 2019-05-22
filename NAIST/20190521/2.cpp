#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

void split(string s, vector<string>&v){
    string tmp = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '"'){
            v.push_back(tmp);
            tmp = "";
        }
        else tmp += s[i];
    }
    if(tmp.size())v.push_back(tmp);
}

int main(){

    for(string s1;cin>>s1;){
        if(s1==".")break;
        string s2;
        cin >> s2;
        int cnt = 0;
        vector<string>v1, v2;
        split(s1, v1);
        split(s2, v2);
        if(v1.size() == v2.size()){
            for(int i = 0; i < v1.size(); i++){
                if(v1[i] != v2[i]){
                    if(i%2)cnt++;
                    else cnt = 2;
                }
            }
        }
        else{
            cnt = 2;
        }
        if(cnt == 0)cout << "IDENTICAL" << endl;
        if(cnt == 1)cout << "CLOSE" << endl;
        if(cnt > 1)cout << "DIFFERENT" << endl;
        
    }

    return 0;
}