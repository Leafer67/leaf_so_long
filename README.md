# So_long

_Voici mon projet So_long pour l'ecole 42_

## Idée Global

Création d'un jeu 2D à l'aide de l'utlisation de la MLX Codam
Il reste quelques erreurs dans le code et le projet est globalement mal structuré étant l'un des premiers "gros" projet que j'ai fait.

- WASD - Se déplacer
- Spacebar - Attaquer
- Esc - Quitter

Le but est de collecter toute les pièces puis d'aller à la sortie.

Initialement, on pouvait restart le jeu avec la touche R mais le passage sur linux du projet (codé sur mac de base) et/ou les nouvelles versions de la lib graphique font que le jeu segfault sur un restart.
Vu que ce n'est pas nécessaire pour le sujet (et que j'ai un peu la flemme de me replonger dans le code 10mois après), j'ai pas corrigé ce problème.

![image](https://github.com/Leafer67/leaf_so_long/assets/106589245/ccb68a8e-6673-427f-aeb3-25d3c069626a)

Pour les personnes hors 42 : Le dossier libft est une liste de fonctions de la librairie standard du C que chaque étudiant doit recoder.

Note : Il est potentiellement nécessaire de modifier la taille de la fenêtre dans le fichier defines.h (Il est possible que certaines map ne soit pas affichables dans ce cas, mais vous êtes libres de les modifier ou d'en créer vous-même)

## Compilation

```
$ make linux
```

## Execution

Il y a plusieurs maps à dispositions dans le dossier 'maps/'
```
$ ./so_long map/map_correct.ber
```
***
