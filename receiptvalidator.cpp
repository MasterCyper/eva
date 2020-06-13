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
    for(auto receiptLine : receipt.getReceiptProductLine())
    {
        if(receiptLine.getTotalDiscount() % receiptLine.getQuantity())
        {
            unsigned int firstLineQuantity = receiptLine.getQuantity() - lastElement;
            unsigned int firstLineDiscount = receiptLine.getTotalDiscount() - receiptLine.getTotalDiscount() / receiptLine.getQuantity();

            unsigned int secondLineQuantity = lastElement;
            unsigned int secondLineDiscount = receiptLine.getTotalDiscount() - firstLineDiscount;

            ReceiptProductLine firstLine(receiptLine.getName(), receiptLine.getPrice(), firstLineQuantity, firstLineDiscount);
            ReceiptProductLine secondLine(receiptLine.getName(), receiptLine.getPrice(), secondLineQuantity, secondLineDiscount);

            receipt.getReceiptProductLine().erase(receipt.getReceiptProductLine().begin() +  lineCount);

            receipt.addReceiptProductLine(secondLine, lineCount);
            receipt.addReceiptProductLine(firstLine, lineCount);
            lineCount++;
        }
        else
            lineCount++;
    }
}
