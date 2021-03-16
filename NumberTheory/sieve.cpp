#include <bits/stdc++.h>
using namespace std;
vector<int> sieve(int n){
  //Get all primes upto n
  bool prime[n+1];
  memset(prime,1,sizeof prime);
  for(int i = 4;i<=n;i+=2)prime[i] = 0;
  for(int i = 3;i*i<=n;i++){
    if(prime[i]){
      for(int j = i*i;j<=n;j+=i)prime[j] = 0;
    }
  }
  vector<int> Prime;
  for(int i = 2;i<=n;i++)if(prime[i])Prime.push_back(i);
  return Prime;
}
int main() {
  // your code goes here
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> prime = sieve(1000);
  for(auto i:prime)cout << i << "\n";
  return 0;
}
