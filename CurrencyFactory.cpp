//
// Created by Christian Pavilanis on 2023-02-15.
//
#include "CurrencyFactory.h"

CurrencyFactory::CurrencyFactory() {
    for (auto & curr : currencies_) {
        curr = nullptr;
    }
}

CurrencyFactory::~CurrencyFactory() {
    for (auto & curr : currencies_) {
        delete curr;
        curr = nullptr;
    }
}

Currency* CurrencyFactory::GetCurrency(int currencyType) {
    switch (currencyType) {
        case 0:  // USD
            if (!currencies_[0]) {
                currencies_[0] = new Currency("USD", "USA", 1);
            }
            return currencies_[0];

        case 1:  // EUR
            if (!currencies_[1]) {
                currencies_[1] = new Currency("EUR", "Europe", 0.88);
            }
            return currencies_[1];

        case 2: // GBP
            if (!currencies_[2]) {
                currencies_[2] = new Currency("GBP", "England", 0.73);
            }
            return currencies_[2];

        case 3: // CAD
            if (!currencies_[3]) {
                currencies_[3] = new Currency("CAD", "Canada", 1.25);
            }
            return currencies_[3];

        case 4: // AUD
            if (!currencies_[4]) {
                currencies_[4] = new Currency("AUD", "Australia", 1.39);
            }
            return currencies_[4];

        case 5: // NZD
            if (!currencies_[5]) {
                currencies_[5] = new Currency("NZD", "New Zealand", 1.56);
            }
            return currencies_[5];

        case 6: // JPY
            if (!currencies_[6]) {
                currencies_[6] = new Currency("JPY", "Japan", 128.75);
            }
            return currencies_[6];

        default:
            throw std::invalid_argument("Invalid currency type.");
    }
}