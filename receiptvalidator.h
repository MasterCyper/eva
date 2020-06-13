#ifndef RECEIPTVALIDATOR_H
#define RECEIPTVALIDATOR_H

#include "receipt.h"

class ReceiptValidator
{
public:
    static ReceiptValidator& getInstance();
    void validateReceipt(Receipt& receipt);
private:
    ReceiptValidator();
    ReceiptValidator(const ReceiptValidator&);
    ReceiptValidator& operator=(ReceiptValidator&);
};

#endif // RECEIPTVALIDATOR_H
