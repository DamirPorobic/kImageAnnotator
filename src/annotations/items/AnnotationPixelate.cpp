/*
 * Copyright (C) 2020 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
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

#include "AnnotationPixelate.h"

namespace kImageAnnotator {

AnnotationPixelate::AnnotationPixelate(const QPointF &startPosition, const ObfuscatePropertiesPtr &properties) :
	AbstractAnnotationObfuscate(startPosition, properties)
{

}

AnnotationPixelate::AnnotationPixelate(const AnnotationPixelate &other) : AbstractAnnotationObfuscate(other)
{

}

Tools AnnotationPixelate::toolType() const
{
	return Tools::Pixelate;
}

QImage AnnotationPixelate::obfuscateBackground(const QImage &sceneBehindItem) const
{
    auto result = sceneBehindItem.convertToFormat( QImage::Format_ARGB32_Premultiplied );
    auto factor = obfuscateProperties()->factor();

    int width  = sceneBehindItem.width() * (0.5 / qMax(1, factor));
    int height = sceneBehindItem.height() * (0.5 / qMax(1, factor));
    QSize size  = QSize(qMax(width, 1), qMax(height, 1));

    result = result.scaled(size, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    result = result.scaled(sceneBehindItem.width(), sceneBehindItem.height());

	return result;
}

} // namespace kImageAnnotator
