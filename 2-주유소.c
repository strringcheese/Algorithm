#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
  int n; scanf("%d", &n);
  vector<int> km;
  vector<int> price;
  
  for(int i = 0; i < n-1; i++) {
    int a; scanf("%d", &a);
    km.push_back(a);
  }

  for(int i = 0; i < n; i++) {
    int a; scanf("%d", &a);
    price.push_back(a);
  }

  int total = 0;
  vector<int> pri;
  for(int i = 0; i < n-1; i++) {
    pri.clear();
    for(int j = 1; j < n-1; j++) {
      pri.push_back(price[j]);
    }
    sort(pri.begin(),pri.end());
    if(pri[0] == price[i]) {
      int temp = 0;
      for(int j = i; j < n-1; j++) {
        temp+= km[j];
      }
      total += temp * pri[0];
      break;
    }

    else {
      total += km[i] * price[i];
    }
  }

  printf("%d", total);
  return 0;
} 
