#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

class Game{
private:
    ifstream input;
    //creamos una matriz bool
    //para tener un seguimiento de las casillas
    //si estan destapadas o no
    bool** posiciones(int n){
        bool** descubiertos;
        descubiertos = new bool*[n];
        for(int i=0; i<n; i++){
            descubiertos[i] = new bool[n];
        }
        //inicializamos la matriz en false
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                descubiertos[i][j] = false;
            }
        }
        return descubiertos;
    }
    void ponerMinas(int** mapa, int n){
        int y;
        int x;
        int num_minas = 0;
        while(num_minas<n){
            //Nos aseguramos que todas las minas deseadas se pongan
            do{
                y = rand()%n;
                x = rand()%n;
            }while(mapa[y][x]>=9);
            //ponemos la mina
            mapa[y][x]=9;
            //agregamos 1s alrededor de la mina
            for(int i=max(0,y-1); i<=min(n-1,y+1); i++){
                for(int j=max(0, x-1); j<=min(n-1,x+1); j++){
                    mapa[i][j] += 1;
                }
            }
            num_minas += 1;
        }
    }
    int** tableroAleatorio(int n, int minas){
        //creamos el espacio de memoria para el tablero
        int** solucion = new int*[n];
        for(int i=0; i<n; i++){
            solucion[i] = new int[n];
        }
        //llenamos de 0s
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                solucion[i][j]= 0;
            }
        }
        ponerMinas(solucion,n);
        return solucion;
    }
    char** obtenerTablero(int n, char caracter){
        char** tablero = new char*[n];
        for(int i=0; i<n; i++){
            tablero[i] = new char[n];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                tablero[i][j] = caracter;
            }
        }
        return tablero;
    }
    char intToChar(int** solucion, int m, int n){
        if(solucion[m][n]==0){
            return '.';
        }else if(solucion[m][n]==1){
            return '1';
        }else if(solucion[m][n]==2){
            return '2';
        }else if(solucion[m][n]==3){
            return '3';
        }else if(solucion[m][n]==4){
            return '4';
        }else if(solucion[m][n]==5){
            return '5';
        }else if(solucion[m][n]==6){
            return '6';
        }else if(solucion[m][n]==7){
            return '7';
        }else if(solucion[m][n]==8){
            return  '8';
        }
        return '9';
    }
    bool siguienteJugada(int** solucion, char** tablero, bool** posiciones, int m, int n){
        bool bandera = false;
        if(solucion[m][n] < 9 and !posiciones[m][n]){
            tablero[m][n] = intToChar(solucion, m, n);
            bandera = true;
        }
        return bandera;
    }
    int contadorCasillasDest(bool** posiciones, int n){
        int contador = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(posiciones[i][j]){
                    contador ++;
                }
            }
        }
        return contador;
    }
    void marcarMina(char** tablero, bool** posiciones, int m, int n){
        if(!posiciones[m][n]){
            tablero[m][n] = 'M';
            posiciones[m][n] = true;
        }
    }
    void desmarcarMina(char** tablero, bool** posiciones, int m, int n){
        if(posiciones[m][n]){
            tablero[m][n] = '_';
            posiciones [m][n] = false;
        }
    }
    bool marcoBien(int** solucion, int x, int y){
        return solucion[x][y] >= 9;
    }
    void mostrarMapa(char **mapa, int n){
        cout << "    ";
        for(int k=0; k<n; k++){
            cout << setw(3) << k;
        }
        cout << endl << endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(j==0){
                    cout << i << "   ";
                }
                cout << setw(3) << mapa[i][j];
            }
            cout << endl;
        }
    }
    void mostrarMapaInt(int** mapa, int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << setw(2) << mapa[i][j] << "  ";
            }
            cout << endl;
        }
    }
    void destaparCeldas(char** tablero, int** solucion, bool** visible, int y, int x, int n){
        if(!visible[y][x]){
            visible[y][x] = true;
            tablero[y][x] = intToChar(solucion, y, x);
            if(solucion[y][x]==0){
                for(int i=max(0,y-1); i<=min(n-1,y+1); i++){
                    for(int j=max(0, x-1); j<=min(n-1,x+1); j++){
                        if(solucion[i][j]<9){
                            destaparCeldas(tablero, solucion, visible ,i ,j ,n);
                        }
                    }
                }
            }
        }
    }
public:
    Score jugar(string player){
        time_t start;
        time_t end = 0;
        int fil, col;
        double scoreValue = 0;
        int vida = 1;
        int n = 0;
        int minas = 0;
        int opcion;
        int minasMarcadasBien = 0;
        char opcionJ;
        cout << "Seleccione la dificultad" << endl;
        cout << "________________________________________________" << endl;
        cout << "1. Principiante (10x10, 10 minas)" << endl;
        cout << "2. Intermedio (15x15, 15 minas)" << endl;
        cout << "3. Avanzado (20x20, 20 minas)" << endl;
        cout << "________________________________________________" << endl;
        cout << "Ingrese una opcion :";
        cin >> opcion;
        switch(opcion){
            case 1:
                n = 10;
                minas = 10;
                break;
            case 2:
                n = 15;
                minas = 15;
                break;
            case 3:
                n = 20;
                minas =20;
                break;
            default:
                cout << "Opcion Invalida" << endl;
                exit(1);
        }
        //creamos solucion
        int** solucion = tableroAleatorio(n, minas);
        //creamos tablero
        char** tablero = obtenerTablero(n,'_');
        //creamos matriz booleana de posiciones destapadas
        bool** booleana = posiciones(n);

        Score newScore(player);

        //iniciamos el timepo
        time(&start);
        do{
            system("cls");
            mostrarMapa(tablero,n);
            cout << "Opciones" << endl;
            cout << "j. Jugar" << endl;
            cout << "m. Marcar Mina" << endl;
            cout << "d. Desmarcar Mina" << endl;
            cout << "Ingrese la accion a realizar: " << endl;
            cin >> opcionJ;

            switch(opcionJ){
                case 'j':
                    cout << "Ingrese las coordenadas [fila][columna] que desea jugar" << endl;
                    cout << "[fila]:";
                    cin >> fil;
                    cout << "[columna]:";
                    cin >> col;
                    if(solucion[fil][col]>=9 and !booleana[fil][col]){
                        vida --;
                    }
                    siguienteJugada(solucion, tablero, booleana, fil, col);
                    destaparCeldas(tablero, solucion, booleana, fil, col, n);
                    break;
                case 'm':
                    cout << "Ingrese la coordenada de la mina a marcar" << endl;
                    cout << "[fila]:";
                    cin >> fil;
                    cout << "[columna]:";
                    cin >> col;
                    marcarMina(tablero, booleana, fil, col);
                    if(marcoBien(solucion, fil, col)){
                        minasMarcadasBien ++;
                    }
                    break;
                case 'd':
                    cout << "Ingrese la coordenada de la mina a desmarcar" << endl;
                    cout << "[fila]:";
                    cin >> fil;
                    cout << "[columna]:";
                    cin >> col;
                    desmarcarMina(tablero, booleana, fil, col);
                    if(marcoBien(solucion, fil, col)){
                        minasMarcadasBien--;
                    }
                    break;
                default:
                    cout << "Opcion Invalida" << endl;
                    exit(1);
            }
        }while(vida>0 and minasMarcadasBien!=n and (contadorCasillasDest(booleana,n)-minasMarcadasBien)!=((n*n)-n));

        //finalizamos el tiempo
        time(&end);
        int limitTime = 600;

        if(vida>0 and double(end-start)<600){
            cout << "________________________________________________" << endl;
            cout << "Ganaste!" << endl;
            scoreValue = limitTime - double(end-start);
        }else{
            if(double(end-start)>=600){
                cout << "Se acabo el tiempo" << endl;
                cout << "No completo el juego en el tiempo de 600 segundos" << endl;
            }
            cout << "________________________________________________" << endl;
            cout << "Perdiste!" << endl;
            cout << "A continuacion se muestra la solucion" << endl;
            cout << "Los numeros mayores a 9 son minas" << endl;
            mostrarMapaInt(solucion,n);
        }

        newScore.setScoreValue(scoreValue);
        cout << "Su score fue: " << endl;
        newScore.displayScore();
        cout << "________________________________________________" << endl;
        return newScore;
    }
};