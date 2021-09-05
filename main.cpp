#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <string>

float abs_function (const float & number) {
    if (number < 0)
        return -number;
    return number;
}

void binomiale (const float & n_max, const float & p_max, const std::string & filename_data) {
 float E_test, E_simple, ecart_E;
 // std::ofstream data_file;
 // data_file.open (filename_data);
 // data_file << "n,p,ecart_E\n";
 std::cout << "n,p,ecart_E\n";

 for (float n = 1; n <= n_max; ++n) {
  for (float p = 0.1; p <= p_max; p = p + 0.1) {
   // calcul de E_test
   float succes_bernoulli;
   E_test = 0;
   for (float indice_bernoulli = 0; indice_bernoulli < n; ++indice_bernoulli) {
    succes_bernoulli = (rand() % 100) + 1;
    if (succes_bernoulli <= (p * 100))
     ++E_test;
   }

   // calcul de E_simple
   E_simple = n * p;

   // calcul de ecart_E
   ecart_E = abs_function(E_simple-E_test);

   // affichage des resultat pour un n et p données
   //*//
   std::cout << std::endl << "n: " << n << ", p:" << p << std::endl;
   std::cout << "E_test: " << E_test << std::endl;
   std::cout << "E_simple: " << E_simple << std::endl;
   std::cout << "ecart_E: " << ecart_E << std::endl;
   //*/

   // sauvegarder data
   // data_file << std::to_string(n) + std::to_string(p) + std::to_string(ecart_E) + "\n";
   std::cout << std::to_string(E_test) + "," + std::to_string(E_simple) + "," + std::to_string(ecart_E) + "\n";
   std::cout << std::to_string(n) + "," + std::to_string(p) + "," + std::to_string(ecart_E) + "\n\n";
  }
 }

 // data_file.close();
}

int main () {
 srand(time(NULL));

 float n_max, p_max;
 n_max = 100;
 p_max = 1;
 std::string filename_data = "data_binomiale.csv";
 binomiale(n_max, p_max, filename_data);
}