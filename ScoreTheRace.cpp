#include <iostream>
using namespace std;

int main () {
  bool equalRunners = false;
  int runners, teams = 0;
  int scores['Z' + 1] = {};
  int num_of_runners['Z' + 1] = {};
	string outcome; 
cout << "In a race where each team has the same amount of runners, the outcome is represented by a string that you input until you write done." << endl;
cout <<  "write the results as a string of characters indicating the order in which runners crossed the finish line." << endl;
while (outcome != "done") {
   cout << "Enter the outcome: ";
      cin >> outcome;
      teams =0; // this resets the loop to begin from zero
      if (outcome == "done") return 0;
      for (int i = 'A'; i < 'Z' + 1; i++) {
          scores[i] = 0;
          num_of_runners[i] = 0;
        }
        //record the outcome
        for (int i = 0; i < outcome.length(); i++) {
          char c = outcome[i];
          scores[c] = scores[c] + (i + 1);  
          if (num_of_runners[c] == 0) teams++;   
          num_of_runners[c] += 1;
        }
        // check for equal runners
        runners = num_of_runners[outcome[0]];
  for (int i = 0; i < outcome.length(); i++) {
          char c = outcome[i];
          if (num_of_runners[c] != runners) {
            equalRunners = false;
            cout << "You didn't put an equal amout of numbers per team please try again:" << endl;
            break; 
          }
          else equalRunners = true;
        }
	if (equalRunners == true) {
              char winner;
              int min = scores[outcome[0]];
              for (int i = 'A'; i < 'Z' + 1; i++) {
                if ((scores[i] != 0) && (scores[i] <= min)) {
                  min = scores[i];
                  winner = i;
              }
            }
            cout << "There are " << teams << " teams." << endl;
            cout << "Each team has " << runners << " runners." << endl;
            cout << "Team:  Score:" << endl;
            for (int i = 'A'; i < 'Z' + 1; i++) {
              if (scores[i] > 0) {
                cout << ((char) i) << "      " << ((double) scores[i]) / runners << endl;
              }
            }
            cout << "The winner is team " << winner << " with a score of " << ((double) min) / runners << "." << endl; 
    }
}  
	return 0;
}
