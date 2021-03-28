#include <bits/stdc++.h>

int main(int argc, char *argv[]) {
  int n;
  std::cin >> n;
  //std::string words;
  //std::vector<std::string> all_words;
  //std::vector<std::string> key_words;
  std::string yearCycle[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
  //bool elsie = false;
  //int years = 0;
  //int bessie_index;
  //bool bessie_found = false;
  std::map<std::string, int> yearsBirth;
  std::map<std::string, std::string> cowBirthMonth;
  std::vector<std::string> sentenceWords;
  std::vector< std::vector<std::string> > sentences;
  std::string cow1;
  std::string cow2;
  int year_num = 0;
  std::string time;

  yearsBirth["Bessie"] = 2021;
  cowBirthMonth["Bessie"] = "Ox";

  /*
  for (int i = 0; i < n*8; i++) {
    std::cin >> words;
    all_words.push_back(words);
  }
  for (int t = 0; t < n; t++) {
    key_words.push_back(all_words[t*8]);
    key_words.push_back(all_words[3+(t*8)]);
    key_words.push_back(all_words[4+(t*8)]);
    key_words.push_back(all_words[7+(t*8)]);
  }

  for (int k = 0; k < n; k++) {
    if (bessie_found == false) {
      if (key_words[3+(k*4)] == "Bessie") {
        bessie_index = k;
        if (key_words[1+(k*4)] == "previous") {
          for (int s = 0; s < 12; s++) {
            if (year_cycle[s] == key_words[2+(k*4)]) {
              years += 12-s;
              bessie_found = true;
            }
          }
        }
        else {
          for (int s = 0; s < 12; s++) {
            if (year_cycle[s] == key_words[2+(k*4)]) {
              years -= 12-s;
            }
          }
        }
      }
    }
  }

  while (elsie == false) {
    for (int f = 0; f < n; f++) {
      //std::cout << "incrementing f";
      if (key_words[f*4] == "Elsie") {
        elsie = true;
      }
      if (key_words[3+(f*4)] == key_words[bessie_index*4]) {
        bessie_index = f;
        if (key_words[1+(f*4)] == "previous") {
          for (int r = 0; r < 12; r++) {
            if (year_cycle[r] == key_words[2+(f*4)]) {
              for (int o = 0; o < 12; o++) {
                if (year_cycle[o] == key_words[2+((f-1)*4)]) {
                  years += o+(12-r);
                }
              }
            }
          }
        }
        else {
          for (int r = 0; r < 12; r++) {
            if (year_cycle[r] == key_words[2+(f*4)]) {
              for (int o = 0; o < 12; o++) {
                if (year_cycle[o] == key_words[2+((f-1)*4)]) {
                  years -= abs(o-(12-r));
                }
              }
            }
          }
        }
      }
    }
  }

  std::cout << years;
  */

  // Inputs each sentence into its own vector in the vector of sentences
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 8; j++) {
      std::string word;
      std::cin >> word;
      sentenceWords.push_back(word);
    }
    sentences.push_back(sentenceWords);
    sentenceWords.clear();
  }

  for (int k = 0; k < n; k++) {
    cow1 = sentences[k][0];
    cow2 = sentences[k][7];
    cowBirthMonth[cow1] = sentences[k][4];
    time = sentences[k][3];
    // Finds the index of the 2nd cow (the context of the sentence is based off the position of the 2nd cow)
    for (int t = 0; t < 12; t++) {
      //if (yearName == yearCycle[t]) {
        //if (time == "previous") {
          //for (int l = 0; l < 12; l++) {
            //if (cowBirthMonth[cow2] == yearCycle[l]) {
              //yearsBirth[cow1] = yearsBirth[cow2] + l;
            //}
          //}
        //}
        //else {
          //yearsBirth[cow1] = yearsBirth[cow2] + t;
        //}
      //}
      if (cowBirthMonth[cow2] == yearCycle[t]) {
        if (time == "next") {
          // Starts going ahead for the rest of the 12 year cycle until you reach the 1st cow's birth year
          for (int l = t; l < 12+t; l++) {
            if (cowBirthMonth[cow1] == yearCycle[l%12]) {
              yearsBirth[cow1] = yearsBirth[cow2] + l;
            }
          }
        }
        else {
          for (int s = 12+t; s > 0+t; s--) {
            if (cowBirthMonth[cow1] == yearCycle[s%12]) {
              yearsBirth[cow1] = yearsBirth[cow2];
            }
          }
        }
      }
    }
  }


  if (yearsBirth["Bessie"] - yearsBirth["Elsie"] >= 0) {
    std::cout << yearsBirth["Bessie"] - yearsBirth["Elsie"];
  }
  else {
    std::cout << yearsBirth["Elsie"] - yearsBirth["Bessie"];
  }

  return 0;
}
