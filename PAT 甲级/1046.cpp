#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> nums(n), sum(n+1);
    for(int i = 0; i < n; i++) cin >> nums[i];
    for(int i = 1; i <= n; i++) sum[i] = sum[i-1]+ nums[i-1];
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        if(a > b)
            swap(a,b);
        int t = sum[b-1] - sum[a-1];
        cout << min(t, sum[n]-t) << endl;
    }
    system("pause");
}