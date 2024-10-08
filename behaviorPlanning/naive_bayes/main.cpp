#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "classifier.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

// Helper functions to load .txt files
vector<vector<double>> Load_State(string file_name);
vector<string> Load_Label(string file_name);

int main() {
  vector<vector<double>> X_train = Load_State("./train_states.txt");
  vector<vector<double>> X_test = Load_State("./test_states.txt");
  vector<string> Y_train = Load_Label("./train_labels.txt");
  vector<string> Y_test = Load_Label("./test_labels.txt");

  cout << "X_train number of elements " << X_train.size() << endl;
  cout << "X_train element size " << X_train[0].size() << endl;
  cout << "Y_train number of elements " << Y_train.size() << endl;

  GNB gnb = GNB();

  gnb.train(X_train, Y_train);

  cout << "X_test number of elements " << X_test.size() << endl;
  cout << "X_test element size " << X_test[0].size() << endl;
  cout << "Y_test number of elements " << Y_test.size() << endl;

  int score = 0;
  for (int i = 0; i < X_test.size(); ++i) {
    vector<double> coords = X_test[i];
    string predicted = gnb.predict(coords);
    if (predicted.compare(Y_test[i]) == 0) {
      score += 1;
    }
  }

  float fraction_correct = float(score) / Y_test.size();
  cout << "You got " << (100 * fraction_correct) << " correct" << endl;

  return 0;
}

// Load state from .txt file
vector<vector<double>> Load_State(string file_name) {
  ifstream in_state_(file_name.c_str(), ifstream::in);
  vector<vector<double>> state_out;
  string line;

  while (getline(in_state_, line)) {
    std::istringstream iss(line);
    vector<double> x_coord;

    string token;
    while (getline(iss, token, ',')) {
      x_coord.push_back(stod(token));
    }
    state_out.push_back(x_coord);
  }

  return state_out;
}

// Load labels from .txt file
vector<string> Load_Label(string file_name) {
  ifstream in_label_(file_name.c_str(), ifstream::in);
  vector<string> label_out;
  string line;
  while (getline(in_label_, line)) {
    std::istringstream iss(line);
    string label;
    iss >> label;

    label_out.push_back(label);
  }

  return label_out;
}