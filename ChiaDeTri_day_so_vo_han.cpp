/*Dãy số nguyên dương vô hạn A[] được định nghĩa một cách đệ quy như sau: A[0] = 0; A[1] = 1; A[i] = A[i-1] + A[i-2] với mọi n ≥ 2. Cho số nguyên dương N không quá 10^9. Hãy xác định số thứ N trong dãy A[].

Input Format

Dòng duy nhất chứa số nguyên dương N

Constraints

1<=N<=10^9

Output Format

In ra đáp án của bài toán sau khi chia dư cho 1e9 + 7

Sample Input 0

7
Sample Output 0

13
Sample Input 1

999992343
Sample Output 1

865905443
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

struct matran
{
    ll F[2][2];
    friend matran operator * (matran a , matran b)
    {
        matran res;
        for(int i = 0 ; i < 2 ; i++)
        {
            for(int j = 0 ; j < 2 ; j++)
            {
                res.F[i][j] = 0;
                for(int k = 0 ; k < 2 ; k++)
                {
                    res.F[i][j] += a.F[i][k] * b.F[k][j];
                    res.F[i][j] %= MOD;
                }
            }
        }
        return res;
    }    
};
matran powMod(matran a , int n)
{
    if(n == 1) return a;
    matran tmp = powMod(a , n / 2);
    if(n % 2 == 0)
    {
        return tmp * tmp;
    }
    else return tmp * tmp * a;
}
int main()
{
    int n ; cin >> n;
    matran a;
    a.F[0][0] = 1 ; a.F[0][1] = 1 ;
    a.F[1][0] = 1 ; a.F[1][1] = 0;
    matran res = powMod(a , n);
    cout << res.F[0][1];
}