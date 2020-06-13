#include "receiptproductline.h"

ReceiptProductLine::ReceiptProductLine(std::string name, unsigned int price, unsigned int quantity, unsigned int totalDiscount)
    : m_name(name), m_price(price), m_quantity(quantity), m_totalDiscount(totalDiscount) {}

std::string ReceiptProductLine::getName()
{
    return m_name;
}

unsigned int ReceiptProductLine::getPrice()
{
    return m_price;
}

unsigned int ReceiptProductLine::getQuantity()
{
    return m_quantity;
}

unsigned int ReceiptProductLine::getTotalDiscount()
{
    return m_totalDiscount;
}
