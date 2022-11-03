/*Nhiệm vụ của bạn là tính N^P, kết quả được chia dư với 10^9 + 7

Input Format

Dòng duy nhất chứa 2 số N và K

Constraints

1<=N<=10^6; 1<=K<=10^9;

Output Format

Kết quả của bài toán

Sample Input 0

9 9
Sample Output 0

387420489
Sample Input 1

994402 999992619
Sample Output 1

925329307
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
    ll n , k ; cin >> n >> k;
    cout << powMod(n , k);
}