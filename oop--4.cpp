#include <iostream>
#include <string>
using namespace std;

// ================= FeeRecord Class =================
class FeeRecord {
private:
    string studentRef;
    double semesterFee;
    double hostelFee;
    double libraryFine;
    double totalPaid;
    double balance;

public:
    // Constructor
    FeeRecord(string ref = "", double sem = 0,
              double hostel = 0, double fine = 0)
    {
        studentRef = ref;
        semesterFee = sem;
        hostelFee = hostel;
        libraryFine = fine;
        totalPaid = 0;
        balance = semesterFee + hostelFee + libraryFine;
    }

    // Copy Constructor (Deep Copy)
    FeeRecord(const FeeRecord& other)
    {
        studentRef = other.studentRef;
        semesterFee = other.semesterFee;
        hostelFee = other.hostelFee;
        libraryFine = other.libraryFine;
        totalPaid = other.totalPaid;
        balance = other.balance;
    }

    // Copy Assignment Operator
    FeeRecord& operator=(const FeeRecord& other)
    {
        if (this != &other)
        {
            studentRef = other.studentRef;
            semesterFee = other.semesterFee;
            hostelFee = other.hostelFee;
            libraryFine = other.libraryFine;
            totalPaid = other.totalPaid;
            balance = other.balance;
        }
        return *this;
    }

    // Operator -= to record payment
    void operator-=(double payment)
    {
        totalPaid += payment;
        balance -= payment;

        if (balance < 0)
            balance = 0;
    }

    void display()
    {
        cout << "\nStudent ID: " << studentRef << endl;
        cout << "Semester Fee: " << semesterFee << endl;
        cout << "Hostel Fee: " << hostelFee << endl;
        cout << "Library Fine: " << libraryFine << endl;
        cout << "Total Paid: " << totalPaid << endl;
        cout << "Balance: " << balance << endl;
    }
};

// ================= Invoice Class =================
class Invoice {
private:
    int invoiceID;
    string date;
    string* items;      // Dynamic Array
    int itemCount;
    double totalAmount;

    static int invoiceCounter;

public:
    // Constructor
    Invoice(string d, int count, double total)
    {
        invoiceCounter++;
        invoiceID = invoiceCounter;

        date = d;
        itemCount = count;
        totalAmount = total;

        items = new string[itemCount];

        for (int i = 0; i < itemCount; i++)
        {
            cout << "Enter Item " << i + 1 << ": ";
            cin >> items[i];
        }
    }

    // Destructor
    ~Invoice()
    {
        delete[] items;
        cout << "Invoice " << invoiceID
             << " destroyed.\n";
    }

    void display()
    {
        cout << "\nInvoice ID: " << invoiceID << endl;
        cout << "Date: " << date << endl;

        cout << "Items: ";
        for (int i = 0; i < itemCount; i++)
            cout << items[i] << " ";

        cout << "\nTotal Amount: " << totalAmount
             << endl;
    }
};

// Static Member Initialization
int Invoice::invoiceCounter = 0;

// ================= Main Function =================
int main()
{
    // Fee Record
    FeeRecord f1("22-CS-101", 50000, 10000, 2000);

    cout << "Original Fee Record:";
    f1.display();

    // Record payment using -=
    f1 -= 20000;

    cout << "\nAfter Payment:";
    f1.display();

    // Copy Constructor
    FeeRecord f2 = f1;

    cout << "\nCopied Fee Record:";
    f2.display();

    // Invoice Objects
    Invoice i1("20-12-2025", 2, 30000);
    Invoice i2("21-12-2025", 3, 45000);

    cout << "\nInvoice 1:";
    i1.display();

    cout << "\nInvoice 2:";
    i2.display();

    return 0;
}