QT       += core gui network

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
    answermessage.cpp \
    chatdialog.cpp \
    chatmix.cpp \
    eachchatbox.cpp \
    findpasswordapply.cpp \
    friendlist.cpp \
    loginwindow.cpp \
    main.cpp \
    message.cpp \
    networkconnection.cpp \
    passwordreset.cpp \
    register.cpp \
    user_base.cpp \
    user_tcpconnect.cpp \
    user_tcpconnect_client.cpp \
    windowcontroller.cpp

HEADERS += \
    answermessage.h \
    chatdialog.h \
    chatmix.h \
    eachchatbox.h \
    findpasswordapply.h \
    friendlist.h \
    loginwindow.h \
    message.h \
    networkconnection.h \
    passwordreset.h \
    register.h \
    user_base.h \
    user_tcpconnect.h \
    user_tcpconnect_client.h \
    windowcontroller.h

FORMS += \
    chatdialog.ui \
    chatmix.ui \
    findpasswordapply.ui \
    friendlist.ui \
    loginwindow.ui \
    networkconnection.ui \
    passwordreset.ui \
    register.ui
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Pic.qrc
