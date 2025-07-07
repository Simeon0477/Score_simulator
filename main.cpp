#include <iostream>

#include "header/score_board.hpp"

ScoreBoard scoreBoard;

int choix;

int main() {
    cout << "\033[35m******** Simulateur de Scores ******** \n\033[0m";
    scoreBoard.addScore("Alice", 150);
    scoreBoard.addScore("Bob", 200);
    scoreBoard.addScore("Charlie", 100);

    while (1) {
        //Menu
        cout << "\nMenu :\n";
        cout << " 1 - Afficher les scores\n";
        cout << " 2 - Ajouter un score\n";
        cout << " 3 - Rechercher le meilleur score\n";
        cout << " 4 - Supprimer un score\n";
        cout << " 5 - Quitter\n";
        cout << "Votre choix -> ";
        cin >> choix;

        switch (choix) {
            case 1:
                cout << "\n\033[32m1 - Afficher les scores \n\n\033[0m";
                scoreBoard.showScore();

                break;

            case 2:
                char name[100];
                int score;
                cout << "\n\033[32m2 - Ajouter un score \n\n\033[0m";
                cout << "Entrez le nom du joueur : ";
                cin.getline(name, 100);
                cout << "Entrez la valeur de votre score : ";
                cin >> score;
                scoreBoard.addScore(name, score);

                break;
                                            
            case 3:
                cout << "\n\033[32m3 - Rechercher le meilleur score \n\n\033[0m";
                break;
                
            case 4:
                cout << "\n\033[32m3 - Supprimer un score \n\n\033[0m";
                break;

            case 5:
                cout << "Au revoir!\n";
                exit(0);

            default:
                cout << "Option invalide. Veuillez réessayer.\n";
                break;
        }
    }

    return 0;
}