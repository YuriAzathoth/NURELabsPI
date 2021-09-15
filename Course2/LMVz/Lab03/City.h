/***************************************************************
 * Name:      City.h
 * Purpose:   Defines Geo Objects
 * Author:    ёрий «инченко (asmodeus.x5@outlook.com)
 * Created:   2018-12-1
 * Copyright: ёрий «инченко (2018)
 * License:   GPLv3
 **************************************************************/

#pragma once
#ifndef CITY_H
#define CITY_H

#include "IShape.h"
#include "ISpline.h"

#define COLOR_BORDER_CITY wxColour(200, 100, 0)
#define COLOR_FILL_CITY wxColour(255, 255, 100)
#define COLOR_BORDER_VILLAGE wxColour(200, 100, 0)
#define COLOR_FILL_VILLAGE wxColour(255, 255, 150)
#define COLOR_BORDER_FOREST wxColour(0, 150, 0)
#define COLOR_FILL_FOREST wxColour(0, 200, 0)
#define COLOR_BORDER_WOOD wxColour(25, 150, 25)
#define COLOR_FILL_WOOD wxColour(50, 200, 50)
#define COLOR_BORDER_SEA wxColour(50, 50, 200)
#define COLOR_FILL_SEA wxColour(75, 75, 255)
#define COLOR_ROAD wxColour(100, 100, 100)
#define COLOR_RAIL wxColour(20, 20, 20)
#define COLOR_RIVER COLOR_BORDER_SEA

#define CREATE_DERIVED_CLASS(base, name, border, fill, classname) \
class name : public base { public: \
	name(const wxPointList &rVertexList, const wxString &rwsName) : base(	rVertexList, border, fill, rwsName, classname) {}; \
	name(const name& other) : base(other.m_Vertexes, border, fill, other.m_wsName, other.m_szClassName) {}; };
#define CREATE_DERIVED_SHAPE_CLASS(name, border, fill, classname) CREATE_DERIVED_CLASS(IShape, name, border, fill, classname)
#define CREATE_DERIVED_SPLINE_CLASS(name, border, classname) CREATE_DERIVED_CLASS(ISpline, name, border, wxColour(0, 0, 0), classname)

CREATE_DERIVED_SHAPE_CLASS(City, COLOR_BORDER_CITY, COLOR_FILL_CITY, "city")
CREATE_DERIVED_SHAPE_CLASS(Village, COLOR_BORDER_VILLAGE, COLOR_FILL_VILLAGE, "village")
CREATE_DERIVED_SHAPE_CLASS(Forest, COLOR_BORDER_FOREST, COLOR_FILL_FOREST, "forest")
CREATE_DERIVED_SHAPE_CLASS(Wood, COLOR_BORDER_WOOD, COLOR_FILL_WOOD, "wood")
CREATE_DERIVED_SHAPE_CLASS(Sea, COLOR_BORDER_SEA, COLOR_FILL_SEA, "sea")
CREATE_DERIVED_SPLINE_CLASS(Road, COLOR_ROAD, "road")
CREATE_DERIVED_SPLINE_CLASS(Rail, COLOR_RAIL, "rail")
CREATE_DERIVED_SPLINE_CLASS(River, COLOR_RIVER, "river")

#endif // CITY_H
