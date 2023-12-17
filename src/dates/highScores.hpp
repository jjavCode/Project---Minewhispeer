#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <fstream>
#include <iostream>
#include <string>
#include "dates/score.hpp"

using namespace std;

class HighScores {
   private:
    Score* scores;
    int total;
    ifstream input;
    ofstream output;
    char* path;

   public:
    HighScores(char* path) {
        this->path = path;
        loadHighScores();
    }
    void loadHighScores() {
        string name;
        double value;
        input.open(path);
        auto file_opened = input.is_open();
        if (file_opened) {
            input >> total;
            scores = new Score[total];
            for (int i = 0; i < total; i++) {
                input >> name >> value;
                scores[i] = Score(name, value);
            }
            input.close();
        }
    }
    bool isSorted() {
        for (int i = 1; i < total; i++) {
            if (scores[i].getScoreValue() > scores[i - 1].getScoreValue()) {
                return false;
            }
        }
        return true;
    }
    void sort() {
        Score temp;
        while (!isSorted()) {
            for (int i = 1; i < total; i++) {
                if (scores[i].getScoreValue() > scores[i - 1].getScoreValue()) {
                    temp = scores[i];
                    scores[i] = scores[i - 1];
                    scores[i - 1] = temp;
                }
            }
        }
    }
    void updateHighScores(Score new_score) {
        if (new_score.getScoreValue() >= scores[total - 1].getScoreValue()) {
            scores[total - 1] = new_score;
            sort();
        }
    }
    void saveHighScores() {
        output.open(path);
        auto file_opened = output.is_open();
        if (file_opened) {
            output << total << endl;
            for (int i = 0; i < total; i++) {
                output << scores[i].getFormated();
            }
            output.close();
        }
    }
    void displayHighScores() {
        cout << "Lista de HighScores: " << endl;
        for (int i = 0; i < total; i++) {
            scores[i].displayScore();
        }
    }
};
#endif
