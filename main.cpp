#include <iostream>
#include <map>
#include "Currency.h"
#include "CurrencyFactory.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
    CurrencyFactory factory;

    std::map<int, Currency*> currency_map {
            {0, factory.GetCurrency(0)},
            {1, factory.GetCurrency(1)},
            {2, factory.GetCurrency(2)},
            {3, factory.GetCurrency(3)},
            {4, factory.GetCurrency(4)},
            {5, factory.GetCurrency(5)},
            {6, factory.GetCurrency(6)}
    };

    do{
        cout << "Enter amount. Enter 0 to exit: ";
        double amount;
        cin >> amount;

        if (amount == 0) {
            cout << "Exiting program." << endl;
            break;
        }

        int baseCurrency;
        cout << "Enter base currency (USD=0 / EUR=1 / GBP=2 / CAD=3 / AUD=4 / NZD=5 / JPY=6): ";
        cin >> baseCurrency;

        Currency* baseCurrencyPtr = nullptr;
        try {
            baseCurrencyPtr = currency_map.at(baseCurrency);
        } catch (const std::out_of_range& e) {
            cout << "Invalid base currency selected. Please try again." << endl;
            continue;
        }

        double amount_usd = amount / baseCurrencyPtr->GetExchangeRate();

        int foreignCurrency;
        cout << "Enter foreign currency (USD=0 / EUR=1 / GBP=2 / CAD=3 / AUD=4 / NZD=5 / JPY=6): ";
        cin >> foreignCurrency;

        Currency* foreignCurrencyPtr = nullptr;
        try {
            foreignCurrencyPtr = currency_map.at(foreignCurrency);
        } catch (const std::out_of_range& e) {
            cout << "Invalid foreign currency selected. Please try again." << endl;
            continue;
        }

        double amount_f = amount_usd * foreignCurrencyPtr->GetExchangeRate();

        cout << "amount in " << foreignCurrencyPtr->GetSymbol() << ": " << amount_f << endl;
    } while (true);

    return 0;
}
