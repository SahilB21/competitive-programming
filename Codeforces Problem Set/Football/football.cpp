#include <bits/stdc++.h>

int main(int argc, char const *argv[]) {
  std::string players;
  std::cin >> players;
  bool dangerous = false;
  int team1Player = 0;
  int team2Player = 0;


  for (int i = 0; i < players.size(); i++) {
    if (players[i] == '1') {
      team1Player++;
      team2Player = 0;
      if (team1Player == 7) {
        dangerous = true;
      }
    }

    else {
      team2Player++;
      team1Player = 0;
      if (team2Player == 7) {
        dangerous = true;
      }
    }

  }



  if (dangerous) {
    std::cout << "YES" << std::endl;
  }
  else {
    std::cout << "NO" << std::endl;
  }


  return 0;
}
