#ifndef __SCORE_BOARD_HPP__
#define __SCORE_BOARD_HPP__

#include <iostream>
#include <cstring>

using namespace std;

//Création de la structure score
typedef struct {
    char player[100];
    int score;
} Score;

//Création de la classe ScoreBoard
class ScoreBoard {
    private:
        Score** board;
        int capacity = 10;
        int nb_scores = 0;

    public:
        //Constructeur
        ScoreBoard() {
            board = new Score*[capacity];
        }

        //Redimensionner le tableau
        void growth(){
            if (nb_scores >= capacity) {
                capacity += 10;
                Score** temp = new Score*[capacity];
                for (int i = 0; i < nb_scores; i++){
                    temp[i] = board[i];
                }
                delete[] board;
                board = temp;
            }
        }

        //Ajout d'un score
        void addScore(const char* player, int score) {
            growth();
            board[nb_scores] = new Score;
            strcpy(board[nb_scores]->player, player);
            board[nb_scores]->score = score;
            nb_scores++;
        }

        //Affichage des scores
        void showScore() const{
            for (int i = 0; i < nb_scores; i++) { 
                cout << "Player: " 
                     << board[i]->player 
                     << "| Score: " 
                     << board[i]->score 
                     << endl;
            }
        }

        //Accès a un élément
        Score* operator[](int index) {
            if (index >= 0 && index < nb_scores) {
                return board[index]; 
            }
            return nullptr;
        }

        //Destructeur 
        ~ScoreBoard() {
            for (int i = 0; i < nb_scores; i++){
                delete[] board[i];
            }
            delete[] board;
        }
};

#endif