// ConsoleApplication33.cpp : 
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#include <list>
#include <vector>
#include <iterator>
class Sudoku {
	const int Colors[9] = { 1,2,3,4,5,6,7,8,9 };
	list<int> *adj;


public:
	int ColSud[81];
	Sudoku(int V);
	void addEdge(int x, int y);
	void ShowList();
	void ColorSud();
	bool possible(int v, int c);
	~Sudoku() { delete[] adj; }

};
Sudoku::Sudoku(int V)
{
	adj = new list<int>[V];
}
void Sudoku::addEdge(int x, int y)
{
	if (find(adj[x].begin(), adj[x].end(), y) == adj[x].end())
		adj[x].push_back(y);
	if (find(adj[y].begin(), adj[y].end(), x) == adj[y].end())
		adj[y].push_back(x);
}
bool Sudoku::possible(int v, int c)
{
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		if (ColSud[*i] == c)
			return false;
	}
	return true;
}
void Sudoku::ColorSud()
{
	for (int u = 0; u < 81; u++)
	{
		if (ColSud[u] == 0) {
			int c;
			for (c = 0;c < 9; c++)
			{
				if (possible(u, Colors[c]))
				{
					ColSud[u] = Colors[c];
				}


			}
		}

	}
	cout << "_______________________________________________" << endl<< endl;
	for (int u = 0; u < 81; u++) {
		cout <<"||"<<" " <<ColSud[u] << " " ;
		if (u == 8 || u == 17 || u == 26 || u == 35 || u == 44 || u == 53 || u == 62 || u == 71 || u == 80)
		{
			cout <<"||" << endl;
			cout << "_______________________________________________" << endl << endl;


		}
	}

}
void Sudoku::ShowList()
{
	for (int v = 0; v < 81; ++v)
	{
		cout << "\n Vertex "
			<< v ;
		for (auto x : adj[v])
			cout << "-> " << x;

		printf("\n");
	}
}

int main()
{
	/*
	__________________________________________________
	|| 0  | 1  | 2  || 3  | 4  | 5  || 6  | 7  |  8 ||
	|| 9  | 10 | 11 || 12 | 13 | 14 || 15 | 16 | 17 ||
	|| 18 | 19 | 20 || 21 | 22 | 23 || 24 | 25 | 26 ||
	__________________________________________________
	|| 27 | 28 | 29 || 30 | 31 | 32 || 33 | 34 | 35 ||
	|| 36 | 37 | 38 || 39 | 40 | 41 || 42 | 43 | 44 ||
	|| 45 | 46 | 47 || 48 | 49 | 50 || 51 | 52 | 53 ||
	__________________________________________________
	|| 54 | 55 | 56 || 57 | 58 | 59 || 60 | 61 | 62 ||
	|| 63 | 64 | 65 || 66 | 67 | 68 || 69 | 70 | 71 ||
	|| 72 | 73 | 74 || 75 | 76 | 77 || 78 | 79 | 80 ||
	__________________________________________________


		*/



	Sudoku S(81);




	vector<int> r1, r2, r3, r4, r5, r6, r7, r8, r9;
	vector<int> c1, c2, c3, c4, c5, c6, c7, c8, c9;
	vector<int> sg1, sg2, sg3, sg4, sg5, sg6, sg7, sg8, sg9;


	for (int i = 0; i < 9;i++)
	{
		r1.push_back(i);
		r2.push_back(i + 9);
		r3.push_back(i + 18);
		r4.push_back(i + 27);
		r5.push_back(i + 36);
		r6.push_back(i + 45);
		r7.push_back(i + 54);
		r8.push_back(i + 63);
		r9.push_back(i + 72);
	}

	for (int i = 0;i < 9; i++)
	{
		c1.push_back(i * 9);
		c2.push_back(i * 9 + 1);
		c3.push_back(i * 9 + 2);
		c4.push_back(i * 9 + 3);
		c5.push_back(i * 9 + 4);
		c6.push_back(i * 9 + 5);
		c7.push_back(i * 9 + 6);
		c8.push_back(i * 9 + 7);
		c9.push_back(i * 9 + 8);
	}

	sg1.push_back(0);
	sg1.push_back(1);
	sg1.push_back(2);
	sg1.push_back(9);
	sg1.push_back(10);
	sg1.push_back(11);
	sg1.push_back(18);
	sg1.push_back(19);
	sg1.push_back(20);

	for (int i = 0;i < 9;i++)
	{
		sg2.push_back(sg1[i] + 3);
		sg3.push_back(sg1[i] + 6);
		sg4.push_back(sg1[i] + 27);
		sg5.push_back(sg1[i] + 30);
		sg6.push_back(sg1[i] + 33);
		sg7.push_back(sg1[i] + 54);
		sg8.push_back(sg1[i] + 57);
		sg9.push_back(sg1[i] + 60);

	}


	for (int x = 0; x < 81; x++)
	{
		for (int y = x + 1; y < 81; y++)
		{
			if ((find(r1.begin(), r1.end(), x) != r1.end() && find(r1.begin(), r1.end(), y) != r1.end()) || (find(r2.begin(), r2.end(), x) != r2.end() && find(r2.begin(), r2.end(), y) != r2.end()) || (find(r3.begin(), r3.end(), x) != r3.end() && find(r3.begin(), r3.end(), y) != r3.end()) || (find(r4.begin(), r4.end(), x) != r4.end() && find(r4.begin(), r4.end(), y) != r4.end()) || (find(r5.begin(), r5.end(), x) != r5.end() && find(r5.begin(), r5.end(), y) != r5.end()) || (find(r6.begin(), r6.end(), x) != r6.end() && find(r6.begin(), r6.end(), y) != r6.end()) || (find(r7.begin(), r7.end(), x) != r7.end() && find(r7.begin(), r7.end(), y) != r7.end()) || (find(r8.begin(), r8.end(), x) != r8.end() && find(r8.begin(), r8.end(), y) != r8.end()) || (find(r9.begin(), r9.end(), x) != r9.end() && find(r9.begin(), r9.end(), y) != r9.end()))
				S.addEdge(x, y);
			if ((find(c1.begin(), c1.end(), x) != c1.end() && find(c1.begin(), c1.end(), y) != c1.end()) || (find(c2.begin(), c2.end(), x) != c2.end() && find(c2.begin(), c2.end(), y) != c2.end()) || (find(c3.begin(), c3.end(), x) != c3.end() && find(c3.begin(), c3.end(), y) != c3.end()) || (find(c4.begin(), c4.end(), x) != c4.end() && find(c4.begin(), c4.end(), y) != c4.end()) || (find(c5.begin(), c5.end(), x) != c5.end() && find(c5.begin(), c5.end(), y) != c5.end()) || (find(c6.begin(), c6.end(), x) != c6.end() && find(c6.begin(), c6.end(), y) != c6.end()) || (find(c7.begin(), c7.end(), x) != c7.end() && find(c7.begin(), c7.end(), y) != c7.end()) || (find(c8.begin(), c8.end(), x) != c8.end() && find(c8.begin(), c8.end(), y) != c8.end()) || (find(c9.begin(), c9.end(), x) != c9.end() && find(c9.begin(), c9.end(), y) != c9.end()))
				S.addEdge(x, y);
			if ((find(sg1.begin(), sg1.end(), x) != sg1.end() && find(sg1.begin(), sg1.end(), y) != sg1.end()) || (find(sg2.begin(), sg2.end(), x) != sg2.end() && find(sg2.begin(), sg2.end(), y) != sg2.end()) || (find(sg3.begin(), sg3.end(), x) != sg3.end() && find(sg3.begin(), sg3.end(), y) != sg3.end()) || (find(sg4.begin(), sg4.end(), x) != sg4.end() && find(sg4.begin(), sg4.end(), y) != sg4.end()) || (find(sg5.begin(), sg5.end(), x) != sg5.end() && find(sg5.begin(), sg5.end(), y) != sg5.end()) || (find(sg6.begin(), sg6.end(), x) != sg6.end() && find(sg6.begin(), sg6.end(), y) != sg6.end()) || (find(sg7.begin(), sg7.end(), x) != sg7.end() && find(sg7.begin(), sg7.end(), y) != sg7.end()) || (find(sg8.begin(), sg8.end(), x) != sg8.end() && find(sg8.begin(), sg8.end(), y) != sg8.end()) || (find(sg9.begin(), sg9.end(), x) != sg9.end() && find(sg9.begin(), sg9.end(), y) != sg9.end()))
				S.addEdge(x, y);
		}
	}


	cout << "Please enter your Sudoku grid row by row :" << endl;
	for (int i = 0;i <81;i++)
		cin >> S.ColSud[i];
	cout << "solving......" << endl <<endl;

	//S.ShowList();
	cout << "The Sulotion for your Sudoku grid is :" << endl << endl;
	S.ColorSud();
	int x;
	cin >> x;
	return 0;
}

