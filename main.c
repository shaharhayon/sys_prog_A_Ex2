#include <stdio.h>
#include "myBank.h"
int main()
{
    char option;
    int accountNumber;
    double amount, interestRate;
    do
    {
        printf("\nPlease choose a transaction type:\n"
               "O-Open Account\n"
               "B-Balance Inquiry\n"
               "D-Deposit\n"
               "W-Withdrawal\n"
               "C-Close Account\n"
               "I-Interest\n"
               "P-Print\n"
               "E-Exit\n");
        scanf(" %c", &option);
        switch (option)
        {
        case 'O':
            printf("Please enter amount for deposit: ");
            if (scanf("%lf", &amount) != 1)
            {
                printf("Failed to read the amount\n");
                continue;
            }
            if (amount < 0)
            {
                printf("Invalid Amount\n");
                continue;
            }
            open(amount);
            break;
        case 'B':
            printf("Please enter account number: ");
            if (scanf("%d", &accountNumber) != 1)
            {
                printf("Failed to read the account number\n");
                continue;
            }
            if ((accountNumber < OFFSET) || (accountNumber >= OFFSET + BANK_SIZE))
            {
                printf("Invalid account number\n");
                continue;
            }
            if (!isOpen(accountNumber))
            {
                printf("This account is closed\n");
                continue;
            }
            balance(accountNumber);
            //printf("\n");
            break;
        case 'D':
            printf("Please enter account number: ");
            if (scanf("%d", &accountNumber) != 1)
            {
                printf("Failed to read the account number\n");
                continue;
            }
            if ((accountNumber < OFFSET) || (accountNumber >= OFFSET + BANK_SIZE))
            {
                printf("Invalid account number\n");
                continue;
            }
            if (!isOpen(accountNumber))
            {
                printf("This account is closed\n");
                continue;
            }
            printf("Please enter amount to deposit?: ");
            if (scanf("%lf", &amount) != 1)
            {
                printf("Failed to read the amount\n");
                continue;
            }
            if (amount < 0)
            {
                printf("Cant deposit negative amount\n");
                continue;
            }
            deposit(accountNumber, amount);
            break;
        case 'W':
            printf("Please enter account number: ");
            if (scanf("%d", &accountNumber) != 1)
            {
                printf("Failed to read the account number\n");
                continue;
            }
            if ((accountNumber < OFFSET) || (accountNumber >= OFFSET + BANK_SIZE))
            {
                printf("Invalid account number\n");
                continue;
            }
            if (!isOpen(accountNumber))
            {
                printf("This account is closed\n");
                continue;
            }
            printf("Please enter amount to withdraw: ");
            if (scanf("%lf", &amount) != 1)
            {
                printf("Failed to read the amount\n");
                continue;
            }
            if (amount < 0)
            {
                printf("Cant Withdraw negative amount\n");
                continue;
            }
            withdrawal(accountNumber, amount);
            break;
        case 'C':
            printf("Please enter account number: ");
            if (scanf("%d", &accountNumber) != 1)
            {
                printf("Failed to read the account number\n");
                continue;
            }
            if (!isOpen(accountNumber))
            {
                printf("This account is already closed\n");
                continue;
            }
            if ((accountNumber < OFFSET) || (accountNumber >= OFFSET + BANK_SIZE))
            {
                printf("Invalid account number\n");
                continue;
            }
            close(accountNumber);
            break;
        case 'I':
            printf("Please enter interest rate: ");
            if (scanf("%lf", &interestRate) != 1)
            {
                printf("Failed to read the interest\n");
                continue;
            }
            if (interestRate < 0)
            {
                printf("Invalid interest rate\n");
                continue;
            }
            interest(interestRate);
            break;
        case 'P':
            print();
            break;
        case 'E':
            exitBank();
            break;
        default:
            printf("Invalid transaction type\n");
            continue;
        }

        printf("\n");
    } while (option != 'E');

    return 0;
}