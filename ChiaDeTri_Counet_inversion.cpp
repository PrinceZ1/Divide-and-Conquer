/*Cho mảng A[] gồm N phần tử, hãy đếm số lượng cặp A[i], A[j] sao cho i < j và A[i] > A[j];

Input Format

Dòng đầu tiên chứa số nguyên dương N; Dòng thứ 2 gồm N phần tử của mảng A

Constraints

1<=N<=10^6; 1<=A[i]<=10^6;

Output Format

In ra đáp án của bài toán

Sample Input 0

9
16 14 10 13 19 14 17 18 16 
Sample Output 0

12
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;
ll meger(int a[] , int l , int r , int m)
{
    vector<int>x(a + l  , a + m + 1);
    vector<int>y(a + m + 1 , a + r + 1);
    ll cnt = 0;
    int i = 0 , j = 0;
    while(i < x.size() && j < y.size())
    {
        if(x[i] > y[j])
        {
            cnt += x.size() - i;
            a[l++] = y[j++];
        }
        else
        {
            a[l++] = x[i++];
        }
    }
    while(i < x.size()) a[l++] = x[i++];
    while(j < y.size()) a[l++] = y[j++];
    return cnt;
}
ll megerSort(int a[] , int l , int r)
{
    ll ans = 0;
    if(l < r)
    {
        int m = (l + r) / 2;
        ans += megerSort(a ,l , m);
        ans += megerSort(a , m + 1 , r);
        ans += meger(a , l , r , m);
    }
    return ans;
}
int main()
{
    int n ; cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    cout << megerSort(a , 0 , n - 1);
}