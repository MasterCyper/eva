TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        receipt.cpp \
        receiptproductline.cpp \
        receiptvalidator.cpp

HEADERS += \
    receipt.h \
    receiptproductline.h \
    receiptvalidator.h
