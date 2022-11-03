/*Cho hai mảng đã được sắp xếp A[], B[] gồm N, M phần tử theo thứ tự và số K. Nhiệm vụ của bạn là tìm phần tử ở vị trí số K sau khi trộn hai mảng để nhận được một mảng được sắp xếp.

Input Format

Dòng đầu tiên chứa 3 số N, M, K; Dòng thứ 2 chứa N số nguyên của mảng A[]; Dòng thứ 3 chứa M số nguyên của mảng B[];

Constraints

1<=N,M<=10^4; 1<=K<=N+M; 1<=A[i],B[i]<=10^6

Output Format

In ra đáp án của bài toán

Sample Input 0

7 9 14
4 6 7 9 10 10 10 
1 1 2 5 7 8 8 9 10 
Sample Output 0

10
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main()
{
    int n , m , k ; cin >> n >> m >> k;
    int a[n] , b[m];
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < m ; i++) cin >> b[i];
    
    int i = 0 , j = 0 , cnt = 0;
    while(i < n && j < m)
    {
        if(a[i] > b[j])
        {
            ++cnt;
            if(cnt == k)
            {
                cout << b[j];
                return 0;
            }
            ++j;
        }
        else
        {
            ++cnt;
            if(cnt == k)
            {
                cout << a[i];
                return 0;
            }
            ++i;
        }
    }
    while(i < n)
    {
        ++cnt;
        if(cnt == k)
        {
            cout << a[i];
            return 0;
        }
        ++i;
    }
    while(j < m)
    {
        ++cnt;
        if(cnt == k)
        {
            cout << b[j];
            return 0;
        }
        ++j;
    }
}