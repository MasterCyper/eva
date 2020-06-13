#include "receiptvalidator.h"

ReceiptValidator::ReceiptValidator() {}

ReceiptValidator& ReceiptValidator::getInstance()
{
    static ReceiptValidator instance;
    return instance;
}

void ReceiptValidator::validateReceipt(Receipt& receipt)
{
    unsigned int lineCount = 0;
    for(auto i : receipt.getReceiptProductLine())
    {
        if(i.getTotalDiscount() % i.getQuantity())
        {
            unsigned int firstLineQuantity = i.getQuantity() - 1;
            unsigned int firstLineDiscount = i.getTotalDiscount() - i.getTotalDiscount() / i.getQuantity();

            unsigned int secondLineQuantity = 1;
            unsigned int secondLineDiscount = i.getTotalDiscount() - firstLineDiscount;

            ReceiptProductLine firstLine(i.getName(), i.getPrice(), firstLineQuantity, firstLineDiscount);
            ReceiptProductLine secondLine(i.getName(), i.getPrice(), secondLineQuantity, secondLineDiscount);

            receipt.getReceiptProductLine().erase(receipt.getReceiptProductLine().begin() +  lineCount);

            receipt.addReceiptProductLine(secondLine, lineCount);
            receipt.addReceiptProductLine(firstLine, lineCount);
            lineCount++;
        }
        else
            lineCount++;
    }
}
