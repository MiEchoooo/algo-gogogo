#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int a1[100000] = {0}, a2[100000] = {0}, a3[200000] = {0};

  // 将字符串转为数字数组
  for (int i = 0; i < s1.size(); i++) {
    a1[s1.size() - 1 - i] = s1[i] - '0';
  }
  for (int i = 0; i < s2.size(); i++) {
    a2[s2.size() - 1 - i] = s2[i] - '0';
  }
  int len1 = s1.size();
  int len2 = s2.size();
  // 进行乘法
  for (int i = 0; i < len1; i++) {
    for (int j = 0; j < len2; j++) {
      a3[i + j] += a1[i] * a2[j];
    }
  }

  // 处理进位
  for (int i = 0; i < len1 + len2; i++) {
    if (a3[i] >= 10) {
      a3[i + 1] += a3[i] / 10;
      a3[i] %= 10;
    }
  }

  // 处理结果，去掉前导零
  int start = len1 + len2 - 1;
  while (start >= 0 && a3[start] == 0) {
    start--;
  }
  string result;
  if (start == -1) {
    result = "0";  // 如果结果为0
  }
  for (int i = start; i >= 0; i--) {
    result += to_string(a3[i]);
  }
  cout << result << endl;

  return 0;
}




/*

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string RemoveLeadingZeros(string s) {
  size_t first_non_zero = s.find_first_not_of('0');
  if (first_non_zero == string::npos) {
    return "0";  // 如果全是零，则返回 "0"
  }
  return s.substr(first_non_zero);
}

string Add(string s1, string s2) {
  int a1[1000000] = {0}, a2[1000000] = {0}, a3[10000000] = {0};

  for (int i = s1.size() - 1; i >= 0; i --) {
    a1[i] = s1[s1.size() - i - 1] - '0';
  }
  //for (int i = 0; i < s1.size(); i++) {
  //  a1[s1.size() - i - 1] = s1[i] - '0';
  //}
  for (int i = 0; i <s2.size(); i++) {
    a2[s2.size() - i - 1] = s2[i] - '0';
  }
  int len = s1.size() > s2.size() ? s1.size() : s2.size();
  for (int i = 0; i < len; i ++) {
    a3[i] = a1[i] + a2[i];
  }
  for (int i = 0; i < len; i ++) {
    if (a3[i] >= 10) {
      a3[i + 1] = a3[i + 1] + (a3[i] / 10);
      a3[i] = a3[i] % 10;
    }
  }
  if (a3[len] != 0) {
    len ++;
  }
 // for (int i = len - 1; i >= 0; i --) {
 //   if(a3[i] == 0) len--;
 //   else break;
 // 
  string s3;
  if (len == 0) s3 = {0};
  for (int i = len - 1; i >= 0; i--) {
    s3 += to_string(a3[i]);
  }
  return s3;
}

int main() {
  string s1, s2;
  cin >> s1;
  cin >> s2;
  int a1[100000] = {0}, a2[100000] = {0};
  string s3;
  if (s1.size() > s2.size()) {
    for (int i = 0; i < s1.size(); i ++) {
      a1[s1.size() - 1 - i] = s1[i] - '0';
    }
    for (int i = 0; i < s2.size(); i ++) {
      a2[s2.size() - 1 - i] = s2[i] - '0';
    }
  }
  else {
    for (int i = 0; i < s1.size(); i ++) {
      a2[s1.size() - 1 - i] = s1[i] - '0';
    }
    for (int i = 0; i < s2.size(); i ++) {
      a1[s2.size() - 1 - i] = s2[i] - '0';
    }
  }
  //保证a1数组存的数更长
  int MinSize = s1.size() > s2.size() ? s2.size() : s1.size();  //为短的长度 即最后需要相加的数字个数 
  int MaxSize = s1.size() < s2.size() ? s2.size() : s1.size();  //为长的长度
  string ss = "0";
  for (int i = 0; i < MinSize; i++) {
    int a3[10000000] = {0};
    int j, k = 0;
    for (j = 0; j < s1.size(); j++) {
      if (i > 0 && k == 0) {
        for (k = 0; k < i; k ++) {
        a3[k] = 0;
        }
      }
      a3[j + k] = a1[j] * a2[i];
    }
    //处理进位
    for (int i = 0; i < MinSize + MaxSize; i ++) {
      if (a3[i] >= 10) {
        a3[i + 1] = a3[i + 1] + (a3[i] / 10);
        a3[i] = a3[i] % 10;
      }
    }
    string str;
    for (int i = 0; i <= MinSize + MaxSize; i++) {
      str += to_string(a3[i]);
    }
    //str当前
    //加到s3上
    for (int i = 0; i < str.size() / 2; i++) {
      swap(str[i], str[str.size() - i - 1]);
    }
    s3 = Add(ss, str);
    ss = s3;
  }

  s3 = RemoveLeadingZeros (s3);
  cout << s3;
  return 0;
}

*/