# set
set，集合，同じ要素の重複を許さない．  
だいたいの処理がO(log N)でできる素敵なデータ構造．  
番兵は積極的に入れよう．

# include
```cpp
#include <set>
// bits/stdc++.hにも入ってる
```

# insert, erase, size, empty, clear
```cpp
set<ll>S;   // empty
S.insert(1);// 1
S.insert(2);// 1, 2
S.insert(2);// 1, 2
S.insert(3);// 1, 2, 3
S.erase(3); // 1, 2
S.erase(4); // 1, 2
cout << S.size() << endl;
// 2
cout << S.empty() << endl;
// false
S.clear();
cout << S.empty() << endl;
// true
```
- 既に挿入済みの要素を追加しようとしたり，ない要素を削除しようとしてもエラーにはならない．
- erase()は引数に値やイテレータを渡せる．

# find_from_set
```cpp
template<class T> bool find_from_set(set<T> &S, const T &t){
    return S.find(t) != S.end();
}
set<ll>S;   // empty
S.insert(1);// 1
cout << find_from_set(S, 1LL) << endl;
// true
cout << find_from_set(S, 0LL) << endl;
// false
```

# minimum, maximum
```cpp
template<class T> T minimum_from_set(set<T> &S){
    return *S.begin();
}
template<class T> T maximum_from_set(set<T> &S){
    typename set<T>::iterator it = S.end();
    it--;
    return *it;
}
set<ll>S;
S.insert(1);
S.insert(2);
S.insert(3);
cout << minimum_from_set(S) << endl;
// 1
cout << maximum_from_set(S) << endl;
// 3
```
- 最小値，最大値queueみたいなもんよ．
- pushはinsert, popはeraseでやる．

# 以上以下未満超過
```cpp
template<class T> T ika_max(set<T> &S, const T &x){
    typename set<T>::iterator it = S.lower_bound(x);
    if(it == S.end())it--;
    else if(*it > x)it--;
    return *it;
}
template<class T> T ijo_min(set<T> &S, const T &x){
    return *S.lower_bound(x);
}
template<class T> T choka_min(set<T> &S, const T &x){
    return *S.upper_bound(x);
}
template<class T> T miman_max(set<T> &S, const T &x){
    typename set<T>::iterator it = S.lower_bound(x);
    it--;
    return *it;
}
```
- くそ便利