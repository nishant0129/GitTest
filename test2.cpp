#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long int
#define cntbit(v) __builtin_popcountll(v)
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((1LL * a * b) / __gcd(a, b))
#define F first
// bool sortbysec(pair<int,int> &a,pair<int,int>&b){
// return(a.second<b.second);}
const int MOD = 1e9 + 7;
void print(vector<int> a)
{
    for (auto it : a)
        cout << it << ' ';
    cout << endl;
}
void print(vector<pair<int, int>> a)
{
    for (auto it : a)
        cout << it.first << ' ' << it.second << endl;
    cout << endl;
}
int xpowy(int x, int y)
{
    int a = 1;
    while (y)
    {
        if (y % 2 == 1)
        {
            a = (a % MOD * x % MOD) % MOD;
            y--;
        }
        x = (x % MOD * x % MOD) % MOD;
        y /= 2;
    }
    return a;
}
int inv(int n)
{
    return xpowy(n, MOD - 2);
}

int mult(int a, int b)
{
    return (1LL * a * b) % MOD;
}

const int ms = 1e6;

// vector<int> fact(ms), invfact(ms), invs(ms);

// void precompute()
//{
//     fact[0] = 1;
//    for (int i = 1; i<ms; i++) fact[i] = mult(fact[i-1], i);
//     invfact[ms-1] = inv(fact[ms-1]);
//     for (int i = ms-2; i>=0; i--) invfact[i] = mult(invfact[i+1], i+1);

//    for (int i = 1; i<ms; i++) invs[i] = mult(invfact[i], fact[i-1]);
//}

// int ncr(int n, int r)
//{
//     if (n<r) return 0;
//     if (n<0 || r<0) return 0;
//     return mult(fact[n], mult(invfact[r], invfact[n-r]));
// }
// void sieve(int n)
//{
// vector<bool> Prime(n + 1, true);
// int count = 0;
// Prime[0] = Prime[1] = false;
// for (int i = 2; i*i <= n; i++)
//{
// if (Prime[i]){
// count++;
// for (int j = 2 * i; j <= n; j = j + i) {
// Prime[j] = false; }
//}
//}
// for (int i = 2; i <= n; i++)
// {
//   if (Prime[i])
//     cout<<i;
// }
// cout << endl;
// if(Prime[n])
// return true;
// else
// return false;
//}
int solve(int n)
{
    int cnt = 0LL;
    for (int i = 1; i <= sqrt(n - 1); ++i)
    {
        for (int j = i; j * i < n; ++j)
        {
            cnt++;
            // cout<<i<<" "<<j<<endl;
        }
    }
    cnt *= 2LL;
    int x = (sqrt(n - 1));
    cnt -= x;
    return cnt;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    vector<int> pref;
    pref.push_back(0);
    int sum = 0;
    for (int i = 2; i <= 10000; i++)
    {
        sum += solve(i);
        pref.push_back(sum);
    }
    while (t--)
    {
        int l,r;
        cin>>l>>r;
        cout<<pref[r-1]-pref[l-1]<<endl;
    }
    return 0;
}