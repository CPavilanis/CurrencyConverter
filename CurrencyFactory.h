//
// Created by Christian Pavilanis on 2023-02-14.
//

#ifndef CURRENCYFACTORY_H
#define CURRENCYFACTORY_H

#include "Currency.h"

class CurrencyFactory {
private:
    Currency* currencies_[7]{};

public:
    CurrencyFactory();
    ~CurrencyFactory();
    Currency* GetCurrency(int currencyType);
};

#endif // CURRENCYFACTORY_H
