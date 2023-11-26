//          Wordle-C++ 
#include<bits/stdc++.h>
#include <conio.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

using namespace std;
ifstream fin("cuvinte.txt");
//declarare variabile
string linie;
int numar_random;
int numar_lini,i,j,ok,corect,s,castig;
 string cuvant_user,cuvant_corect,varianta;

int main()
{
srand(time(0));
numar_random = rand() % 10658;

while (fin>>linie)
{
    numar_lini++;
    if (numar_lini == numar_random)
    {
        cuvant_corect=linie; break;
    }
}
cout<<"Cuvantul corect este: "<<cuvant_corect<<endl;

int lungime_cuvant=cuvant_corect.length();
int incercari=lungime_cuvant+1;

while(castig==0)
{
//introducere cuvant de la user
 while(corect==0)
  {
    cout<<"Introduceti un cuvant de "<<lungime_cuvant<<" litere: ";
    cin>>cuvant_user;
    cout<<endl;
    if(lungime_cuvant!=cuvant_user.length())
      cout<<"Cuvantul introdus nu are lungimea corecta"<<endl;
    else
      {
        corect=1; incercari--;
      }
  }
//verific litera cu litera si formez varianta
 for(i=0;i<lungime_cuvant;i++)
  { ok=0;
    for(j=0;j<lungime_cuvant;j++)
      {
       if(cuvant_user[i]==cuvant_corect[j] && i==j)
       {
        ok=2;break;
       }
       else if(cuvant_user[i]==cuvant_corect[j] && i!=j)
         {
            ok=1;

         }
      }
      varianta[i]=ok;

  }
  //verificare varianta introdusa de user
  for(i=0;i<lungime_cuvant;i++)
    {
      if(varianta[i]==2)
       cout << GREEN <<cuvant_user[i]<< RESET;
      else if(varianta[i]==1)
         cout << YELLOW <<cuvant_user[i]<< RESET;
      else
         cout << RED <<cuvant_user[i]<< RESET;
    }
    //verific daca e solutie finala
        for(i=0;i<lungime_cuvant;i++)
          {
          s+=varianta[i];
          }
          if(s==2*lungime_cuvant)
            {
              cout<<endl;
            castig=2;break;
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
    if(castig==1)
      {
      cout<<"Ati pierdut! Cuvantul era: "<<cuvant_corect;
      }
    else if(castig==2)
      {
      cout<<"Felicitari! Ati castigat!";
      }

//Oprire la apasarea tastei Enter
      char ch;
      cout<<endl<<"Apasati Enter pentru a iesi din program";
     do
     {
      ch = getch();
     }while( ch != char(13) );//13 cod ASCII pt Enter

      return 0;
    
}