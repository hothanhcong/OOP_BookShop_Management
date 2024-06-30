#include <string>
using namespace std;

typedef struct
{
    int date;
    int month;
    int year;
} date;

class Book
{
	static int next_id;
	int id = 0;
	string name;
	string auth;
	int price;
	int qty;
public:
	Book(): id(++next_id){}
	void add();
	void update_price(int price);
	void update_quantity(int qty);
	bool search(string& name);
	void display();
	int get_qty() {
		return qty;
	}
	string get_name() { return name; }
};

class Person
{
    string name;
    string addr;
    static int next_id;
	int id; 
	date date_of_joining;

    public:
		Person():id(++next_id){}
        void add_person();
        void display();
        int get_id();
        string set_name(string name);
        string get_name();
};

class Employee:public Person
{
	long int salary;
public:
    void add_employee();
    void display();
	void update_sal(int salary);
	bool search(string name);
};

class Customer:public Person, public Book
{
	int book_quantity;
    string book_name;
public:
	void purchase(Book& books, int quantity);
	void display();
	bool search(string name);
};
