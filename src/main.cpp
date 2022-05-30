#include <cstdlib>
#include <utility>
#include <iostream>
#include <string>
#include <iterator>
#include <list>
#include <bits/stdc++.h>
#include "Labirinto.hpp"
using namespace std;

int
main ()
{
  Labirinto j;
  int n, escolha;
  escolha = 0;
  cout << "De o tamanho da matriz Labirinto:\n";
  cin >> n;
  j.setN (n);
  j.create (n);
  cout << "Original:\n";
  j.mostra (n);
  
  while (escolha != 1 && escolha != 2){
  cout << "1 - Euclidiano, 2 - Manhattan\n";
  cin >> escolha;
  if (escolha != 1 && escolha != 2)
  cout << "valor invalido.\n";
}
  j.CaminhoA(n, escolha);

  cout << "Matriz caminhada:" << endl;
  j.grade[n - 1][n - 1] = -1;
  j.mostra (n);

  return 0;
}
