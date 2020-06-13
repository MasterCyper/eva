#ifndef RECEIPT_H
#define RECEIPT_H

#include "receiptproductline.h"
#include <vector>

class Receipt
{
public:
    Receipt();
    void addReceiptProductLine(ReceiptProductLine& receiptProductLine);
    void addReceiptProductLine(ReceiptProductLine& receiptProductLine, int position);
    std::vector<ReceiptProductLine>& getReceiptProductLine();
private:
    std::vector<ReceiptProductLine> m_receiptProductLine;
};

#endif // RECEIPT_H
