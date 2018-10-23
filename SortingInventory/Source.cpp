/*************** PROGRAM IDENTIFICATION*****************************
//*																	*
//* PROGRAM FILE NAME: Source.cpp Assisgnment #:5 Grade:_______		*
//*																    *
//* PROGRAM AUTHOR	______________________							*
//*					Rishika Swarnkar								*
//*																	*
//*COURSE: CSC 36000 1							 DATE:April 16,2018 *
//*																	*
/********************************************************************/
//*************** PROGRAM DESCRIPTION ********************************
//*																     *
//* PROCESS:This program is desgined to read Data from an input file *
//* and sort the Inventory based on various data field of the        *
//* Inventory. It also displays the Inventory after each sort.       *
//*																	 *
//*																     *
//* USER DEFINED													 *
//* MODULES : getInventory - Reads the inventory from input file and *
//* creates an array *
//* printInventory - Prints the Inventory *
//* shellSortSellingPrice - Shell Sort using Selling Price *
//* pageBreak -Insert Lines to Break the page *
//* partition- Sets the pivot Value *
//* quicksort- Quick Sort the item array based on Inventory *
//* Number *
//* ExchangeSort- Exchange sort Inventory based on Quantity *
//* resetLinecounter - sets line counter to 0 *
//* Header – Prints output Preamble *
//* Footer – Prints output Footer *
//*********************************************************************
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include"dataClass.h"
using namespace std;
struct item
{
	//Input
	int invenNumber;
	string itemDiscription;
	int quantity;
	int recNum;
	float cost, sp;
};
int getInventory(item Inventory[])
	
{
	//Receives - Array of item
	//Task - Read data from Input file and save it in Array Item
	//Returns - Number of elements in the array
	ifstream infile;
	item getItem;
	int numOfItem = 0;
	infile.open("data5.txt");
	do {
		infile >> getItem.invenNumber;
		infile >> ws;
		getline(infile, getItem.itemDiscription);
		infile >> getItem.quantity;
		infile >> getItem.recNum;
		infile >> getItem.cost;
		infile >> getItem.sp;
		Inventory[numOfItem] = getItem;
		numOfItem++;
		cout << getItem.invenNumber << endl;
	} while (getItem.invenNumber > 0);
	cout << "done taking input" << endl;
	infile.close();
	return numOfItem;
}
/************************************/
void printInventory(ofstream &fout, int numOfRec, item Inventory[])
{
	//Receives - An Output File, Array of item , Number of elements in array
	//Task - Prints the Inventory
	//Returns - Nothing
	item itemInsatnce;
	fout << left;
	fout << setw(10) << "Inventory" << setw(25) << "Item " << setw(10) <<
		"Quantity" << setw(10);
	fout << "Reorder" << setw(10) << "Cost of" << setw(10) << "Selling";
	fout << endl;
	fout << setw(10) << "Number" << setw(25) << "Description" << setw(10) <<
		"on hand" << setw(10);
	fout << "Number" << setw(10) << "Item" << setw(10) << "Price" << endl;
	fout << setw(10) << "-------" << setw(25) << "--------------------" <<
		setw(10) << "-------" << setw(10);
	fout << "-------" << setw(10) << "-------" << setw(10) << "-------" <<
		endl;
	for (int i = 0; i < numOfRec; i++)
	{
		fout << setw(10) << Inventory[i].invenNumber << setw(15) << Inventory
			[i].itemDiscription << setw(10) << Inventory[i].quantity;
		fout << setw(10) << Inventory[i].recNum << setw(10) << Inventory
			[i].cost << setw(10) << Inventory[i].sp;
		fout << endl;
	}
	cout << "done printing" << endl;
}
/*************************************/
void shellSortSellingPrice(item Inventory[], int numOfRec)
{
	//Receives - Array of item , Number of elements in array
	//Task - Shell Sort using Selling Price
	//Returns - Nothing
	/* function to sort array using shellSort */
	// Start with a big gap, then reduce the gap
	for (int gap = numOfRec / 2; gap > 0; gap /= 2)
	{
		// Do a gapped insertion sort for this gap size.
		// The first gap elements a[0..gap-1] are already in gapped order
		// keep adding one more element until the entire array is
		// gap sorted
		for (int i = gap; i < numOfRec; i += 1)
		{
			// add a[i] to the elements that have been gap sorted
			// save a[i] in temp and make a hole at position i
			//float temp = Inventory[i].sp;
			item temp = Inventory[i];
			// shift earlier gap-sorted elements up until the correct
			// location for a[i] is found
			int j;
			for (j = i; j >= gap && Inventory[j - gap].sp < temp.sp; j -=
				gap)
			{
				Inventory[j] = Inventory[j - gap];
			}
			// put temp (the original a[i]) in its correct location
			Inventory[j] = temp;
		}
	}
	return;
}
/*************************************/
void pageBreak(ofstream &fout, int printedLine)
{
	//Receives - Output file and number of lines already printed
	//Task - Insert Lines to Break the page
	//Returns - Nothing
	for (int i = 0; i < 50 - printedLine; i++)
	{
		fout << endl;	
	}
	return;
}
/*************************************/
int partition(item inven[], int low, int high)
{
	//Receives - array of item Inventory, Lowest Index of array , Highest Index of Array
		//Task - Sets the pivot Value
		//Returns - The position of the pivot
		// pivot (Element to be placed at right position)
		int pivot = inven[high].invenNumber;
	int i = (low - 1); // Index of smaller element
	item temp1;
	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (inven[j].invenNumber <= pivot)
		{
			i++; // increment index of smaller element
				 //swap inven[i] and inven[j];
			temp1 = inven[i];
			inven[i] = inven[j];//swap inven[i] and inven[j];
			inven[j] = temp1;
		}
	}
	//swap inven[i + 1] and inven[high]);
	temp1 = inven[i + 1];
	inven[i + 1] = inven[high];//swap inven[i] and inven[j];
	inven[high] = temp1;
	return (i + 1);
}
/*********************************/
void quicksort(item inven[], int low, int high)
{
	//Receives - Array of item Inventory, Lowest Index of array , Highest Index of Arrayf
		//Task - Quick Sort the item array based on Inventory Number
		//Returns - Nothing
		if (low < high)
		{
			/* pi is partitioning index, inven[p] is now
			at right place */
			int pi = 0;
			pi = partition(inven, low, high);
			quicksort(inven, low, pi - 1); // Before pi
			quicksort(inven, pi + 1, high); // After pi
		}


}
/************************************/
void ExchangeSort(item Inventory[], int numOfItems)
{
	//Receives - An Array of item and number of Item in that Array
	//Task - Exchange sort Inventory based on Quantity
	//Returns - Nothing
	int i, j;
	item temp; // holding variable
	for (i = 0; i < numOfItems; i++) // element to be compared
	{
		for (j = (i + 1); j < numOfItems; j++) // rest of the elements
		{
			if (Inventory[i].quantity < Inventory[j].quantity)

				// descending order

			{
				temp = Inventory[i]; // swap
				Inventory[i] = Inventory[j];
				Inventory[j] = temp;
			}
		}
	}
	return;
}/************************************/
void Header(ofstream& fout)
{
	//Receives - the outfile file
	//Task - Prints the output preamble
	//Returns - Nothing
	fout << setw(30) << "Rishika Swarnkar";
	fout << setw(17) << "CSC 36000";
	fout << setw(15) << "Section 11" << endl;
	fout << setw(30) << "Spring 2018";
	fout << setw(17) << "Assignment #5" << endl;
	fout << setw(35) << "--------------------------------------";
	fout << setw(35) << "-------------------------------------- " << endl <<
		endl;
	return;
}
/************ END OF FUNCTION HEADER *****************/
//***************************************************
/************* FUNCTION FOOTER **********************/
void Footer(ofstream& fout)
{
	//Receives - the outfile file
	//Task - Prints the output preamble
	//Returns - Nothing
	fout << endl;
	fout << setw(35) << "------------------------------" << endl;


	fout << setw(35) << "| END OF PROGRAM OUTPUT |" << endl;
  fout << setw(35) << "-------------------------------" << endl;
  return;
}
/******* END OF FUNCTION FOOTER************/
void resetLinecounter(int lineCount)
{
	//Receives - Nothing
	//Task - Reset the line counter to Zero
	//Returns - Nothing
	lineCount = 0;
}
/************************************/
int main()
{
	int lineCount = 0;
	int const maxItems = 50;// Constant Maximum Number Of array element
	int numOfItems;// Number of elements from our Input file
	item myInventory[maxItems];// item Array
							   // Saving the Inventory in an array
	numOfItems = getInventory(myInventory);
	ofstream fout;
	fout.open("sortedInventory.txt");
	Header(fout);
	lineCount += 4;
	fout << "The Original Inventory Array:" << endl;
	lineCount = lineCount + 5;//Incrementing the Line counter
	lineCount = lineCount + numOfItems;
	printInventory(fout, numOfItems, myInventory);
	pageBreak(fout, lineCount);
	resetLinecounter(lineCount);
	//Excahnge Sort Quantity
	ExchangeSort(myInventory, numOfItems);
	fout << "The Inventory Array sorted in descending order according to the " << endl;
		fout << "Quantity on Hand using the Exchange Sort : ";
	fout << endl;
	lineCount = +2;
	printInventory(fout, numOfItems, myInventory); //Print sorted Quantity
	lineCount += numOfItems;
	pageBreak(fout, lineCount);
	resetLinecounter(lineCount);
	// Shell Sort using Selling Price
	shellSortSellingPrice(myInventory, numOfItems);
	fout << "The Inventory Array sorted in descending order according to the Selling Price" << endl;
		fout << "using the Shell Sort :" << endl;
	lineCount = +2;
	printInventory(fout, numOfItems, myInventory);


	lineCount += numOfItems;
  pageBreak(fout, lineCount);
  //Quick Sort Inventory Number
  int low = 0;
  int high = numOfItems - 1;
  quicksort(myInventory, low, high);
  fout << "The Inventory Array sorted in ascending order according to the Inventory" << endl;
	  fout << "Number using the Quick Sort :" << endl;
  lineCount = +2;
  printInventory(fout, numOfItems, myInventory);
  Footer(fout);//Program Footer
  lineCount += 4;
  lineCount += numOfItems;
  pageBreak(fout, lineCount);
  fout.close();//Close output file
  system("pause");
  return 0;
}