#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <string>

float abs_fonction (const float & nombre) {
    if (nombre < 0)
        return -nombre;
    return nombre;
}

void binomiale (const float & n_max, const float & p_max, const std::string & nomfichier_data) {
    std::string content_data = "n,p,diff_E\n";
 
 // Effectuer les tests
 float succes_bernoulli;
 float random_E, E, diff_E;
 for (float n = 1; n <= n_max; ++n) {
  for (float p = 0.1; p <= p_max+0.1; p = p + 0.1) {
   // calculer random_E en effectuant n expérience de Bernoulli
   random_E = 0;
   for (float indice_bernoulli = 0; indice_bernoulli < n; ++indice_bernoulli) {
    succes_bernoulli = (rand() % 100) + 1;
    // l'expérience est un succès
    if (succes_bernoulli <= (p * 100))
     ++random_E;
   }

   // calculer E
   E = n * p;

   // calculer diff_E
   diff_E = abs_fonction(E-random_E);

   content_data.append(std::to_string(n) + "," + std::to_string(p) + "," + std::to_string(diff_E) + "\n");
  }
 }
 // supprime la dernière ligne vide
 content_data.pop_back();

 // Sauvegarder les données
 std::ofstream data_file;
 data_file.open(nomfichier_data, std::fstream::out);
 data_file << content_data;
 data_file.close();
}

int main () {
 srand(time(NULL));

 float n_max, p_max;
 n_max = 100;
 p_max = 0.9;
 std::string nomfichier_data = "data/data_binomiale.csv";
 binomiale(n_max, p_max, nomfichier_data);
}