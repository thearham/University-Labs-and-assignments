#include<fstream>
#include"Link_List.h"
#include"Doubly_list.h"
#include"Interface.h"
#include"BST_Customer.h"
#include"Offers.h"

int main()
{
	Link_list_Airports obj;
	
	DoublyList obj1,obj4,obj5; //obj 4 is for waiting lists
	DoublyList1 obj6,obj7;
	int flight_no;

	BST_Customer obj2;
	string data;
	BST_Customer * root=NULL;

	node* head = NULL;node1* head1 = NULL;
	Array obj3;


	char arr[50] = { 'U','p',' ','t','o',' ','5','0',' ',' r','e','s','e','r','v','a','t','i','o','n','s',' ','5','0','%',' ','o','f','f' ,'\0'};
	int ticket = 0;
	int chk = 0;

	WelcomeScreen();


	while (true)
	{
		
		color(15);

		cout << "\n*****************************";
		cout << "\n1  to Flight Reservation.   |";
		cout << "\n2  to Customers Reservation.|";
		cout << "\n3  to OFFERS Reservation.   |";
		cout << "\n4  to Quit   Reservation.   |";
		cout << "\n*****************************\n";

		cout << "\n Input the choice-> ";
		cin >> chk;
		if (chk == 1)
		{
			
			while (true)
			{
				int chk1 = 0;
				cout << "\n*****************************";
				cout << "\n1  to search for Destinaton.|";
				cout << "\n2  to Reserve Flight.       |";
				cout << "\n3  to Cancel the reserved.  |";
				cout << "\n4  to update the l-reserved.|";
				cout << "\n5  to go back.              |";
				cout << "\n*****************************\n";
				cout << "\n Input the choice-> ";
				cin >> chk1;
				if (chk1 == 1)
				{
					string flights;
					ifstream fin;
					fin.open("Regular flights.txt",ios::in);
					if (!fin)
						cout << "\n File is not open.";
					else
					{
						cout << "\n Flights destinations are  \n";
						while (!fin.eof())
						{
							fin >> flights;
							if (flights == ".")
							{
								cout << endl;
							}
							cout << flights<<" ";
						}
					}
				}
				else if (chk1 == 2)
				{
					ticket++;
					color(10);

					if (ticket > 70)
					{
						cout << "\n ! [Note] the flight is fully reserved. \n";
						int waiting = 0; 
						cout << "\n Do you want to get in waiting list press 1  : ";
						cin >> waiting;
						if (waiting == 1)
						{
							obj4.insert_at_tail(head, data);
							cout << "\n waiting list have : ";
							obj4.display(head);
						}
						
					}
					else
					{
						cout << "\n | Reserve flight | \n ";

						cout << "\nInput n customer name -> ";
						cin >> data;
						cout << "\n Input the flight number -> ";
						cin >> flight_no;

						obj1.insert_at_tail(head, data);
						obj6.insert_at_tail_flight(head1, flight_no);

						ofstream fout;
						fout.open("Reserved flight Customers.txt", ios::app);
						fout << data << "'s ticket number is " << ticket<< " and flight number is. "<<flight_no << endl;

						obj1.display(head); 
						cout << " 's ticket number is " << ticket ;
						cout << " and flight number is "; obj6.display_flight(head1);



						color(15);
					}
				}

				else if (chk1 == 3)
				{
					cout << "\n | Cancel Reserve flight | \n ";

					obj4.removeLastNode(head);
					obj7.removeLastNode_flight(head1);

					obj4.display(head);
					obj6.display_flight(head1);

				}

				else if (chk1 == 4)
				{
					cout << "\n | Update Reserve flight | \n ";

					obj4.removeLastNode(head);
					obj7.removeLastNode_flight(head1);
					cout << "\nEnter new name : ";
					cin >> data;
					cout << "\nEnter new flight no : ";
					cin >> flight_no;
					obj1.insert_at_tail(head, data);
					obj6.insert_at_tail_flight(head1, flight_no);
					obj4.display(head);

				}
				else if (chk1 == 5)
				{
					system("CLS");
					break;
				}
			}

		}
		else if (chk == 2)
		{
		    int chk1 = 0;
		    cout << "\n*****************************";
		    cout << "\n1  to search for Customers. |";
		    cout << "\n2  to Add customer.         |";
		    cout << "\n3  to delete the Customer.  |";
		    cout << "\n4  to update the Customer.  |";
		    cout << "\n5  to go back.              |";
		    cout << "\n*****************************\n";
		    cout << "\n Input the choice-> ";
		    cin >> chk1;
			
			if (chk1 == 1)
			{
				string customer;
				ifstream fin;
				fin.open("Customer.txt", ios::in);
				if (!fin)
					cout << "\n File is not open.";
				else
				{
					cout << "\n Flights destinations are  \n";
					while (!fin.eof())
					{
						fin >> customer;
						if (customer == ".")
						{
							cout << endl;
						}
						cout << customer << " ";
					}
				}
			}
			else if (chk1 == 2)
			{
				color(10);
				cout << "\n BST to insert customer data  ";
				cin >> data;
				root = obj2.insert(root, data);
				color(15);
				color(6);
				obj2.inorder(root);
				color(15);
			}

			else if (chk1 == 3)
			{
				cout << "\n | Delete customer | \n ";
				root = obj2.deleteNode(root, data);
				obj2.inorder(root);
			}

			else if (chk1 == 4)
			{
				cout << "\n | Update added customers | \n ";

				
				root = obj2.deleteNode(root, data);
				cout << "\n BST to insert customer data  ";
				cin >> data;
				root = obj2.insert(root, data);
				obj2.inorder(root);

			}
			else if (chk1 == 5)
			{
				system("CLS");
				break;
			}


		}
		
		else if (chk == 3)
		{
		obj3.insert(arr, 100);
		obj3.Display();
		}
		else if (chk == 4)
		{
		system("CLS");
		break;
		}
	}
	system("pause");
	return 0;
}
