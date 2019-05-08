#include "bits/stdc++.h"
using namespace std;

string s;
int ans = 0;
string t;
string t2;
queue<string>f, b;

bool check(){
    t2 = t;
    for(char c = 'b'; c <= 'z'; c++){
        for(int i = 0; i < t2.size(); i++){
            if(t2[i] == c){
                t2[i]--;
                break;
            }
        }
    }
    for(int i = 0; i < s.size(); i++){
        if(t2[i] == '*')break;
        if(t2[i] != s[i])return false;
    }
    return true;
}


void dfs(int idx){
    if(idx == s.size()){
        ans++;
        if(f.size() < 5)f.push(t);
        else{
            b.push(t);
            while(b.size() > 5)b.pop();
        }
    }
    else{
        t[idx] = s[idx];
        if(check())dfs(idx+1);
        if(t[idx] < 'z'){
            t[idx]++;
            if(check())dfs(idx+1);
        }
        t[idx] = '*';
    }
}

int main(){

    for(;cin >> s;){
        if(s == "#")break;
        ans = 0;
        t = string(s.size(), '*');
        dfs(0);
        cout << ans << endl;
        while(!f.empty()){
            cout << f.front() << endl;
            f.pop();
        }
        while(!b.empty()){
            cout << b.front() << endl;
            b.pop();
        }
    }

    return 0;
}