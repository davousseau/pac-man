# Pacman

## Auteur
[David Brousseau](mailto:dbrsseau@gmail.com)

## Contexte
Projet effectué dans le cadre du cours **420-SE2-DM Système d'exploitation II**, remis à l'enseignant **Louis Marchand** au [Cégep de Drummondville](https://www.cegepdrummond.ca/) le 19 décembre 2014. Ce projet a été retranscris en 2020 pour le rendre public et l'insérer dans mon porte-folio.

## Description
Conception partielle du jeu [Pac-Man](https://fr.wikipedia.org/wiki/Pac-Man) sur la première console de salon [Nintendo Entertainment System](https://fr.wikipedia.org/wiki/Nintendo_Entertainment_System). À noter qu'il n'y a aucune détection des collisions.

## Prérequis
- [NESASM](http://www.magicengine.com/mkit/), assembleur NES 6502 pour compiler le code.
- [VS Code](), éditeur de texte pour modifier le code.
- [Retro Assembler](https://marketplace.visualstudio.com/items?itemName=EngineDesigns.retroassembler), extension du langage d'assemblage à l'utilisation de VS Code.
- [FCEUX](http://fceux.com/web/download.html), émulateur NES pour lancer le jeu.

## Compatibilité
Testé sous un environnement **linux** et **windows** avec l'émulateur **FCEUX seulement**.

## Lancer le jeu
```
fceux bin/pac-man.nes
```

## Fonctionnement
### Joueur 1
Utilisez le `pad directionnel` de votre manette pour déplacer Pac-Man.

### Joueur 2
#### Permutation entre les logos
- `Bouton A` &rarr; Microsoft
- `Bouton B` &rarr; Linux
- `Select` &rarr; Apple
- `Start` &rarr; Céti

Utilisez le `pad directionnel` de votre manette pour déplacer le logo sélectionné.

## Références
- [6502 ASM, first app](https://taywee.github.io/NerdyNights/nerdynights/asmfirstapp.html)
- [NES ASM Tutorial](https://patater.com/gbaguy/nesasm.htm)
- [NES Basics and Our First Game](http://thevirtualmountain.com/nes/2017/03/08/nes-basics-and-our-first-game.html)
