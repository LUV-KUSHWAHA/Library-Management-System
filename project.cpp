#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>
using namespace std;

class Library
{
    private:
        char BookName[20];
        int PurchaseDate;
        int BookId;
        int NumberOfBooks;
    public:
        char* getBookName()
        {
            return BookName;
        }
        int getPurchaseDate()
        {
            return PurchaseDate;
        }
        int getBookId()
        {
            return BookId;
        }
        int getNumberOfBooks()
        {
            return NumberOfBooks;
        }

        Library()
        {
            PurchaseDate=0;
            strcpy(BookName,"");
            BookId=0;
            NumberOfBooks=0;
        }
        void AddBook();
        void ShowBooks();
        void header();
        void listview();
};

void Menu();
void Heading();
void SearchByBookName();
void AddToFile();
void DisplayFromFile();

void Library::AddBook()
{
    cout<<"\tEnter Book ID: ";
    cin>>BookId;
    cout<<"\tEnter Book Name: ";
    cin.get();
    cin.getline(BookName,20);
    cout<<"\tEnter Number Of Books:";
    cin>>NumberOfBooks;
    cout<<"\tEnter Purchase Date: ";
    cin>>PurchaseDate;
}

void Library:: ShowBooks()
{
    cout<<endl;
    cout<<"Book ID: "<<BookId<<endl;
    cout<<"Book Name: "<<BookName<<endl;
    cout<<"Number Of Books: "<<NumberOfBooks<<endl;
    cout<<"Purchase Date: "<<PurchaseDate<<endl;
}

void Library:: header()
{
    cout.setf(ios::left);
    cout<<setw(5)<<"I.D."<<setw(20)<<"Book Name"<<setw(20)<<"Number of Books"<<setw(20)<<"Purchase Date"<<endl;
    for(int i=1;i<=72;i++)
    cout<<"=";
    cout<<endl;
}

void Library:: listview()
{
    cout.setf(ios::left);
    cout<<setw(5)<<BookId<<setw(20)<<BookName<<setw(20)<<NumberOfBooks<<setw(20)<<PurchaseDate<<endl;
}

void heading()
{
    cout<<"**********LIBRARY MANAGEMENT SYSTEM*********"<<endl;
}

void AddToFile()
{
    ofstream fout;
    Library l;
    fout.open("books.txt",ios::app);
    l.AddBook();
    fout.write((char*)&l,sizeof(l));
    cout<<"Book data saved in file.....\n";
    fout.close();
}

void DisplayFromFile()
{
    ifstream fin;
    Library l;
    fin.open("books.txt",ios::in);
    int rec=0;
    while(fin.read((char*)&l,sizeof(l)))
    {
        if(rec<1)
        l.header();
        l.listview();
        rec++;
    }
    fin.close();
    cout<<"\nTotal "<<rec<<" Records in file.....\n";
}

void SearchByBookName()
{
    int flag=0;
    char bookname[20];
    ifstream fin;
    fin.open("books.txt",ios::in);
    Library l;
    cout<<"Enter Book Name: ";
    cin.ignore();
    cin.getline(bookname,20);
    while(fin.read((char*)&l,sizeof(l)))
    {
        if(strcmp(bookname,l.getBookName())==0)
        {
            l.ShowBooks();
            flag++;
        }
    }
    fin.close();
    if(flag==0)
    cout<<"Book with Name:: "<<bookname<<" not available...\n";
}

void Menu()
{
    int ch;
    do
    {
        system("cls");
        heading();
        cout<<"0.Exit\n";
        cout<<"1.Add New Books\n";
        cout<<"2.Show All Books\n";
        cout<<"3.Search Books\n";

        cout<<"\nEnter your choice\n";
        cin>>ch;
        system("cls");
        heading();
        switch(ch)
        {
            case 1: AddToFile(); break;
            case 2: DisplayFromFile(); break;
            case 3: SearchByBookName(); break;
        }
        system("pause");
    }while(ch!=0);
}

int main()
{
    Menu();
    return 0;
}
