#ifndef SVG_LINE
#define SVG_LINE
#include "svg_shape.h"
class SvgLine : public SvgShape {
  public:
     SvgLine(double x1, double y1, double x2, double y2): _x1(x1),_x2(x2),_y1(y1),_y2(y2) {
     }
     std::string toSVG() const {
     return "<line x1=\"" + to_string(_x1) + "\" y1=\"" + to_string(_y1) +
            "\" x2=\"" + to_string(_x2) + "\" y2=\"" + to_string(_y2) + "\" stroke-width=\"" +
            to_string(getStrokeWidth())  + "\" stroke=\"" + getStrokeColor() + "\" fill=\"" +
            getFillColor() + "\"/>" ;
   }
  private:
     double _x1, _y1, _x2, _y2;
   };

#endif
