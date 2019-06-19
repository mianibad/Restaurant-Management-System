#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<windows.h>

using namespace std;

struct abc1{
    char id[10];
    string name;
    float salary;
};
struct abc{
    char user_id[10];
    string username;
    double bill;
};
void write_and_show_bill(abc ,int c);
void write_and_show_employee(abc1 ,int c);

class OrgEmployee{
public:
    abc1 aa;
    OrgEmployee(){
        aa.name="none";
        aa.salary=0.0;
    }

    void get_data(){
        cout<<"Please enter ID of employee : "<<endl;
        cin>>aa.id;
        cout<<"Now enter name of employee :"<<endl;
        cin>>aa.name;
       cout<<"Enter salary :"<<endl;
       cin>>aa.salary;
    }

    bool password(){
        int i=0, j=0, k=5;
        char X[11]="intel", Z[5];
        while(j!=k){
            while(i<k){
                Z[i]=getch();
                cout<<"*";
                i++;
            }
            for(int i=0;i<k;i++){
                if(X[i]==Z[i]){
                    j++;
                }
                else{
                    j=j+2;
                }
            }
            if(j==k){
                cout<<"\n\n\t\t\t\t\t\t'Password Matched'"<<endl;
                cout<<"\n\n\t\t\t\t\tPlease press any key to continue.."<<endl;
                getch();
                system("cls");
                return 1;
            }
            else{
                cout<<endl<<"\n\n\n\t\t\t\t\t\tWRONG PASSWORD "<<endl;
                Sleep(1500);
                system("cls");
                return 0;
            }
        }
    }
};

class User{
protected:
    int items[40];
    int counter;
public:
    abc a;
    User(){
        a.username="none";
        a.bill=0.0;
        items[0]=0;
    }
    User(string name){
        a.username=name;
        a.bill=0;
    }
    void getdata(){
        cout<<"Please enter your Token no. :"<<endl;
        cin>>a.user_id;
        cout<<"Now enter your name :"<<endl;
        cin>>a.username;
        cout<<"\n\n\t\t\t\t\t  The food items available are :\n"<<endl;
        cout<<"   'Items'                         'Price'"<<endl;
        cout<<"1) 2 Pc. Chicken		  Rs :150"<<endl;
        cout<<"2) Doublicious Sandwich           Rs :200"<<endl;
        cout<<"3) 2 Chicken Littles		  Rs :250"<<endl;
        cout<< "4) Pot Pie		          Rs :200"<<endl;
        cout<< "5) Hot Wings	5 Pc.	          Rs :375"<<endl;
        cout<< "6) Hot Wings	10 Pc.	          Rs :450"<<endl;
        cout<<"7) Hot Wings	20 Pc.	          Rs :780"<<endl;
        cout<<"8) Hot Wings - Combo	5 Pc.	  Rs :550"<<endl;
        cout<< "9) Chicken Tenders	3 Pc.	  Rs :450"<<endl;
        cout<< "10) Chicken Tenders	6 Pc.	  Rs :600"<<endl;
        cout<<"\nMake choice : \nEnter food no. with quantity, enter -1 when done : \n";
        int i=0;
        while(i<40){
            cout<<"\nFood item : "<<endl;
            cin>>items[i];
            max:if(items[i]==-1){
            break;
            }
            if(items[i]>10){
                cout<<"Please enter a valid value.."<<endl;
                cin>>items[i];
                goto max;
            }
            i++;
            cout<<"Quantity : "<<endl;
            cin>>items[i];
            if(items[i]==-1){
                break;
            }
            i++;
            counter=i;
        }
    }

    double totalbill[20];

    void calculatebill(){
        int i=0, j=0;
        while(i<counter){
            switch (items[i]){

            case 1:{
               a.bill=a.bill+150*(items[i+1]);
            break;
            }
            case 2:{
                totalbill[j]=200*(items[i+1]);
                a.bill=a.bill+totalbill[j];
                break;
            }
            case 3:{
                totalbill[j]=250*(items[i+1]);
                a.bill=a.bill+totalbill[j];
                break;
            }
            case 4:{
                totalbill[j]=200*(items[i+1]);
                a.bill=a.bill+totalbill[j];
            break;
            }
            case 5:{
                totalbill[j]=375*(items[i+1]);
                a.bill=a.bill+totalbill[j];
            break;
            }
            case 6:{
                totalbill[j]=450*(items[i+1]);
                a.bill=a.bill+totalbill[j];
            break;
            }
            case 7:{
                totalbill[j]=780*(items[i+1]);
                a.bill=a.bill+totalbill[j];
            break;
            }
            case 8:{
                totalbill[j]=550*(items[i+1]);
                a.bill=a.bill+totalbill[j];
            break;
            }
            case 9:{
                totalbill[j]=450*(items[i+1]);
                a.bill=a.bill+totalbill[j];
            break;
            }
            case 10:{
                totalbill[j]=600*(items[i+1]);
                a.bill=a.bill+totalbill[j];
            break;
            }
            default:{
                cout<<"Error.."<<endl;
            break;
            }
        }
        i+=2;
        j++;
        }
    }
};
void write_and_show_bill(abc a,int c){
    if(c==1){
        ofstream outFile;
        outFile.open("bill.txt", ios::app);
        if(!outFile)
			{
				cout<<"File could not be opened !! Press any Key...";
				exit(1);
			}
        outFile.write((char*)&a,sizeof(a));
        cout<<"Your total bill is Rs "<<a.bill<<endl;

            outFile.close();
    }
    int rn=0;

    if(c==2){
            char id[10];
             cout<<"Please enter token no. of the user :"<<endl;
            cin>>id;

        	ifstream inFile("bill.txt");

	if(!inFile)
	{
		cout<<"File could not be opened !! Press any Key...";
		exit(1);
	}
	while(inFile.read((char*)&a,sizeof(a)))
	{
		if(strcmp(id,a.user_id)==0){
			rn=(rn)*sizeof(a);
			inFile.seekg(rn);

            cout<<"User Token ID   :      "<<a.user_id<<endl;
            cout<<"User Name       :      "<<a.username<<endl;
            cout<<"Total Bill      :      "<<a.bill<<endl;
            inFile.close();

		}
		rn++;
    }
    }
}


void write_and_show_employee(abc1 a,int c){
    if(c==1){
        ofstream outFile;
        outFile.open("employe.txt",ios::app);
        if(!outFile)
			{
				cout<<"File could not be open !! Press any Key...";
				exit(1);
			}
        else{
        outFile.write((char*)&a,sizeof(a));
        cout<<"Employee added successfully.."<<endl;
        outFile.close();
        }
    }


    if(c==2){
            int rn=0;
            char id[10];
            cout<<"enter id "<<endl;
            cin>>id;
        	ifstream inFile("employe.txt",ios::app);

	if(!inFile)
	{
		cout<<"File could not be opened !! Press any Key...";
		exit(1);
	}
	while(inFile.read((char*)&a,sizeof(a))){
		if(strcmp(id,a.id)==0){
			rn=(rn-1)*sizeof(a);
			inFile.seekg(rn);
            cout<<"Employee's ID    :        "<<a.id<<endl;
            cout<<"Employee's Name  :        "<<a.name<<endl;
            cout<<"Monthly Salary   :        "<<a.salary<<endl;
			inFile.close();
		}
		rn++;
    }
    }

}
int main(){
 User ab[1000];
 OrgEmployee ab1[30];
 char choice;
 int i=0, j=0;
 cin:cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t  \"Welcome to the CLASSIC FOOD\"";
    cout<<"\n\t\t\t\t\t\t'Quality speaks'"<<endl;
 getch();
 system("cls");
 min:cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tEnter C for customer & E for employee :       ";
    cin>>choice;
    system("CLS");
    if(choice=='c' or choice=='C'){
  end:cout<<"\t\t\t\t\t\t Hello :)\n\n\n"<<endl;
        cout<<"\n\n\n\t\t\t\t\t 1)Place your order.\n"<<endl;
        cout<<"\t\t\t\t\t 2)See your bill.\n"<<endl;
        cout<<"\t\t\t\t\t 3)Exit.\n"<<endl;
        cout<<"\t\t\t\t\t Please enter 1 , 2 or 3 :    ";
        cin>>choice;
        system("cls");
        if(choice=='1'){
        ab[i].getdata();
        system("cls");
        ab[i].calculatebill();
        write_and_show_bill(ab[i].a,1);
        i++;
        cout<<"\tThank you very much! Hope you Enjoy your meal.. :)"<<endl;
        cout<<"\n\tPress any key to continue...";
        getch();
        system("cls");
        goto min;
        }
        else if(choice=='2'){
            write_and_show_bill(ab[0].a,2);
            cout<<"\nPress any key to continue...  ";
            getch();
            system("cls");
            goto min;
        }
        else if(choice=='3'){
            system("cls");
            goto cin;
        }
        else{
            cout<<"Enter a valid value.";
            system("cls");
            goto end;
        }

    }
    else if(choice=='e' or choice=='E'){
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tPlease enter Password :      ";
        int check=ab1[0].password();
        if(check==1){
        cout:cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t 1)See a customer's bill"<<endl;
            cout<<"\t\t\t\t\t 2)Enter Employee's data."<<endl;
            cout<<"\t\t\t\t\t 3)See employees data."<<endl;
            cout<<"\t\t\t\t\t 4)Exit."<<endl;
            cout<<"\t\t\t\t\t Please enter an option :    ";
            cin>>choice;
            system("cls");
            switch (choice){
            case '1':{
                write_and_show_bill(ab[0].a,2);
                cout<<"\nPress any key to continue...  ";
                getch();
                system("cls");
                goto cout;
            break;
            }
            case '2':{
                ab1[j].get_data();
                write_and_show_employee(ab1[j].aa,1);
                j++;
                cout<<"\nPress any key to continue...  ";
                getch();
                system("cls");
                goto cout;
            break;
            }
            case '3':{
                write_and_show_employee(ab1[0].aa,2);
                cout<<"\nPress any key to continue...  ";
                getch();
                system("cls");
                goto cout;
            break;
            }
            case '4':{
                system("cls");
                goto cin;
            break;
            }
            default:{
                cout<<"Enter a valid value."<<endl;
                getch();
                system("cls");
                goto cout;
            }
            }
        }
        else if(check==0){
                system("cls");
                goto min;
        }
    }
    else{
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tInvalid input!!"<<endl;
        getch();
        system("cls");
        goto min;
    }
    getch();
return 0;
}
