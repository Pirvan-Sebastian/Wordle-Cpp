#include<bits/stdc++.h>
//#include <string>
using namespace std;
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

string alegere_cuvant (int numar_random)
{ 
    ifstream fin("cuvinte.txt");
    string linie,cuvant_corect;
    int numar_lini=0;
    while(fin>>linie)
    {
        numar_lini++;
        if (numar_lini == numar_random)
        {
            cuvant_corect=linie; 
            break;
        }
    }
    return cuvant_corect;
}
void citire_cuvant(int lungime_cuvant,int &incercari,int &corect,string &cuvant_user)
{
    while(corect==0)
  {
    cout<<"Introduceti un cuvant de "<<lungime_cuvant<<" litere: ";
    cin>>cuvant_user;
    cout<<endl;
    if(lungime_cuvant!=cuvant_user.length())
      cout<<"Cuvantul introdus nu are lungimea corecta"<<endl;
    else
      {
        corect=1; 
        incercari--;
      }
  }
}

void verificare_cuvant(int lungime_cuvant,int Frecventa[],string cuvant_user,string cuvant_corect,string &varianta)
{int numar_aparitii=0,i=0,j=0,ok=0;
    for(i=0;i<lungime_cuvant;i++)
  { ok=0; numar_aparitii=0;

    for(j=0;j<lungime_cuvant;j++)
      {
       if(cuvant_user[i]==cuvant_corect[j] && i==j)
       {
        ok=2;
        numar_aparitii++;
        break;
       }
       else if(cuvant_user[i]==cuvant_corect[j] && i!=j)
         {
             ok=1;
             numar_aparitii++;
         }
         if(numar_aparitii>Frecventa[cuvant_user[i]-'a']) ok=0;
      }

      varianta[i]=ok;
  }
}
void verificare_varianta(int lungime_cuvant,string cuvant_user,string &varianta)
{int i=0;
    for(i=0;i<lungime_cuvant;i++)
    {
      if(varianta[i]==2)
       cout << GREEN <<cuvant_user[i]<< RESET;
      else if(varianta[i]==1)
         cout << YELLOW <<cuvant_user[i]<< RESET;
      else
         cout << RED <<cuvant_user[i]<< RESET;
    }
}
void verificare_castig(int castig,string cuvant_corect)
{
    if(castig==1)
      {
      cout<<"Ati pierdut! Cuvantul era: "<<cuvant_corect;
      }
    else if(castig==2)
      {
      cout<<"Felicitari! Ati castigat!";
      }
}
