#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  int a, b, c; scanf("%d %d %d", &a, &b, &c);

  int cnt = 0;
  while(1) {
    c -= a;
    if(c <= 0) {
      cnt++; 
      break;
    }
    else {
      c += b;
    }
    cnt++;
  }

  printf("%d", cnt);
  return 0;
}
