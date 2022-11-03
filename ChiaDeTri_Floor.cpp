/*Cho mảng đã được sắp xếp A[] gồm N phần tử không có hai phần tử giống nhau và số X. Nhiệm vụ của bạn là tìm floor(X). Trong đó, K=floor(X) là phần tử lớn nhất trong mảng A[] nhỏ hơn hoặc bằng X.

Input Format

Dòng 1 chứa 2 số N và X; Dòng 2 chứa N số của mảng A[]

Constraints

1<=N<=10^5; 1<=X,A[i]<=10^6;

Output Format

In ra đáp án của bài toán nếu tìm thấy số lớn hơn X, trường hợp không tìm thấy in -1

Sample Input 0

9 8
1 2 3 4 5 6 7 8 9 
Sample Output 0

8
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int first(int a[] , int l , int r , int res , int x)
{
    if(l > r) return res;
    int m = (l + r) / 2;
    if(a[m] <= x)
    {
        res = a[m];
        return first(a , m + 1 , r , res , x);
    }
    else return first(a , l , m - 1 , res , x);
    
}

int main()
{
    int n , x; cin >> n >> x;
    int a[n];
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    cout << first(a , 0 , n - 1 , -1 , x);
    return 0;
}