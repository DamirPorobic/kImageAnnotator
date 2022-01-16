/*
 * Copyright (C) 2022 Damir Porobic <damir.porobic@gmx.com>
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

#ifndef KIMAGEANNOTATOR_CUTOUTCOMMAND_H
#define KIMAGEANNOTATOR_CUTOUTCOMMAND_H

#include <QUndoCommand>
#include <QPainter>

#include "src/annotations/core/AnnotationArea.h"

namespace kImageAnnotator {

class CutOutCommand : public QUndoCommand
{
public:
	CutOutCommand(QGraphicsPixmapItem *backgroundImage, const QRectF &cutOutRect, AnnotationArea *annotationArea);
	~CutOutCommand() override = default;
	void undo() override;
	void redo() override;

private:
	AnnotationArea *mAnnotationArea;
	QPixmap mOriginalImage;
	QPixmap mCutOutImage;
	QGraphicsPixmapItem *mBackgroundImage;

	bool isVerticalCut(const QRectF &cutOutRect, const QRectF &imageRect) const;
	void createCutOutImage(const QRectF &imageRect, const QPointF &bottomRightRect1, const QPointF &topLeftRect2, const QPointF &connectionPoint);
};

} // namespace kImageAnnotator

#endif //KIMAGEANNOTATOR_CUTOUTCOMMAND_H