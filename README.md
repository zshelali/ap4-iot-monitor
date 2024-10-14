TP AP4A

Alexandre BRUNOUD - Jean-Charles CREPUT
Automne 2024

1. Présentation du projet

1.1 Introduction

Le TP d’AP4A prend la forme d’un mini-projet individuel qui vous permettra de mettre en pratique les connaissances acquises en cours. Ce projet servira également d’aperçu pour le projet Java à rendre en fin de semestre.
Vous aurez trois séances de trois heures pour réaliser ce projet, et sa difficulté sera croissante.

1.2 Mise en contexte

Le but du projet est de réaliser un simulateur qui modélise un écosystème IOT spécialisé dans le monitoring de la qualité de l’air dans un espace de travail. Cet écosystème comprendra un serveur communiquant avec plusieurs types de capteurs répartis dans l’espace, tels que des capteurs de température, d’humidité, de lumière, et des capteurs sonores.
Les données recueillies par ces capteurs pourront être stockées sous forme de fichiers logs ou visualisées sur une console.

2. Les outils de développement

Le projet sera réalisé en C++17, standard largement supporté et facile à compiler sur Linux et Windows. Vous utiliserez le compilateur GNU g++ pour le langage C++ (sur Windows, via MinGW).
Après avoir compilé un programme de type “hello world”, vous réaliserez un projet plus élaboré avec un fichier main.cpp et une classe Server (dans Server.cpp et Server.h) pour mettre en place et tester vos outils de développement.

2.1 IDE et outils recommandés

Vous pouvez utiliser divers IDE comme Qt Creator, DevC++, CLion, Visual Studio Code, ou Visual Studio. Cependant, pour assurer une compatibilité multi-plateforme (Linux, Windows, MacOS), il est recommandé d’utiliser un outil de gestion de projet comme CMake (avec CMakeLists.txt), ou qmake (avec <projet>.pro pour Qt Creator).
L’outil choisi devra permettre de générer automatiquement des Makefiles pour la plateforme cible. Exemples et configurations seront présentés en TP.

Quel que soit l’IDE choisi, un fichier CMakeLists.txt devra être inclus dans le rendu final, ou bien un fichier <projet>.pro pour Qt Creator.

3. Première séance

3.1 Premier programme

Lors de cette première séance, vous allez écrire un programme classique “Hello World”, le compiler et l’exécuter.
Vous utiliserez le compilateur GNU g++ et devrez connaître les options de compilation, la séparation entre la compilation et l’édition de liens, ainsi que l’affichage des warnings. Consultez la documentation Linux (man) pour rédiger la commande g++.
Une fois cela terminé, montrez votre travail à un professeur. Vous pouvez ensuite utiliser les IDE mentionnés précédemment pour la suite du projet.

3.2 Développement du simulateur

Votre simulateur comportera un serveur (classe Server) et des capteurs (classe Sensor), ainsi qu’une classe pour l’ordonnancement des exécutions (classe Scheduler).
Votre première tâche sera de créer la classe Server, qui doit recevoir, analyser, formater, et stocker les données envoyées par les capteurs dans des fichiers logs ou les afficher dans la console.

Vous implémenterez la forme canonique de Coplien pour cette classe, et écrirez deux fonctions :

	•	consoleWrite : pour afficher les données des capteurs dans la console.
	•	fileWrite : pour stocker les données dans des fichiers logs (un fichier par type de capteur).

4. Deuxième séance

4.1 Architecture du projet

Lors de la deuxième séance, vous commencerez à implémenter l’architecture globale du projet. Si les concepts d’héritage n’ont pas encore été abordés, vous créerez les classes Server, Scheduler et Sensor avec un comportement par défaut.
Les mécanismes d’héritage et de polymorphisme seront introduits plus tard pour ajouter de la généricité au système.

Vous créerez ensuite un schéma UML pour visualiser l’architecture du projet. Vous devrez également créer les classes Sensor et Scheduler, conformément au diagramme de classes fourni.

4.2 La classe Sensor

La classe Sensor est la classe mère des capteurs. Chaque capteur est un processus autonome, simulé par la classe Scheduler. Le rôle de l’ordonnanceur est d’activer les processus selon une base de temps définie. Chaque capteur gère son propre comportement interne.

La classe Sensor devra inclure des attributs comme un identifiant unique, un type de capteur par défaut (sous forme de chaîne de caractères), une donnée mesurée, et un pointeur vers le serveur associé. Elle inclura également une fonction update pour gérer le comportement dynamique du capteur et une fonction execute pour générer des données aléatoires simulant les lectures des capteurs.

4.3 La classe Scheduler

La classe Scheduler gère l’animation des capteurs et leur activation selon une base de temps. La fonction simulation organise l’exécution des capteurs via leur méthode update.

5. Troisième séance

5.1 Héritage et polymorphisme

Lors de la troisième séance, vous implémenterez les mécanismes d’héritage et de polymorphisme pour rendre les classes abstraites et maximiser la généricité du projet. Les capteurs pourront désormais renvoyer des types de données différents selon leur nature.
Les concepteurs les plus avancés pourront ajouter des fonctionnalités supplémentaires, telles que des fonctions d’analyse de mesures ou des systèmes de décision autonomes pour le serveur.

6. Synthèse

Voici une liste des outils utilisés dans ce projet :

	•	g++ : compilateur C++
	•	make : pour générer des Makefiles
	•	gdb : pour déboguer
	•	valgrind : pour détecter les fuites mémoire
	•	IDE : Qt Creator, Visual Studio Code, CLion, etc.
	•	UML : ASTAH

Objectifs atteints :

	•	Implémentation correcte des mécanismes de C++ (constructeurs, destructeurs, héritage, polymorphisme, etc.)
	•	Compilation et exécution sans erreur
	•	Gestion correcte de la mémoire
	•	Niveau de sophistication dans l’implémentation

7. Rendu de projet

Le rapport et le code sont à rendre individuellement pour le 10 novembre 2024 avant minuit via Moodle. Vous devez fournir deux fichiers :

	1.	Rapport AP4A Groupe Nom Prénom.pdf : avec le rapport et le diagramme UML.
	2.	Code AP4A Groupe Nom Prénom.zip : contenant le code source C++.

N’oubliez pas d’inclure un fichier CMakeLists.txt ou <projet>.pro pour la compilation multi-plateforme.
