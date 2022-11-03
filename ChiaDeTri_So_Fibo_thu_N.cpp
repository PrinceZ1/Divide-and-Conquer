/*Tìm số Fibonacci thứ N sau khi chia dư kết quả cho 10^9 + 7

Input Format

Dòng duy nhất chứa số nguyên dương N;

Constraints

1<=N<=10^10

Output Format

In ra đáp án của bài toán

Sample Input 0

58
Sample Output 0

286725742
Sample Input 1

36
Sample Output 1

14930352
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
struct maxtrix
{
    ll F[2][2];
    friend maxtrix operator * (maxtrix a , maxtrix b)
    {
        maxtrix res;
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
maxtrix powMod(maxtrix a , ll n)
{
    if(n == 1) return a;
    maxtrix x = powMod(a , n / 2);
    if(n % 2 == 0)
    {
        return x * x;
    }
    else return a * x * x;
}
int main()
{
    ll n; cin >> n;
    maxtrix a ;
    a.F[0][0] = 1 ; a.F[0][1] = 1; a.F[1][0] = 1; a.F[1][1] = 0;
    maxtrix res = powMod(a , n);
    cout << res.F[0][1];
}