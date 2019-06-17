#include <iostream>
#include <fstream>
#include <chrono> //laiko skaiciavimo biblioteka
using namespace std;
int main() 
{
int n, Mas[9999], kiekis = 0;
int variantas;

cout << "1. Mazejimo tvarka su tarpiniais rezultatais" << endl; // leidziamas pasirinkimas tarp mazejimo arba didejimo tvarkos
cout << "2. Didejimo tvarka su tarpiniais rezultatais" << endl;
cout << "3. Mazejimo tvarka be tarpiniu rezultatu" << endl; 
cout << "4. Didejimo tvarka be tarpiniu rezultatu" << endl;

cin >> variantas;

ifstream fd("U.txt");
ofstream fr("U_rez.txt");      
fd >> n;


auto laikas1 = std::chrono::steady_clock::now();

for (int i = 0; i < n; i++) // Nuskaitomas ivedimo failas
  {
     fd >> Mas[i];
  } 
//===========================================
// Shello rikiavimas mazejimo tvarka su tarpiniais rez
if(variantas == 1)
{
 for (int gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (int i = gap; i < n; i = i + 1)
        {
            int temp = Mas[i];
            int j;            
            for (j = i; j >= gap && Mas[j - gap] < temp; j = j - gap) 
            {
              Mas[j] = Mas[j - gap];
              kiekis++;
            }
            Mas[j] = temp;
            for(int c = 0; c < n; c++)
            {
              fr << Mas[c] << " ";
            }
        }
    }
}
//===============================================
//Shello rikiavimas didejimo tvarka su tarpiniais rez
if(variantas == 2)
{
 for (int gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (int i = gap; i < n; i = i + 1)
        {
            int temp = Mas[i];
            int j;            
            for (j = i; j >= gap && Mas[j - gap] > temp; j = j - gap) 
            {
              Mas[j] = Mas[j - gap];
              kiekis++;
            }
            Mas[j] = temp;
            for(int c = 0; c < n; c++)
            {
              fr << Mas[c] << " ";
            }
        }
    }
}
//===========================================
//Shello rikiavimas mazejimo tvarka be tarpiniu rez
if(variantas == 3)
{
 for (int gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (int i = gap; i < n; i = i + 1)
        {
            int temp = Mas[i];
            int j;            
            for (j = i; j >= gap && Mas[j - gap] < temp; j = j - gap) 
            {
              Mas[j] = Mas[j - gap];
              kiekis++;
            }
            Mas[j] = temp;

        }
    }
}
//===============================================
//Shello rikiavimas didejimo tvarka be tarpiniu rez
if(variantas == 4)
{
 for (int gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (int i = gap; i < n; i = i + 1)
        {
            int temp = Mas[i];
            int j;            
            for (j = i; j >= gap && Mas[j - gap] > temp; j = j - gap) 
            {
              Mas[j] = Mas[j - gap];
              kiekis++;
            }
            Mas[j] = temp;
        }
    }
}
//===========================================
fr << endl;
fr << "Isrikiuotas masyvas: ";
for (int i = 0; i < n; i++) //Irasomas surikiuotos reiksmes i isvedimo faila
  {
     fr << Mas[i] << " ";
  } 

auto laikas2 = std::chrono::steady_clock::now();
double laikas3 = double(std::chrono::duration_cast<std::chrono::microseconds>(laikas2 - laikas1).count());

fr << endl << "Sukeista buvo: " << kiekis << " kartus " << endl;
fr << "Kiek laiko uztruko sia uzduoti padarysi mircosekundemis : " << laikas3;
fd.close();
fr.close();
return 0;
}
