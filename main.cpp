#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include <fstream>
#define dim 2
#define m  4
#define n 4000

using namespace std;

int main()
{
	ifstream fin("dwell_ref.txt");
	ofstream fout("podaci.txt");
	
	double sumx[dim];
	double x[4000][dim];
	double centx[4000][dim];
	int  klasa[4000];
	



	//cin >> n;
	
	int min = 150000;
	int max = -10000;
	for (int i = 0; i < n; i++)
	{
		//fin >> x[i][0];
		for (int j = 0; j < dim; j++)
		{
 			fin >> x[i][j];
			if (x[i][j] > max)
			{
				max = x[i][j];
			}
			if (min > x[i][j])
			{
				min = x[i][j];
			}
		}
	}
//djesba: string uros = "eo malo";
	//cout << "cao";
	for (int i = 0; i < m; i++)

	{
		for (int j = 0; j < dim; j++)
		{
			centx[i][j] = (rand() % (max - min)) + min;

			//cout << centx[i][j];
		}
	}


	for (int k = 0; k < 100; k++)
	{	
	//	cout << k;
		//cout << "\n";


		for (int i = 0; i < n; i++)
		{


			double rastmin = 1000000;

			for (int j = 0; j < m; j++)
			{
				double rast = 0;
				for (int p = 0; p < dim; p++)
				{
					rast += (x[i][p] - centx[j][p])*(x[i][p] - centx[j][p]);
					 //rast += (x[j][i] - centx[j][i])*(x[j][i] - centx[i][j]) + (x[i][j] - centy[i][j])*(x[i][j] - centy[i][j]);
					 
				}
				rast = sqrt(rast);

				if (rastmin > rast)
				{
					rastmin = rast;
					klasa[i] = j;
					
				}
			}

		}

		for ( int i = 0; i < m; i++)
		{

			int num = 0;
			for (int s = 0; s < dim; s++)
			{
				sumx[s] = 0;
			}

			for (int j = 0; j < n; j++)
			{ 
		
				for (int k = 0; k < dim; k++)
				{

					if (klasa[j] == i)
					{
						sumx[k] += x[j][k];
						num++;
					}
				}
			}

			if (num != 0)
			{
				for (int v = 0; v < dim; v++)
				{
					centx[i][v] = (sumx[v] / num)*dim;
				}
			}
			else
			{
				for (int v = 0; v < dim; v++)
				{
					centx[i][v] = -20;
				}
				
			}


		}

	}
	for (int i = 0; i < n; i++)
	{
		
		fout << klasa[i] << endl;
		
		
	}
	fout << "\n";
	for (int p = 0; p < m; p++)
	{
		for (int k = 0; k < dim; k++)
		{
			fout << centx[p][k] << " ";
		}
		fout << "\n";
	}
	//cout << min << " " << max;
	system("PAUSE");
	
	
	return 0;

}
