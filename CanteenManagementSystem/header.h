#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;


class productInfo
{
	string itemName, itemID, itemQua;
	
public:
	vector<string>productName{"biscuit", "nazo", "cola", "cracker"};
	vector<string>productID{ "123","124","125","126" };
	vector<string>productQua{ "15","5","54","26" };

	productInfo() {
		itemName = this->itemName;
		itemID = this->itemID;
		itemQua = this->itemQua;
	}

	void allItems();
	void addItem();
	void findItembyName();
	void findItembyID();
	void deleteItem();
	void editItem();

};


void productInfo::allItems() {
	cout << "\n\n\n" <<"--------------------------------------------------------------" << endl;
	cout << "Name" << "\t\t" << "ID" << "\t\t" << "Quantity" << endl << endl;

	for (int i = 0; i < productName.size() ; i++)
	{
		cout << productName[i];
		cout << "\t\t" << productID[i];
		cout << "\t\t" << productQua[i];
		cout << endl;	
		cout << endl;
	}
	cout << "--------------------------------------------------------------" << endl;
}


void productInfo::addItem() {	

cursor:

	cout << "\n\n" << "Enter Item's Name: ";
	cin >> itemName;

	for (int i = 0; i < productName.size() ; i++)
	{
		if (productName[i] == itemName) {
			cout << "\n\n" << "They have already added." << endl;
			goto cursor;
		}
	}
	
	cout << "\n" << "Enter Item's ID: ";
	cin >> itemID;

	cout << "\n" << "Enter Item's Quantity: ";
	cin >> itemQua;

	productName.push_back(itemName);
	productID.push_back(itemID);
	productQua.push_back(itemQua);
	
	cout << "\n\n" << "\t\t" <<"Successfully Added." << "\n" << endl;
		
}

void productInfo::findItembyName() {
	string item;
	int counter = 0;

	cout << "\n\n" << "Enter You Want Search Item's Name: ";
	cin >> item;

	for (int i = 0; i < productName.size(); i++)
	{
		if (productName[i] == item)
		{
			cout << "\n\n\t\t    ---- Results ----";
			cout << "\n\n\n" << "--------------------------------------------------------------" << endl;
			cout << "Name" << "\t\t" << "ID" << "\t\t" << "Quantity" << endl << endl;
			cout << productName[i];
			cout << "\t\t" << productID[i];
			cout << "\t\t" << productQua[i];
			cout << endl;
			cout << endl;
			cout << "--------------------------------------------------------------" << endl << endl << endl;
			counter += 1;
		}
	}
	if (counter == 0)
	{
		cout << "\n\t\t)-: Item Not Found :-(" << endl;
	}
}

void productInfo::findItembyID() {	
	string id;
	int counter = 0;
	
	cout << "\n\n" <<"Enter You Want Search Item's ID: ";
	cin >> id;

	for (int i = 0; i < productID.size(); i++)
	{
		if (productID[i] == id)
		{
			cout << "\n\n\n" << "--------------------------------------------------------------" << endl;
			cout << "Name" << "\t\t" << "ID" << "\t\t" << "Quantity" << endl << endl;
			cout << productName[i];
			cout << "\t\t" << productID[i];
			cout << "\t\t" << productQua[i];
			cout << endl;
			cout << endl;
			cout << "--------------------------------------------------------------" << endl;
			counter += 1;
		}
	}
	
	if (counter == 0)
	{
		cout << "\n\t\t)-: Item Not Found :-(" << endl;
	}
}


void productInfo::deleteItem() {
	
	string id;
	int counter = 0;

	cout << "\n\n" << "Enter You Want Remove Item's Name: ";
	cin >> id;

	for (int i = 0; i < productName.size() ; i++)
	{
		if (productName[i] == id)
		{
			productName.erase(productName.begin() + i);
			productID.erase(productID.begin() + i);
			productQua.erase(productQua.begin() + i);
			counter += 1;
			cout << "\n\n" << "\t\t" << "Successfully Removed." << "\n" << endl;
		}	

	}
	if (counter == 0)
	{
		cout << "\n\n\n" << "\n\t\t)-: Item Not Found :-(" << endl;
	}
}

void productInfo::editItem() {

	string name;
	int counter = 0;

	cout << "\n\n" << "Enter You Want Edit Item's Name: ";
	cin >> name;

	for (int i = 0; i < productName.size() ; i++)
	{
		if (productName[i] == name) 
		{
							 //
			cout << "\nEnter New Name: ";
			cin >> itemName;
			cout << "\nEnter New ID: ";
			cin >> itemID;
			cout << "\nEnter New Quantity: ";
			cin >> itemQua;

			productName[i] = itemName;
			productID[i] = itemID;
			productQua[i] = itemQua;

			cout << "\n\n\t\tSuccessfully Changed." << endl;
		}
	}


}
