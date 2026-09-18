# Code Review

Auteur : Osmane Amine

- Préférer mettre les includes de "main.cpp" dans le fichier d'en-tête "main.h"
- main.cpp ligne 4 : ```#include "../Inc/Pokemon_party.h"``` Attention à la casse. Nom du fichier : ```"Pokemon_Party.h"```
- Pokedex.cpp ligne 46 : Préférer un chemin relatif ```../pokedex.csv``` plutôt qu'un chemin absolu ```C://Users//tompi//Desktop//cours//c++//TP//pokedex.csv``` pour bien trouver le fichier après avoir cloner le repository sur une autre machine
- Le programme entre dans une boucle infinie si aucun starter n'est choisi
- Ne pas inclure les bibliothèques pas encore utilisée, ce qui rallonge le temps de compilation (ici : sfml)