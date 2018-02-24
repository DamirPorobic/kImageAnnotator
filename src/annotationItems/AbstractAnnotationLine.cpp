/*
 * Copyright (C) 2018 Damir Porobic <damir.porobic@gmx.com>
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

#include "AbstractAnnotationLine.h"

AbstractAnnotationLine::AbstractAnnotationLine(const QPointF& startPosisition, const AnnotationItemProperties& properties) :
    AbstractAnnotationItem(properties)
{
    mLine = new QLineF();
    mLine->setP1(startPosisition);
}

AbstractAnnotationLine::~AbstractAnnotationLine()
{
    delete mLine;
}

void AbstractAnnotationLine::addPoint(const QPointF& position)
{
    prepareGeometryChange();
    mLine->setP2(position);
    updateShape();
}

void AbstractAnnotationLine::moveTo(const QPointF& newPosition)
{
    prepareGeometryChange();
    mLine->translate(newPosition - boundingRect().topLeft());
    updateShape();
}

QLineF AbstractAnnotationLine::line() const
{
    return *mLine;
}

void AbstractAnnotationLine::setLine(const QLineF& line)
{
    prepareGeometryChange();
    mLine->setP1(line.p1());
    mLine->setP2(line.p2());
    updateShape();
}

void AbstractAnnotationLine::setP1(const QPointF& point)
{
    prepareGeometryChange();
    mLine->setP1(point);
    updateShape();
}

void AbstractAnnotationLine::setP2(const QPointF& point)
{
    prepareGeometryChange();
    mLine->setP2(point);
    updateShape();
}


