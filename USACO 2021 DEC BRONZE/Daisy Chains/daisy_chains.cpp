#include <bits/stdc++.h>

bool in_sub_array(int a, std::vector<int> v, int index_2) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == a && i <= index_2) {
      return true;
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> petals;
  for (int i = 0; i < n; i++) {
    int num = 0;
    std::cin >> num;
    petals.push_back(num);
  }
  int final_average = 0;
  final_average += n;

  for (int t = 0; t < petals.size(); t++) {
    std::vector<int> sub_vector;
    for (int j = t; j < petals.size(); j++) {
      sub_vector.push_back(petals[j]);
    }
    int temp_sum = 0;
    temp_sum += sub_vector[0];
    for (int k = 1; k < sub_vector.size(); k++) {
      temp_sum += sub_vector[k];
      if (temp_sum % k == 0 && in_sub_array(temp_sum/k, sub_vector, k)) {
        final_average += 1;
      }
    }
  }

  std::cout << final_average << std::endl;

  return 0;
}
