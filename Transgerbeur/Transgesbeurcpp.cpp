#include <cstring> // Pour strcpy_s

// --- Définitions des types (rappel avec la taille des tableaux) ---
enum e_etat {
    VIDE,
    PALETTE,
    ROULEAU
};

struct s_palette {
    int poids;
    char ref[20]; // 19 caractères max + '\0'
};

struct s_rouleau {
    float longueur;
    int num;
};

union u_contenu {
    s_palette palette;
    s_rouleau rouleau;
};

struct s_casier {
    int px;
    int py;
    e_etat etat;
    u_contenu contenu;
};

// --- Programme de test ---
int main() {
    // 1. Déclarer et initialiser un rouleau ro1
    s_rouleau ro1 = { 125.5f, 101 };

    // 2. Déclarer une palette pa1 et affecter ses membres avec strcpy_s
    s_palette pa1;
    pa1.poids = 450;
    strcpy_s(pa1.ref, sizeof(pa1.ref), "PAL_2026_A");

    // 3. Déclarer et initialiser un état etatC1 à la valeur vide
    e_etat etatC1 = VIDE;

    // 4. Déclarer et initialiser un contenu cont avec pa1, puis lui affecter ro1
    u_contenu cont = { pa1 }; // Initialise le 1er membre de l'union (palette)
    cont.rouleau = ro1;       // Écrase la mémoire de l'union avec le rouleau

    // 5. Déclarer un casier c1, lui affecter pa1, l'état qui convient et (2, 3)
    s_casier c1;
    c1.px = 2;
    c1.py = 3;
    c1.etat = PALETTE;
    c1.contenu.palette = pa1;

    // 6. Déclarer et initialiser un casier c2 avec une palette
    s_casier c2 = { 1, 4, PALETTE, { { 320, "PAL_2026_B" } } };

    // 7. Déclarer un tableau de casiers avec c1 à l'indice 0 et c2 à l'indice 2
    s_casier tabCasiers[9] = { c1, {}, c2 };

    return 0; // Placer un point d'arrêt ici (ou à chaque ligne) pour observer au débogueur
}
