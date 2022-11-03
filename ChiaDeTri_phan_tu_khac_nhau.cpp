/*Cho hai mảng đã được sắp xếp A[] và B[] gồm N và N-1 phần tử. Các phần tử của mảng A[] chỉ khác mảng B[] một phần tử duy nhất. Hãy tìm vị trí của phần tử khác nhau giữa A[] và B[].

Input Format

Dòng đầu chứa số nguyên dương N; Dòng thứ 2 chứa các phần tử của mảng A[]; Dòng thứ 3 chứa các phần tử của mảng B[];

Constraints

1<=N<=10^5; 1<=A[i], B[i]<=10^6;

Output Format

In ra đáp án của bài toán

Sample Input 0

8
1 2 3 4 5 6 7 8 
1 2 3 4 5 6 8 
Sample Output 0

7
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main()
{
    int n ; cin >> n;
    int a[n] , b[n - 1];
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < n - 1 ; i++) cin >> b[i];
    for(int i = 0 ;i < n - 1 ; i++)
    {
        if(a[i] != b[i])
        {
            cout << i + 1;
            return 0;
        }
    }
}