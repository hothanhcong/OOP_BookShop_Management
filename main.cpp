#include <iostream>
#include "main.h"
#include <cstring>
#include <conio.h>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
using std::setw;
using std::find;

int Book::next_id = 0;

int Person::next_id = 0;

int Person::get_id() {
    return this->id;
}

//=================================== implementation of Book =========================================
void Book::add() {
    cout << "Enter book name: " ;
    cin.ignore();
    getline(cin, name);
    cout << "Enter book author: ";
    getline(cin, auth);
    cout << "Enter book price: ";
    cin >> price;
    cout << "Enter book quantity: ";
    cin >> qty;
}

bool Book::search(string& name) {
    return this->name == name;
}
void Book::display(){
    cout << "ID: " << id << setw(20)<< "Name: " << name <<setw(20)<< " Author: " <<  this->auth << setw(20) 
    << " Price: " <<  this->price << setw(20)  << " Quantity: " <<  this->qty << endl;
}

void Book::update_price(int price) {
    this->price = price;
}
void Book::update_quantity(int qty) {
    this->qty = qty;
}
//================================ implementation of person ============================================================

void Person::add_person(){
    cout << "Enter name: " ;
    cin.ignore();
    getline(cin, name);
    cout << "Enter address: ";
    getline(cin, addr);
    do {
        cout << "Enter date join: ";
        cin >> date_of_joining.date;
    } while(date_of_joining.date > 31 || date_of_joining.date < 1);

    do {
        cout << "Enter month join: ";
        cin >>date_of_joining.month;
    } while(date_of_joining.month > 12 || date_of_joining.month < 1);
    
    cout << "Enter year join: ";
    cin >>date_of_joining.year ;
}


void Person::display(){
    cout << "ID: " <<  id << "\t" << "Name: " << name <<"\t" << " Adress: " <<  addr << 
    "\t" << " Date of join: " <<  date_of_joining.date << "/" << date_of_joining.month << "/" << date_of_joining.year << "\t\t";
}

string Person::get_name(){
    return name;
}
string Person::set_name(string name){
    this->name = name;
}

//=================================================================== implementation employees ================================================
void Employee::add_employee(){
    Person::add_person();
    cout << "Employees slary: ";
    cin >> salary;
}

void Employee::update_sal(int salary){
    this->salary = salary;
}

void Employee::display(){
    Person::display();
    cout <<"Salary: " << this->salary << endl;
}

bool Employee::search(string name){
    return get_name() == name;
}

//================================ implementation customers ============================================
void Customer::purchase(Book& book, int quantity){

    Person::add_person();
    book_name = book.get_name();
    book_quantity = quantity;
}

void Customer::display(){
    Person::display();
    cout <<"Your book paid:" << book_name <<"\t"<< "Your book quantity paid:" << book_quantity << endl;
}

bool Customer::search(string name){
    return Person::get_name() == name;
}

//================================ Menu functions ===============================================
void book_menu(vector<Book>& books);
void employees_menu(vector<Employee>& employees);
void customer_menu(vector<Customer>& customers, vector<Book>& books);


//=============BOOKS===============
void add_book(vector<Book>& books);
void update_price_book(vector<Book>& books);
void display_all_Book(vector<Book>& books);
void search_book(vector<Book>& books);

//=============EMPLOYEES=============

void add_one_employee(vector<Employee>& employees);
void view_all_employees(vector<Employee>& employees);
void search_employees(vector<Employee>& employees);
void update_salary(vector<Employee>& employees);
void remove_employee(vector<Employee>& employees);

//=================CUSTOMERS===============

void purchase_book(vector<Customer>& customers, vector<Book>& books);
void search_customers(vector<Customer>& customers);
void display_customer(vector<Customer>& customers);


//============== MAIN ======================

int main() {

    vector<Employee> employees;
    vector<Book> books;
    vector<Customer> customers;
    int choice;
    do {
    cout << "*************************************************" << endl;
	cout << "         BOOKSHOP MANGEMENT SYSTEM" << endl;
	cout << "*************************************************" << endl;
	cout << "   1. BOOKS" << endl;
	cout << "   2. EMPLOYEES" << endl;
	cout << "   3. CUSTOMERS" << endl;
	cout << "   4. EXIT" << endl<< endl << endl;
	cout << "Enter Your Choice : ";
    cin >> choice;
    switch (choice) {
        case 1:
            book_menu(books);
            break;
        case 2:
            employees_menu(employees);
        case 3:
            customer_menu(customers, books);
            break;
        case 4:
            exit(1);
    }
    }
    while(choice != 4);
    return 0;
}

void book_menu(vector<Book>& books) {
    int c;
    do{
	cout << "*************************************************" << endl;
	cout << "                  BOOK MENU" << endl;
	cout << "*************************************************" << endl;
	cout << "   1. ADD BOOK" << endl;
	cout << "   2. UPDATE PRICE" << endl;
	cout << "   3. SEARCH BOOK" << endl;
	cout << "   4. VIEW ALL BOOK" << endl;
	cout << "   5. RETURN TO MAIN MENU" << endl << endl << endl;
	cout << "Enter Your Choice for Book Menu: ";
	cin >> c;
    int i;
    switch (c)
	{
		case 1: 
            add_book(books);
			break;
		case 2: 
            update_price_book(books);
			break;
		case 3:
            search_book(books);
			break;
		case 4: 
            display_all_Book(books);
			break;
        case 5:
            return ;
            break;
		default:
			cout << "Wrong Input" << endl << "Invalid input";
			break;
	}
    }
    while(c != 5);

}

void employees_menu(vector<Employee>& employees){
    int c;
    do {
	cout << "*************************************************" << endl;
	cout << "                 EMPLOYEE MENU" << endl;
	cout << "*************************************************" << endl;
	cout << "   1. NEW EMPLOYEE" << endl;
	cout << "   2. SEARCH EMPLOYEE" << endl;
	cout << "   3. UPDATE SALARY" << endl;
	cout << "   4. VIEW ALL EMPLOYEE" << endl;
	cout << "   5. REMOVE EMPLOYEE" << endl;
	cout << "   6. RETURN TO MAIN MENU" << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
		case 1:
            add_one_employee(employees);
			break;
		case 2:
            search_employees(employees);
			break;
		case 3:
            update_salary(employees);
			break;
		case 4:
            view_all_employees(employees);
			break;
		case 5:
            remove_employee(employees);
			break;
		case 6:
			return;
		default:
			cout << "Wrong Input" << endl << "Invalid input";
			break;
	}
    } while(c!=6);
}

void customer_menu(vector<Customer>& customers, vector<Book>& books){
    int c;
    do {
	cout << "*************************************************" << endl;
	cout << "                 CUSTOMER MENU" << endl;
	cout << "*************************************************" << endl;
	cout << "   1. PURCHASE" << endl;
	cout << "   2. SEARCH CUSTOMER" << endl;
	cout << "   3. VIEW ALL CUSTOMER" << endl;
	cout << "   4. RETURN TO MAIN MENU" << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
		case 1:
            purchase_book(customers, books);
			break;
		case 2:
            search_customers(customers);
			break;
		case 3:
            display_customer(customers);
            break;
        case 4:
            return;
		default:
			cout << "Wrong Input" << endl << "Invalid input";
			break;
	}
    } while(c != 4);
}

//book
void add_book (vector<Book>& books) {
    Book new_book;
    new_book.add();
    books.push_back(new_book);
}

void display_all_Book(vector<Book>& books){
    if (books.empty()) {
        cout << "No Book available." << endl;
    } else {
    for (auto& book : books) 
    {
        book.display();
        }
    }
}
void update_price_book(vector<Book>& books){
    string name;
    int price;
    cout << "Enter book name to update price: ";
    cin.ignore();
    getline(cin, name);
    for (auto& book : books) {
        if (book.search(name)) {
            cout << "Enter new book price: ";
            cin >> price;
            book.update_price(price);
            cout << "Book price updated successfully." << endl;
            return;
        }
    }
    cout << "Book not found" << endl;
}

void search_book(vector<Book>& books){
    string name;
    cout << "Enter name to search: ";
    cin.ignore();
    getline(cin, name);
    for (auto& book : books) {
        if (book.search(name)) {
            book.display();
        }
    }

}

//employee
void add_one_employee(vector<Employee>& employees){
    Employee new_employee;
    new_employee.add_employee();
    employees.push_back(new_employee);
}

void view_all_employees(vector<Employee>& employees){
    for(auto& employee : employees) {
        employee.display();
    }
}

void search_employees(vector<Employee>& employees){
    string name;
    cout << "Enter name employee to search: ";
    cin.ignore();
    getline(cin, name);
    for(auto employee : employees) {
        if(employee.search(name)) {
            employee.display();
        }
    }

}

void update_salary(vector<Employee>& employees){
    string name;
    int salary;
    cout << "Enter name employee to update: ";
    cin.ignore();
    getline(cin, name);
    for(auto& employee : employees) {
        if(employee.search(name)) {
            cout << "Enter new salary: ";
            cin >> salary;
            employee.update_sal(salary);
        }
    }
}


void remove_employee(vector<Employee>& employees){
    string name;
    cout << "Enter name employee to remove: ";
    cin.ignore();
    getline(cin, name);
    // Remove the element using erase function and iterators 
    auto it = find_if(employees.begin(), employees.end(), [&name](Employee& emp) { return emp.get_name() == name; });
    // If element is found, erase it 
    if (it != employees.end()) { 
        employees.erase(it); 
        cout <<"Removed employee: " << name << endl;
    }
    else {
        cout <<"Not found employee: " << name << endl;
    }
}

//Customer

void purchase_book(vector<Customer>& customers, vector<Book>& books){
    string name;
    int book_quantity;
    cout << "Enter name of the book you want to buy: ";
    cin.ignore();
    getline(cin, name);

    auto it = std::find_if(books.begin(), books.end(), [&name](Book& book) {  // iterator
        return book.search(name); 
    });
    if (it != books.end()) {
        cout << "Enter quantity of the book you want to buy: ";
        cin >> book_quantity;
        if(book_quantity <= it->get_qty()){
            it->update_quantity(it->get_qty() - book_quantity);
        }
    Customer customer;
    customer.purchase(*it, book_quantity);
    customers.push_back(customer);
    cout << "Book purchased successfully!" << endl;
    customer.display();
    }
    else {
        cout << "Not found this book in the store!" << endl;
    }
}

void search_customers(vector<Customer>& customers){
    string name;
    cout << "Enter name customer to search: ";
    cin.ignore();
    getline(cin, name);
    for(auto customer : customers){
        if(customer.search(name)) {
            customer.display();
        }
    }
}

void display_customer(vector<Customer>& customers){
    for(auto customer : customers){
        customer.display();
    }
}

