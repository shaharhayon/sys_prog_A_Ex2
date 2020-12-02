#define BANK_SIZE 50
#define OFFSET 901
void open(double amount);
void balance(int accountNumber);
void deposit(int accountNumber, double amount);
void withdrawal(int accountNumber, double amount);
void close(int accountNumber);
void interest(double interestRate);
void print();
void exitBank();
int isOpen(int accountNumber);