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

#ifndef VIEWCONTROLLER_H_
#define VIEWCONTROLLER_H_

#include <QtGui/QMainWindow>
#include <QObject>
#include <QString>

//#include "settingsview.h"
#include "antsnesqt.h"
#include "emusettings.h"

#ifdef __SYMBIAN32__
#include "QRemoteControlKeys.h"
#endif
class ViewController : public QObject
{
    Q_OBJECT
public:
    ViewController();
    ~ViewController();

public slots:
    void loadROM( QString rom, TAntSettings antSettings );
    void showSettings();
    void LoadState( int state );
    void SaveState( int state );
    void reset();
    void continueGame();
    
private:
    AntSnesQt* emuView;
    EmuSettings* settingsView;
    
#ifdef Q_OS_SYMBIAN
    qint32 iMenuKeyHandle;
    qint32 iNoKeyHandle;
    qint32 iNoKeyHandle2;
    qint32 iMenuKeyHandle2;
    qint32 iCameraKeyHandle;
    QRemoteControlKeys* remotekeys;
#endif
    
    
};
#endif /* VIEWCONTROLLER_H_ */
