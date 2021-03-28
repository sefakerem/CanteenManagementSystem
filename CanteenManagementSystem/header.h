#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <fstream>

using namespace std;


class productInfo
{
	string itemName, itemID, itemQua;
	
public:
	vector<string>productName;
	vector<string>productID;
	vector<string>productQua;

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
	
	productName.clear();
	productID.clear();
	productQua.clear();
	
	string textData;
	vector<string>temporary;
	
	fstream file1; 
	file1.open("data.txt");

	while (getline(file1,textData,' '))
	{
		temporary.push_back(textData);
	}

	for (int i = 0; i < temporary.size(); i++)
	{
		productName.push_back(temporary[i]);
		i += 1;

		productID.push_back(temporary[i]);
		i += 1;

		productQua.push_back(temporary[i]);
	}
	
	file1.close();
		
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
	
	productName.clear();
	productID.clear();
	productQua.clear();
}


void productInfo::addItem() {	

	while (1)
	{
		cursor:
		char question;
		string textData;
		vector<string>temporary;

		fstream file1;
		file1.open("data.txt");

		while (getline(file1, textData, ' '))
		{
			temporary.push_back(textData);
		}

		for (int i = 0; i < temporary.size(); i++)
		{
			productName.push_back(temporary[i]);
			i += 1;

			productID.push_back(temporary[i]);
			i += 1;

			productQua.push_back(temporary[i]);
		}

		cout << "\n\n" << "Enter Item's Name: ";
		cin >> itemName;

		if (itemName == "7")
		{
			break;
		}

		for (int i = 0; i < productName.size(); i++)
		{
			if (productName[i] == itemName) {
				cout << "\n\n\t" << "It's already added." << endl;
				goto cursor;
			}
		}

		cout << "\n" << "Enter Item's ID: ";
		cin >> itemID;

		cout << "\n" << "Enter Item's Quantity: ";
		cin >> itemQua;

		fstream file;
		file.open("data.txt", ios::app);

		file << itemName << " ";
		file << itemID << " ";
		file << itemQua << " ";

		file.close();

		cout << "\n\n" << "\t\t" << "Successfully Added." << "\n" << endl;
		
		productName.clear();
		productID.clear();
		productQua.clear();
	
		cout << "\n\nDo you want to add another item? [Y/N]: ";
		cin >> question;

		switch (question)
		{
		case 'Y':
		case 'y':
			goto cursor;
		
		case 'N':
		case 'n':
			break;
		default:
			break;
		}
		break;
	}
		
}

void productInfo::findItembyName() {
	
	string item;
	int counter = 0;
	string textData;
	vector<string>temporary;

	fstream file1;
	file1.open("data.txt");

	while (getline(file1, textData, ' '))
	{
		temporary.push_back(textData);
	}

	for (int i = 0; i < temporary.size(); i++)
	{
		productName.push_back(temporary[i]);
		i += 1;

		productID.push_back(temporary[i]);
		i += 1;

		productQua.push_back(temporary[i]);
	}


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
	productName.clear();
	productID.clear();
	productQua.clear();
}

void productInfo::findItembyID() {	
	
	string id;
	int counter = 0;
	string textData;
	vector<string>temporary;

	fstream file1;
	file1.open("data.txt");

	while (getline(file1, textData, ' '))
	{
		temporary.push_back(textData);
	}

	for (int i = 0; i < temporary.size(); i++)
	{
		productName.push_back(temporary[i]);
		i += 1;

		productID.push_back(temporary[i]);
		i += 1;

		productQua.push_back(temporary[i]);
	}

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
	productName.clear();
	productID.clear();
	productQua.clear();
}


void productInfo::deleteItem() {
	
	string id;
	int counter = 0;
	string textData;
	vector<string>temporary;

	fstream file1;
	file1.open("data.txt");

	while (getline(file1, textData, ' '))
	{
		temporary.push_back(textData);
	}

	for (int i = 0; i < temporary.size(); i++)
	{
		productName.push_back(temporary[i]);
		i += 1;

		productID.push_back(temporary[i]);
		i += 1;

		productQua.push_back(temporary[i]);
	}

	file1.close();

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
			
			remove("data.txt");
			ofstream file;
			file.open("data.txt", ios::app);			
			for (int i = 0; i < productName.size(); i++)
			{
				file << productName[i] << " ";
				file << productID[i] << " ";
				file << productQua[i]<< " ";
			}		
			file.close();			
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
