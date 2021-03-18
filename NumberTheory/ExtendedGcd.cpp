#include <bits/stdc++.h>
using namespace std;
int extended_gcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int d, x1, y1;
  d = extended_gcd(b, a % b, x1, y1);
  x = y1;
  y = (x1 - (a / b) * y1);
  return d;
}
int main() {
  // your code goes here
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a = 8, b = 10, x, y;
  int g = extended_gcd(a, b, x, y);
  /*
  By extended gcd tells that any gcd 'g' of two number a,b can be represented as
       ax + by = g
       where are x and y are integer number
  */
  cout << x << " " << y << "\n";
  cout << a << "*" << x << " + " << b << "*" << y << " = " << g << "\n";
  return 0;
}
