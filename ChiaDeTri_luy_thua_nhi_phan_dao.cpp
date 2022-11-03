/*Cho số nguyên dương N, gọi M là số đảo của N. Hãy tính lũy thừa với cơ số N và số mũ M và chia dư kết quả cho 10^9 + 7

Input Format

Dòng duy nhất chứa số nguyên dương N

Constraints

1<=N<=10^9

Output Format

In ra đáp án của bài toán

Sample Input 0

8
Sample Output 0

16777216
Sample Input 1

999995841
Sample Output 1

987348397
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

ll powMod(ll n , ll k)
{
    ll res = 1;
    while(k)
    {
        if(k % 2 == 1)
        {
            res *= n;
            res %= MOD;
        }
        n *= n;
        n %= MOD;
        k /= 2;
    }
    return res;
}

int main()
{
    string n ; cin >> n;
    string m = n;
    reverse(m.begin() , m.end());
    cout << powMod(stoll(n) , stoll(m));
}