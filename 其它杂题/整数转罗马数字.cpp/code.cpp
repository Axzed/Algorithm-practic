#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int n;
int values[] = {
   1000,
   900, 500, 400, 100,
   90, 50, 40, 10,
   9, 5, 4, 1
};

string roman[] = {
   "M",
   "CM", "D", "CD", "C",
   "XC", "L", "XL", "X",
   "IX", "V", "IV", "I"
};

int main() {
   cin >> n;
   string ans;
   for (int i = 0; i < 13; i ++) {
      while (n >= values[i]) {
         n -= values[i];
         ans += roman[i];
      }
   }
   cout << ans << endl;
   return 0;
}
