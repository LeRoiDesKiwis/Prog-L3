/*
 * Exercice 2.02
 * compilation :
 *   $ make main.o     # ne génère que le .o
 * ou :
 *   $ make main       # génère l'exécutable (et les .o)
 */

#include <stdio.h>
#include <stdlib.h>

// sûrement quelque chose à faire ici
// ====== TODO ==========
#include "ImageMono.h"

int main()
{
    // déclaration et initialisation de l'image
    // changement de la couleur
    // affichage des caractéristiques
    // ====== TODO ==========
    ImageMono image;
    im_init(&image, 20, 30, "vert");
    printf("%d %d, %s", im_largeur(&image), im_hauteur(&image), im_color(&image));
    im_color_set(&image, "rouge");

    return EXIT_SUCCESS;
}
