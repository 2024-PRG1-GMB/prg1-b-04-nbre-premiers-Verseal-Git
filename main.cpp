#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {
    int user_input;
    const int min_val = 2; // au cas où l'on souhaiterait ignorer les n premiers chiffres
    const int max_val = 1000;
    char choice;

    do {
        bool isPrime;
        int row_count = 0;

        cout << "Entrer une valeur [2-" << to_string(max_val) << "] : ";
        cin >> user_input;

        while (user_input < min_val || user_input > max_val) {
            cout << "Entrer une valeur [" << min_val << "-" << max_val << "] : ";
            cin >> user_input;
        }

        cout << "Voici la liste des nombres premiers" << endl;

        for (int x = min_val; x <= user_input; x++) {
            isPrime = true; // par défaut tout nombre est considéré comme premier
            for (int y = min_val; y <= x / 2; y++) {
                if (x % y == 0) {
                    isPrime = false; // et on passe le nombre non-premier dès que l'on a une itération divisable en entier
                    break;
                }
            }

            if (isPrime) {

                if (row_count % 5 == 0) { // après 5ème chiffre, passer à la première colonne de la ligne n+1
                    cout << " ";
                }

                cout << ((row_count % 5 == 0) ? setw(10) : setw(5)) << x << " ";
                row_count++;

                if (row_count % 5 == 0) { // après 5ème chiffre, passer à la première colonne de la ligne n+1
                    cout << setw(5) << " " << endl;
                }
            }
        }

        cout << endl;

        do {
            cout << "Voulez-vous recommencer [O/N] : ";
            cin >> choice;
        } while (choice != 'O' && choice != 'N');

        cout << endl;
    } while (choice == 'O');

    cout << "Fin de programme" << endl;

    return EXIT_SUCCESS;
}
