#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include "sortBubble.h"
#include "sortHeap.h"
#include "sortQuick.h"
#include "sortSelection.h"

#define NSQUARED_MAX 30000
#define NLOGN_MAX 3000000

using namespace std;

void randomf(float * data, int n);
void randomi(int * data, int n);

int main()
{
	// initialize the file streams
	ofstream nsquaredinputs("nsi.txt");
	ofstream bubbletimes("bubblei.txt");
	ofstream selectiontimes("selectioni.txt");

/*
	cout << "   Inputs   |     Bubbble     |    Selection" << endl
	     << "________________________________________________" << endl;*/

	// make the buffer as long as it needs to be
	float * data = new float[NSQUARED_MAX];

	for (int i = 1000; i <= NSQUARED_MAX; i += 1000)
	{
		// output the number of inputs
		// cout << setw(11) << i << "   ";
		nsquaredinputs << i << endl;

		// read in the correct number of random numbers
		randomf(data, i);

		// time the bubble sort
		long timeBefore = clock();
		sortBubble(data, i);
		long timeAfter = clock();

		// cout << setw(15) << timeAfter - timeBefore << "   ";
		bubbletimes << timeAfter - timeBefore << endl;

		randomf(data, i);

		// time the selection sort
		timeBefore = clock();
		sortSelection(data, i);
		timeAfter = clock();

		// cout << setw(15) << timeAfter - timeBefore << endl;
		selectiontimes << timeAfter - timeBefore << endl;
	}

	nsquaredinputs.close();
	bubbletimes.close();
	selectiontimes.close();

	delete [] data;

	/* now do the same thing for the nlogn sorts */

	// initialize the file streams
	ofstream nlogninputs("lgni.txt");
	ofstream quicktimes("quicki.txt");
	ofstream heaptimes("heapi.txt");

/*
	cout << "   Inputs   |     Quick     |    Heap" << endl
	     << "___________________________________________" << endl;*/

	// make the buffer as long as it needs to be
	data = new float[NLOGN_MAX];

	for (int i = 100000; i <= NLOGN_MAX; i += 100000)
	{
		// output the number of inputs
		// cout << setw(11) << i << "   ";
		nlogninputs << i << endl;

		// read in the correct number of random numbers
		randomf(data, i);

		// time the quick bubble sort
		long timeBefore = clock();
		sortQuick(data, i);
		long timeAfter = clock();

		// cout << setw(13) << timeAfter - timeBefore << "   ";
		quicktimes << timeAfter - timeBefore << endl;

		randomf(data, i);

		// time the heap sort
		timeBefore = clock();
		sortHeap(data, i);
		timeAfter = clock();

		// cout << setw(13) << timeAfter - timeBefore << endl;
		heaptimes << timeAfter - timeBefore << endl;
	}

	delete [] data;

	nlogninputs.close();
	quicktimes.close();
	heaptimes.close();

	cout << "Done" << endl;

	return 0;
}

/*
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
} */

void randomi(int * data, int n)
{
   	srand(time(NULL));

	// output the random numbers
	for (int i = 0; i < n; i++)
    	data[i] = (rand() % 100000) + 1;
}

void randomf(float * data, int n)
{
   	srand(time(NULL));

	// output the random numbers
	for (int i = 0; i < n; i++)
    	data[i] = (rand() % 100000) + 1;
}