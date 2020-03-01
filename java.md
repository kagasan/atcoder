# java
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

## methods
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

## 64bit
```java
List<Long>A = new ArrayList<Long>();
Long a = sc.nextLong();
Long ans = 0L;
```
