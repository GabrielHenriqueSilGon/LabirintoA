#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>
#include <iterator>
#include <list>
#include <bits/stdc++.h>
#include "Labirinto.hpp"
using namespace std;

void
Labirinto::setN (int n)
{
  int l, c;
  grade = new int *[n];
  for (int i = 0; i < n; ++i)
    grade[i] = new int[n];

}


void
Labirinto::create (int n)
{
  int l, c, b, auxb, numerobloqueios;
  numerobloqueios = 6;		//mudar em teste
  pair <int,int> bloqueios[numerobloqueios];

  bloqueios[0] = {2,3};
  bloqueios[1] = {3,3};
  bloqueios[2] = {4,3};
  bloqueios[3] = {5,3};
  bloqueios[4] = {1,5};
  bloqueios[5] = {2,5};
  //bloqueios[6] = {,};
  //bloqueios[7] = {,};
  //bloqueios[8] = {,};
  //bloqueios[9] = {,};
  //bloqueios[10] = {,};

  for (l = 0; l < n; l++)
    {
      for (c = 0; c < n; c++)
	{
	  this->grade[l][c] = 0;
	  for (b = 0; b < numerobloqueios; b++)
	    {
	      if (l == bloqueios[b].first && c == bloqueios[b].second)
		this->grade[l][c] = 1;
	    }
	}
    }
  this->grade[0][0] = 0;
}



void
Labirinto::setGrade (int l, int c)
{

  this->grade[l][c] = -1;

}


void
Labirinto::mostra (int n)
{
  for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
	{
	  if (grade[i][j] == 1)
	    cout << "x | \t";
	  else if (grade[i][j] == -1)
	    cout << "o | \t";
	  else
	    cout << "  | \t";
	}
      cout << endl << "-----------------------------------------------" <<
	endl;
    }

}

double Labirinto::euclidiano (pair <int, int> local, int n) {
   
    
    if (local.first >= n || local.first <= -1 || local.second >=n 
    || local.second <= -1 || grade[local.first][local.second] != 0){
       return 18000.0;}
    
    else{
    return ((double)sqrt(
        (local.first - (n - 1)) * (local.first - (n - 1))
        + (local.second - (n - 1)) * (local.second - (n - 1))));}
}

double Labirinto::man (pair <int, int> local, int n) {
   
    
    if (local.first >= n || local.first <= -1 || local.second >=n 
    || local.second <= -1 || grade[local.first][local.second] != 0){
       return 18000.0;}
    
    else{
    return (fabs(local.first - (n - 1)) + fabs(local.second - (n - 1)));}
}

Ppair Labirinto::Proximo (pair < int, int >local, int n, int escolha)
{  
    double dir, esq, bai, cim;
    
    if (escolha != 2){
     dir = euclidiano ({local.first, local.second + 1}, n);
     esq = euclidiano ({local.first, local.second - 1}, n);
     bai = euclidiano ({local.first + 1, local.second}, n);
     cim = euclidiano ({local.first - 1, local.second}, n);
}
   else {
     dir = man ({local.first, local.second + 1}, n);
     esq = man ({local.first, local.second - 1}, n);
     bai = man ({local.first + 1, local.second}, n);
     cim = man ({local.first - 1, local.second}, n);
}
    if (dir <= esq && dir <= bai && dir <= cim && dir != 18000.0) {
        return {{local.first,local.second + 1}, dir};
    }

  else if (bai <= esq && bai <= dir && bai <= cim && bai != 18000.0) {
        return {{local.first + 1,local.second}, bai};
    }
  
  else if (esq <= bai && esq <= dir && esq <= cim && esq != 18000.0) {
        return {{local.first,local.second - 1}, esq};
    }
    
    else if (cim <= bai && cim <= dir && cim <= esq && cim != 18000.0) {
        return {{local.first - 1,local.second}, cim};
    }
    
  else
    {
      return{{-1,-1}, 18000.0};
    }

} 


void
Labirinto::CaminhoA (int n, int escolha)
{
  int iteracoes = 0;
  Ppair local;
  (escolha == 1)? local = {{0,0}, euclidiano({0,0}, n)} : local = {{0,0}, man({0,0}, n)};
  Ppair teste = {{-1,-1}, 18000.0};
  list<Ppair> caminho;
  caminho.push_front (local);
  this->grade[0][0] = -1;
  while (((local.first.first) != (n - 1)) || ((local.first.second) != (n - 1)))
    {
        
        if (Proximo(local.first, n, escolha) == teste)
        {
            caminho.pop_front();
            this->grade[local.first.first][local.first.second] = -1;
            local = caminho.front();
            //iteracoes++;
        }
        
        else
        {
        caminho.push_front (Proximo(local.first, n, escolha));
        this->grade[local.first.first][local.first.second] = -1;
        local = caminho.front();
        iteracoes++;
        }
        
    }
       
    cout << "===============================================\n";
    cout << "Caminho encontrado com " << iteracoes << " iteracoes.\n";
}
