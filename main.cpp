#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include "sortBubble.h"
#include "sortHeap.h"
#include "sortQuick.h"
#include "sortSelection.h"

#define NSQUARED 8
#define NLOGN 8

using namespace std;

void readInts(int * data, int n);
void readFloats(float * data, int n);

int main()
{
	// number of random numbers to use
	int nSquared[] = { 100, 1000, 10000, 20000, 30000, 100000, 150000, 200000 };
	int nLogn[]    = { 100, 1000, 10000, 100000, 500000, 1000000, 10000000, 100000000 };

	cout << "   Inputs   |     Bubbble     |    Selection" << endl
	     << "________________________________________________" << endl;

	// make the buffer as long as it needs to be
	int * data = new int[nSquared[NSQUARED - 1]];

	for (int i = 0; i < NSQUARED; i++)
	{
		// output the number of inputs
		cout << setw(11) << nSquared[i] << " | ";

		// read in the correct number of random numbers
		readInts(data, nSquared[i]);

		// time the bubble sort
		long timeBefore = clock();
		sortBubble(data, nSquared[i]);
		long timeAfter = clock();

		cout << setw(15) << timeAfter - timeBefore << " | ";

		readInts(data, nSquared[i]);

		// time the selection sort
		timeBefore = clock();
		sortSelection(data, nSquared[i]);
		timeAfter = clock();

		cout << setw(15) << timeAfter - timeBefore << endl;
	}

	delete [] data;

	/* now do the same thing for the nlogn sorts */

	cout << "   Inputs   |     Quick     |    Heap" << endl
	     << "___________________________________________" << endl;

	// make the buffer as long as it needs to be
	data = new int[nLogn[NLOGN - 1]];

	for (int i = 0; i < NLOGN; i++)
	{
		// output the number of inputs
		cout << setw(11) << nLogn[i] << " | ";

		// read in the correct number of random numbers
		readInts(data, nLogn[i]);

		// time the quick bubble sort
		long timeBefore = clock();
		sortQuick(data, nLogn[i]);
		long timeAfter = clock();

		cout << setw(13) << timeAfter - timeBefore << " | ";

		readInts(data, nSquared[i]);

		// time the heap sort
		timeBefore = clock();
		sortHeap(data, nSquared[i]);
		timeAfter = clock();

		cout << setw(13) << timeAfter - timeBefore << endl;
	}

	delete [] data;

	return 0;
}

void readInts(int * data, int n)
{
	ifstream fin("random.txt");

	if (fin.fail())
      return;
   
	for(int i = 0; i < n - 1 && !fin.fail(); ++i)
		fin >> data[i];

	// close the file
	fin.close();
	return;
}

void readFloats(float * data, int n)
{
	ifstream fin("random.txt");

	if (fin.fail())
      return;
   
	for(int i = 0; i < n - 1 && !fin.fail(); ++i)
		fin >> data[i];

	// close the file
	fin.close();
	return;
}