#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <thread>
#include <chrono>
#include<iostream> 


using namespace std;

//function prototype
void login(); //fuction to login system
void index(); //funtion to login page
void forgot(); //function to search user authentication
void registr(); //function to add user authentication
void menu(); //function to get menu page
double getUnitprice(int Item_Code); //function to create order and print receipt
void printRecipt();
void delete_order(); //to delete the order
void modify_order(); //to modify the order
void daily_summary(); //to display daily_summary
void exit();  //function to exit system


struct Receipt_detail
{
	int reciept_Number;
	string cashier_Name;
	string date;
	int quantity[16];
	int x;
	int menu2[16];
	double amount[16];
	string medicineName[16] = { "Sitagliptin Tablet 100 mg","Gp 2mg (Glimepiride)","ranoxyl 500 mg ","Piriton tablet ",
		"Betamethasone Valerate Ointment ( USP 0.1%) ","Glycomet (Metformin) 500 mg",
	"Glycomet (Metformin) 850 mg","Nervijen tablet ","Acne Aid Soap ","Aloe Soft Soap ","Scino 5% Solution (Minoxidil Topical) ",
	"Concor 5 MG Tablet (Bisoprolol)","Concor 2.5 MG Tablet (Bisoprolol)","Losartan Potassium 50mg","Hydrocortisone 10mg ","Thyroxine Tablet 100 mg" };
	double Medicine[16] = { 35.00,40.00,35.00,1.00,125.00,38.50,40.00,75.00,500.00,350.00,1750.00,28.00,28.00,42.00,15.00,50.00 };
	double total;

	Receipt_detail* prev;
	Receipt_detail* next;
	Receipt_detail* link;

}*q, * temp;				//pointer declaration 

Receipt_detail* start_ptr = NULL;
Receipt_detail* head = NULL;
Receipt_detail* last = NULL;

int main()

//function invoke(calling)

{
	index();
	login();
	forgot();
	registr();
	system("COLOR 0A");//Color to change background
	menu();
	getUnitprice;
	printRecipt();
	Receipt_detail  medicine;
	return 0;

}//end  main function


//function definition

void index() {
	int index;
	int choice;
	std::string l = "************************************************************************************************************************\n\n\n";

	for (const auto c : l) {
		std::cout << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}
	std::cout << std::endl;
	std::string s = "\t\t\t\t************* Welcome to okmed login page *************\n\n\n\n\n";

	for (const auto c : s) {
		std::cout << c << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	std::cout << std::endl;

	cout << "\t************************        MENU        **************************\n\n";
	cout << "\t\t\t1.LOGIN" << endl;
	cout << "\t\t\t2.FORGOT USERNAME (or) PASSWORD" << endl;
	cout << "\t\t\t3.ADD NEW USER" << endl;
	cout << "\t\t\t4.Exit\n\n" << endl;
	cout << "\t**********************************************************************\n\n";
	cout << "\t\nPlease select your option... :";
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 1:
		login();
		break;
	case 2:
		forgot();
		break;
	case 3:
		registr();
		break;
	case 4:

		cout << "Thanks for using OKMED PHARMACY App...\n\n\n";
		exit();
		break;
	default:
		cout << "Invalid option..!! Please try again...\n" << endl;
		main();
	}
}

void login()
{
	int enumerate;
	string user, pass, u, p;
	cout << "Please enter your USERNAME and PASSWORD" << endl;
	cout << "USERNAME :";
	cin >> user;
	cout << "PASSWORD :";
	cin >> pass;

	ifstream input("database.txt");
	while (input >> u >> p)
	{
		if (u == user && p == pass)

		{
			enumerate = 1;
		}
	}
	input.close();
	if (enumerate == 1)
	{
		cout << "\nLOGIN SUCESSFUL...\nThanks for logging in\n";
		cin.get();
		cin.get();
		if (user == "user" && pass == "123")
		{
			cout << " ******************************************** Welcome to Okmed Pharmacy... *******************************************\n" << endl;
			menu();
		}
		else if (user == "admin" && pass == "admin")
		{
			cout << " ******************************************** Welcome to Okmed Pharmacy... *******************************************\n" << endl;
			menu();
		}
		else
		{
			cout << "\nPlease contact your system administrator for more details \n" << endl;
			index();
		}

	}
	else
	{
		cout << "\nInvalid login attempt..!! Please try again...\n";
		index();
	}

}

void registr()
{

	string reguser, regpass, ru, rp;
	cout << "Enter the new user username :";
	cin >> reguser;
	cout << "\nEnter the new user password :";
	cin >> regpass;

	ofstream reg("database.txt", ios::app);
	reg << reguser << ' ' << regpass << endl;
	cout << "\nAdd new user Sucessfully..\n";
	main();


}

void forgot()
{
	int ch;
	cout << "Forgot Your Username or Password...\n:( We're here for help\n:)";
	cout << "1.Search your id by username" << endl;
	cout << "2.Search your id by password" << endl;
	cout << "3.Main index" << endl;
	cout << "Enter your choice :";
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		int enumerate = 0;
		string searchuser, su, sp;
		cout << "\nEnter your remembered username :";
		cin >> searchuser;

		ifstream searchu("database.txt");
		while (searchu >> su >> sp)
		{
			if (su == searchuser)
			{
				enumerate = 1;
			}
		}
		searchu.close();
		if (enumerate == 1)
		{
			cout << "\n\nAccount found\n";
			cout << "\nYour password is " << sp;
			cin.get();
			cin.get();
			main();
		}
		else
		{
			cout << "\nYour userID is not found\n";
			cout << "\nPlease contact your system administrator for more details \n";
			cin.get();
			cin.get();
			main();
		}
		break;
	}
	case 2:
	{
		int enumerate = 0;
		string searchpass, su2, sp2;
		cout << "\nEnter the remembered password :";
		cin >> searchpass;

		ifstream searchp("database.txt");
		while (searchp >> su2 >> sp2)
		{
			if (sp2 == searchpass)
			{
				enumerate = 1;
			}
		}
		searchp.close();
		if (enumerate == 1)
		{
			cout << "\nYour password is found\n";
			cout << "\nYour Id is : " << su2;
			cin.get();
			cin.get();
			main();
		}
		else
		{
			cout << "Cannot found your password\n";
			cout << "\nPlease Contact your administrator for more information\n";
			cin.get();
			cin.get();
			index();
		}

		break;
	}

	case 3:
	{
		cin.get();
		main();
	}
	default:
		cout << "Wrong choice!!! Please try again.." << endl;
		forgot();
	}
}

void menu() {
	int menu;
	do
	{
		std::string l = "\t\t\t\t*******************************************************************\n\n";

		for (const auto c : l) {
			std::cout << c << std::flush;
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
		std::cout << std::endl;
		std::string s = " \t\t\t\t\t\t    Okmed Pharmacy Management System \n\n";

		for (const auto c : s) {
			std::cout << c << std::flush;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
		std::cout << std::endl;
		cout << "\t\t\t\t*******************************************************************";
		cout << "\t\t\t\t\t\t\t\t*******************************************************************\n\n";
		cout << "\t\t\t\t--------------------------------------------------\n";
		cout << "\t\t\t\t\t||\t1. Create Medicine order and Print receipt\t\t ||\n";
		cout << "\t\t\t\t\t||\t2. Delete latest Medicine order\t\t ||\n";
		cout << "\t\t\t\t\t||\t3. Modify Order List \t\t\t ||\n";
		cout << "\t\t\t\t\t||\t4. Exit\t\t\t\t\t ||\n";
		cout << "\t\t\t\t-------------------------------------------------------------------\n" << endl << endl;
		cout << "\t\tEnter choice: ";

		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			getUnitprice;
			printRecipt();	//function to add detail and print receipt
			break;
		}	//end case 1


		case 2:
		{
			delete_order();	//function delete
			break;
		}	//end case 2

		case 3:
		{
			modify_order();	//function modify
			break;
		}	//end case 3

		case 4:
		{
			exit();	//function exit
			goto a;
			break;
		}	//end case 4


		default:
		{
			cout << "You enter invalid input\nre-enter the input\n" << endl;
			break;
		}//end defeault
		}//end Switch

	} while (menu != 6);//end do
a://goto
	cout << "thank you" << endl;
}

void printRecipt() {
	ofstream ofile;
	ofile.open("text.txt");
	double invoice[16][5];
	int i = 0;
	char more;
	char date[100];
	int InvoiceNo;
	cout << "\n\n********* Here are the Item prices for your information********** \n\n";
	cout << "**********************************************************************************************************************\n";
	cout << "	ITEM CODE" << "	\t\tITEM NAME" << "                                          PRICE(Per 1 tablet)" << endl;
	cout << "***********************************************************************************************************************\n";
	cout << "	STG0001" << "\t\t" << "    Sitagliptin Tablet 100 mg" << "			                        LKR 35.00" << endl;
	cout << "	GMP0002" << "\t\t" << "    Gp 2mg (Glimepiride) " << "		                                LKR 40.00" << endl;
	cout << "	RXL0003" << "\t\t" << "    ranoxyl 500 mg " << "		                                        LKR 35.00" << endl;
	cout << "	PTN0004" << "\t\t" << "    Piriton tablet " << "		                                        LKR 1.00" << endl;
	cout << "	BTMV005" << "\t\t" << "    Marino TabletBetamethasone Valerate Ointment ( USP 0.1%) " << "	 	LKR 125.00(Per one pack)" << endl;
	cout << "	GLY0006" << "\t\t" << "    Glycomet (Metformin) 500 mg" << " 		                            LKR 38.50" << endl;
	cout << "	GLY0007" << "\t\t" << "    Glycomet (Metformin) 850 mg" << "		                                LKR 40.00" << endl;
	cout << "	NVJ0008" << "\t\t" << "    Nervijen tablet " << "			                                LKR 75.00" << endl;
	cout << "	ACN0009" << "\t\t" << "    Acne Aid Soap " << "			                                LKR 500.00" << endl;
	cout << "	ALO0010" << "\t\t" << "    Aloe Soft Soap " << "		                                        LKR 350.00" << endl;
	cout << "	MNX0011" << "\t\t" << "    Scino 5% Solution (Minoxidil Topical) " << "		                LKR 1750.00" << endl;
	cout << "	CON0012" << "\t\t" << "    Concor 5 MG Tablet (Bisoprolol)" << "		                        LKR 28.00" << endl;
	cout << "	CON0013" << "\t\t" << "    Concor 2.5 MG Tablet (Bisoprolol)" << "		                        LKR 28.00" << endl;
	cout << "	LSTP014" << "\t\t" << "    Losartan Potassium 50mg" << "		                                LKR 42.00" << endl;
	cout << "	HCT0015" << "\t\t" << "    Hydrocortisone 10mg " << "		                                LKR 15.00" << endl;
	cout << "	TXN0016" << "\t\t" << "    Thyroxine Tablet 100 mg" << "		                                LKR 50.00" << endl;
	cout << "	" << endl;
	cout << "Enter the date: ";
	cin >> date;
	cout << "Enter the invoice no: ";
	cin >> InvoiceNo;

	ofile << date << endl;
	ofile << "Invoice no: " << InvoiceNo << endl;

	do {
		cout << "\n\nPlease enter ITEM CODE : ";
		cin >> invoice[i][0];
		cout << "How many tablets do you want: ";
		cin >> invoice[i][1];
		invoice[i][2] = getUnitprice(invoice[i][0]);
		invoice[i][3] = invoice[i][1] * invoice[i][2];
	
		cout << "Do you have any other items to be entered next (y/n) ? ";
		cin >> more;

		i++;
	} while (more == 'y');



	cout << "\n\n-----------------------------\n\n";
	cout << "Date : " << date << "\n\n";
	cout << "Invoice No : " << InvoiceNo << "\n\n";

	cout << "|Item_Code|\t""|Quantity|\t""|UnitPrice(LKR)|\t""|TotalPrice(LKR)\n\n";

	double tot = 0;
	//	
	for (int k = 0; k < i; k++)

	{
		for (int l = 0; l < 4; l++) {
			cout << invoice[k][l] << "\t\t\t";
		}
		cout << endl;
		tot = tot + invoice[k][3];
	}
	cout << fixed << showpoint << setprecision(2);
	cout << "\n\nTotal : " << tot;
	cout << "\n\n-----------------------------\n\n\n";

	//for bakup
	ofile << "\n\nTotal : " << tot << endl;

	ofile.close();


}

double getUnitprice(int Item_Code)
{
	double price;
	switch (Item_Code) {
	case 1:
		cout << "Sitagliptin Tablet 100 mg";
		price = 35.00;
		break;
	case 2:
		price = 40.00;
		break;
	case 3:
		price = 35.00;
		break;
	case 4:
		price = 1.00;
		break;
	case 5:
		price = 125.00;
		break;
	case 6:
		price = 38.50;
		break;
	case 7:
		price = 40.00;
		break;
	case 8:
		price = 75.00;
		break;
	case 9:
		price = 500.00;
		break;
	case 10:
		price = 350.00;
		break;
	case 11:
		price = 1750.00;
		break;
	case 12:
		price = 28.00;
		break;
	case 13:
		price = 28.00;
		break;
	case 14:
		price = 42.00;
		break;
	case 15:
		price = 15.00;
		break;
	case 16:
		price = 50.00;
		break;
	default:
		price = 0;
		break;
	}
	return price;
}

void delete_order()	//function to delete_order
{

	int i, num, counter;
	cout << "Enter the data you want to delete \n";
	cin >> num;
	Receipt_detail* q;
	Receipt_detail* temp;
	bool found;

	if (start_ptr == NULL)
		cerr << "Can not delete from an empty list.\n";
	else
	{
		if (start_ptr->reciept_Number == num)
		{
			//int counter;
			q = start_ptr;
			start_ptr = start_ptr->next;
			//++counter;
			if (start_ptr == NULL)
				last = NULL;
			delete q;
			cout << "The Reciept is Deleted Successfully" << endl;
		}
		else
		{
			found = false;
			temp = start_ptr;
			q = start_ptr->next;

			while ((!found) && (q != NULL))
			{
				if (q->reciept_Number != num)
				{
					temp = q;
					q = q->next;
				}
				else
					found = true;
			}

			if (found)
			{
				temp->next = q->next;
				/*int counter;
				++counter;*/

				if (last == q)
					last = temp;
				delete q;
				cout << "The Reciept is Deleted Successfully" << endl;
			}
			else
				cout << "Item to be deleted is not in the list." << endl;
		}
	}
}	//End function delete_order



void modify_order()		//function to modify order
{
	int i, ch, sid;
	bool found;
	found = false;
	temp = start_ptr;
	cout << "Enter Receipt Number To Modify: ";
	cin >> sid;
	if (temp == NULL && sid == 0)
	{
		cout << "NO RECORD TO MODIFY..!" << endl;
	}

	else
	{
		while (temp != NULL && !found)
		{
			if (temp->reciept_Number == sid)
			{
				found = true;
			}
			else
			{
				temp = temp->next;
			}
			if (found)
			{
				cout << "Change  Order Number: ";
				cin >> temp->reciept_Number;
				cout << "Change Cashier Name: ";
				cin >> temp->cashier_Name;
				cout << "Change Date : ";
				cin >> temp->date;
				cout << "How many New Medicine would you like to Change:" << endl;
				cout << "( Maximum is 16 order for each transaction ) \n";
				cout << "  ";
				cin >> temp->x;
				if (temp->x > 16)
				{
					cout << "The Medicine you order is exceed the maximum amount of order !";

				}
				else {
					for (i = 0; i < temp->x; i++)
					{

						cout << "Please enter your selection to Change: " << endl;
						cin >> temp->menu2[i];
						cout << "Change Medicine Name: " << temp->medicineName[temp->menu2[i] - 1] << endl;
						cout << "How many New medicine do you want: ";
						cin >> temp->quantity[i];
						temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i] - 1];
						cout << "The amount You need to pay After Modify  is: " << temp->amount[i] << "LKR" << endl;

					}
					temp = temp->next;

				}

				cout << "RECORD MODIFIED....!" << endl;
			}
			else
			{
				if (temp != NULL && temp->reciept_Number != sid)
				{
					cout << "Invalid Reciept Number...!" << endl;
				}
			}
		}
	}
}		//End modify function



void exit() //Function to exit
{
	cout << "\nYou choose to exit..Please Enter 0 value\n" << endl;
	int exit_code;
	cout << "Enter a value: ";
	cin >> exit_code;
	if (0)
	{
		cout << "Exiting using _Exit";
		_Exit(exit_code);
	}
	else
	{
		cout << "Exiting using exit";
		exit(exit_code);
	}
}	//end function exit