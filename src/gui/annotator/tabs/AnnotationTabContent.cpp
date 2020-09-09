/*
 * Copyright (C) 2020 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "AnnotationTabContent.h"

namespace kImageAnnotator {

AnnotationTabContent::AnnotationTabContent(const QPixmap &pixmap, Config *config, AbstractSettingsProvider *settingsProvider) :
	mAnnotationView(new AnnotationView(this)),
	mAnnotationArea(new AnnotationArea(config, settingsProvider, new DevicePixelRatioScaler, mAnnotationView->camera())),
	mMainLayout(new QHBoxLayout(this))
{
	mAnnotationView->setScene(mAnnotationArea);
	mAnnotationArea->loadImage(pixmap);
	mMainLayout->addWidget(mAnnotationView);
	setLayout(mMainLayout);
}

AnnotationTabContent::~AnnotationTabContent()
{
	delete mMainLayout;
	delete mAnnotationArea;
	delete mAnnotationView;
}

AnnotationArea* AnnotationTabContent::annotationArea() const
{
	return mAnnotationArea;
}

} // namespace kImageAnnotator