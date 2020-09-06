/*
 * @Copyright [2020] <Copyright yourui>
 * @Author: yourui
 * @Date: 2020-08-24
 */

#include <iostream>
#include <vector>

union test {
  int i;
  char c;
};

int main() {
  test t;
  t.i = 0x41424344;
  std::cout << char(0x41) << std::endl;
  std::cout << t.c << std::endl;
}
