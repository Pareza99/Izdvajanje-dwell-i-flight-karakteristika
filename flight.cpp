#include <bits/stdc++.h>

using namespace std;

map <int, vector<vector <int> > > mat;


int main()
{

    ifstream fin ("baza.txt");
    ofstream fout ("flight_podaci.txt");

    int ime,tip,t;
    string c;

    map <int, vector<vector <int> > > ::iterator j2;
    vector <vector<int> >::iterator j3;
    vector<int>::iterator j4;



    fin >> ime;

    map<string, int> klik;
    map<string, int> klik2;

    vector <int> pomv;

    pomv.clear();

    bool indikator=false;

    while (!fin.eof())
    {
        fin >> tip;

        if (tip<0)
        {
            indikator=false;
            mat[ime].push_back(pomv);
            fin >> ime;
            pomv.clear();
            continue;
        }


        fin >> c;
        fin >> t;

        if (tip)
        {

            klik[c]=t;
            if (indikator)
            {
                 pomv.push_back(t-klik2[c]);

            }

        }

        else
        {
            if (!indikator) indikator = true;
            klik2[c] = t;


        }

    }

    mat[ime].push_back(pomv);
    for (j2=mat.begin(); j2!=mat.end(); j2++)
    {
        fout << j2->first << endl;
        for (j3=(j2->second).begin(); j3!=(j2->second).end(); j3++)
        {
            for (j4=(*j3).begin(); j4!=(*j3).end(); j4++)
                fout << *j4 << " ";
            fout << endl;
        }
    }

    return 0;
}
