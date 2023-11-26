//          Wordle-C++ 
#include<bits/stdc++.h>

using namespace std;

 


int main()
{
 int i,j,ok,corect=0,s=0,castig=0;
 char cuvant_user[8],cuvant_corect[8],varianta[8];
 cin.getline(cuvant_corect,8);
int lungime_cuvant=strlen(cuvant_corect);
int incercari=lungime_cuvant+1;

while(castig==0)
{
//introducere cuvant de la user
 while(corect==0)
  {
    cout<<"Introduceti un cuvant de "<<lungime_cuvant<<" litere: ";
    cin.getline(cuvant_user,8);
    cout<<endl;
    if(lungime_cuvant!=strlen(cuvant_user))
      cout<<"Cuvantul introdus nu are lungimea corecta"<<endl;
    else
      {
        corect=1; incercari--;
      }
  }
//verific litera cu litera si formez varianta
 for(i=0;i<strlen(cuvant_user);i++)
  { ok=0;
    for(j=0;j<strlen(cuvant_corect);j++)
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
        {
        //instructiune cu verde ca e corect si pe pozitia buna+afisez litera cu verde pe ea(daca pot in c++)
        cout<<'x';
        }
      else if(varianta[i]==1)
        {
        //instructiune cu galben ca e corect dar pe pozitia gresita+afisez litera cu galben pe ea(daca pot in c++)
        cout<<'o';
        }
      else
        {
        //instructiune cu rosu ca e gresit+afisez litera cu rosu pe ea(daca pot in c++)
        cout<<'-';
        }
    
    }
    //verific daca e solutie finala
        for(i=0;i<lungime_cuvant;i++)
          {
          s+=varianta[i];
          }
          if(s==2*lungime_cuvant)
            {
            cout<<"Felicitari! Ati castigat!";
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
    
}