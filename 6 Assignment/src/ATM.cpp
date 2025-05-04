#include <iostream>
#include "ATM.hh"

Account::Account(const float& initialBalance)
{
    balance = initialBalance;
}

void Account::credit(const float& amount)
{
    balance += amount;
    std::cout << amount << "has been credited to your account" << std::endl;
}

void Account::debit(const float& amount)
{
    if (balance >= amount)
    {
        balance -= amount;
    }
    else 
    {
        std::cout << "The requested amount is more than what is available in the account. Please try again" << std::endl;
    }
}

float Account::printBalance() const
{
    return balance;
}

void CheckingAccount::debit(const float& amount)
{
    float total = amount + fee;
    if (printBalance() >= total)
    {
        Account::debit(total);
    }
    else
    {
        std::cout << "You do not have enough credit to complete this transaction. Fee amount is " << fee << std::endl;
    }
}