/*
 * Copyright (C) 2021 Damir Porobic <damir.porobic@gmx.com>
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

#ifndef KIMAGEANNOTATOR_SCALEDSIZEPROVIDER_H
#define KIMAGEANNOTATOR_SCALEDSIZEPROVIDER_H

#include <QSize>

#if defined(__linux__)
#include <QApplication>
#include <QScreen>

#include "src/common/helper/DesktopEnvironmentChecker.h"
#endif

#include "src/common/constants/Constants.h"

namespace kImageAnnotator {

class ScaledSizeProvider
{
public:
	static int scaledWidth(int width);
	static QSize scaledSize(const QSize &size);
	static QSize settingsWidgetIconSize();
	static QSize menuItemIconSize();
	static int resizeHandleSize();

private:
	static qreal scaleFactor();
	static qreal getScaleFactor();

#if defined(__linux__)
	static bool isGnomeEnvironment();
#endif

	ScaledSizeProvider() = default;
	~ScaledSizeProvider() = default;
};

} // namespace kImageAnnotator

#endif //KIMAGEANNOTATOR_SCALEDSIZEPROVIDER_H
