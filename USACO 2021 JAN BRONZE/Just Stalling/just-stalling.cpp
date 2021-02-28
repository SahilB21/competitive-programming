#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
  int n;
  std::vector<int> heights;
  std::vector<int> limits;
  int max_height = 0;
  int max_height_counter = 0;
  int options;

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int temp_variable;
    std::cin >> temp_variable;
    heights.push_back(temp_variable);
  }
  for (int j = 0; j < n; j++) {
    int temp_variable2;
    std::cin >> temp_variable2;
    limits.push_back(temp_variable2);
  }

  for (int k = 0; k < heights.size(); k++) {
    if (heights[k] > max_height) {
      max_height = heights[k];
    }
  }
  for (int t = 0; t < heights.size(); t++) {
    if (heights[t] == max_height) {
      max_height_counter += 1;
    }
  }

  for (int r = 0; r < heights.size(); r++) {
    for (int p = 0; p < limits.size(); p++) {
      if (heights[r] == max_height) {
        break;
      }
      if (heights[r] <= limits[p]) {
        options += 1;
        //std::cout << options;
      }
    }
    //std::cout << "subtracting max thing";
    if (heights[r] != max_height) {
      options -= max_height_counter;
    }
  }

  std::cout << options;

  return 0;
}
