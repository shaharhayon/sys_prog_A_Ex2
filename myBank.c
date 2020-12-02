
#include <stdio.h>
#include "myBank.h"
enum status
{
    CLOSED = 0,
    OPEN = 1,
    ACC_NUM = 0,
    STATUS = 1,
    BALANCE = 2
};

double bank[BANK_SIZE][3] = {{0}};
/*
bank[i][0] -> account number of bank[i]
bank[i][1] -> status of bank[i]
bank[i][2] -> balance of bank[i]
*/

void open(double amount)
{
    int accountNumber = 0;
    for (; accountNumber < BANK_SIZE; accountNumber++)
    {
        if (bank[accountNumber][STATUS] == CLOSED)
            break;
    }
    if (accountNumber >= BANK_SIZE)
    {
        printf("Too many opened accounts!");
        return;
    }
    bank[accountNumber][STATUS] = OPEN;
    printf("New account account number is: %d", accountNumber + OFFSET);
    deposit(accountNumber + OFFSET, amount);
}

void balance(int accountNumber)
{

    if (!isOpen(accountNumber))
    {
        printf("This account is closed.");
        return;
    }
    printf("The balance of account number %d: %.2lf", accountNumber, bank[accountNumber - OFFSET][BALANCE]);
}

void deposit(int accountNumber, double amount)
{
    if (!isOpen(accountNumber))
    {
        printf("This account is closed");
        return;
    }
    if (amount < 0)
    {
        printf("Cant deposit negative amount!");
        return;
    }

    bank[accountNumber - OFFSET][BALANCE] += amount;
    //balance(accountNumber);
}

void withdrawal(int accountNumber, double amount)
{
    if (!isOpen(accountNumber))
    {
        printf("This account is closed.");
        return;
    }
    if (bank[accountNumber - OFFSET][BALANCE] < amount)
    {
        printf("There isn't enough money to withdrawal in account %d.", accountNumber);
        return;
    }
    bank[accountNumber - OFFSET][BALANCE] -= amount;
    balance(accountNumber);
}

void close(int accountNumber)
{
    if (!isOpen(accountNumber))
    {
        printf("This account is closed.");
        return;
    }
    bank[accountNumber - OFFSET][BALANCE] = 0;
    bank[accountNumber - OFFSET][STATUS] = CLOSED;
    printf("Closed account number %d", accountNumber);
}

void interest(double interestRate)
{
    for (int accountNumber = 901; accountNumber < BANK_SIZE + OFFSET; accountNumber++)
    {
        if (!isOpen(accountNumber))
        {
            continue;
        }
        double toDeposit = bank[accountNumber - OFFSET][BALANCE] * (interestRate / 100);
        deposit(accountNumber, toDeposit);
    }
}

void print()
{
    for (int accountNumber = 901; accountNumber < BANK_SIZE + OFFSET; accountNumber++)
    {
        if (isOpen(accountNumber))
        {
            balance(accountNumber);
        }
    }
}

void exitBank()
{
    for (int accountNumber = 901; accountNumber < BANK_SIZE + OFFSET; accountNumber++)
    {
        bank[accountNumber - OFFSET][BALANCE] = 0;
        bank[accountNumber - OFFSET][STATUS] = CLOSED;
    }
}

int isOpen(int accountNumber)
{
    if (bank[accountNumber - OFFSET][STATUS] == OPEN)
        return 1;
    else
        return 0;
}
