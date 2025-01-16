#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  char map[12][12];
  int turn[4] = {0, 1, 2, 3};  //上 右 下 左
  int f[3], c[3];
  for (int i = 0; i < 12; i ++) {
    map[i][0] = '*';
    map[i][11] = '*';
  }
  for (int j = 0; j < 12; j ++) {
    map[0][j] = '*';
    map[11][j] = '*';
  }
  for (int i = 1; i < 11; i ++) {
    for (int j = 1; j < 11; j ++) {
      cin >> map[i][j];
    }
  }
  for (int i = 0; i < 10; i ++) {
    for (int j = 0; j < 10; j ++) {
      if (map[i][j] == 'F') {
        f[0] = i;
        f[1] = j;
      }
      if (map[i][j] == 'C') {
        c[0] = i;
        c[1] = j;
      }
    }
  }
  f[2] = 0;
  c[2] = 0;
  int time = 0;
  int N = 0;
   while (1) {
    if (N > 1000000000000) {
      cout << 0;
      break;
    }
    if (c[2] == 0) {
      if (map[c[0] - 1][c[1]] == '*') c[2] = 1;
      else c[0] --;
    }
    else if (c[2] == 1) {
      if (map[c[0]][c[1] + 1] == '*') c[2] = 2;
      else c[1] ++;
    }
    else if (c[2] == 2) {
      if (map[c[0] + 1][c[1]] == '*') c[2] = 3;
      else c[0] ++;
    }
    else if (c[2] == 3) {
      if (map[c[0]][c[1] - 1] == '*') c[2] = 0;
      else c[1] --;
    }
    if (f[2] == 0) {
      if (map[f[0] - 1][f[1]] == '*') f[2] = 1;
      else f[0] --;
    }
    else if (f[2] == 1) {
      if (map[f[0]][f[1] + 1] == '*') f[2] = 2;
      else f[1] ++;
    }
    else if (f[2] == 2) {
      if (map[f[0] + 1][f[1]] == '*') f[2] = 3;
      else f[0] ++;
    }
    else if (f[2] == 3) {
      if (map[f[0]][f[1] - 1] == '*') f[2] = 0;
      else f[1] --;
    }
    time ++;
    if (c[0] == f[0] && c[1] == f[1]) {
      cout << time;
      break;
    }
    N ++;
   }
  return 0;
} 
