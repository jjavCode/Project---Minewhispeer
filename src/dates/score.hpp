#ifndef SCORE_H
#define SCORE_H
#include <iostream>
#include <string>

using namespace std;
class Score {
   private:
    string player;
    double score_value;

   public:
    Score() {
    }
    Score(string player) {
        this->player = player;
    }
    Score(string player, double score_value) {
        this->player = player;
        this->score_value = score_value;
    }
    void setPlayer(string player) {
        this->player = player;
    }
    void setScoreValue(double score_value) {
        this->score_value = score_value;
    }
    string getPlayer() {
        return player;
    }
    double getScoreValue() {
        return score_value;
    }
    void displayScore() {
        cout << player << " " << score_value << endl;
    }
    string getFormated() {
        return player + " " + to_string(score_value) + "\n";
    }
};
#endif  // !SCORE_H
