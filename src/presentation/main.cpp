#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "dates/highScores.hpp"
#include "dates/score.hpp"
#include "logic/game.hpp"

using namespace std;

int max(int x, int y) {
    if (x > y) {
        return x;
    }
    return y;
}
int min(int x, int y) {
    if (x < y) {
        return x;
    }
    return y;
}

int main() {
    srand((int)time(NULL));

    char path_scores[] = "./highscores.txt";
    char opcion;
    Game juego;
    HighScores hs(path_scores);
    Score new_score;

    string player = "Player";

    cout << "________________________________________________" << endl;
    cout << "Reglas de Juego" << endl;
    cout << "Tiene 600 segundos para jugar" << endl;
    cout << "Si se acaba el tiempo tendra un score de 0" << endl;
    cout << "'.' representa casillas destapadas" << endl;
    cout << "'_' representa casillas tapadas" << endl;
    cout << "________________________________________________" << endl;
    cout << "Para ganar" << endl;
    cout << "1. Se marcan todas las minas dependiendo del nivel de dificultad"
         << endl;
    cout << "2. Se libera todo el mapa menos las minas" << endl << endl;
    cout << "Para perder" << endl;
    cout << "1. Se marca una mina" << endl;
    cout << "________________________________________________" << endl;

    do {
        cout << "Menu de Juego" << endl;
        cout << "a. Ver Lista de Scores." << endl;
        cout << "b. Definir el nombre del Jugador." << endl;
        cout << "c. Jugar una partida." << endl;
        cout << "d. Salir." << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 'a':
                hs.displayHighScores();
                break;
            case 'b':
                cout << "Ingrese su nombre: ";
                cin >> player;
                break;
            case 'c':
                if (player == "Player") {
                    cout << "Ingrese su nombre: ";
                    cin >> player;
                }
                new_score = juego.jugar(player);
                hs.updateHighScores(new_score);
                break;
            case 'd':
                cout << "Gracias por jugar" << endl;
                hs.saveHighScores();
                break;
            default:
                cout << "Ingrese una opcion valida (a, b, c, d)." << endl;
                break;
        }
    } while (opcion != 'd');
    return 0;
}
