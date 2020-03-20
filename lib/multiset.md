# multiset
```cpp
template<class T> T ika_max(multiset<T> &S, const T &x){
    typename multiset<T>::iterator it = S.lower_bound(x);
    if(it == S.end())it--;
    else if(*it > x)it--;
    return *it;
}
template<class T> T ijo_min(multiset<T> &S, const T &x){
    return *S.lower_bound(x);
}
template<class T> T choka_min(multiset<T> &S, const T &x){
    return *S.upper_bound(x);
}
template<class T> T miman_max(multiset<T> &S, const T &x){
    typename set<T>::iterator it = S.lower_bound(x);
    it--;
    return *it;
}
int main(){
    multiset<ll>S;
    rep1(i, 5)rep(j, 2)S.insert(i);
    cout << "ika_max : " << ika_max(S, 3LL) << endl; // 3
    cout << "ika_min : " << ijo_min(S, 3LL) << endl; // 3
    cout << "choka_min : " << choka_min(S, 3LL) << endl; // 4
    cout << "miman_max : " << miman_max(S, 3LL) << endl; // 2
    return 0;
}
```
```cpp
void show(multiset<ll>S){
    for(auto x : S)cout << x << " ";
    cout << endl;
}
int main(){
    multiset<ll>S;
    rep1(i, 3)rep(j, 2)S.insert(i);
    show(S); // 1 1 2 2 3 3
    S.erase(2LL);
    show(S); // 1 1 3 3 
    S.erase(S.find(3LL));
    show(S); // 1 1 3
    return 0;
}
```
