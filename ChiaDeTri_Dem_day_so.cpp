/*Cho số nguyên dương n, bạn được phép sử dụng không giới hạn các số tự nhiên từ 1 tới n. Hỏi có bao nhiêu cách chọn ra 1 dãy có tổng các phần tử bằng n.

Input Format

Dòng duy nhất chứa số nguyên dương n

Constraints

1<=n<=10^12

Output Format

In ra đáp án của bài toán sau khi chia dư với 10^9 + 7

Sample Input 0

6
Sample Output 0

32
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

ll powMod(ll n , ll k)
{
    if(k == 0) return 1;
    ll x = powMod(n , k / 2);
    if(k % 2 == 1)
    {
        return (((x % MOD) * (x % MOD)) % MOD *(n % MOD)) % MOD;
    }
    else
    {
        return ((x % MOD) *(x % MOD)) % MOD;
    }
}

int main()
{
   ll n ; cin >> n;
   cout << powMod(2 , n - 1);
}