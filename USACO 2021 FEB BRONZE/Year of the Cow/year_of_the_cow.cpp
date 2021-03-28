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

  // Goes through each sentence
  for (int k = 0; k < n; k++) {
    cow1 = sentences[k][0];
    cow2 = sentences[k][7];
    cowBirthMonth[cow1] = sentences[k][4];
    time = sentences[k][3];
    // Finds the index of the 2nd cow (the context of the sentence is based off the position of the 2nd cow)
    for (int t = 0; t < 12; t++) {
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
          // Starts going back for the rest of the 12 year cycle until you reach the 1st cow's birth year
          for (int s = 12+t; s > 0+t; s--) {
            if (cowBirthMonth[cow1] == yearCycle[s%12]) {
              yearsBirth[cow1] = yearsBirth[cow2];
            }
          }
        }
      }
    }
  }

  // Checks which order to put the result
  if (yearsBirth["Bessie"] - yearsBirth["Elsie"] >= 0) {
    std::cout << yearsBirth["Bessie"] - yearsBirth["Elsie"];
  }
  else {
    std::cout << yearsBirth["Elsie"] - yearsBirth["Bessie"];
  }

  return 0;
}
