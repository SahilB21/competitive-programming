#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
  int num1, num2, num3, num4, num5, num6, num7;
  std::cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7;
  int numbers[7] = {num1, num2, num3, num4, num5, num6, num7};
  int a = 1000000001;
  int a_index;
  int b = 1000000001;
  int c = 1;

  // Finds the correct value of a
  for (int i = 0; i < 7; i++) {
    if (numbers[i] < a) {
      a = numbers[i];
      a_index = i;
    }
  }

  // Finds the correct value of b
  for (int j = 0; j < 7; j++) {
    if (numbers[j] < b && j != a_index) {
      b = numbers[j];
    }
  }

  // Finds the correct value of c
  for (int k = 0; k < 7; k++) {
    if (numbers[k] > c) {
      c = numbers[k];
    }
  }
  c -= a;
  c -= b;

  std::cout << a << " " << b << " " << c << std::endl;

  return 0;
}
