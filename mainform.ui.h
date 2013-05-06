/*
Copyright (C) 2004-2005 Kolian^Spöntz

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/

/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you wish to add, delete or rename functions or slots use
** Qt Designer which will update this file, preserving your code. Create an
** init() function in place of a constructor, and a destroy() function in
** place of a destructor.
*****************************************************************************/

#include <qapplication.h>
#include <qfiledialog.h>
#include <qcolordialog.h>

// ******************************************************************

void MainForm::init() {

	// disable UI
	layerFrame->setEnabled(false);
	currentGroup->setEnabled(false);

	// disable menu actions
	fileOpenLayersAction->setEnabled(false);
	fileSaveLayersAction->setEnabled(false);
	fileExportAction->setEnabled(false);
	toolsObject_InformationAction->setEnabled(false);
	toolsView_InformationAction->setEnabled(false);
	toolsOrigin_DisplayAction->setEnabled(false);
	toolsOrigin_RotateAction->setEnabled(false);
	toolsBench_Action->setEnabled(false);

	// toggle actions
	toolsOrigin_DisplayAction->setToggleAction(true);
	toolsOrigin_RotateAction->setToggleAction(true);
}

// ******************************************************************

void MainForm::openObject() {

	// select file
	QString s = QFileDialog::getOpenFileName("",
					"All files (*.3ds *.lwo);;3DStudio files (*.3ds);;LightWave files (*.lwo)",
					this, "open file dialog");
	if (s.isNull()) return;

	// load file
	if (!Viewport->loadObject(s)) return;

	// enable controls and update
	enableControls();
}

// ******************************************************************

void MainForm::enableControls() {

	// enable menu actions
	fileOpenLayersAction->setEnabled(true);
	fileSaveLayersAction->setEnabled(true);
	fileExportAction->setEnabled(true);
	toolsObject_InformationAction->setEnabled(true);
	toolsView_InformationAction->setEnabled(true);
	toolsOrigin_DisplayAction->setEnabled(true);
	toolsOrigin_RotateAction->setEnabled(true);
	toolsBench_Action->setEnabled(true);

	// enable UI
	layerFrame->setEnabled(true);
	if (layerList->currentItem() == -1) layerList->setSelected(0, true);
	currentGroup->setEnabled(true);

	// update viewport
	Viewport->update();
}

// ******************************************************************

void MainForm::loadLayers() {

	// select file
	QString s = QFileDialog::getOpenFileName("",
					"Layers files (*.layer)",
					this, "open file dialog");
	if (s.isNull()) return;

	// load layers
	Viewport->setUpdates(false);
	Viewport->loadLayers(s);

	// update listbox
	layerList->clear();
	for (int i=0; i<Viewport->getLayerCount(); i++) {
		layerList->insertItem(Viewport->getName(i), -1);
	}
	layerList->setSelected(0, true);
	layerList->ensureCurrentVisible();

	// enable remove button
	if ((layerList->count() > 1) && (!removeLayerButton->isEnabled())) {
		removeLayerButton->setEnabled(true);
	}

	// update viewport
	Viewport->setUpdates(true);
	Viewport->update();
}

// ******************************************************************

void MainForm::saveLayers() {

	// select file
	QString s = QFileDialog::getSaveFileName("",
					"Layers files (*.layer)",
					this, "save file dialog");
	if (s.isNull()) return;

	// save layers
	Viewport->saveLayers(s);
}

// ******************************************************************

void MainForm::exportLayers() {

	// export layers to engine
	Viewport->exportLayers();

	// display successful message
	QString text = "Export files have been generated";
	QMessageBox::information(this,"Spöntz",text,
			QMessageBox::Ok,QMessageBox::NoButton,QMessageBox::NoButton);
}

// ******************************************************************

void MainForm::setBackgroundColor() {

	// select color
	QColor color = QColorDialog::getColor(Viewport->getBackgroundColor(),
						this, "choose color dialog");
	if (!color.isValid()) return;

	// change viewport background color
	Viewport->setBackgroundColor(color);
	Viewport->update();
}

// ******************************************************************

void MainForm::openglInfo() {

	QMessageBox::information(this,"OpenGL Info",Viewport->getExtensionsInfo(),
			QMessageBox::Ok,QMessageBox::NoButton,QMessageBox::NoButton);
}

// ******************************************************************

void MainForm::objectInfo() {

	bool warn;
	QString msg = Viewport->getInfo(&warn);

	if (warn) {
		QMessageBox::warning(this,"Object Info",msg,
			QMessageBox::Ok,QMessageBox::NoButton,QMessageBox::NoButton);
	}
	else {
		QMessageBox::information(this,"Object Info",msg,
			QMessageBox::Ok,QMessageBox::NoButton,QMessageBox::NoButton);
	}
}

// ******************************************************************

void MainForm::viewInfo() {

	QMessageBox::information(this,"View Info",Viewport->getViewInfo(),
			QMessageBox::Ok,QMessageBox::NoButton,QMessageBox::NoButton);
}

// ******************************************************************

void MainForm::toggleDisplayOrigins(bool value) {

	Viewport->toggleDisplayOrigins(value);
	Viewport->update();
}

// ******************************************************************

void MainForm::toggleRotateOrigin(bool value) {

	Viewport->toggleRotateOrigin(value);
	Viewport->update();
}

// ******************************************************************

void MainForm::benchmark() {

	QApplication::setOverrideCursor(Qt::waitCursor);
	float fps = Viewport->benchmark();
	QApplication::restoreOverrideCursor();

	QMessageBox::information(this,"Benchmark",QString("%1 frames per second").arg((int) fps),
			QMessageBox::Ok,QMessageBox::NoButton,QMessageBox::NoButton);

	Viewport->update();
}

// ******************************************************************

void MainForm::aboutDialog() {

	QString text = "Spöntz Layers Editor\n(c) 2004-2005 Kolian\n\nkolian@spontz.org";
	QMessageBox::information(this,"Spöntz",text,
			QMessageBox::Ok,QMessageBox::NoButton,QMessageBox::NoButton);
}

// ******************************************************************

void MainForm::changeLayer() {

	int layer = layerList->currentItem();

	Viewport->setUpdates(false);

	layerName->setText(Viewport->getName(layer));
	disabledCheck->setChecked(Viewport->getDisabled(layer));

	srcBlend->setCurrentItem(Viewport->getSrcBlend(layer));
	dstBlend->setCurrentItem(Viewport->getDstBlend(layer));

	QRgb color = Viewport->getColor(layer);
	red->setValue(qRed(color));
	green->setValue(qGreen(color));
	blue->setValue(qBlue(color));
	alpha->setValue(qAlpha(color));
	colorPixmap->setPaletteBackgroundColor(color);
	alphaPixmap->setPaletteBackgroundColor(QColor(qAlpha(color), qAlpha(color), qAlpha(color)));

	effectWidget->setCurrentPage(Viewport->getEffectMode(layer));

	renderMode->setCurrentItem(Viewport->getRenderMode(layer));
	width->setValue(Viewport->getWidth(layer));
	smooth->setChecked(Viewport->getSmooth(layer));
	cull->setCurrentItem(Viewport->getCull(layer));
	texturePixmap->setPixmap(QPixmap(Viewport->getTexture(layer)));

	filterMode->setCurrentItem(Viewport->getFilterMode(layer));
	radius->setValue(Viewport->getRadius(layer));
	accum->setValue(Viewport->getAccum(layer));
	accum2->setValue(Viewport->getAccum2(layer));
	recursive->setChecked(Viewport->getRecursive(layer));

	Viewport->setUpdates(true);
}

// ******************************************************************

void MainForm::addLayer() {

	// get an automatic new layer name
	QString name = QString("Layer %1").arg(Viewport->getLayerCount()+1);

	if (!Viewport->addLayer(name)) return;
	Viewport->setUpdates(false);

	layerList->insertItem(name, -1);
	layerList->setSelected(layerList->count()-1, true);
	layerList->ensureCurrentVisible();

	// enable remove button
	if ((layerList->count() > 1) && (!removeLayerButton->isEnabled())) {
		removeLayerButton->setEnabled(true);
	}

	// update viewport
	Viewport->setUpdates(true);
	Viewport->update();
}

// ******************************************************************

void MainForm::removeLayer() {

	int item = layerList->currentItem();

	Viewport->setUpdates(false);
	Viewport->removeLayer(item);

	layerList->removeItem(item);
	if (item >= (int) layerList->count()) item--;
	layerList->setSelected(item, true);
	layerList->ensureCurrentVisible();

	// disable remove button
	if (layerList->count() == 1) removeLayerButton->setEnabled(false);

	// update viewport
	Viewport->setUpdates(true);
	Viewport->update();
}

// ******************************************************************

void MainForm::upLayer() {

	// if it's the first element do nothing
	int item = layerList->currentItem();
	if (item == 0) return;

	// up layer
	Viewport->setUpdates(false);
	Viewport->upLayer(item);

	// up layer in listbox
	QString s = layerList->text(item);
	layerList->removeItem(item);
	layerList->insertItem(s, item-1);
	layerList->setSelected(item-1, true);
	layerList->ensureCurrentVisible();

	// update viewport
	Viewport->setUpdates(true);
	Viewport->update();
}

// ******************************************************************

void MainForm::downLayer() {

	// if it's the last element do nothing
	int item = layerList->currentItem();
	if (item == (int) layerList->count()-1) return;

	// down layer
	Viewport->setUpdates(false);
	Viewport->downLayer(item);

	// down layer in listbox
	QString s = layerList->text(item);
	layerList->removeItem(item);
	layerList->insertItem(s, item+1);
	layerList->setSelected(item+1, true);
	layerList->ensureCurrentVisible();

	// update viewport
	Viewport->setUpdates(true);
	Viewport->update();
}

// ******************************************************************

void MainForm::setLayerName() {

	QString text = layerName->text();
	int item = layerList->currentItem();

	Viewport->setUpdates(false);
	Viewport->setName(item, text);

	if (item == 0) {
		layerList->insertItem(text, 1);
		layerList->removeItem(0);
		layerList->setSelected(0, true);
	}
	else layerList->changeItem(text, item);

	Viewport->setUpdates(true);
}

// ******************************************************************

void MainForm::setLayerDisabled(bool flag) {

	Viewport->setDisabled(layerList->currentItem(), flag);
	Viewport->update();
}

// ******************************************************************

void MainForm::setSrcBlend(int mode) {

	Viewport->setSrcBlend(layerList->currentItem(), mode);
	Viewport->update();
}

// ******************************************************************

void MainForm::setDstBlend(int mode) {

	Viewport->setDstBlend(layerList->currentItem(), mode);
	Viewport->update();
}

// ******************************************************************

void MainForm::setRed(int color) {

	Viewport->setRed(layerList->currentItem(), color);
	colorPixmap->setPaletteBackgroundColor(Viewport->getColor(layerList->currentItem()));
	Viewport->update();
}

// ******************************************************************

void MainForm::setGreen(int color) {

	Viewport->setGreen(layerList->currentItem(), color);
	colorPixmap->setPaletteBackgroundColor(Viewport->getColor(layerList->currentItem()));
	Viewport->update();
}

// ******************************************************************

void MainForm::setBlue(int color) {

	Viewport->setBlue(layerList->currentItem(), color);
	colorPixmap->setPaletteBackgroundColor(Viewport->getColor(layerList->currentItem()));
	Viewport->update();
}

// ******************************************************************

void MainForm::setAlpha(int color) {

	Viewport->setAlpha(layerList->currentItem(), color);
	alphaPixmap->setPaletteBackgroundColor(QColor(color, color, color));
	Viewport->update();
}

// ******************************************************************

void MainForm::setColor() {

	// select color dialog
	bool ok;
	QRgb color = QColorDialog::getRgba(Viewport->getColor(layerList->currentItem()), &ok, this, "choose color dialog");
	if (!ok) return;

	// change viewport color
	red->setValue(qRed(color));
	green->setValue(qGreen(color));
	blue->setValue(qBlue(color));
	alpha->setValue(qAlpha(color));
	colorPixmap->setPaletteBackgroundColor(color);
	alphaPixmap->setPaletteBackgroundColor(QColor(qAlpha(color), qAlpha(color), qAlpha(color)));

	Viewport->setColor(layerList->currentItem(), color);
	Viewport->update();
}

// ******************************************************************

void MainForm::setEffectMode() {

	int layer = layerList->currentItem();
	if (layer == -1) return;

	Viewport->setEffectMode(layer, effectWidget->currentPageIndex());
	Viewport->update();
}

// ******************************************************************

void MainForm::setRenderMode(int mode) {

	Viewport->setRenderMode(layerList->currentItem(), mode);
	Viewport->update();
}

// ******************************************************************

void MainForm::setWidth(int width) {

	Viewport->setWidth(layerList->currentItem(), width);
	Viewport->update();
}

// ******************************************************************

void MainForm::setSmooth(bool flag) {

	Viewport->setSmooth(layerList->currentItem(), flag);
	Viewport->update();
}

// ******************************************************************

void MainForm::setCull(int mode) {

	Viewport->setCull(layerList->currentItem(), mode);
	Viewport->update();
}

// ******************************************************************

void MainForm::openTexture() {

	// select file
	QString s = QFileDialog::getOpenFileName("",
					"Image files (*.jpg *.png);;JPEG files (*.jpg);;PNG files (*.png)",
					this, "open file dialog");
	if (s.isNull()) return;

	// load file
	QImage tex = QImage(s, 0);
	if (tex.isNull()) return;

	texturePixmap->setPixmap(QPixmap(tex));
	Viewport->loadTexture(layerList->currentItem(), tex, s);
	Viewport->update();
}

// ******************************************************************

void MainForm::setFilterMode(int mode) {

	Viewport->setFilterMode(layerList->currentItem(), mode);
	Viewport->update();
}

// ******************************************************************

void MainForm::setRadius(int radius) {

	Viewport->setRadius(layerList->currentItem(), radius);
	Viewport->update();
}

// ******************************************************************

void MainForm::setAccum(int accum) {

	Viewport->setAccum(layerList->currentItem(), accum);
	Viewport->update();
}

// ******************************************************************

void MainForm::setAccum2(int accum) {

	Viewport->setAccum2(layerList->currentItem(), accum);
	Viewport->update();
}

// ******************************************************************

void MainForm::setRecursive(bool flag) {

	Viewport->setRecursive(layerList->currentItem(), flag);
	Viewport->update();
}
