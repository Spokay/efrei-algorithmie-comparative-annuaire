## Exercice 0

### Question 1 : pourquoi ne peut-on pas affecter une chaîne à un tableau de `char` avec `=` ?

Réponse : un tableau de `char` contient directement les caractères et sa taille est fixée lors de sa déclaration.
Le nom du tableau représente le premier caractère et ne peut donc pas être affecté avec `=`. Il faut copier la chaîne dans le tableau.

## Exercice 1

Entrées : array d'objets de type User
Sorties : 1 adresse email
Contraintes : 100 caractère max par adresse email
Volume : 30
Fréquence : deux fois par jour


Entrées : array d'objets de type User
Sorties : 1 adresse email
Contraintes : 100 caractère max par adresse email
Volume : 5 millions
Fréquence : mille fois par seconde 

### Question 2 : Question : parmi les cinq points, lesquels vous aideraient à choisir entre deux structures de données ?
Lesquels ne vous apprennent rien sur ce choix ?

Réponse : le volume et la fréquence sont les deux points utiles pour choisir entre deux structures de données,
car ils indiquent la quantité de données à stocker et le nombre de consultations à traiter. 
Les entrées, les sorties et les contraintes n'apportent rien dans cet exemple puisqu'elles sont identiques pour les deux annuaires.

### Question 3 : Question : deux annuaires ont les mêmes entrées et la même sortie, l’un contient 30 employés consultés
deux fois par jour, l’autre 5 millions de comptes interrogés mille fois par seconde. Quels sont les deux
points de la grille qui les distinguent ?

Réponse : les deux points qui les distinguent sont le volume et la fréquence.
Le premier annuaire contient peu de données et est consulté rarement, tandis que le second contient beaucoup de données et est consulté très fréquemment.

## Exercice 2

taille = 1
capacite = 16
taille = 2
capacite = 16
taille = 3
capacite = 16
taille = 4
capacite = 16
taille = 5
capacite = 16
taille = 6
capacite = 16
taille = 7
capacite = 16
taille = 8
capacite = 16
taille = 9
capacite = 16
taille = 10
capacite = 16
taille = 11
capacite = 16
taille = 12
capacite = 16
taille = 13
capacite = 16
taille = 14
capacite = 16
taille = 15
capacite = 16
taille = 16
capacite = 16
taille = 17
capacite = 32
taille = 18
capacite = 32
taille = 19
capacite = 32
taille = 20
capacite = 32
taille = 21
capacite = 32
taille = 22
capacite = 32
taille = 23
capacite = 32
taille = 24
capacite = 32
taille = 25
capacite = 32
taille = 26
capacite = 32
taille = 27
capacite = 32
taille = 28
capacite = 32
taille = 29
capacite = 32
taille = 30
capacite = 32
taille = 31
capacite = 32
taille = 32
capacite = 32
taille = 33
capacite = 64
taille = 34
capacite = 64
taille = 35
capacite = 64
taille = 36
capacite = 64
taille = 37
capacite = 64
taille = 38
capacite = 64
taille = 39
capacite = 64
taille = 40
capacite = 64


### Question 4 : combien de fois realloc a-t-il été appelé pour ces 40 insertions ? Et pour 1000 insertions ?

Réponse : `realloc` a été appelé 3 fois pour 40 insertions.
La capacité double à chaque fois que le tableau est plein. Donc pour 1000 insertions,
on passe de 16, 32, 64, 128, 256, 512 et 1024. Pour 1000 insertions realloc est donc appelé 7 fois. 
C'est logarithmique par rapport au
nombre d'insertions.

## Exercice 3

| Recherche | Attendu | Obtenu |
|---|---|---|
| Une adresse présente | `true` | `true` |
| Une adresse absente | `false` | `false` |
| Sur annuaire vide | `false` | `false` |

### Question 5 : combien de comparaisons seq_search effectue-t-elle sur un annuaire de n utilisateurs, dans
le cas favorable, dans le cas moyen, puis dans le cas défavorable ? Décrivez à chaque fois quelle donnée
produit ce cas.

Réponse : 
- Cas favorable -> 1 comparaison
- Cas moyen -> n / 2
- Cas défavorable -> n