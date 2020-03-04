# java

## helpful
- https://qiita.com/p_shiki37/items/3902f4e3adc3aeb382f1

## template
```java
import java.util.*;
public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        // code here!
    }
}
```
## input
```java
int a = sc.nextInt();
int b = sc.nextInt();
int c = sc.nextInt();
String s = sc.next();

char c = sc.next().charAt(0);
```

## output
```java
System.out.print("a");
System.out.print("b");
System.out.print("c");
System.out.print("\n");
System.out.println((a + b + c) + " " + s);
```

## list
```java
// empty
List<Integer>A = new ArrayList<Integer>();
for(int i = 0; i < 5; i++)A.add(i);
for(int i = 0; i < A.size(); i++){
  System.out.print(A.get(i) + (i + 1 == A.size() ? "\n" : " "));
}

// get
A.get(i);

// set
A.set(i, null);

// sort
Collections.sort(A);

// reverse
Collections.reverse(A);
```
```java
// 2d list
ArrayList<ArrayList<Integer>> A = new ArrayList<ArrayList<Integer>>();
for(int i = 0; i <= N; i++)A.add(new ArrayList<Integer>());
A.size();
A.get(0).size();
A.get(0).add(1);
A.get(0).get(0);
```


## array
```java
// 0埋め
int A[] = new int[N + 1];
int L[] = new int[101010];
int R[] = new int[101010];
for(int i = 1; i <= N; i++){
    A[i] = sc.nextInt();
}
```
```java
// 2d array
int[][] A = new int[3][3];
```

## String
```java
String s = sc.next();
s = "0123456";
s.substring(2, 3);
s.charAt(3);
s.length();
```

## queue
```java
Queue<Integer> Q = new ArrayDeque<Integer>();
Q.add(1);
Q.add(2);
while(true){
    Integer x = Q.poll();
    if(x == null)break;
    System.out.println(x);
}
```

## TreeSet
```java
TreeSet<Integer> TS = new TreeSet<Integer>();
TS.add(5);
TS.remove(0);
TS.remove(5);
TS.ceiling(2);
```
```java
// 2d TreeSet
ArrayList<TreeSet<Integer>>S = new ArrayList<TreeSet<Integer>>();
for(int i = 0; i < 26; i++)S.add(new TreeSet<Integer>());
for(int i = 0; i < 26; i++)S.get(i).add(505050);
```

## methods
```java
import java.util.*;
public class Main {
    public static int max(int a, int b){return (a > b ? a : b);}
    public static int min(int a, int b){return (a < b ? a : b);}
    public static int gcd(int a, int b){return (b > 0 ? gcd(b, a % b) : a);}
    public static int lcm(int a, int b){return a / gcd(a, b) * b;}
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        
        
    }
}
```

## 64bit
```java
List<Long>A = new ArrayList<Long>();
Long a = sc.nextLong();
Long ans = 0L;
```
