/* AntSnes
 *
 * Copyright (C) 2010 Summeli <summeli@summeli.fi>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef ANTSNESQT_H
#define ANTSNESQT_H

#include <QtGui/QMainWindow>
#include <QKeyEvent>
#include <QList>
#include <QtOpenGL/QGLWidget>

#include "ui_AntSnesQt.h"

#include "AntAudio.h"
#include "dpadwidget.h" 
#include "AntSettings.h"
#include "MEmulatorAdaptation.h"
#include "QRemoteControlKeys.h"

#include "dpadwidget.h"
#include "buttonwidget.h"
#include "middlebuttons.h"
#include "icontrolpadclient.h"

class QSnesController;

class AntSnesQt : public QWidget, MEmulatorAdaptation
{
    Q_OBJECT

public:
    AntSnesQt( QWidget *parent = 0 );
    ~AntSnesQt();

public:
    void setRemoteControl( QRemoteControlKeys* remote, iControlPadClient* client );
    void keyPressEvent( QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent* event);
    bool event(QEvent *event);

//rendering stuff
public slots:
    void saveStateImage( QString rom, int state );
    void render(int width, int height);

protected:
    void paintEvent(QPaintEvent *);

public: //From MEmulatorAdaptation
    quint32 getSnesKeys();

public:
    void LoadROM(QString rom, TAntSettings antSettings);
    void LoadState( int state );
    void SaveState( int state );
    void reset();
    void continueGame();
    
signals:
    void Start();
    void Stop();
    void doLoadROM(QString rom, TAntSettings antSettings);
    void showmenu();
    
public slots:
    void showAntSnesMenu();
    void updateSettings( TAntSettings );
    void virtualKeyEvent( quint32 aKey, bool isDown );

private slots:
    void listencontrols();

private:
    void LoadButtons();
    void ApplyTransparency(QPixmap &pm, QString png);

private:
    //Ui::AntSnesQtClass ui;
    //QGLBlitterWidget* widget;
    CAntAudio* antaudio;
    QSnesController* control;
    
    TAntSettings iAntSettings;
    QList<antKeyEvent> iPressedKeys;
    QRemoteControlKeys* remotecontrol;
    iControlPadClient* cpClient;
    DPadWidget* dpad;
    buttonwidget* buttons;
    MiddleButtons* middlebutton;

    quint32 iSnesKeys;
    quint32 iHardKeys;

    //drawing
    QImage* buf;
    TUint8* bitmapdata;
    QPixmap dpad_graphics;
    QPixmap buttons_graphics;
    QPixmap tl_graphics;
    QPixmap tr_graphics;
    QPixmap menu_graphics;
    int buttonOpacity;
    int stretch;

};

#endif // ANTSNESQT_H
