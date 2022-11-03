/*Cho dãy số nguyên A[] gồm N phần tử, nhiệm vụ của bạn là tính tổng của dãy con có tổng lớn nhất.

Input Format

Dòng đầu tiên chứa số nguyên dương N; Dòng thứ 2 chứa N số nguyên của dãy A[]

Constraints

1<=N<=10^5; 1<=abs(A[i])<=10^6

Output Format

In ra đáp án của bài toán

Sample Input 0

5
-3 6 1 -3 6 
Sample Output 0

10
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll findMax(int a[] , int l , int r , int m)
{
    ll tmp = 0 , s1 = 0 , s2 = 0;
    for(int i = m ; i >= l ; i--)
    {
        tmp += a[i];
        s1 = max(s1 , tmp);
    }
    tmp = 0;
    for(int i = m + 1 ; i <= r ; i++)
    {
        tmp += a[i];
        s2 = max(s2 , tmp);
    }
    return s1 + s2;
}
ll Max(int a[] , int l , int r )
{
    if(l == r) return a[l];
    int m = (l + r) / 2;
    ll res1 = Max(a , l , m);
    ll res2 = Max(a , m + 1 , r);
    ll res3 = findMax(a , l , r , m);
    return max({res1 , res2 , res3});
}

int main()
{
    int n ; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    cout << Max(a , 0 , n - 1);
}