# Objectif de la piscine
Il s'agit d'une piscine, dans laquelle nous allons nous focaliser sur le kit de développement du ATMega328p, 
une très belle pièce pleine de ressources, tout à fait dans l’air du temps.

Les exercices sont réalisés en C. Ils sont tous compilés pour l’architecture
AVR avec avr-gcc.

Pour écrire le binaire sur la mémoire flash du kit, nous devons utiliser avr-objcopy
et avrdude. Nous devons utiliser le programmeur "arduino", avec un baud rate de 115200.
Les 2 documents les plus importants durant toute cette piscine sont :
• le datasheet de l’ATmega328p ( 653 pages de pur bonheur ) ;
• le schéma du devkit (https://github.com/ouachani-il/Piscine_embarquee/blob/main/module00/elec42_pool-2-1.pdf).
