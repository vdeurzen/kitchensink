/**********************************************************************
*
* Copyright (c) 2012-2019 Barbara Geller
* Copyright (C) 2015 The Qt Company Ltd.
*
* You may use this file under the terms of the 2-Clause BSD license
* provided with KitchenSink or available at:
*
* https://opensource.org/licenses/BSD-2-Clause
*
* KitchenSink is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
***********************************************************************/

#ifndef SYSTRAY_H
#define SYSTRAY_H

#include <QAction>
#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QLabel>
#include <QDialog>
#include <QSystemTrayIcon>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>
#include <QSpinBox>
#include <QTextEdit>

class SysTray : public QDialog
{
   CS_OBJECT(SysTray)

   public:
      SysTray();
      void setVisible(bool visible);

   protected:
      void closeEvent(QCloseEvent *event);

   private:
      void createIconGroupBox();
      void createMessageGroupBox();
      void createActions();
      void createTrayIcon();

      void iconActivated(QSystemTrayIcon::ActivationReason reason);
      void messageClicked();
      void showMessage();
      void setIcon(int index);

      CS_SLOT_1(Private, void actionQuit())
      CS_SLOT_2(actionQuit)

      QGroupBox *iconGroupBox;
      QLabel *iconLabel;
      QComboBox *iconComboBox;
      QCheckBox *showIconCheckBox;

      QGroupBox *messageGroupBox;
      QLabel *typeLabel;
      QLabel *durationLabel;
      QLabel *durationWarningLabel;
      QLabel *titleLabel;
      QLabel *bodyLabel;
      QComboBox *typeComboBox;
      QSpinBox *durationSpinBox;
      QLineEdit *titleEdit;
      QTextEdit *bodyEdit;
      QPushButton *showMessageButton;

      QAction *minimizeAction;
      QAction *maximizeAction;
      QAction *restoreAction;
      QAction *quitAction;
      bool m_quitNow;

      QSystemTrayIcon *trayIcon;
      QMenu *trayIconMenu;
};

#endif
