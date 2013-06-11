// copyshareuimethod.cpp

/*
 * copy-share-ui-plugin
 * Copyright (C) 2013 Roopesh Chander <roop@forwardbias.in>
 * Copyright (C) 2010-2011 Nokia Corporation and/or its subsidiary(-ies). All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "copyshareuimethod.h"
#include <ShareUI/ItemContainer>
#include <ShareUI/FileItem>
#include <ShareUI/DataUriItem>
#include <MDataUri>
#include <MTheme>
#include <QClipboard>
#include <QApplication>
#include <QTimer>

CopyShareUIMethod::CopyShareUIMethod(QObject *parent)
    : ShareUI::MethodBase(parent), m_isPixmapDirAdded(false) {
}

CopyShareUIMethod::~CopyShareUIMethod()
{
}

QString CopyShareUIMethod::id()
{
    return "com.example.copy";
}

QString CopyShareUIMethod::title()
{
    return "Copy path";
}

QString CopyShareUIMethod::subtitle()
{
    return "Copy path to clipboard";
}

QString CopyShareUIMethod::icon()
{
    if (!m_isPixmapDirAdded) { // need to add it just once
        QString shareIconPath = "/usr/share/icons/hicolor/64x64/apps";
        MTheme::addPixmapDirectory(shareIconPath);
        m_isPixmapDirAdded = true;
    }
    return "copy-shareui-qtlogo64";
}

void CopyShareUIMethod::currentItems(const ShareUI::ItemContainer * items)
{
    // This sharing method is valid only if
    // there's just one item to share
    emit visible(items->count() == 1);
}

void CopyShareUIMethod::selected(const ShareUI::ItemContainer * items)
{
    QString path("");
    if (items->count() == 1) { // can handle only one shared item
        ShareUI::SharedItem item = items->getItem(0);
        ShareUI::FileItem *fileItem = ShareUI::FileItem::toFileItem(item);
        ShareUI::DataUriItem *dataUriItem = ShareUI::DataUriItem::toDataUriItem(item);
        if (fileItem) { // it's a file
            path = fileItem->filePath();
        } else if (dataUriItem) { // it's a URL
            path = dataUriItem->dataUri().textData();
        }
    }
    QApplication::clipboard()->setText(path);
    // Give some time for the setText() call to talk to the X Server
    // and then emit done() to quit the share-ui app
    QTimer::singleShot(500, this, SIGNAL(done()));
}
