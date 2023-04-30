#ifndef Outils_h_
#define Outils_h_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "myBmpGris.h"
#include "Reconnaissance_forme.h"



/** Methode de creation d'une matrice de stockage de l'image binaire (dimension (dimx,dimy)) initialisée à 0
 * \param :Nombre de colonnes
 * \param :Nombre dee lignes
 * \return :Image de type Image avec (dimx,dimy,pixels) initialisés
 */
Image initialiser_image(int dimx,int dimy);


/** Methode de lecture et de binarisation d'une image bmp
 * Utilise la methode ReadBmpImage de la bibliothèque myBmpGris.c
 * \param Nom de l'image
 * \return image de type Image avec le champ pixels contenant l'image binarisée
 */
Image lire_image_ndg(char* bmpimage);


/** Méthode d'écriture d'une image binaire au format bmp (conversion de l'image en niveau de gris)
 * Utilise createBmpImg pour la création d'une image au format Bmp et writeBmpImg pour l'écriture de l'image
 * \param Image à écrire
 * \param Nom de l'image à créer et écrire (.bmp)
 */
void ecrire_Image(Image I, char* nom_image);


/** Méthode de création de matrice triangulaire respectant la contrainte p+q<=N
  * Cette fonction ne possède pas d'entrée car N est l'odre défini grâce aux macros
  * \return : matrice triangailaire allouée (initialisée à 0)
  */
double** cree_mat_trian();


/** Méthode de déstruction d'une matrice triangulaire 
 * \param Nom de la matrice à détruire
*/
void desallocationMatrice(double** matriceADetruire, int colonnes);

/** Méthode d'écriture des valeurs des élément d'une matrice triangulaire dans un fichier texte
 * \param Matrice à écrire dans le fichier texte
 * \param nom du ficier texte qui va contenir les valeurs de la matrice
 */
void ecrire_matrice_triangulaire_text(double** lambda,char* nom);

/** Méthode de lecture des valeurs des éléments d'une matrice triangulaire stockés dans un fichier texte
 * \param Nom du ficher texte à lire
 */
double** lire_matrice_triangulaire_text(char* nom);



#endif // Outils_h_
