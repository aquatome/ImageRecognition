#ifndef Outils_h_
#define Outils_h_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "myBmpGris.h"
#include "Reconnaissance_forme.h"



/** Methode de creation d'une matrice de stockage de l'image binaire (dimension (dimx,dimy)) initialis�e � 0
 * \param :Nombre de colonnes
 * \param :Nombre dee lignes
 * \return :Image de type Image avec (dimx,dimy,pixels) initialis�s
 */
Image initialiser_image(int dimx,int dimy);


/** Methode de lecture et de binarisation d'une image bmp
 * Utilise la methode ReadBmpImage de la biblioth�que myBmpGris.c
 * \param Nom de l'image
 * \return image de type Image avec le champ pixels contenant l'image binaris�e
 */
Image lire_image_ndg(char* bmpimage);


/** M�thode d'�criture d'une image binaire au format bmp (conversion de l'image en niveau de gris)
 * Utilise createBmpImg pour la cr�ation d'une image au format Bmp et writeBmpImg pour l'�criture de l'image
 * \param Image � �crire
 * \param Nom de l'image � cr�er et �crire (.bmp)
 */
void ecrire_Image(Image I, char* nom_image);


/** M�thode de cr�ation de matrice triangulaire respectant la contrainte p+q<=N
  * Cette fonction ne poss�de pas d'entr�e car N est l'odre d�fini gr�ce aux macros
  * \return : matrice triangailaire allou�e (initialis�e � 0)
  */
double** cree_mat_trian();


/** M�thode de d�struction d'une matrice triangulaire 
 * \param Nom de la matrice � d�truire
*/
void desallocationMatrice(double** matriceADetruire, int colonnes);

/** M�thode d'�criture des valeurs des �l�ment d'une matrice triangulaire dans un fichier texte
 * \param Matrice � �crire dans le fichier texte
 * \param nom du ficier texte qui va contenir les valeurs de la matrice
 */
void ecrire_matrice_triangulaire_text(double** lambda,char* nom);

/** M�thode de lecture des valeurs des �l�ments d'une matrice triangulaire stock�s dans un fichier texte
 * \param Nom du ficher texte � lire
 */
double** lire_matrice_triangulaire_text(char* nom);



#endif // Outils_h_
