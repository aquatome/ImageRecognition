# ImageRecognition

## Introduction

L’information traitée par le corps humain passe à 83% par la vue. Supposons maintenant
qu’il soit possible d’automatiser certaines tâches, complexes ou redondantes, qui
nécessitent des ressources visuelles importantes et ce, à l’aide de méthodes permettant à
des machines de reconnaître leur environnement. Alors il serait possible d’augmenter
drastiquement la productivité de chaque individu amené à effectuer ces tâches.
Mais quelles méthodes mathématiques utiliser pour permettre aux machines de
reconnaître des formes ? 

Pour permettre à un ordinateur de reconnaître les formes présentes sur une image, il faut
décomposer mathématiquement celles-ci afin de pouvoir opérer dessus. Pour simplifier le
problème, nous allons travailler avec des images binaires (composée de 2 niveaux de
couleurs : noir et blanc).
Premièrement, il faut passer par une phase d’apprentissage où il convient de décrire les
formes sur les images en fonction de définitions mathématiques (calcul des moments
géométriques de la forme à reconnaître). 

Ensuite il faut implémenter et mettre en
pratique la méthode utilisée, en comparant les moments géométriques de toutes les
images d’une base de données. L’image déterminée comme ressemblante sera celle dont
la distance euclidienne des moments géométriques avec l’image de référence est la plus
proche. Cette image sera alors reconstruite afin de vérifier que l’opération s’est déroulée
correctement.

## Outils utilisés
<details>
<summary>Bibliothèques</summary>

Pour simplifier l’écriture, la lecture et l’organisation du code source, il faut séparer celui-ci en différents fichiers. A chaque tâche est associée une bibliothèque contenant les
fonctions nécessaires à la réalisation de celle-ci. 

Ces bibliothèques sont au nombre de 3 :

- myBmpGris.c : bibliothèque nécessaire à l’initialisation, la création, la copie, la
conversion et la destruction d’images bitmap (format d’image utilisé dans le projet)

- Outils.c : bibliothèque d’initialisation, de création et de destruction de matrices
nécessaires au traitement de l’image sous forme de nombres. Elle contient également des
fonctions de lecture et d’écritures de valeurs matricielles dans un fichier texte

- Reconnaissance_forme.c : bibliothèque contenant toutes les méthodes
mathématiques de calcul nécessaires aux étapes de reconnaissance des formes :
l’apprentissage, la reconstruction de l’image pour validation de l’apprentissage et la
reconnaissance d’une image
</details>

<details>
<summary>Structures</summary>

Il est possible de mieux organiser le code et de le simplifier en faisant appel aux
structures. 

Ces structures permettent principalement de créer un type de données
personnelles afin de pouvoir ranger toutes les informations en fonction des attributs de la
structure :

- BmpImg : structure contenant les noms et les tailles des images sources au format
bmp ainsi que la taille des headers.
- Image : structure contenant les tailles des images à reconstruire, leurs dimensions
en pixels, l’aire de la forme à reconnaître, les barycentres ainsi que la matrice contenant
les moments de Legendre de l’image

</details>

## Phase d'apprentissage
<details>
<summary>Calcul des moments géométriques</summary>
</details>

<details>
<summary>Création et initialisation de la matrice triangle</summary>
</details>

<details>
<summary>Calcul de l'aire et du barycentre</summary>
</details>

<details>
<summary>Création de la matrice de Vandermonde</summary>
</details>

<details>
<summary>Calcul des moments géométriques centrés et normés</summary>
</details>

<details>
<summary>Calcul des moments de Légendre centrés et normés</summary>
</details>

<details>
<summary>Reconstruction de l'image</summary>
</details>

## Reconnaissance des formes
<details>
<summary>Création de la base de données</summary>
</details>

<details>
<summary>Calcul de la distance euclidienne entre matrices de moments</summary>
</details>

<details>
<summary>Comparaison de la matrice des moments des différentes images</summary>
</details>