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
    unsigned int lastElement = 1;
    for(auto i : receipt.getReceiptProductLine())
    {
        if(i.getTotalDiscount() % i.getQuantity())
        {
            unsigned int firstLineQuantity = i.getQuantity() - lastElement;
            unsigned int firstLineDiscount = i.getTotalDiscount() - i.getTotalDiscount() / i.getQuantity();

            unsigned int secondLineQuantity = lastElement;
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
