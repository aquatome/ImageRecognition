#include <math.h>

#include "Reconnaissance_forme.h"
#include "Outils.h"



/** Methode de calcul des moments géometriques d'une image binarisée
  *  Utilise la methode cree_mat_trian
  * \param Structure contenant les paramètres de l'image
  * \return Matrice triangulaire contenant les moments géometriques
  */
double** matrice_triangle_moment_geometrique(Image I){

    double** matrice_triangulaire=cree_mat_trian();

    for (int p=0 ; p<=N ; p++){
        for (int q=0 ; q<=N-p ; q++){
            for(int x=0 ; x<I.dimx ; x++){
                for(int y=0 ; y<I.dimy ; y++){
                    matrice_triangulaire[p][q]+=pow(x,p)*pow(y,q)*I.pixels[x][y];
                }
            }
        }
    }

    return matrice_triangulaire;
}


/** Méthode de calcul de l'aire d'une forme d'une image binarisée
  * \param Structure contenant les paramètres de l'image
  * \return Aire de la forme
  */
int aire_de_la_forme(Image I){

    int aire_de_la_forme_totale=0 ;

    for(int x=0 ; x<I.dimx ; x++){
        for(int y=0 ; y< I.dimy ; y++){
            aire_de_la_forme_totale+=I.pixels[x][y];
        }
    }

    return aire_de_la_forme_totale;
}



 /** Methode de calcul des barycentres d'une image binaire
  * Utilise la méthode aire_de_la_forme
  * \param Structure contenant l'image
  * \return Vecteur de 2 éléments contenant les barycentres
  */
int* centre_de_masse(Image I){

    // Calcul des moments M01 et M10
    int* centre_de_masse= calloc(2, sizeof(int));
    int M01=0 ;
    int M10 = 0 ;
    int M00=aire_de_la_forme(I) ;

    for(int x=0 ; x<I.dimx ; x++){
        for (int y=0 ; y<I.dimy ; y++){

            M01+= y*I.pixels[x][y] ;
            M10+= x*I.pixels[x][y] ;
        }
    }

    centre_de_masse[0]=M10/M00;
    centre_de_masse[1]=M01/M00;

    return centre_de_masse ;
}


/* Méthode de calcul de la base de Vandermonde en X
 * \return Tableau en X de la base de Vandermonde
*/
double** base_de_matrice_de_Vandermonde_X(Image I){
    int i, j;
    double** matrice_de_Vandermonde_X = malloc((I.dimx+1)*sizeof(double*));

    for (int c = 0; c<=I.dimx; c++){
        matrice_de_Vandermonde_X[c]= calloc( N+1 , sizeof(double));
    }

    for (i = 0; i<=I.dimx; i++){
        for(j=0;j<=N;j++)
        {
            matrice_de_Vandermonde_X[i][j]= pow((i-I.X_barre),j);
        }
    }

    return matrice_de_Vandermonde_X;
}


/* Méthode de calcul de la base de Vandermonde en Y
 * \return Tableau en Y de la base de Vandermonde
*/
double** base_de_matrice_de_Vandermonde_Y(Image I){
    int i, j ;
    double** matrice_de_Vandermonde_Y = malloc( (I.dimy+1) * sizeof(double*));
    for(int c=0; c<=I.dimy; c++){
        matrice_de_Vandermonde_Y[c]= calloc( N+1 , sizeof(double));
    }

    for(i=0; i<=I.dimy; i++){
        for(j=0;j<=N;j++){

            matrice_de_Vandermonde_Y[i][j]= pow((i -I.Y_barre),j);
        }
    }

    return matrice_de_Vandermonde_Y;
}


double** matrice_triangle_moment_geometrique_centre_norme(Image I,double** matrice_de_Vandermonde_X,double** matrice_de_Vandermonde_Y){

    long double var1,var2;
    double** matrice_triangulaire=cree_mat_trian();
    int a;

    for (int p=0 ; p<=N ; p++){
        for (int q=0 ; q<=N-p ; q++){
            var1=0;
            var2=pow(I.aire_de_la_forme,(p+q+2)/2.0);//Iref_2 Beta=135.5

            for(int x=0; x<=I.dimx; x++){
                for(int y=0 ; y<=I.dimy ; y++){

                    if( (x==I.dimx) || (y==I.dimy)){
                        a=0;
                    }

                    else{
                        a=I.pixels[x][y];
                        }

                    var1=matrice_de_Vandermonde_X[x][p]*matrice_de_Vandermonde_Y[y][q];
                    matrice_triangulaire[p][q]+=(double)(var1 *a)/(double)var2;

                }
            }
        }
    }

    return matrice_triangulaire;
}


/** Methode de calcul des coeffcients des polynomes de Legendre (ordre 0 à N)
 * \return matrice de réels contenant les coeffcient de Legendre
 */
long double** matrice_coeff_polynome(int ordre){

    //variables intérmedaire de calcule
    long double var,a;

    //déclaration et initialisation à 0 de la matrice des coeffcient
    long double** mat_coeff=malloc((ordre+1)*sizeof( long double*));

    for(int r=0;r<=ordre;r++){
        mat_coeff[r]=calloc(r+1,sizeof(long double));
    }

    //n est un compteur correspondant à l'ordre du polynome
    for(int n=0;n<=ordre;n++){

        if(n==0){
            // Coefficient dominant égal à 1
            mat_coeff[n][n]=1;
        }

        else{

            // Calcul du coefficent dominant à partir de celui du polynome précédent
            mat_coeff[n][n]+= mat_coeff[n-1][n-1]*(((2*(n-1))+1)/(double)n);
        }

        //k est un comtpeur correspondant à l'ordre du coeffcient
        for(int k=n-2;k>=0;k=k-2){

            //pour avoir une résultat réel
            var=k;
            a=((var+1)*(var+2))/((long double)(n-var)*(var+n+1));
            mat_coeff[n][k]+=((-1)*mat_coeff[n][k+2]*(long double)a);//calcule du coeffcient a partir de celui d'ordre supérieure(application de l'equation de récurences)z
        }
    }
    return mat_coeff;
}


/** Methode qui calcule les moments géometriques de Legendre à partir des moments centrés et normés
 *  Utilise la fonction matrice_coeff_polynome pour récuperer les coeffcients des polynomes de Legendre
 * \param matrice de réels qui contient les moments centrés et normés de l'image
 * \return matrice de réels qui contient les moments de Legendre centrés et normés
 */
double** moments_legendrecentre_norme_lambda(double** moment_centre_norme)
{

    long double** base_de_legendre_X=matrice_coeff_polynome(N);
    long double** base_de_legendre_Y=matrice_coeff_polynome(N);
    long double C;
    double** lambda=cree_mat_trian();

    for(int p=0;p<=N;p++){
        for(int q=0;q<=N-p;q++){
                 C=(2*p+1)*(2*q+1)/(double)4;
            for(int i =0; i<=p ; i++){
                for(int j=0; j<=q; j++){


                    lambda[p][q]+= C*moment_centre_norme[i][j]*base_de_legendre_X[p][i]*base_de_legendre_Y[q][j];
                }
            }
        }
    }
    return lambda;
}


/** Methode de calcul des polynomes de legendre (ordre 0 à N) en x
 * Effectue un changement de variable sur x avant le calcul
 * \param Variable de départ x
 * \param Matrice des coeffcients des Polynomes de Legendre
 * \param Entier permettant un changement de variable entre -1 et 1
 * \return Vecteur de dimension N. Chaque élément contient le polynome d'ordre (indice de l'élément) en x
 */
double* polynome(double x,long double** coeff, int dim,int ordre){

    double* polynome_x=calloc((ordre+1),sizeof(double));

    // Changement de variable
    double xx=(-1+((2*x)/(double)dim));

    // Variables intermédiaires de calcul
    long double var1,var2;

    for(int n=0;n<=ordre;n++){
        var2=0;
        for(int i=0;i<=n;i++){

            // Calcul de x^i
            var1=pow(xx,i);

            //Somme la multiplication des coeffcient d'ordre i et x^i
            var2+=coeff[n][i]*var1;
        }
        //P(x) d'ordre n
        polynome_x[n]=var2;
    }
    return polynome_x;
}


/** Méthode de reconstuction d'une image à partir des moments de Legendre centrée et normés
 * \param Image de départ qui récupurère les dimensions de l'image à écrire
 * \param Matrice de réels qui contient les moments de Légendre
 * \return Image contenant "pixels" intialisé à partir du calcul des moments de Legendre
 */
void apprentissage(Image* i,int n)
{

i->aire_de_la_forme=aire_de_la_forme(*i);
int* tab=centre_de_masse(*i);
i->X_barre=tab[0];
i->Y_barre=tab[1];
double** mat1=base_de_matrice_de_Vandermonde_X(*i);
double** mat2=base_de_matrice_de_Vandermonde_Y(*i);
double** matrice_intermedaire=matrice_triangle_moment_geometrique_centre_norme(*i,mat1,mat2);
i->matrice_lambda=moments_legendrecentre_norme_lambda(matrice_intermedaire);
 }
Image reconstruction(Image Iref,double** lambda){

    Image I=initialiser_image(Iref.dimx,Iref.dimy);

    long double var;
    long double** coefx=matrice_coeff_polynome(N);

    for(int x=0;x<Iref.dimx;x++){
       double* polynomex=polynome(x,coefx,Iref.dimx,N);
        for(int y=0;y<Iref.dimy;y++){

            var=0;
            double*polynomey=polynome(y,coefx,Iref.dimy,N);

            for(int p=0;p<=N;p++){
                for(int q=0;q<=N-p;q++){
                    var+=(lambda[p][q]*polynomex[p]*polynomey[q]);
                }
            }

            if(var<0.555){
                I.pixels[x][y]=0;
            }
            else{
                I.pixels[x][y]=1;
            }
        }
    }
    return I;
}

/* Méthode de calcul de la distance euclidienne entre les moments des matrices de toutes les images
 * \param Structure contenant les images
*/
int distance(Image i){

    double** Iref_0=lire_matrice_triangulaire_text("Iref0.txt");
    double** Iref_1=lire_matrice_triangulaire_text("Iref1.txt");
    double** Iref_2=lire_matrice_triangulaire_text("Iref2.txt");
    double** Iref_3=lire_matrice_triangulaire_text("Iref3.txt");
    double* tab=calloc(4,sizeof(double));

    for(int p=0;p<=N;p++){
        for(int q=0;q<=N-p;q++){
            double var=(i.matrice_lambda[p][q]-Iref_0[p][q]);
             double var1=(i.matrice_lambda[p][q]-Iref_1[p][q]);
            double var2=(i.matrice_lambda[p][q]-Iref_2[p][q]);
            double var3=(i.matrice_lambda[p][q]-Iref_3[p][q]);
            tab[0]+= pow(var,2) ;
            tab[1]+= pow(var1,2) ;
            tab[2]+= pow(var2,2) ;
            tab[3]+= pow(var3,2) ;
        }
    }
    tab[0]=sqrt( tab[0]);
    tab[1]=sqrt( tab[1]);
    tab[2]=sqrt( tab[2]);
    tab[3]=sqrt( tab[3]);


    double min=tab[0];
    int c=0;


      for(int i=1;i<4;i++)
      {
          if(min>tab[i])
          {

             min=tab[i];
             c=i;

          }



      }



return c;
}









