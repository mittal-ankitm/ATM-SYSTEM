QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ATM.cpp \
    ATM_card.cpp \
    Account.cpp \
    Transaction.cpp \
    bank_customer.cpp \
    current_account.cpp \
    login.cpp \
    main.cpp \
    savings_account.cpp \
    selectpage.cpp \
    welcome.cpp

HEADERS += \
    ATM.h \
    ATM_card.h \
    Account.h \
    Transaction.h \
    bank_customer.h \
    checkacc.h \
    current_account.h \
    deposit.h \
    func.h \
    login.h \
    savings_account.h \
    selectpage.h \
    tr.h \
    welcome.h \
    withdraw.h

FORMS += \
    login.ui \
    selectpage.ui \
    welcome.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ATM.dat \
    bankcustomer.dat \
    caccount.dat \
    saccount.dat \
    trsum.dat
