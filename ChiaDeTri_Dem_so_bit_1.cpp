/*Cho số nguyên dương N. Mỗi bước, bạn sẽ biến đổi N thành [N/2], N mod 2, [N/2]. Sau khi thực hiện một cách triệt để, ta thu được một dãy số chỉ toàn số 0 và 1. Nhiệm vụ của bạn là hãy đếm các số bằng 1 trong đoạn [L, R] của dãy số cuối cùng.

Input Format

Dòng duy nhất chứa 3 số nguyên N, L, R;

Constraints

1<=N,L<=R<=10^10; 0<=R-L<=100000;

Output Format

In ra đáp án của bài toán

Sample Input 0

7 2 5
Sample Output 0

4
Explanation 0

Test : [7] => [3, 1, 3] => [1, 1, 1, 1, 3] => [1, 1, 1, 1, 1, 1, 1].
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
vector<ll>v;
void init(ll n)
{
    int tmp = log2(n);
    for(int i = 0 ; i <= tmp ; i++)
    {
        v.push_back((ll)pow(2 , i));
    }
}
ll find(ll pos , ll n , int idx)
{
    if(pos % 2 == 1)
    {
        return 1;
    }
    if(pos == v[idx])
    {
        return n % 2;
    }
    else if(pos < v[idx])
    {
        return find(pos , n / 2 , idx - 1);
    }
    else return find(2*v[idx] - pos , n / 2 , idx - 1);
}
int main()
{
    ll n , l , r ; cin >> n >> l >> r;
    init(n);
    ll ans = 0;
    int m = v.size() - 1;
    for(ll res = l; res <= r ; res++)
    {
        ans += find(res , n , m);
    }
    cout << ans;
}