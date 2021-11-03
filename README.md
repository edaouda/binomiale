Le but de ce projet est d'étudier la différence (diff_E) entre l'espérance (E=n*p) et les tests (random_E) d'une loi binomiale.
En faisant n expériences de Bernouilli, random_E est obtenu en choisisant une valeur aléatoire (plus p est élevé, plus l'expérience sera un succès).

Langages utilisés:
    -C++ pour génerer et stocker les données
    -Python pour tracer un graphique avec le bibliothèque Matplotlib

Pour les tests, on va varier n de 1 à 100 et p de 0.1 à 0.9.
Des exemples de test sont stockées dans le dossier test.

Suivez ces étapes pour génerer un graphique sur linux:
    -compiler binomiale.cpp: g++ -std=c++11 binomiale.cpp -o a.out
    -éxecuter a.out: ./a.out
    -éxecuter binomiale_analyse.py: python3 binomiale_analyse.py
    dans data, cela va génerer le graphique graphique.png

Après plusieurs test, on observe que plus n augmente, plus diff_E augmente souvent.
Cela s'explique par le fait que plus n augmente, plus le nombre de succès ou défaite sera possiblement grande.