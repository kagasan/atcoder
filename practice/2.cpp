#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

// 200point
void AB(int N){
    string s = "A";
    for(int i = 1; i < N; i++){
        char c = 'A' + i;
        int mn = -1, mx = i;
        while(mn + 1 < mx){
            int p = (mn + mx) / 2;
            cout << "? " << c << " " << s[p] << endl << flush;
            char code;
            cin >> code;
            if(code == '<')mx = p;
            else mn = p;
        }
        stringstream ss;
        for(int j = -1; j < i; j++){
            if(j >= 0)ss << s[j];
            if(mn == j)ss << c;
        }
        s = ss.str();
    }
    cout << "! " << s << endl << flush;
}

// 300point
void C(int N){
    vector<int>vec(N);
    vector<string>strs;
    vector<int>flgs;
    for(int i = 0; i < N; i++)vec[i] = i;
    do{
        string str = "";
        for(int i = 0; i < N; i++)str += ('A' + vec[i]);
        strs.push_back(str);
        flgs.push_back(1);
    }while(next_permutation(vec.begin(), vec.end()));
    int num = strs.size();
    while(num > 1){
        char c1 = 'A', c2 = 'A';
        
    }
    for(int i = 0; i < flgs.size(); i++){
        if(flgs[i] == 1){
           cout << strs[i] << endl << flush;
        }
    }
}

int main(){

    int N, Q;
    cin >> N >> Q;
    if(N == 26)AB(N);
    else C(N);

    return 0;
}
