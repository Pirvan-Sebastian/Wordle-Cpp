//          Wordle-C++ 
#include<bits/stdc++.h>
#include <conio.h>
#include "functii.h"



using namespace std;

//declarare variabile
string linie;
int numar_aparitii,numar_random,Frecventa[27];
int numar_lini,i,j,ok,corect,s,castig;
string cuvant_user,cuvant_corect,varianta;


int main()
{

srand(time(0));
numar_random = rand() % 10658;

cuvant_corect=alegere_cuvant(numar_random);

cout<<"             WORDLE             "<<endl;
cout<<endl;
int lungime_cuvant=cuvant_corect.length();
cout<<cuvant_corect<<endl;
//Vector frecventa
for(i=0;i<lungime_cuvant;i++) Frecventa[cuvant_corect[i]-'a']++;

int incercari=lungime_cuvant+1;

while(castig==0)
{
citire_cuvant(lungime_cuvant,incercari,corect,cuvant_user);
verificare_cuvant(lungime_cuvant,Frecventa,cuvant_user,cuvant_corect,varianta);
verificare_varianta(lungime_cuvant,cuvant_user,varianta);
    //verific daca e solutie finala
  for(i=0;i<lungime_cuvant;i++) s+=varianta[i];
        if(s==2*lungime_cuvant)
           {
             cout<<endl;
             castig=2;
             break;
           }
        else
           {
              cout<<endl;
              cout<<"Mai aveti "<<incercari<<" incercari"<<endl;
            }
        if(incercari==0)
          {
          castig=1;break;
          }

    //resetez variabilele
      corect=0;s=0;
    }
verificare_castig(castig,cuvant_corect);
//Oprire la apasarea tastei Enter
      char ch;
      cout<<endl<<"Apasati Enter pentru a iesi din program";
    do
     {
      ch = getch();
     }while( ch != char(13) );//13 cod ASCII pt Enter


  return 0;
}