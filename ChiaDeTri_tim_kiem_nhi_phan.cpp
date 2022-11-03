/*Cho dãy A[] gồm N phần tử đã được sắp xếp và số nguyên dương K. Hãy kiểm tra xem K có xuất hiện trong mảng hay không, nếu có in ra YES, ngược lại in ra NO

Input Format

Dòng 1 chứa 2 số N và K; Dòng 2 chứa N số nguyên của mảng A[]

Constraints

1<=N<=10^5; 1<=A[i], K<=10^6;

Output Format

In ra đáp án của bài toán

Sample Input 0

7 2
1 8 9 10 10 12 17 
Sample Output 0

NO
Sample Input 1

6 4
4 8 9 16 19 20 
Sample Output 1

YES
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

bool binary_search(int a[] , int n , int x)
{
    int l = 0 , r = n - 1 ;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(a[m] == x) return true;
        else if(a[m] > x)
        {
            r = m - 1;
        }
        else l = m + 1;
    }
    return false;
}

int main()
{
    int n , x; cin >> n >> x;
    int a[n];
    for(int i = 0 ; i < n; i++) cin >> a[i];
    if(binary_search(a , n , x)) cout << "YES";
    else cout << "NO";
}