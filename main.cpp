#include <iostream>
#include <fstream>
#include<conio.h>

using namespace std;

class shopping
{
private:
	int pcode;
	float price;
	float dis;
	string pname;

public:
	void menu();
	void adminstrator();
	void buyer();
	void add();
	void edit();
	void rem();
	void list();
	void receipt();
};

void shopping ::menu()
{
    m:
	
	int choice;
	string email;
	string password;

	std::cout << "\t\t\t\t\t____________________________________________\n";
	std::cout << "\t\t\t\t\t                                            \n";
	std::cout << "\t\t\t\t\t           SUPERMARKET MAIN MENU            \n";
	std::cout << "\t\t\t\t\t                                            \n";
	std::cout << "\t\t\t\t\t____________________________________________\n";
	std::cout << "\t\t\t\t\t                                            \n";
	std::cout << "\t\t\t\t\t|   1)  Adminstrator   |\n";
	std::cout << "\t\t\t\t\t|   2)  Buyer          |\n";
	std::cout << "\t\t\t\t\t|   3)  Exit           |\n";
	std::cout << "\t\t\t\t\t|                      |\n";
	std::cout << "\n\t\t\t\t Please select ";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{       system("cls");
			system("color 3F");
		std::cout << "\t\t\t Please Login \n";
		std::cout << "\t\t\t Enter Email  : ";
		cin >> email;
		std::cout << "\t\t\t Password  :";
		cin >> password;

		if (email == "amrit@gmail.com" && password == "amrit123")
		{   
			
			adminstrator();
		}
		else
		{
			cout << "\n\n\t\t\t Invalid email/password\n\n\n";
		}
		break;
	}
	case 2:
	{     system("cls");
			system("color 3F");
		buyer();
	}
	case 3:
	{   system("cls");
	    system("color 3A");
		cout<<"\t\t\t\t\t\t********* THANKS FOR VISITING US *********** ";
		exit(0);
	}
	default:
	{
		std::cout << "\t\t\t Please select from the given options";
	}
	}

	goto m;
}

void shopping::adminstrator()
{   
	system("cls");
	system("color 3F");
	m:
	
	int choice;
	std::cout << "\t\t\t========================================\n";
	std::cout << "\t\t\t          Adminstrator Menu             \n";
	std::cout << "\t\t\t========================================\n";
	std::cout << "\t\t\t |                         |\n";
	std::cout << "\t\t\t |  1) Add the product     |\n";
	std::cout << "\t\t\t |  2) Modify the product  |\n";
	std::cout << "\t\t\t |  3) Delete the product  |\n";
	std::cout << "\t\t\t |  4) Back to main menu   |\n";
	std::cout << "\t\t\t |                         |\n";
	std::cout << "\n\t\t Please enter your choice\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
	{
		add();
		break;
	}
	case 2:
	{
		edit();
		

		break;
	}
	case 3:
	{
		rem();
		break;
	}
	case 4:
	{
		menu();
		break;
	}
	default:
	{
		std::cout << "\t\t\tInvalid Choice\n";
	}

	} 
  goto m;
}

void shopping::buyer()
{  
	system("color 3F");
	m:
	
	int choice;
	std::cout << "\t\t\t========================================\n";
	std::cout << "\t\t\t           Buyer Menu                   \n";
	std::cout << "\t\t\t========================================\n";
	std::cout << "\t\t\t |  1) Buy product     |\n";
	std::cout << "\t\t\t |  2) Go back         |\n";
	std::cout << "\n\t Enter your choice \n";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{   system("cls");
		system("color 3F");
		receipt();
		break;
	}
	case 2:
	{   
		system("cls");
		system("color 3F");
		menu();
		break;
	}
    default:
    {
		cout<<"Invalid choice\n";
		break;
	}
	}
	goto m;
 }

 void shopping::add(){
	system("color 3F");
	m: 
	
    fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;

	std::cout<<"\t\t\t *********  ADD NEW PRODUCT  ********* \n";
	std::cout<<"\n\n\t Product code of the product \n";
	cin>>pcode;
	std::cout<<"\n\t Name of the product \n";
	cin>>pname;
	std::cout<<"\t Price of the product \n";
	cin>>price;
	std::cout<<"\t Discount on product \n";
	cin>>dis;

	data.open("database.txt",ios::in);

	if(!data){
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else{
		data>>c>>n>>p>>d;
		while(!data.eof()){
			if(c==pcode){
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	
	if(token==1){
		goto m;
	}
	else{
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
		
	}
	std::cout<<"\t ******** RECORD INSERTED ! ******** \n\n";
	}
	
	
 }
 
 void shopping::edit(){
	
	
	list();
	system("color 3F");
     fstream data,data1;
	 int pkey;
	 int token=0;
	 int c;
	 float p;
	 float d;
	 string n;

	 std::cout<<"\n\t\t******** Modify the product ********\n";
	 std::cout<<"\n\t\t Product code \n";
	 cin>>pkey;

	 data.open("database.txt",ios::in);
	 if(!data){
       std::cout<<"\n\n\t file doesn't exist ! \n";
	 }
	 else{
		data1.open("database1.txt",ios::app|ios::out);

		data>>pcode>>pname>>price>>dis;

		while(!data.eof()){
			if(pkey==pcode){
				cout<<"\n\t\t Product new code : ";
				cin>>c;
				cout<<"\n\t\t Name of the product : ";
				cin>>n;
				cout<<"\n\t\t Price : ";
				cin>>p;
				cout<<"\n\t\t Discount : ";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\t\t******** RECORD EDITED ********\n\n";
				token ++;
			}
		    else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis;
			}
			data>>pcode>>pname>>price>>dis;
		}
		 data.close();
		 data1.close();

		 remove("database.txt");
		 rename("database1.txt","database.txt");
		 
		 if(token==0){
			cout<<"\n ******** RECORD NOT FOUND SORRY ! ********\n";
		 }
	 }
     
  }

  void shopping::rem(){
	system("color 3F");
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\t\t ******** Delete product ********\n";
	cout<<"\n\t Product code : ";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"\t File doesn't exist ";
	}
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof()){
			if(pkey==pcode){
				cout<<"\t\t ******** Product deleted successfully ********\n";
				token++;
			}
			else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

			}
		data>>pcode>>pname>>price>>dis;

		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0){
			cout<<"\t\t****** RECORD NOT FOUND *******";
		}
	}
  }

void shopping::list(){
     
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\t\t==================================================\n";
	cout<<"\n\t\t\t\t   LIST OF PRODUCTS  \t\t\n";
    cout<<"\n\t\t==================================================\n";
    cout<<"|\t Pcode \t |\t Name \t|\t Price \t |\t Discount \t |\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof()){
	
	cout<<"|\t"<<pcode<<"\t |\t"<<pname<<"\t|\t"<<price<<"\t |\t"<<dis<<"\t\t |\n";
	data>>pcode>>pname>>price>>dis;
	}
    data.close();

}

void shopping::receipt() {
    system("color 3F");
	m:
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float total = 0;

    data.open("database.txt", ios::in);
    if (!data) {
        cout<<"\n\t\t Empty database ";
    }
    else {
        data.close();

        list();
        cout << "\n_____________________________________________________\n";
        cout << "\n                                                     \n";
        cout << "               Please place the order                  ";
        cout << "\n_____________________________________________________\n";

        do {
            cout << "\n Enter product code : ";
            cin >> arrc[c];
            cout << "\n Enter the product Quantity : ";
            cin >> arrq[c];

            c++;
            cout << "\n Do you want to buy another product ? (y/n) ";
            cin >> choice;
        } while (choice == 'y');

        // Now, display the receipt
        cout << "\n\t\t\t_______________________RECEIPT_______________________";
        cout << "\nProduct No\t Product Name\t Quantity\t Price\t Amount\t Amount with discount \n";

        data.open("database.txt", ios::in);
        if (!data) {
            std::cout << "\n\t\t Empty database ";
        }
        else {
            for (int i = 0; i < c; i++) {
                int enteredCode = arrc[i];
                int enteredQuantity = arrq[i];
                bool found = false;

                while (data >> pcode >> pname >> price >> dis) {
                    if (pcode == enteredCode) {
                        found = true;
                        float amount = price * enteredQuantity;
                        float discountedAmount = amount - (amount * dis / 100);
                        total += discountedAmount;
                        cout << "\n" << pcode << "\t\t" << pname << "\t\t" << enteredQuantity << "\t\t" << price << "\t" << amount << "\t\t" << discountedAmount;
                        break; // Exit the loop once a match is found
                    }
                }

                if (!found) {
                    std::cout << "\nProduct with code " << enteredCode << " not found in the database.";
                }

                data.clear(); // Clear the end-of-file flag to read the file again
                data.seekg(0, ios::beg); // Set the file pointer back to the beginning
            }
            data.close();
        }
    }


	
	std::cout<<"\n\n________________________________________________________________________________";
	std::cout<<"\n\t\t\t\t\t\t Total amount   :  "<<total<<"\n\n";
}


  int main()
  {  
     system("color 3F");
     shopping s;
     s.menu();
	 
  }