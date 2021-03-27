#include "header.h"
#include <stdlib.h>
int main() {
	
	productInfo main;
	int secim;
	
	cout << "\t*****************************************************************************************\n\n" << endl;
	cout << "\t\t\t\t\tCANTEEN MANAGEMENT SYSTEM\n\n" << endl;
	cout << "\t\t\t1. Add New Item" << endl << "\t\t\t" << "2. Edit Item" << endl << "\t\t\t" << "3. Delete Item" << endl << "\t\t\t" << "4. Search Item by Name" << endl << "\t\t\t" << "5. Search Item by ID" << endl << "\t\t\t" << "6. All Items" << endl << "\t\t\t" << "7. Exit" << endl << endl;
	cout << "\n\t*****************************************************************************************\n\n" << endl;
	
	while (1)
	{
		cout << "\n\n" <<"Please select an option: ";
		cin >> secim;
		system("cls");
		
		cout << "\t*****************************************************************************************\n\n" << endl;
		cout << "\t\t\t\t\tCANTEEN MANAGEMENT SYSTEM\n\n" << endl;
		cout << "\t\t\t1. Add New Item" << endl << "\t\t\t" << "2. Edit Item" << endl << "\t\t\t" << "3. Delete Item" << endl << "\t\t\t" << "4. Search Item by Name" << endl << "\t\t\t" << "5. Search Item by ID" << endl << "\t\t\t" << "6. All Items" << endl << "\t\t\t" << "7. Exit" << endl << endl;
		cout << "\n\t*****************************************************************************************\n\n" << endl;
		
		
		switch (secim)
		{
		case 1:
			main.addItem();
			continue;
		case 2:
			main.editItem();
			continue;
		case 3:
			main.deleteItem();
			continue;
		case 4:
			main.findItembyName();
			continue;
		case 5:
			main.findItembyID();
			continue;
		case 6:
			main.allItems();
			continue;
		case 7:
			break;
		default:
			cout << "\n" << "Incorrect Entry Please Try Again" << endl;
			continue;
		}
		break;
	}


	return 0;
}