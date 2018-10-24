# Sorting
https://github.com/rishikaswarnkar/SortingInventory

PROCESS:This program is desgined to read Data from an input file.
The input file has the inventory number, Item discription,Quantity on hand, Recorder Number, Cost of Item and Selling Price.
The program uses an array of structures,Inventory[],store structure called "item". Item stored all the information related to
"Item" of Inventory.It perform various sorts ascendong/decending based on one of the attributes of "item" 
The inventory array is sorted in decending irder according to the Quantity on Hand using Exachange Sort.
The inventory Array sorted in decending order according to the Selling Price using Shell Sort. 
The inventory Array sorted in ascending order according to the Inventory Number using Quick Sort

OUTPUT: The program prints the original inventory. All Outputs appear on seperate page. 
After every sort, i.e. Exchange sort on Quantity on Hand, Shell Sort on Selling
price, Quick Sort on Inventory Number, the program prints the Inventory along with the
headers.

USER DEFINED MODULES : 

getInventory(item []) - Reads the inventory from input file and creates an array 
printInventory(ofstream &,int,item []) - Prints the Inventory
shellSortSellingPrice(item [],int) - Shell Sort using Selling Price 
pageBreak(oftsream &,int) -Insert Lines to Break the page
partition(item [],int,int)- Sets the pivot Value 
quicksort(item [],int,int)- Quick Sort the item array based on Inventory Number 
ExchangeSort(item [],int)- Exchange sort Inventory based on Quantity 
resetLinecounter - sets line counter to 0 
Header(ofstream &) – Prints output Preamble 
Footer(ofstream &) – Prints output Footer 
