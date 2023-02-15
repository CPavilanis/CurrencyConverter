//
// Created by Christian Pavilanis on 2023-01-28.
//

#include "Currency.h"

Currency::Currency(const std::string& symbol, const std::string& country, double exchange_rate) : symbol_(symbol), country_(country), exchange_rate_(exchange_rate) {
}

std::string Currency::GetSymbol() const {
//    std::cout << symbol_ << std::endl;
    return symbol_;
}

std::string Currency::GetCountry() const {
    //    std::cout << country_ << std::endl;
    return country_;
}

double Currency::GetExchangeRate() const {
    //    std::cout << exchange_rate_ << std::endl;
    return exchange_rate_;
}

void Currency::SetExchangeRate(double rate) {
    exchange_rate_ = rate;
}

Currency& Currency::operator=(const Currency &other) {
    if (this != &other) {
        symbol_ = other.symbol_;
        country_ = other.country_;
        exchange_rate_ = other.exchange_rate_;
    }
    return *this;
}
