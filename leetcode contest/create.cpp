#include <bits/stdc++.h>
using namespace std;

#define int long long
#define IO std::ios::sync_with_stdio(false); cin.tie(0)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define umap unordered_map
#define uset unordered_set 
#define pqueue priority_queue 
#define bitcnt(x) (__builtin_popcountll(x))
#define frac(x) fixed << setprecision(x)

typedef pair<int, int> pii;
typedef long long ll; 
typedef unsigned long long ull;
typedef pair<ll, ll> pll; 
typedef pair<string, string> pss; 

const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
int dirx[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, diry[8] = { 0, -1, 0, 1, -1, 1, -1, 1 }; 

template<typename T> void print(vector<T>& nums){
    for(int i = 0; i < nums.size(); i++){
        if(i) cout << ' '<< nums[i];else cout << nums[i];
    } cout << endl;}
template<typename T> void print(T* nums,signed l, signed r){
   for(int i = l; i <= r ; i++){
    if(i) cout << ' '<< nums[i];else cout << nums[i];
   }cout << endl;}
template<typename T> inline T max(vector<T>& nums){
    if(!nums.size()) return 0;
    T ans = nums[0];
    for(int i = 1; i <nums.size(); i++){
    if(nums[i] > ans) ans = nums[i];}return ans;}
template<typename T> inline T min(vector<T>& nums){
    if(!nums.size()) return 0;
    T ans = nums[0];
    for(int i = 1; i <nums.size(); i++){
        if(nums[i] < ans) ans = nums[i];
    }return ans;}
template<typename T> inline T sum(vector<T>& nums){
    if(!nums.size()) return 0;
    T ans = 0;
    for(int i = 0; i <nums.size(); i++) ans += nums[i];
    return ans;}
void read() { }
template <typename T, typename... T2> inline void read(T &x, T2 &... oth) {
	char ch = getchar(); x = 0;
    ll f = 1;
    while (!isdigit(ch)) { if (ch == '-') f *= -1; ch = getchar();}
    while (isdigit(ch)) {x = x * 10 + ch - 48;ch = getchar();} x *= f;
    read(oth...);}
void print(){putchar('\n');}
char print_f[105];
template <typename T, typename... T2>
inline void print( T x,  T2... oth) {ll p3=-1;
    if(x<0) putchar('-'), x=-x;
    do{print_f[++p3] = x%10 + 48;} while(x/=10);
    while(p3>=0) putchar(print_f[p3--]);
    putchar(' ');print(oth...);
}
signed main(){
    string t;
    t = "./blog/leetcode contest/double ";
    ofstream out;
    for(int i =1; i < 31; i++){
        string tt = t;
        tt += to_string(i) + ".md";
        out.open(tt);
        out.close();
    }
    
    return 0;
}