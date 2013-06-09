// copyshareuiplugin.cpp

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

#include "copyshareuiplugin.h"
#include "copyshareuimethod.h"
#include <QtPlugin>

QList<ShareUI::MethodBase*> CopyShareUIPlugin::methods(QObject *parent)
{
    QList<ShareUI::MethodBase*> methods;
    methods << new CopyShareUIMethod(parent);
    return methods;
}

// Make this class available as a Qt Plugin
Q_EXPORT_PLUGIN2(copy-share-ui-plugin, CopyShareUIPlugin)
