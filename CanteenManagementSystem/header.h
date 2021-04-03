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

	while (getline(file1,textData))
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
	
	cout << "\n\n\n" << "-------------------------------------------------------------------------" << endl;
	cout << "        Name" << "\t\t\t" << "ID" << "\t\t\t" << "Quantity" << endl;
	cout << "-------------------------------------------------------------------------" << endl;

	for (int i = 0; i < productName.size(); i++)
	{
		if (productName[i].size() >= 10)
		{
			cout << "  " << i + 1 << "." << " " << productName[i];
			cout << "\t\t";
			cout << productID[i];
			cout << "\t\t\t";
			cout << productQua[i];
			cout << "\n\n";
		}		
		else
		{
			cout << "  " << i + 1 << "." << " " << productName[i];
			cout << "\t\t\t";
			cout << productID[i];
			cout << "\t\t\t";
			cout << productQua[i];
			cout << "\n\n";
		}
			
	}

	cout << "-------------------------------------------------------------------------" << endl;


	productName.clear();
	productID.clear();
	productQua.clear();
	
	file1.close();
}

void productInfo::addItem() {	

	while (1)
	{		
		cursor:
		cin.ignore();
		char question;
		string textData;
		vector<string>temporary;

		fstream file1;
		file1.open("data.txt");

		while (getline(file1, textData))
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
		getline(cin, itemName);

		if (itemName == "7")
		{
			break;
		}

		for (int i = 0; i < productName.size(); i++)
		{
			if (productName[i] == itemName) {
				cout << "\n\n\t" << "It's already added." << endl;
				file1.close();
				goto cursor;
			}
		}
	
		cout << "\n" << "Enter Item's ID: ";
		cin >> itemID;
		
		for (int i = 0; i < productID.size(); i++)
		{
			if (productID[i] == itemID) {
				cout << "\n\n\t" << "It's already added." << endl;
				file1.close();
				goto cursor;
			}
		}

		cout << "\n" << "Enter Item's Quantity: ";
		cin >> itemQua;

		fstream file;
		file.open("data.txt", ios::app);

		file << itemName << endl;
		file << itemID << endl;
		file << itemQua << endl;

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
			file1.close();
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
	cin.ignore();

	string item;
	int counter = 0;
	string textData;
	vector<string>temporary;

	fstream file1;
	file1.open("data.txt");

	while (getline(file1, textData))
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
	getline(cin, item);

	for (int i = 0; i < productName.size(); i++)
	{
		if (productName[i] == item)
		{
			cout << "\n\n\t\t\t---- Results ----" << endl << endl << endl;
			cout << "        Name" << "\t\t\t" << "ID" << "\t\t\t" << "Quantity" << endl;
			cout << "-------------------------------------------------------------------------" << endl << endl;
			
			if (productName[i].size() >= 10)
			{
				cout << "  " << i + 1 << "." << " " << productName[i];
				cout << "\t\t";
				cout << productID[i];
				cout << "\t\t\t";
				cout << productQua[i];
				cout << "\n\n";
			}
			else
			{
				cout << "  " << i + 1 << "." << " " << productName[i];
				cout << "\t\t\t";
				cout << productID[i];
				cout << "\t\t\t";
				cout << productQua[i];
				cout << "\n\n";
			}
			cout << "-------------------------------------------------------------------------" << endl << endl << endl;
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

	while (getline(file1, textData))
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
			cout << "\n\n\t\t\t---- Results ----" << endl << endl << endl;
			cout << "        Name" << "\t\t\t" << "ID" << "\t\t\t" << "Quantity" << endl;
			cout << "-------------------------------------------------------------------------" << endl << endl;

			if (productName[i].size() >= 10)
			{
				cout << "  " << i + 1 << "." << " " << productName[i];
				cout << "\t\t";
				cout << productID[i];
				cout << "\t\t\t";
				cout << productQua[i];
				cout << "\n\n";
			}
			else
			{
				cout << "  " << i + 1 << "." << " " << productName[i];
				cout << "\t\t\t";
				cout << productID[i];
				cout << "\t\t\t";
				cout << productQua[i];
				cout << "\n\n";
			}
			cout << "-------------------------------------------------------------------------" << endl << endl << endl;
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
	cin.ignore();

	string name;
	int counter = 0;
	string textData;
	vector<string>temporary;

	fstream file1;
	file1.open("data.txt");

	while (getline(file1, textData))
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
	getline(cin,name);

	for (int i = 0; i < productName.size() ; i++)
	{
		if (productName[i] == name)
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
				file << productName[i] << endl;
				file << productID[i] << endl;
				file << productQua[i] << endl;		
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

	while (true)
	{
		cin.ignore();
		string name;
		int counter = 0;

		string textData;
		vector<string>temporary;

		fstream file1;
		file1.open("data.txt");

		while (getline(file1, textData))
		{
			temporary.push_back(textData);
		}

		file1.close();

		for (int i = 0; i < temporary.size(); i++)
		{
			productName.push_back(temporary[i]);
			i += 1;

			productID.push_back(temporary[i]);
			i += 1;

			productQua.push_back(temporary[i]);
		}

		cout << "\n\n" << "Enter You Want Edit Item's Name: ";
		getline(cin, name);

		if (name == "7")
		{
			break;
		}

		for (int i = 0; i < productName.size(); i++)
		{
			if (productName[i] == name) {
				
				cout << "\nEnter New Name: ";
				getline(cin, itemName);

				cout << "\nEnter New ID: ";
				cin >> itemID;

				cout << "\nEnter New Quantity: ";
				cin >> itemQua;

				productName[i] = itemName;
				productID[i] = itemID;
				productQua[i] = itemQua;

				break;
			}			
		}

		remove("data.txt");
		ofstream file;
		file.open("data.txt", ios::app);
		for (int i = 0; i < productName.size(); i++)
		{
			file << productName[i] << endl;
			file << productID[i] << endl;
			file << productQua[i] << endl;
		}
		file.close();

		cout << "\n\n\t\tSuccessfully Changed." << endl;

		productName.clear();
		productID.clear();
		productQua.clear();
		break;
	}


}
