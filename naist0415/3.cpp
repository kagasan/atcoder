#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    string s;
    cin >> s;
    for(;;){
        // cout << s << endl;
        if(s == "ABC"){
            cout << "Yes" << endl;
            return 0;
        }
        string tmp = "D";
        if(s.find("ABCBC") != string::npos)tmp = "A";
        if(s.find("AABCC") != string::npos)tmp = "B";
        if(s.find("ABABC") != string::npos)tmp = "C";
        if(tmp == "D")break;
        string s2 = "";
        for(int i = 0; i < s.size(); i++){
            int f = 0;
            if(i + 2 < s.size()){
                if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='C'){
                    f = 1;
                }
            }
            if(f){
                s2 += tmp;
                i += 2;
                continue;
            }
            s2 += s[i];
            if(s[i] == tmp[0])break;
        }
        s = s2;
    }
    cout << "No" << endl;

    return 0;
}