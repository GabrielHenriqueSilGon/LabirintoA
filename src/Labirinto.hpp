#ifndef __LABIRINTO_HPP
#define __LABIRINTO_HPP
#include <string>
#include <utility>
#define MAXTAM 10
using namespace std;

typedef pair< pair<int, int>, double > Ppair;

class Labirinto
{

public:
  int **grade;
  void create (int v);

  void setN (int n);
  void setGrade (int l, int c);
  void mostra (int n);
  Ppair Proximo (pair <int,int> local, int n, int escolha);
  void CaminhoA(int n, int escolha);
  double euclidiano(pair <int, int> local, int n);
  double man(pair <int, int> local, int n);
};

#endif
