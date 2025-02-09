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

#include "ScaledSizeProvider.h"

namespace kImageAnnotator {

int ScaledSizeProvider::scaledWidth(int width)
{
	return (int)(width * scaleFactor());
}

QSize ScaledSizeProvider::scaledSize(const QSize &size)
{
	return size * scaleFactor();
}

QSize ScaledSizeProvider::settingsWidgetIconSize()
{
	return scaledSize(Constants::SettingsWidgetIconSize);
}

QSize ScaledSizeProvider::menuItemIconSize()
{
	return scaledSize(Constants::MenuItemIconSize);
}

int ScaledSizeProvider::resizeHandleSize()
{
	return scaledWidth(Constants::ResizeHandleSize);
}

qreal ScaledSizeProvider::scaleFactor()
{
	static auto scaleFactor = getScaleFactor();
	return scaleFactor;
}

qreal ScaledSizeProvider::getScaleFactor()
{
#if defined(__linux__)
	if(isGnomeEnvironment()) {
		auto screen = QApplication::primaryScreen();
		auto logicalDotsPerInch = (int) screen->logicalDotsPerInch();
		auto physicalDotsPerInch = (int) screen->physicalDotsPerInch();
		return (qreal)logicalDotsPerInch / (qreal)physicalDotsPerInch;
	}
#endif

	return 1;
}

#if defined(__linux__)
bool ScaledSizeProvider::isGnomeEnvironment()
{
	auto currentDesktop = QString(qgetenv("XDG_CURRENT_DESKTOP"));
	return currentDesktop.contains(QLatin1String("gnome"), Qt::CaseInsensitive)
		|| currentDesktop.contains(QLatin1String("unity"), Qt::CaseInsensitive);
}
#endif

} // namespace kImageAnnotator
