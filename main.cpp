#include <iostream>
#include <memory>
#include "receiptvalidator.h"

void printReceipts(Receipt& receipt);

int main()
{
    ReceiptProductLine mars("mars", 755, 4, 27);
    ReceiptProductLine coca("coca-cola", 127, 3, 23);
    ReceiptProductLine fanta("fanta", 353, 5, 45);

    std::shared_ptr<Receipt> p_receipt(new Receipt);
    p_receipt->addReceiptProductLine(mars);
    p_receipt->addReceiptProductLine(coca);
    p_receipt->addReceiptProductLine(fanta);

    ReceiptValidator::getInstance().validateReceipt(*p_receipt);

    printReceipts(*p_receipt);
    return 0;
}

void printReceipts(Receipt& receipt)
{
    for(auto i : receipt.getReceiptProductLine())
    {
        std::cout << i.getName() << ", "
                  << i.getPrice() << " penny, "
                  << i.getQuantity() << " quantity, "
                  << i.getTotalDiscount() << " penny discount" << std::endl;
    }
}
