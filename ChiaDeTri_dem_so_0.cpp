/*Cho mảng A[] gồm N phần tử chỉ bao gồm các số 0 và 1. Các số 0 được đặt trước các số 1. Hãy đếm các số 0 với thời gian log(N).

Input Format

Dòng 1 chứa số nguyên dương N; Dòng thứ 2 chứa N số nguyên của mảng A[]

Constraints

1<=N<=10^6; 0<=A[i]<=1;

Output Format

In ra đáp án của bài toán, nếu số 0 không xuất hiện in ra 0

Sample Input 0

6
0 0 1 1 1 1 
Sample Output 0

2
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int first(int a[] , int l , int r , int res)
{
    if(l > r) return res;
    int m = (l + r) / 2;
    if(a[m] == 0)
    {
        res = m;
        return first(a , l , m - 1 , res);
    }
    else return first(a , l , m - 1 , res);
}
int last(int a[] , int l , int r , int res)
{
    if(l > r) return res;
    int m = (l + r) / 2;
    if(a[m] == 0)
    {
        res = m;
        return last(a , m + 1 , r , res);
    }
    else return last(a , l , m - 1 , res);
}
int main()
{
    int n ; cin >> n;
    int a[n];
    for(int i = 0 ; i < n; i++) cin >> a[i];
    if(first(a , 0 , n - 1 , -1) != -1)
    {
        cout << last(a , 0 , n - 1 , -1) - first(a , 0 , n - 1 , -1) + 1;
    }
    else cout << 0;
}