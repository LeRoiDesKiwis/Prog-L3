/*
 * Exercice 2.02
 * compilation :
 *   un .h NE se compile PAS (enfin pas dans ce cours)
 */

// on n'oublie pas la protection contre les doubles inclusions
// ====== TODO ==========
#ifndef IMAGE_MONO
#define IMAGE_MONO

// définition des données (une structure)
// ====== TODO ==========

typedef struct  {
    int largeur;
    int hauteur;
    char couleur[100];
} ImageMono;

// "constructeur"
// - largeur et hauteur doivent être positifs
// - la couleur ne doit pas être vide
// Ne pas respecter ces directives peut conduire à des erreurs d'exécution
// ====== TODO ==========
void im_init(ImageMono* image, int largeur, int hauteur, const char* color);

// accesseurs : dimensions
// ====== TODO ==========
// la largeur et la hauteur ne peuvent pas être modifiées après
// l'initialisation, d'où l'absence des setters
int im_largeur(ImageMono* image);
int im_hauteur(ImageMono* image);

// accesseurs : couleur
// getter
// ====== TODO ==========
// setter
// la couleur ne doit pas être vide
// ====== TODO ==========
char* im_color(ImageMono* image);
void im_color_set(ImageMono* image, const char* couleur);

// cf. premier TODO sur la protection des doubles inclusions
// ====== TODO ==========
#endif