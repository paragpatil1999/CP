#include <bits/stdc++.h>
using namespace std;
long long binexp(long long base, long long pow, long long mod) {
  long long s = 1;
  while (pow) {
    if (pow & 1) s *= base,s %= mod;
    base *= base;
    base %= mod;
    pow >>= 1;
  }
  return s;
}
int main() {
  // your code goes here
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << binexp(2, 10, 1000000007) << "\n";
  return 0;
}
