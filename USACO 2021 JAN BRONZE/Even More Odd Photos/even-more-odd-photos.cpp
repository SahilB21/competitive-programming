#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
  int n;
  std::vector<int> ids;
  int sum = 0;
  bool even = false;
  int groups = 0;
  int min_even = 1002;
  int min_even_index = 0;
  int num_odds = 0;
  int min_odd = 1001;
  int min_odd_index = 0;
  int num_evens = 0;
  int min_odd2 = 1001;
  int min_odd_index2 = 0;

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int temp_variable;
    std::cin >> temp_variable;
    ids.push_back(temp_variable);
  }

  for (int k = 0; k < n; k++) {
    sum += ids[k];
  }
  if (sum % 2 == 0) {
    even = true;
  }
  for (int h = 0; h < n; h++) {
    if (ids[h] % 2 == 0) {
      num_evens += 1;
    }
    else {
      num_odds += 1;
    }
  }

  if (even) {
    for (int r = 0; r < n; r++) {
      if (ids[r] % 2 == 0 && ids[r] < min_even) {
        min_even = ids[r];
        min_even_index = r;
      }
    }
    groups += 1;
    ids.erase(ids.begin() + (min_even_index - 1));
  }
  else {
    while (num_evens > 0) {
      for (int r = 0; r < n; r++) {
        if (ids[r] % 2 == 0 && ids[r] < min_odd) {
          min_odd = ids[r];
          min_odd_index = r;
        }
      }
      groups += 1;
      ids.erase(ids.begin() + (min_odd_index - 1));
      num_odds -= 1;
      for (int s = 0; s < n; s++) {
        if (ids[s] % 2 == 0 && ids[s] < min_even) {
          min_even = ids[s];
          min_even_index = s;
        }
      }
      groups += 1;
      ids.erase(ids.begin() + (min_even_index - 1));
      num_evens -= 1;
    }
    groups += 1;
    num_odds -= 1;
    while (num_odds > 0) {
      if (num_odds != 1) {
        for (int r = 0; r < n; r++) {
          if (ids[r] % 2 == 0 && ids[r] < min_odd) {
            min_odd = ids[r];
            min_odd_index = r;
          }
        }
        for (int t = 0; t < n; t++) {
          if (ids[t] % 2 == 0 && ids[t] < min_odd2) {
            min_odd2 = ids[t];
            min_odd_index2 = t;
          }
        }
        groups += 1;
        ids.erase(ids.begin() + (min_odd_index - 1));
        num_odds -= 1;
        ids.erase(ids.begin() + (min_odd_index2 - 1));
        num_odds -= 1;
      }
      else {
        
      }
    }
  }


  return 0;
}
