#pragma once

//#include "DynamicObject.h"
//
//class Plane : public DynamicObject {
//public:
//
//    void Draw() const override;
//
//    inline void ChangePlaneY(double dy) { yDirection += dy; }
//
//private:
//
//};

#include <iostream>

#include "Plane.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

#include "DynamicObject.h"

class Plane : public DynamicObject {
public:

    void Draw() const override 
    { 
        DrawBody();
        DrawWings();
        DrawTail();
    };

    inline void ChangePlaneY(double dy) { yDirection += dy; }

protected:

    virtual void DrawBody() const = 0;

    virtual void DrawWings() const = 0;

    virtual void DrawTail() const = 0;

};

