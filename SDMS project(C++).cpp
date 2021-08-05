//STUDENT MANAGEMENT SYSTEM
//welcome
//press any key at the blipping pointer
#include<fstream>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;
class student
{
char Sname[25];
int Srno;
char SFname[25];
char Sdob[25];
char Semail[35];
char Snumber[15];
char Saddress[30];
public: void inputdata();
	void adddata(char*a);
	void deletedata(char*a);
	void modifydata(char*a);
	void searchdata(char*a);
	void sortdata(char*a);
	void displaysorteddata(char*a);
	void displaydata()
	{
	 cout<<"The details of student:";
	 cout<<"\nName: "<<Sname<<"\nFather's name: "<<SFname;
	 cout<<"\nRoll Number: "<<Srno<<"\nDate of Birth: "<<Sdob;
	 cout<<"\nEmail Address: "<<Semail<<"\nMobile Number: "<<Snumber;
	 cout<<"\nAddress: "<<Saddress;
	 cout<<endl;
	}

	void getname(){fflush(stdin);gets(Sname);}void getfname(){fflush(stdin);gets(SFname);}
	void getrno(){cin>>Srno;}void getdob(){fflush(stdin);gets(Sdob);}
	void getemail(){fflush(stdin);gets(Semail);}void getnumber(){fflush(stdin);gets(Snumber);}
	void getaddress(){fflush(stdin);gets(Saddress);}
	student()
	{
	strcpy(Sname," ");
	strcpy(SFname," ");
	Srno=0;
	strcpy(Sdob,"00 00 0000");
	strcpy(Semail,"xyz@abc.com");
	strcpy(Snumber,"8888888888");
	strcpy(Saddress," ");
	}

	char* returnname()
	{
	return Sname;
	}

	int returnrno()
	{
	return Srno;
	}
}stud[1],temp;




void student::inputdata()
{       cout<<endl<<endl;
	cout<<"Enter name: ";
	fflush(stdin);
	gets(Sname);
	cout<<"\nEnter Father's name: ";
	fflush(stdin);
	gets(SFname);
	cout<<"\nEnter Roll number: ";
	cin>>Srno;
	cout<<"\nEnter Date of Birth(DD_MM_YYYY): ";
	fflush(stdin);
	gets(Sdob);
	cout<<"\nEnter Email-Address: ";
	fflush(stdin);
	gets(Semail);
	cout<<"\nEnter Mobile number: ";
	fflush(stdin);
	gets(Snumber);
	cout<<"\nEnter address: ";
	fflush(stdin);
	gets(Saddress);system("cls");
}




void student::searchdata(char*a)
{
ifstream fin;
student s;
int rno,flag=0;
fin.open(a,ios::binary);
fin.seekg(0);
system("cls");
cout<<"Enter the roll number to be displayed.\n";
cin>>rno;
while(fin.read((char*)&s,sizeof(s)))
{
if(s.returnrno()==rno)
{
flag=1;
system("cls");
cout<<"\n\n\n\n\n\n\n\n";
s.displaydata();
getch();
}
}
if(flag==0)
{cout<<"\nInvalid roll number.";
getch();}
fin.close();
}




void student::adddata(char*a)
{
student s;
ofstream f;
f.open(a,ios::binary|ios::app);
if(!f)
{
cout<<"Cannot open file";
getch();
return;
}
char choi;
do
{
system("cls");
cout<<"Please enter the details for the registration";
cout<<"\nof student ";
if(((f.tellp()/sizeof(s))+1)!=1)
cout<<((f.tellp()/sizeof(s))+1)<<" :";
s.inputdata();
f.write((char*)&s,sizeof(s));
cout<<"\n\n\n\n\n\n\n\n\n\n\nYour entry with name \""<<s.returnname()<<"\" has been added.";
cout<<"\nAdd another record?(Enter Y for yes and N for No)\n";
cin>>choi;
}while(choi=='y'||choi=='Y');
f.close();

system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\nExtra student(s) added.";
getch();
temp.sortdata(a);
}




void student::modifydata(char*a)
{
char detail;
int flag=0;
char ch;
student s;
fstream f;
f.open(a,ios::in|ios::out|ios::binary);
int rno;
mains:system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\nEnter the roll number to be edited:\n";
cin>>rno;
f.seekg(0);
while(f.read((char*)&s,sizeof(s)))
{
if(rno==s.returnrno())
{
main104:int x=f.tellg()-sizeof(s);
f.seekg(x);
flag=1;
system("cls");
s.displaydata();
cout<<"\nWhat detail do you wish to edit?\n";
cout<<"1-Name, 2-F.Name, 3-Roll Number\n";
cout<<"4-DOB, 5-E-mail, 6-Number\n";
cout<<"7-Address, 8-No Detail\n";
cin>>detail;
switch(detail)
{
case '1':cout<<"\nEnter updated information:\n";
       s.getname();
       break;
case '2':cout<<"\nEnter updated information:\n";
       s.getfname();
       break;
case '3':cout<<"\nEnter updated information:\n";
       s.getrno();
       break;
case '4':cout<<"\nEnter updated information:\n";
       s.getdob();
       break;
case '5':cout<<"\nEnter updated information:\n";
       s.getemail();
       break;
case '6':cout<<"\nEnter updated information:\n";
       s.getnumber();
       break;
case '7':cout<<"\nEnter updated information:\n";
       s.getaddress();
       break;
case '8':return;
default:cout<<"\n\t\t\tInvalid number";
	getch();
}
system("cls");

f.write((char*)&s,sizeof(s));
system("cls");
cout<<"Details have been set.";
s.displaydata();
cout<<"\nDo you wish to continue editing the same record?(Y for yes, N for no)\n";
cin>>ch;
if(ch=='y'||ch=='Y')
goto main104;
break;
}
}
if(flag==0)
{cout<<"\nInavlid roll number.";
getch();
}
f.close();
}




void student::deletedata(char*a)
{
int flag=0;
char ch;
student s;
ifstream fin;
ofstream fout;
fout.open("temp.dat",ios::out|ios::binary);
fin.open(a,ios::in|ios::binary);
if(!fin||!fout)
{
cout<<"\nCannot open file";
return;
}
int rno;
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\nPlease enter the ROLL NO. of the student whose record is to be deleted:\n";
cin>>rno;
fin.seekg(0);
while(fin.read((char*)&s,sizeof(s)))
{
if(s.returnrno()==rno)
{
flag=1;
main101:system("cls");
cout<<"\nAre you sure you want to delete the following record:(Y for yes, N for No)";
cout<<"\nName= "<<s.returnname()<<"\nRoll Number= "<<s.returnrno()<<endl;
cin>>ch;
if(ch=='y'||ch=='Y')
{cout<<"\n\nRecord deleted.";
getch();}
else if(ch=='n'||ch=='N')
{fout.write((char*)&s,sizeof(s));
cout<<"\n\nRecord Not deleted.";
getch();}
else
{
cout<<"\nInvalid choice";
goto main101;}
}
if(s.returnrno()!=rno)
fout.write((char*)&s,sizeof(s));
}
if(flag==0)
{cout<<"\nInvalid roll number.";
getch();}
fout.close();
fin.close();
remove(a);
rename("temp.dat",a);
}




void student::sortdata(char*a)
{
student s[100],temp1,temp2;
ifstream fin;
fin.open(a,ios::binary);
int i=0;
while(fin.read((char*)&temp1,sizeof(temp1)))
{
s[i++]=temp1;
}
fin.close();
int n=i;
int j;
for(i=0;i<n;i++)
{
 for(j=i+1;j<n;j++)
 {
  if(s[j].returnrno()<s[i].returnrno())
  {
   temp2=s[j];
   s[j]=s[i];
   s[i]=temp2;
  }
 }
}
ofstream fout;
fout.open(a,ios::binary);
fout.seekp(0);
for(i=0;i<n;i++)
{fout.write((char*)&s[i],sizeof(s[i]));}
fout.close();
}




void student::displaysorteddata(char*a)
{
temp.sortdata(a);
int i=0;
ifstream fin;
student s;
fin.open(a,ios::binary);
fin.seekg(0);
system("cls");
while(fin.read((char*)&s,sizeof(s)))
{
if(i%22==0&&i!=0)
{getch();
system("cls");}
cout<<"ROLL NUMBER:  "<<s.returnrno()<<"    NAME: "<<s.returnname();
cout<<endl;
i++;
}
getch();
fin.close();
}



int main()
{
fstream fout,fo;
int flag=0;
ofstream fou;
ifstream fin;
char line[15];
char pass[15];
int g=0;
int n=1;
char file[20],temp[25];
char show[20]={""};
char show1[20]={""};
student s;
system("cls");
char c,choices;
cout<<"WELCOME TO THE *SCHOOL MANAGEMENT* DATABASE.\n";
getch();
system("cls");
cout<<"Salient features we offer:";
getch();
system("cls");
cout<<"*We sort your data for you*";
cout<<"\nYou may enter the data in any order and trust our software to sort it for you.\n";
getch();
system("cls");
cout<<"*We secure your database with encryption*";
cout<<"\nThe software comes with a user-friendly password system to ensure that only you can access your database.";
getch();
vmain:system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\nDo you wish to open an existing database or create a new database?";
main5:cout<<"\nEnter E for existing and N for new.\n";
cin>>c;
if(c=='E'||c=='e'||c=='N'||c=='n')
{
}
else
{
cout<<"\nInvalid choice";
goto main5;
}
main15:system("cls");
if(c=='e'||c=='E')
{
main98:
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\nWELCOME BACK! Enter the name of your file(case sensitive).\n";
fflush(stdin);
gets(file);
strcpy(show,file);
strcpy(show1,show);
strcpy(temp,strcat(file,".dat"));
fo.open(temp,ios::in|ios::binary);
if(!fo)
{
fo.close();
char cha;
system("cls");
main97:cout<<"No such file exists. Now,";
cout<<"\n1.Do you wish to rather make a new file with the same name?";
cout<<"\n2.Retype the name of your file?";
cout<<"\nEnter 1 or 2 to make a choice\n";
cin>>cha;
if(cha=='1')
{
fo.open(temp,ios::binary|ios::app);
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\nEnter a password to encrypt your file(max 10 characters).\n";
fflush(stdin);
gets(pass);
strcat(show1,".txt");
fou.open(show1);
fou<<pass<<" ";
fou<<show1;
fou.close();
getch();
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\nYour database named \""<<show<<"\" has been registered with us.";
cout<<"\nNow, lets begin adding new entries.\n";
getch();
system("cls");
char choi;
do
{
system("cls");
cout<<"Please enter the details for the registration";
cout<<"\nof student "<<((fo.tellp()/sizeof(s))+1)<<" :";
s.inputdata();
fo.write((char*)&s,sizeof(s));
cout<<"\n\n\n\n\n\n\n\n\n\n\nYour entry with name \""<<s.returnname()<<"\" has been added.";
cout<<"\nAdd another record?(Enter Y for yes and N for No)\n";
cin>>choi;
}while(choi=='y'||choi=='Y');
fo.close();
goto main109;
}
else if(cha=='2')
goto main98;
else
{cout<<"\nInvalid choice";
goto main97;
}
}
strcat(show1,".txt");
fin.open(show1);
main102:fin.seekg(0);
fin>>line;
system("cls");cout<<"\n\n\n\n\n\n\n\n\n\n\nEnter the password to open your database.\n";
g=0;
while(g<=10)
{
pass[g]=getch();
if(pass[g]==13)
break;
else
{cout<<"*";}
g++;
}
pass[g]='\0';
if(strcmp(pass,line)==0)
{
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\nAccess granted.";
getch();
goto main16;
}
else
{
++flag;
system("cls");
cout<<"Incorrect password.Try again.";
getch();
if(flag==3)
{
system("cls");
cout<<"Maximum attempts(3) reached.";
getch();
return 0;
}
goto main102;
}
}

else if(c=='n'||c=='N')
{
cout<<"\n\n\n\n\n\n\n\n\n\nEnter the name of the file you want to make(case sensitive).\n";
fflush(stdin);
gets(file);
strcpy(show,file);
strcpy(show1,show);
strcpy(temp,strcat(file,".dat"));
fout.open(temp,ios::in|ios::binary);
if(fout)
{
mainv:
cout<<"\nCannot create file. Name of the file already exists. Enter a different name.";
cout<<"\n(Press X to return to previous menu,Y to continue.)\n";
cin>>choices;
if(choices=='x'||choices=='X')
{goto vmain;}
else if(choices=='y'||choices=='Y')
{goto main15;}
else
goto mainv;
}
else
{
fout.close();
fout.open(temp,ios::out|ios::binary|ios::app);
}
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\nEnter a password to encrypt your file(max 10 characters).\n";
fflush(stdin);
gets(pass);
strcat(show1,".txt");
fou.open(show1);
fou<<pass<<" ";
fou<<show1;
fou.close();
getch();
system("cls");

cout<<"\n\n\n\n\n\n\n\n\n\n\nYour database named \""<<show<<"\" has been registered with us.";
cout<<"\nNow, lets begin adding new entries.\n";
getch();
system("cls");
char choi;
do
{
system("cls");
cout<<"Please enter the details for the registration";
cout<<"\nof student "<<((fout.tellp()/sizeof(s))+1)<<" :";
s.inputdata();
fout.write((char*)&s,sizeof(s));
cout<<"\n\n\n\n\n\n\n\n\n\n\nYour entry with name \""<<s.returnname()<<"\" has been added.";
cout<<"\nAdd another record?(Enter Y for yes and N for No)\n";
cin>>choi;
}while(choi=='y'||choi=='Y');
fout.close();
main109:system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\nThank you for registering. All of your entries have been added.";
cout<<"\nThe registration process is over.\n";
getch();
system("cls");
main6:cout<<"\n\n\n\n\n\n\n\n\n\n\nDo you want your data to be sorted(Roll No. wise)? Enter Y for YES and N for NO.\n";
cin>>choi;
if(choi=='Y'||choi=='y')
{
stud[0].sortdata(temp);
cout<<"\nYour data is sorted.\n";
getch();
}
else if(choi=='N'||choi=='n')
{cout<<"\nAhead you go.\n";
getch();}
else
{
cout<<"\nInvalid choice";
goto main6;
}
}
char ch;
char cho;

do
{
main16:system("cls");
cout<<"Your database is all set and done. Now,";
cout<<"\n1.Do you wish to look at any existing record?";
cout<<"\n2.Do you wish to modify any existing record?";
cout<<"\n3.Do you wish to delete any existing record?";
cout<<"\n4.Do you wish to add new record(s)?";
cout<<"\n5.Do you wish to see the sorted list?";
cout<<"\n6.Do you wish to take no further action?";
cout<<"\nEnter 1, 2, 3, 4, 5 or 6 to make a choice.\n";
cin>>ch;
system("cls");
if(ch=='1')
stud[0].searchdata(temp);
else if(ch=='2')
stud[0].modifydata(temp);
else if(ch=='3')
stud[0].deletedata(temp);
else if(ch=='4')
stud[0].adddata(temp);
else if(ch=='5')
stud[0].displaysorteddata(temp);
else if(ch=='6')
{cout<<"Thank you for being here. Have a magnificent day ahead.";
getch();
system("cls");
cout<<"\"IMPORTANT\"\n";
cout<<"The name of your database file is \""<<show<<"\".";
cout<<"\nPlease remember it for future uses.";
cout<<"\nContact the developer for troubleshoot.";

break;}
else
{cout<<"\nInvalid choice.Enter again.";
getch();
goto main16;
}
goto main16;
getch();
system("cls");
cout<<"\nDo you wish to perform any of the actions of the MAIN MENU again?";
cout<<"\nEnter Y for YES and N for NO.\n";
cin>>cho;
system("cls");
}while(cho=='Y'||cho=='y');
return 0;
}
