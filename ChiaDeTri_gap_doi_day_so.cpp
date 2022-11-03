/*Một dãy số tự nhiên bắt đầu bởi con số 1 và được thực hiện N-1 phép biến đổi “gấp đôi” dãy số như sau: Với dãy số A hiện tại, dãy số mới có dạng A, x, A trong đó x là số tự nhiên bé nhất chưa xuất hiện trong A.

Ví dụ với 2 bước biến đổi, ta có [1] - [1 2 1] - [1 2 1 3 1 2 1].

Các bạn hãy xác định số thứ K trong dãy số cuối cùng là bao nhiêu?

Input Format

Dòng duy nhất chứa 2 số nguyên dương N và K

Constraints

1<=N<=50; 1<=K<=2^N - 1

Output Format

In ra đáp án của bài toán

Sample Input 0

3 2
Sample Output 0

2
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

ll soCach(ll n , ll k)
{
    if(k % 2 == 1) return 1;
    ll x = pow(2 , n - 1);
    if(k == x)
    {
        return n;
    }
    else if(k > x) return soCach(n - 1 , k - x);
    else return soCach(n - 1 , k);
}
int main()
{
   ll n , k ; cin >> n >> k;
   cout << soCach(n , k) << endl;
}