#include <iostream>
#include <string>
#include <array>
using namespace std;

int main() {
	cout << ("Transgerbeur");


    // 1. Définition de l'énumération (enum class recommandée en C++ moderne)
    enum class e_etat {
        VIDE,
        PALETTE,
        ROULEAU
    };

    // 2. Définition de la structure Palette
    struct s_palette {
        int poids;
        char ref; 
    };

    // 3. Définition de la structure Rouleau
    struct s_rouleau {
        float longueur;
        int num;
    };

    // 4. Définition de l'union pour le contenu du casier
    union u_contenu {
        s_palette palette;
        s_rouleau rouleau;
    };

    // 5. Définition de la structure Casier
    struct s_casier {
        int px;
        int py;
        e_etat etat;
        u_contenu contenu;
    };

    // 6. Déclaration de l'ensemble des 9 casiers du transgerbeur
    s_casier tabCasiers; 

	return 0;
}
