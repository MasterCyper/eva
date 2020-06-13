#include "receipt.h"

Receipt::Receipt()
{

}

void Receipt::addReceiptProductLine(ReceiptProductLine &receiptProductLine)
{
    m_receiptProductLine.push_back(receiptProductLine);
}

void Receipt::addReceiptProductLine(ReceiptProductLine &receiptProductLine, int position)
{
    m_receiptProductLine.insert(m_receiptProductLine.begin() +  position, receiptProductLine);
}

std::vector<ReceiptProductLine>& Receipt::getReceiptProductLine()
{
    return m_receiptProductLine;
}
