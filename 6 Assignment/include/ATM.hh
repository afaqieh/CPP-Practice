#ifndef ATM_H
#define ATM_H

/**
 * @class Account
 * @brief Represents a basic bank account with deposit and withdrawal functionality.
 */
class Account
{
    public:
        /**
         * @brief Default constructor.
         */
        Account() = default;

        /**
         * @brief Constructor that initializes the account with an initial balance.
         * @param initialBalance The starting balance for the account.
         */
        explicit Account(const float& initialBalance);

        /**
         * @brief Credits (adds) a specified amount to the account balance.
         * @param amount The amount to be added.
         */
        void credit(const float& amount);

        /**
         * @brief Debits (subtracts) a specified amount from the account balance.
         * @param amount The amount to be subtracted.
         * @note This method is virtual to allow overriding in derived classes.
         */
        virtual void debit(const float& amount);

        /**
         * @brief Returns the current balance of the account.
         * @return The current account balance.
         */
        float printBalance() const;

        /**
         * @brief Virtual destructor.
         */
        virtual ~Account() = default;

    private:
        float balance{0}; ///< The account balance.
};

/**
 * @class CheckingAccount
 * @brief Derived class from Account that includes a transaction fee for withdrawals.
 */
class CheckingAccount : public Account
{
    public:
        /**
         * @brief Constructor that initializes balance and fee.
         * @param initialBalance The starting balance for the checking account.
         * @param fee The transaction fee for each debit.
         */
        CheckingAccount(const float& initialBalance, const float& fee)
        : Account(initialBalance), fee(fee)
        {}

        /**
         * @brief Overrides the debit method to apply the transaction fee.
         * @param amount The amount to be debited (excluding fee).
         */
        void debit(const float& amount) override;

    private:
        float fee{0}; ///< Transaction fee for each debit.
};

#endif