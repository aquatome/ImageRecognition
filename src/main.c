#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Reconnaissance_forme.h"
#include "Outils.h"
#include "myBmpGris.h"


int main(){
    
    int var;
    int choix=1;

    printf("\n\t\t\t\t Bienvenue dans le programme ""Reconnaissance des Formes"" \n\n");


    while(choix == 1){
    
        printf("********************************************** I-RECONNAISSANCE DE FORME **********************************************\n\n\n");
        printf("Entrez le nom de l'image a reconnaitre (ex: ""Iref_1.bmp"")\n>>> ");
        
        char nom[30];
        scanf("%s",nom);


        Image i=lire_image_ndg(nom);
        
        printf("\n\n>>>>> 1.DEBUT DE LA PHASE D'APPRENTISSAGE \n");
        
        apprentissage(&i,N);
        ecrire_matrice_triangulaire_text(i.matrice_lambda,"matrice.txt");
        
        printf("\n>>>>> 2.PHASE D'APPRENTISSAGE REUSSIE\n\n");
        printf("(La matrice des moments de l'image est disponible sous format texte dans le dossier du projet)\n\n\n\n");
        
        printf("********************************* II-RECONSTRUCTION OU RECONAISSANCE *********************************\n\n\n");
        
        printf(">>>>> Reconnaitre la forme APPUYER sur (1)\n>>>>> Reconstruire l'image APPUYER sur (2)\n\n>>>>> ");
        
        
        scanf("%d",&var);
        
        while(var != 1 && var!= 2){
            printf ("Veuillez choisir uniquement l'une des propositions ci-dessous !\n>>>>>");
            scanf("%d", &var);
        }
        
        printf(" \n\n\n");

        
        if(var==1){
            printf("\t\t\t\t>>> RECONAISSANCE DE LA FORME EN COURS <<<\n\n\n");
            int d=distance(i);
            printf("\nL'image identifiee est Iref_%d\n\n",d);
        }

        
        else{
            
            printf("\t\t\t\t>>> RECONSTRUCTION DE L'IMAGE EN COURS <<<\n\n\n");
            Image I=reconstruction(i,i.matrice_lambda);
            ecrire_Image(I,"image_reconstruite.bmp");

            printf(">>>>> Image reconstruite avec succes !\n");
            printf(">>>>> Pour changer l'ordre de reconstruction de l'image, rendez-vous dans la bibliotheque Reconnaissance_forme.h \n\n\n");
            printf("\t\t\t\t/!\\ Ordre maximal de reconstruction: N = 50 /!\\ \n\n\n");
        }

        printf("********************************* FIN DU PROGRAMME *********************************\n\n\n");
     
        printf("Voulez vous relancer le programme (1:OUI/0:NON) ? \n>>>>> ");
    
        if(scanf("%d", &choix)!=1){
            
            printf("ERREUR FATALE ! FIN DU PROGRAMME \n");
            exit(EXIT_FAILURE);

        }

    }
    

    printf("\n\n\n---Copyright 2021---\n\n");
    
    printf("KHECHAI Hiba\n");
    printf("BENABID M'Hamed\n");
    printf("BECHROURI Yassine\n");
    printf("MANSOOR Qassim-Tayab\n");




    return 0;
}
