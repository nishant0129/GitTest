#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq1;
    int sum = 0;
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
        pq.push(v[i]);
        pq1.push(v[i]);
    }

    int top1=-1;
    int top2=-1;
    vector<int>ans(n,0);
    ans[0]=sum;
    for(int i=1; i<n; i++){

        top1 = pq.top();
        top2=pq1.top();
        ans[i] = ans[i-1]-(top1+top2)+(top1-top2);
        pq.pop();
        pq1.pop();
        pq.push(top1-top2); 
        pq1.push(top1-top2);

    }

    while(q--){
        int x;
        cin>>x;
        cout<<ans[x]<<endl;
    }
    return (0);
}