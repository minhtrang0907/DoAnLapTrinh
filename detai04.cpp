#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<iomanip>
using namespace std;
struct Date
    {
        int date, month, year;
    };
struct Clock
    {
        int hour, min, sec;
    };
class Book
{
    protected:
        string Code;
        string Name;
        string Topic;
        string Author;
        string Producer;
        Date Time;
        int PageNumber;
        int NumberArchive;
    public:
        Book (string c="", string n="", string t="", string a="", string b="", Date x, int p=0, int na=0)
        {
            x.date =0;x.month=0;x.year=0;
            Code=c; Name=n; Topic=t; Author=a; Producer=b; Time=x; PageNumber=p; NumberArchive=na;
        }
        void input()
        {
            
            //cout<<"Ma so sach: ";
            cin>>Code;
            //cout<<"\nTen sach: ";
            cin.ignore();
            getline(cin,Name);
            //cout<<"\nChu de: ";
            getline(cin,Topic);
            //cout<<"\nTen tac gia: ";
            getline(cin,Author);
            //cout<<"\nNha xuat ban: ";
            getline(cin,Producer);
            //cout<<"\nNgay - Thang - Nam xuat ban: ";
            cin>>Time.date>>Time.month>>Time.year;
            //cout<<"\n So trang: ";
            cin>>PageNumber;
            //cout<<"\nSo ban luu thu vien: ";
            cin>>NumberArchive;
        }
        void output()
        {
            cout<<setw(14)<<left<<Code<<"|"
                <<setw(24)<<left<<Name<<"|"
                <<setw(24)<<left<<Topic<<"|"
                <<setw(19)<<left<<Author<<"|"
                <<setw(24)<<left<<Producer<<"|"
                <<setw(2)<<Time.date<<"/"<<setw(2)<<Time.month<<"/"<<setw(23)<<Time.year<<"|"
                <<setw(19)<<PageNumber<<"|"
                <<setw(19)<<NumberArchive<<"|"<<'\n';
            cout<<"+---+--------------+------------------------+------------------------+-------------------+------------------------+-----------------------------+-------------------+-------------------+\n";
        }
        void InputBooks(int k)
        {
            //cout<<"Nhap so sach nhap vao: ";
            cin>>k;
            NumberArchive+=k;
        }
        void OutputBooks(int q)
        {
            cout<<"Nhap so sach xuat ra: ";cin>>q;
            if(NumberArchive < q) cout<<"Khong du sach de xuat";
            else NumberArchive-=q;
        }
        
};
bool operator>(Date a, Date b)
{
    if (a.date > b.date && a.month == b.month && a.year == b.year) return true;
    if (a.year > b.year) return true;
    if (a.month > b.month && a.year == b.year) return true;
    return false;
}
bool operator>(Clock a, Clock b)
{
    if(a.hour > b.hour) return true;
    if(a.hour == b.hour && a.min > b.min) return true;
    if(a.hour == b.hour && a.min == b.min && a.sec > b.sec) return true;
    return false;
}
class BookToHome:virtual public Book
{
    protected:
        Date BDate, RDate;
    public:
        void input()
        {
            Book::input();
            //cout<<"Nhap ngay - thang - nam muon: ";
            cin>>BDate.date>>BDate.month>>BDate.year;
            //cout<<"Nhap ngay - thang - nam tra: ";
            cin>>RDate.date>>RDate.month>>RDate.year;
        }
        void output()
        {
            Book::output();
            cout<<"Ngay muon: "<<BDate.date<<"/"<<BDate.month<<"/"<<BDate.year;
            cout<<"Ngay tra: "<<RDate.date<<"/"<<RDate.month<<"/"<<RDate.year;
        }
        bool OutDate()
        {
            Date H;
            H.date = BDate.date + 7;
            H.month = BDate.month;
            H.year = BDate.year;
            if (H.date > 31) H.date -= 31;
            if(RDate > H) return true;
        }


};
class BookToRead:virtual public Book
{
    protected:  
        Clock BTime, RTime;
    public:
        void input()
        {
            Book::input();
            //cout<<"Nhap gio muon: ";
            cin>>BTime.hour>>BTime.min>>BTime.sec;
            //cout<<"Nhap gio tra: ";
            cin>>RTime.hour>>RTime.min>>RTime.sec;
        }
        void output()
        {
            Book::output();
            cout<<"Gio muon: "<<BTime.hour<<":"<<BTime.min<<":"<<BTime.sec;
            cout<<"Gio tra: "<<RTime.hour<<":"<<RTime.min<<":"<<RTime.sec;
        }
        bool OutTime()
        {
            Clock H;
            H.hour = BTime.hour + 2;
            H.min = BTime.min;
            H.sec = BTime.sec;
            if(RTime > H) return true;
            return false;
        }
    
};  
class Library:public BookToRead,public BookToHome
{
    private:
        Book *s;
        int total;
    public:
        void addbook()
        {
            cout<<"Them sach:\n";
            int select;
            cout<<"1.Sach Muon ve\n";
            cout<<"2.Sach muon doc\n";
            cin>>select;
            if(select == 1)
                s= new BookToHome();
            else s=new BookToRead();
            int n;
            cout<<"Nhap so sach them vao: "; cin>>n;
            for (int i=0;i<n;i++)
                s[i].input();
            total+=n;
            cout<<"Them thanh cong!";//thieu them vao danh sach
        }
        void deletebook()
        {
            int select;
            cout<<"Xoa sach:\n";
            cout<<"1.Sach Muon ve\n";
            cout<<"2.Sach muon doc\n";
            cin>>select;
            if(select == 1)
                s= new BookToHome();
            else s=new BookToRead();
            int n;
            cout<<"Nhap so sach xoa vao: "; cin>>n;
            for (int i=0;i<n;i++)
                s[i].input();
            total-=n;
            cout<<"Xoa thanh cong!";//thieu xoa trong danh sach
        }
        void display()
        {
            cout<<"===========================Danh sach hien thi============================================\n";
            cout<<"+---+--------------+------------------------+------------------------+-------------------+------------------------+-----------------------------+-------------------+-------------------+\n";
            Book::output();

        }
        void fixbook()
        {

        }
        
        void Static()
        {
            cout<<"So luong sach trong thu vien: "<<total;
           // cout<<"So luong sach dang muon ve: "<<
        }
        void ReadFile()
        {
            freopen("input1.txt","r",stdin);
            int k;
            cin>>k;
            Book s[k];
            for(int i=0;i<k;i++)
                s[i].input();
            
            freopen("output1.txt","w",stdout);
            cout<<"=======Danh sach hien thi=============\n";
            cout<<setw(5)<<"|STT|"
                <<setw(15)<<"Ma so sach   |"
                <<setw(25)<<"Ten sach       |"
                <<setw(25)<<"Chu de         |"
                <<setw(20)<<"Ten tac gia    |"
                <<setw(25)<<"Nha xuat ban       |"
                <<setw(30)<<"Ngay-thang-nam xuat ban   |"
                <<setw(20)<<"So trang  |"
                <<setw(20)<<"So ban sao luu  |"<<endl;
            cout<<"+---+--------------+------------------------+------------------------+-------------------+------------------------+-----------------------------+-------------------+-------------------+\n";
            for (int i=0;i<k;i++)
            {
                cout<<"|"<<setw(3)<<left<<i+1<<"|";s[i].output();
            }
        }
        
        
};
void ReadfromFile(char *filename, Book S[], int &count)
{
    ifstream file(filename);
    if(!file)
    {
        cout<<"Khong the mo tep!"<<filename<<endl;
        cout<<"Khoi tao du lieu mau..."<<endl;//

    }
    count=0;
    string line;
    while(getline(file,line))
    {
        stringstream ss(line);
        string Code,Name,Topic,Author,NXB;
        int Page,Archive;
        Date Time;
        getline(ss,Code,'|');
        getline(ss,Name,'|');
        getline(ss,Topic,'|');
        getline(ss,Author,'|');
        getline(ss,NXB,'|');
        ss>>Time.date;ss.ignore();
        ss>>Time.month;ss.ignore();
        ss>>Time.year;ss.ignore();
        ss>>Page;ss.ignore();
        ss>>Archive;
        S[count] = Book(Code, Name, Topic, Author, NXB, Time, Page, Archive);
        count++;
    }
    file.close();
}
void menu()
{
    cout << "\n============= QUAN LY THU VIEN =============\n";

    cout << "1. Hien thi danh sach\n";
    cout << "2. Them sach\n";
    cout << "3. Tim theo ma\n";
    cout << "4. Tim theo ten\n";
    cout << "5. Tim theo nha xuat ban\n";
    cout << "6. Thong ke\n";
    cout << "7. Xoa sach\n";
    cout << "8. Ghi file\n";
    cout << "0. Thoat\n";
}
int k;

int main()
{
    int chon;
    Book TV[100];
    menu();
    int count=0;
    ReadfromFile("input.txt",TV,count);
    cout<<"Nhap lua chon: ";cin>>chon;
    switch(chon)
    {
        case(1):
            
            break;
    }
}