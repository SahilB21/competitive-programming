#include <bits/stdc++.h>

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
  std::pair<int, int> adjacent_nums;
  for (int j = 0; j < n; j++) {
    adjacent_nums.first = petals[j];
    adjacent_nums.second = petals[j+1];
    if (adjacent_nums.first == adjacent_nums.second) {
      final_average += 1;
    }
  }
  int triple_adjacent_nums[3] = {0, 0, 0};
  for (int k = 0; k < n; k++) {
    int temp_average = 0;
    triple_adjacent_nums[0] = petals[k];
    triple_adjacent_nums[1] = petals[k+1];
    triple_adjacent_nums[2] = petals[k+2];
    std::accumulate(triple_adjacent_nums, sizeof(triple_adjacent_nums), temp_average)
  }

  std::cout << final_average << std::endl;

  return 0;
}
