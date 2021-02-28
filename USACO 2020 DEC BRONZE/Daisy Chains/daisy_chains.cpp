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
  int photos = 0;
  int total_petals;
  bool present = false;

  // Moving border line at close end so that the program knows what numbers have already been looked at aka looks at each possible photo
  for (int t = 0; t < n; t++) {
    // Looks at the rest of each of the numbers inside the border line aka each flower in the photo
    for (int j = t; j < n; j++) {
      total_petals = 0;
      // Adds up the number of petals for the remaining numbers aka looks at number of petals in each flower in each photo
      for (int k = t; k <= j; k++) {
        total_petals += petals[k];
      }
      // Looks through all flowers in the photo and checks if any of them are an average flower
      present = false;
      for (int s = t; s <= j; s++) {
        // (j-t+1) represents the total number of flowers in each photo
        if (petals[s] * (j-t+1) == total_petals) {
          present = true;
        }
      }
      if (present) {
        photos++;
      }
    }
  }

  std::cout << photos << std::endl;

  return 0;
}
