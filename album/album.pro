QT += widgets gui core

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    confirm_page.cpp \
    main.cpp \
    main_window.cpp \
    pro_set_page.cpp \
    pro_tree.cpp \
    pro_tree_item.cpp \
    pro_tree_thread.cpp \
    pro_tree_widget.cpp \
    wizard.cpp

HEADERS += \
    confirm_page.h \
    const.h \
    main_window.h \
    pro_set_page.h \
    pro_tree.h \
    pro_tree_item.h \
    pro_tree_thread.h \
    pro_tree_widget.h \
    wizard.h

FORMS += \
    confirm_page.ui \
    main_window.ui \
    pro_set_page.ui \
    pro_tree.ui \
    wizard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

RC_ICONS = "icon/bulm.ico"

DISTFILES +=
