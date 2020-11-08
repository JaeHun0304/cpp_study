#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GameEntry {
private:
  string name;
  int score;

public:
  GameEntry(string new_name, int new_score) {
    name = new_name;
    score = new_score;
  }

  void updateAll(string name, int score) {
    this -> name = name;
    this -> score = score;
  }

  void printEntry() {
    cout << "( " << name << ", " << score << " )";
  }

  void updateScore(int new_score) {
    score = new_score;
  }

  string returnString() {
    return name;
  }
};

class ScoreBoard {
private:
  GameEntry** board;
  int capacity;
public:
  ScoreBoard(int capacity) {
    this -> capacity = capacity;
    // board is array of GameEntry objects
    board = new GameEntry*[capacity];
    for (int i = 0; i < capacity; i++) {
      board[i] = new GameEntry(" ", 0);
    }
  }

  void updateBoard(int index, string name, int new_score) {
    board[index] -> updateAll(name, new_score);
  }

  void updateScore(string name, int new_score) {
    for (int i = 0; i < capacity; i++) {
      if (board[i] -> returnString() == name) {
        board[i] -> updateScore(new_score);
      }
    }
  }

  void printBoard() {
    for (int i = 0; i < capacity; i++) {
      board[i] -> printEntry();
    }
    cout << "\n";
  }
};