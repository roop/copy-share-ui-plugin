# copy-share-ui-plugin.pro

TEMPLATE = lib
TARGET = copy-share-ui-plugin

CONFIG += share-ui-plugin

HEADERS = copyshareuiplugin.h   copyshareuimethod.h
SOURCES = copyshareuiplugin.cpp copyshareuimethod.cpp

target.path = /usr/lib/share-ui/plugins
INSTALLS += target

icon.path = /usr/share/icons/hicolor/64x64/apps/
icon.files = copy-shareui-qtlogo64.png
INSTALLS += icon
