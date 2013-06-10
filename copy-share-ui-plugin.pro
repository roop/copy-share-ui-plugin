# copy-share-ui-plugin.pro

TEMPLATE = lib
TARGET = copy-share-ui-plugin

CONFIG += share-ui-plugin

HEADERS = copyshareuiplugin.h   copyshareuimethod.h
SOURCES = copyshareuiplugin.cpp copyshareuimethod.cpp

target.path = /usr/lib/share-ui/plugins
INSTALLS += target
