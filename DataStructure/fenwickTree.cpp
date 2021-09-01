#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define all(a) a.begin(), a.end()
#define x first
#define y second
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

class Fenwick{
    // Fenwick is 1-based 
    public:
    int sz;
    vector<int> arr;
    Fenwick(vector<int> &a){
        sz = a.size()+1;
        arr.resize(sz,0);
        for(int i = 0;i<sz;i++)arr[i] = 0;
        for(int i  = 0;i<a.size();i++){
            add(i+1,a[i]);
        }
    }
    int getSum(int i){
        int s = 0;
        while(i){
            s += arr[i];
            i -= (i & (-i));
        }
        return s;
    }
    void add(int i,int delta){
        while(i < sz){
            arr[i] += delta;
            i += (i & (-i));
        }
    }
    int rangeSum(int l,int r){
        return getSum(r) - getSum(l-1);
    }
    //Use getSum(i) to get PrefixSum from 1 to i i.e sum[1:i];
    //Range sum(l,r) will give sum of elemnts in range l and r included
    //sum[l:r];
};



int main() {
  // your code goes here
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vi arr{1,2,3,4,5,6,7,8,9};
  Fenwick t = Fenwick(arr);
  cout << t.rangeSum(1,5) << "\n";
  cout << t.rangeSum(2,4) << "\n";
  cout << t.rangeSum(2,2) << "\n";
  cout << t.rangeSum(5,8) << "\n";
  return 0;
}
