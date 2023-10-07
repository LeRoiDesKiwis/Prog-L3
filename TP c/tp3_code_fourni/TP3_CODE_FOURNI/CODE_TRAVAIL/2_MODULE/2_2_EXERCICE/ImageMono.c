/*
 * Exercice 2.02
 * compilation :
 *   $ make ImageMono.o     # ne génère que le .o
 */

#include <string.h>

// une inclusion à faire ici
// ====== TODO ==========
#include <ImageMono.h>

// constructeur
// ====== TODO ==========
void im_init(ImageMono *image, int largeur, int hauteur, const char* color){

    image->hauteur = hauteur;
    image->largeur = largeur;
    strcpy(image->couleur, color);

}

// getters largeur et hauteur
// ====== TODO ==========

int im_largeur(ImageMono* image){
    return image->largeur;

}
int im_hauteur(ImageMono* image){
    return image->hauteur;
}

char* im_color(ImageMono* image){
    return image->couleur;
}
void im_color_set(ImageMono* image, const char* couleur){
    strcpy(image->couleur, couleur);
}

// getter et setter couleur
// ====== TODO ==========
