#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int era[102000];
void initEra(){
    for(int i = 2; i < 102000; i++)era[i] = 1;
    for(int i = 2; i * i < 102000; i++){
        if(era[i] == 0)continue;
        for(int j = i + i; j < 102000; j += i)era[j] = 0;
    }
}

int main(){
    initEra();
    vector<int>prime;
    for(int i = 0; i < 102000; i++){
        if(era[i])prime.push_back(i);
    }
    
    for(int n, p; cin >> n >> p;){
        if(n < 0)break;
        vector<int>A;
        for(int i = 0; A.size() < p; i++){
            if(prime[i] > n)A.push_back(prime[i]);
        }
        vector<int>B;
        for(int i = 0; i < A.size(); i++){
            for(int j = i; j < A.size(); j++){
                B.push_back(A[i] + A[j]);
            }
        }
        sort(B.begin(), B.end());
        cout << B[p - 1] << endl;
        // for(int i = 0; i < 10; i++)cout << "#" << B[i] << endl; 
        // break;
    }

    return 0;
}