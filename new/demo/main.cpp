/*
 * @Copyright [2020] <Copyright yourui>
 * @Author: yourui
 * @Date: 2020-08-21
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string smallestK(string str, int K) {
  priority_queue<string> pqStr;
  for (int i = 0; i < str.size(); i++) {
    for (int j = i; j < str.size(); j++) {
      pqStr.push(str.substr(i, j - i + 1));
      if (pqStr.size() > K) pqStr.pop();
    }
  }
  return pqStr.top();
}

int main() {
  string str;
  int K;
  while (cin >> str >> K) {
    cout << smallestK(str, K) << endl;
  }
}
