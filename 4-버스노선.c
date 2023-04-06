#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
  int l, n; scanf("%d %d", &l, &n);
  vector<pair<int,int>> arr;
  
  for(int i = 0; i < n; i++) {
    int n1, n2; scanf("%d %d", &n1, &n2);
    arr.push_back(make_pair(n1,n2));
  }

  vector<int> remove;
  for(int i = 0; i < n; i++) {
    int a = arr[i].first;
    int b = arr[i].second;
    int ar1[500000] = {0,};
    int ar2[500000] = {0,};
    int ii = 0;
    int s1 = 0;
    int s2 = 0;
    
    while(1) {
      ar1[ii] = a;
      if(a == b) break;
      
      if(a == l-1) {
        a = -1;
      }
      a++;
      ii++;
      s1++;
    }
    
    for(int j = 0; j < n; j++) {
      if(i != j) {
        a = arr[j].first;
        b = arr[j].second;
        ii = 0;
        while(1) {
          ar1[ii] = a;
          if(a == b) break;
      
          if(a == l-1) {
            a = -1;
          }
          a++;
          ii++;
          s2++;
        }

        int temp = 0;
        if(s1 > s2) {
          int num = 0;
          for(int k = 0; k < s2; k++) {
            for(int w = 0; w < s1; w++) {
              if(ar1[w] == ar2[k]) {
                num++;
                break;
              }
            }
          }
          if(num == s2) temp=2;
        }

        else if(s1 < s2) {
          int num = 0;
          for(int k = 0; k < s1; k++) {
            for(int w = 0; w < s2; w++) {
              if(ar1[k] == ar2[w]) {
                num++;
                break;
              }
            }
          }
          if(num == s1) temp = 1;
        }

        if(temp > 0) {
          if(temp == 1) remove.push_back(i);
          else if(temp == 2) remove.push_back(j);
        }
      }
    }
  }

  for(int i = 0; i < remove.size(); i++) {
    printf("%d", remove[i]);
  }

  return 0;
}
