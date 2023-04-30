#ifndef Reconnaissance_forme_h_
#define Reconnaissance_forme_h_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "myBmpGris.h"

#define N 30 // Ordre des moments géometrque
//#define __USE_MINGW_ANSI_STDIO 1



typedef struct{
    char* nom ;
    int dimx;               //dimension en x(ligne)
    int dimy;               // dimension en y(colonne)
    int** pixels;           //Matrice pour stocker l'image binariser
    int X_barre ;           //Barrycentre en x de l'image
    int Y_barre ;           //Barrycentre en y de l'image
    int aire_de_la_forme;       //aire de la forme dans l'image
    double** matrice_lambda;    //matrice pour stocker les moments de legendre de l'image
}Image;


/** Methode de calcul des moments géometriques d'une image binarisée
  *  Utilise la methode cree_mat_trian
  * \param Structure contenant les paramètres de l'image
  * \return Matrice triangulaire contenant les moments géometriques
  */
double** matrice_triangle_moment_geometrique(Image I);


/** Méthode de calcul de l'aire d'une forme d'une image binarisée
  * \param Structure contenant les paramètres de l'image
  * \return Aire de la forme
  */
int aire_de_la_forme(Image I);


 /** Methode de calcul des barycentres d'une image binaire
  * Utilise la méthode aire_de_la_forme
  * \param Structure contenant l'image
  * \return Vecteur de 2 éléments contenant les barycentres
  */
int* centre_de_masse(Image I);


/* Méthode de calcul de la base de Vandermonde en X
 * \return Tableau en X de la base de Vandermonde
*/
double** base_de_matrice_de_Vandermonde_X  (Image I);


/* Méthode de calcul de la base de Vandermonde en Y
 * \return Tableau en Y de la base de Vandermonde
*/
double** base_de_matrice_de_Vandermonde_Y(Image I);


/** Methode qui calcule les moments centre et norme d'une image
 * \param Image a calculer
 * \return matrice de réel qui contient les moments geometrique centre et normee
 */
double** matrice_triangle_moment_geometrique_centre_norme(Image I,double** base_de_matrice_de_Vandermonde_X,double** base_de_matrice_de_Vandermonde_Y);


/** Methode de calcul des coeffcients des polynomes de Legendre (ordre 0 à N)
 * \return matrice de réels contenant les coeffcient de Legendre
 */
long double** matrice_coeff_polynome(int ordre);


/** Methode qui calcule les moments géometriques de Legendre à partir des moments centrés et normés
 *  Utilise la fonction matrice_coeff_polynome pour récuperer les coeffcients des polynomes de Legendre
 * \param matrice de réels qui contient les moments centrés et normés de l'image
 * \return matrice de réels qui contient les moments de Legendre centrés et normés
 */
double** moments_legendrecentre_norme_lambda(double**  moment_centre_norme);


/** Methode de calcul des polynomes de legendre (ordre 0 à N) en x
 * Effectue un changement de variable sur x avant le calcul
 * \param Variable de départ x
 * \param Matrice des coeffcients des Polynomes de Legendre
 * \param Entier permettant un changement de variable entre -1 et 1
 * \return Vecteur de dimension N. Chaque élément contient le polynome d'ordre (indice de l'élément) en x
 */
 double* polynome(double x,long double** coeff,int dim,int ordre);


 void apprentissage(Image* i,int n);


/** Méthode de reconstuction d'une image à partir des moments de Legendre centrée et normés
 * \param Image de départ qui récupurère les dimensions de l'image à écrire
 * \param Matrice de réels qui contient les moments de Légendre
 * \return Image contenant "pixels" intialisé à partir du calcul des moments de Legendre
 */
Image reconstruction(Image Iref,double** lamda);


/* Méthode de calcul de la distance euclidienne entre les moments des matrices de toutes les images
 * \param Structure contenant les images
*/
int distance(Image i);


#endif // projet_h_
