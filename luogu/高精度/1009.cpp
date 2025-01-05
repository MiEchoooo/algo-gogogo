#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
int factorial (int n) {
  int f = 1;
  for (int i = 1; i <= n; i++) {
    f *= i;
  }
  return f;
}
*/

string multiply (string s1, string s2) {
  int a1[1000] = {0}, a2[1000] = {0}, a3[10000] = {0};
  string s3;
  for (int i = 0; i < s1.size(); i ++) {
    a1[s1.size() - i - 1] = s1[i] - '0';
  }
  for (int i = 0; i < s2.size(); i ++) {
    a2[s2.size() - i - 1] = s2[i] - '0';
  }
  int len1 = s1.size();
  int len2 = s2.size();

  for (int i = 0; i < len1; i ++) {
    for (int j = 0; j < len2; j ++) {
      a3[i + j] += a1[i] * a2[j];
    }
  }
  int len = len1 + len2;
  for (int i = 0; i < len; i ++) {
    if (a3[i] >= 10) {
      a3[i + 1] += a3[i] / 10;
      a3[i] = a3[i] % 10;
    }
  }
  while (len > 0 && a3[len - 1] == 0) {
      len --;
  }
  if (len == 0) s3 = "0";
  for (int i = len - 1; i >= 0; i--) {
    s3 += to_string(a3[i]);
  }
  return s3;
}

string factorial (int n) {
    string s = "1";
    for (int i = 1; i <= n; i ++) {
      string str;
      int temp = i;
      while (temp) {
        str = (char) (temp % 10 + '0') + str;
        temp /= 10;
      }
      s = multiply(s, str);
    }
    return s;
}

string add (string s1, string s2) {
  int a1[1000] = {0}, a2[1000] = {0}, a3[10000] = {0};
  string s3;
  for (int i = 0; i < s1.size(); i ++) {
    a1[s1.size() - i - 1] = s1[i] - '0';
  }
  for (int i = 0; i < s2.size(); i ++) {
    a2[s2.size() - i - 1] = s2[i] - '0';
  }
  int len = s1.size() > s2.size() ? s1.size() : s2.size();
  for (int i = 0; i < len; i ++) {
    a3[i] = a1[i] + a2[i];
  }
  for (int i = 0; i < len; i ++) {
    if (a3[i] >= 10) {
      a3[i + 1] += a3[i] / 10;
      a3[i] = a3[i] % 10;
    }
  }
  if (a3[len] != 0) len ++;
  for (int i = len - 1; i >= 0; i --) {
    if (a3[i] == 0) len --;
    else break;
  }
  if (len == 0) {
    s3 = "0";
  }
  for (int i = len - 1; i >= 0; i--) {
    s3 += to_string(a3[i]);
  }
  return s3;
}

int main() {
  int n;
  cin >> n;
  string s;
  for (int i = 1; i <= n; i ++) {
    string s0 = factorial (i);
    s = add (s, s0);
  }
  cout << s;
  return 0;
}


/*

int main() {
  int n;
  cin >> n;
  int S = 0;
  for (int i = 1; i <= n; i ++) {
    int f = factorial (i);
    S += f;
  }
  cout << S;
  return 0;
}

*/
