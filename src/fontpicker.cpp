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

#include "util.h"
#include "fontpicker.h"

#include <QFont>
#include <QFontDialog>

FontPicker::FontPicker(QWidget *parent) :
   QWidget(parent), ui(new Ui::FontPicker)
{
   ui->setupUi(this);
   setWindowTitle("Font Selector");

   QString fontname = ui->fontEdit->font().family();
   ui->label->setText("Sample Text Displayed in " + fontname);

   // missing two letters
   ui->fontEdit->setText("A wacky fox and sizeable pig jumped halfway over a blue moon.");

   connect(ui->selectFont_PB, &QPushButton::clicked, this, &FontPicker::setFont);
   connect(ui->closePB,       &QPushButton::clicked, this, &FontPicker::actionClose);
}

FontPicker::~FontPicker()
{
   delete ui;
}

void FontPicker::setFont()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont(ui->fontEdit->text()), this);

    if (ok) {
        ui->label->setText("Sample Text Displayed in " + font.family());

        ui->fontEdit->setFont(font);
        ui->fontEdit->setFocus();
        ui->fontEdit->setSelection(0,0);
    }
}

void FontPicker::actionClose() {
   this->parentWidget()->close();
}
