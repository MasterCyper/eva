#ifndef CHECKPRODUCTLINE_H
#define CHECKPRODUCTLINE_H

#include <string>

class ReceiptProductLine
{
public:
    ReceiptProductLine(std::string name, unsigned int price, unsigned int quantity, unsigned int totalDiscount);
    std::string getName();
    unsigned int getPrice();
    unsigned int getQuantity();
    unsigned int getTotalDiscount();
private:
    std::string m_name;
    unsigned int m_price;
    unsigned int m_quantity;
    unsigned int m_totalDiscount;
};

#endif // CHECKPRODUCTLINE_H
