#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Outils.h"
#include "myBmpGris.h"


/** Methode de creation d'une matrice de stockage de l'image binaire (dimension (dimx,dimy)) initialisée à 0
 * \param :Nombre de colonnes
 * \param :Nombre dee lignes
 * \return :Structure Image contenant (dimx,dimy,pixels) initialisés
 */
Image initialiser_image(int dimx,int dimy){

    Image I;
    I.dimx=dimx;
    I.dimy=dimy;
    I.pixels=malloc(dimx*sizeof(int*));

    for(int i=0;i<dimx;i++){
        I.pixels[i]=calloc(dimy,sizeof(int));
    }
    return I;
}


/** Methode de lecture et de binarisation d'une image bmp
 * Utilise la methode ReadBmpImage de la bibliothèque myBmpGris.c
 * \param Nom de l'image
 * \return image de type Image avec le champ pixels contenant l'image binarisée
 */
Image lire_image_ndg(char* bmpimage){

    BmpImg B;
    B=readBmpImage(bmpimage);
    Image I=initialiser_image(B.dimX,B.dimY);

    for(int i=0;i<I.dimx;i++){
        for(int j=0;j<I.dimy;j++){

            // Récupère les niveau de gris de l'image
            I.pixels[i][j]=getPixel(B,i,j);

            // Définition d'un seuil pour la binarisation
            if(I.pixels[i][j]<127){
                I.pixels[i][j]=0;
            }
            else{
                I.pixels[i][j]=1;
            }
        }
    }
    return I;
}


/** Méthode d'écriture d'une image binaire au format bmp (conversion de l'image en niveau de gris)
 * Utilise createBmpImg pour la création d'une image au format Bmp et writeBmpImg pour l'écriture de l'image
 * \param Image à écrire
 * \param Nom de l'image à créer et écrire (.bmp)
 */
void ecrire_Image(Image I, char* nom_image){

    BmpImg B = createBmpImg(nom_image,I.dimx, I.dimy);

    for(int i=0;i<I.dimx;i++){
        for(int j=0;j<I.dimy;j++){

            if(I.pixels[i][j]==1){
                B.img[i][j]=255;
            }
            else{
                B.img[i][j]=0;
            }
        }
    }
    writeBmpImage(nom_image, &B );
 }


/** Méthode de création de matrice triangulaire respectant la contrainte p+q<=N
  * Cette fonction ne possède pas d'entrée car N est l'odre défini grâce aux macros
  * \return : matrice triangailaire allouée (initialisée à 0)
  */
double** cree_mat_trian(){

    double** matrice_triangulaire=malloc ((N+1)*sizeof(double*));
    for (int i =0 ; i<=N ; i++){
        matrice_triangulaire[i]= calloc((N+1)-i ,sizeof(double));
    }

    return matrice_triangulaire;
}


/** Méthode de déstruction d'une matrice
 * Pas de paramètres d'entrée car l'ordre de la matrice est défini en macro
*/
void desallocationMatrice(double** matriceADetruire, int colonnes){
    
    for(int ii = 0; ii<colonnes; ii++){
        free(matriceADetruire[ii]);
    }

    free(matriceADetruire);
}


/* Méthode d'écriture des valeurs des élément d'une matrice triangulaire dans un fichier texte
 * \param Matrice à écrire dans le fichier texte
 * \param nom du ficier texte qui va contenir les valeurs de la matrice
*/
void ecrire_matrice_triangulaire_text(double** lambda,char* nom){

    FILE *fichier=fopen(nom,"w");

    for(int p=0;p<=N;p++){
        for(int q=0;q<=N-p;q++){
            fprintf(fichier,"%f ",lambda[p][q]);
        }
        fprintf(fichier,"\n");
    }
    fclose(fichier);
}

/* Méthode de lecture des valeurs des éléments d'une matrice triangulaire stockés dans un fichier texte
 * \param Nom du ficher texte à lire
*/
double** lire_matrice_triangulaire_text(char* nom){

    FILE* fichier=fopen(nom,"r");
    double** matrice_triangulaire=cree_mat_trian();

    for(int p=0;p<=N;p++){
        for(int q=0;q<=N-p;q++){
            fscanf(fichier,"%lf",&matrice_triangulaire[p][q]);
        }
    }

    fclose(fichier);
    return matrice_triangulaire;
}

