#include <bits/stdc++.h>

using namespace std;

map <int, vector<vector <int> > > mat;
// mapa gde se za svakog coveka cuva po jedan vektor, a svaki taj vektor cuva podatke o svakom tasteru koji je kliknut tokom unosa teksta
//na pocetku je prazna jer je globalna promenljiva, moze da se napise u main-u i doda mat.clear() kao za pomv

int main()
{

    ifstream fin ("baza.txt"); //ulazna datoteka
    ofstream fout ("dwell_podaci.txt"); //izlazna datoteka

    int ime,tip,t; //ime trenutnog korisnika koji kuca, up/down, vreme klika
    string c; //koji je taster kliknuo

    map <int, vector<vector <int> > > ::iterator j2;
    vector <vector<int> >::iterator j3;
    vector<int>::iterator j4;

    //fin >> c; //da zakacimo -1 na pocetku

    fin >> ime; //ime prvog korisnika

    map<string, int> klik; //za svaki taster se cuva poslednji trenutak kad je kliknut, tj down

    vector <int> pomv; //vektor vremena za trenutni tekst koji se posle dodaje u vektor korisnika koji ga je otkucao

    pomv.clear(); //na pocetku je prazan

    while (!fin.eof()) //unosi se do kraja fajla
    {
        fin >> tip; //0, 1 ili -1

        if (tip<0) //ako je -1
        {
            mat[ime].push_back(pomv); //dodaje se trenutni vektor vremena u vektor trenutnog korisnika
            fin >> ime; //unosi se novi korisnik
            pomv.clear(); //pomocni vektor za vremena je sada prazan
            continue; //krecemo unos ispocetka za novog korisnika
        }

        fin >> c; //unosi se taster koji je kliknut
        fin >> t; //vreme kad je kliknut


        if (tip)
            klik[c]=t; //ako je down onda belezimo taj trenutak
        else
            pomv.push_back(t-klik[c]); //ako je up dodajemo razliku izmedju ovog trenutka (kad je pusten) i onog kad je kliknut


    }

    mat[ime].push_back(pomv); //dodajemo poslednji unet vektor jer nismo uneli novog korisnika (ovo bi se moglo izbeci dodavanjem -1 na kraju datoteke, ali nema potrebe)

    for (j2=mat.begin(); j2!=mat.end(); j2++) //idemo redom po korisnicima
    {
        fout << j2->first << endl; //ispisemo tog korisnika
        for (j3=(j2->second).begin(); j3!=(j2->second).end(); j3++) //idemo po svim njegovim kucanjima
        {
            for (j4=(*j3).begin(); j4!=(*j3).end(); j4++) //idemo po svim njegovim tasterima u datom kucanju
                fout << *j4 << " "; //ispisemo vreme zadrzavanja na svakom tasteru
            fout << endl; //ispisujemo novi red radi matricnog oblika
        }
    }

    return 0;
}
