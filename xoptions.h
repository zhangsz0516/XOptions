// Copyright (c) 2020 hors<horsicq@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#ifndef XOPTIONS_H
#define XOPTIONS_H

#include <QObject>
#include <QMap>
#include <QDir>
#include <QSettings>
#include <QTranslator>
#ifdef QT_GUI_LIB
#include <QWidget>
#include <QCheckBox>
#include <QComboBox>
#include <QLineEdit>
#include <QApplication>
#include <QStyleFactory>
#else
#include <QCoreApplication>
#endif

class XOptions : public QObject
{
    Q_OBJECT

public:
    enum ID
    {
        ID_STAYONTOP=0,
        ID_SCANAFTEROPEN,
        ID_SAVELASTDIRECTORY,
        ID_LASTDIRECTORY,
        ID_SAVEBACKUP,
        ID_STYLE,
        ID_QSS,
        ID_LANG,
        ID_DBPATH,
        ID_INFOPATH,
        ID_SCANENGINE,
        ID_ROOTPATH,
        ID_DATAPATH,
        ID_JSON
    };

    explicit XOptions(QObject *pParent=nullptr);
    void setName(QString sName);
    void setValueIDs(QList<ID> listValueIDs);
    void setDefaultValues(QMap<ID,QVariant> mapDefaultValues);
    void load();
    void save();
    QVariant getValue(ID id);
    void setValue(ID id,QVariant vValue);
    static QString idToString(ID id);
    QString getLastDirectory();
    void setLastDirectory(QString sValue);
    QString getDbPath();
    QString getInfoPath();
    QString getScanEngine();
    QString getRootPath();
    QString getDataPath();
    QString getJson();
    bool isSaveBackup();
    bool isSaveLastDirectory();
    bool isRestartNeeded();
    bool isScanAfterOpen();
    static QString getApplicationLangPath();
    static QString getApplicationQssPath();
    static QList<QString> getAllFilesFromDirectory(QString sDirectory,QString sExtension);
    static QString getApplicationDataPath();
#ifdef QT_GUI_LIB
    void setCheckBox(QCheckBox *pCheckBox,ID id);
    void getCheckBox(QCheckBox *pCheckBox,ID id);
    void setComboBox(QComboBox *pComboBox,ID id);
    void getComboBox(QComboBox *pComboBox,ID id);
    void setLineEdit(QLineEdit *pLineEdit,ID id);
    void getLineEdit(QLineEdit *pLineEdit,ID id);
    void adjustStayOnTop(QWidget *pWidget);
    void static setMonoFont(QWidget *pWidget);
    static void adjustApplicationView(QString sOptionFileName,QString sTranslationName);
#endif
#ifdef WIN32
    bool registerContext(QString sApplicationName,QString sType,QString sApplicationFilePath);
    bool clearContext(QString sApplicationName,QString sType);
    bool checkContext(QString sApplicationName,QString sType);
#endif

signals:
    void errorMessage(QString sText);

private:
    QString sName;
    QString sFilePath;
    QList<ID> listValueIDs;
    QMap<ID,QVariant> mapValues;
    QMap<ID,QVariant> mapDefaultValues;
    bool bIsRestartNeeded;
};

#endif // XOPTIONS_H
