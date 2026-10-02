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


