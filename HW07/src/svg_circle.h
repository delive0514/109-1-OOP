#ifndef SVG_CIRCLE
#define SVG_CIRCLE
#include "svg_shape.h"
class SvgCircle : public SvgShape {
  public:
      SvgCircle(double x, double y, double r): _x(x),_y(y),_r(r){
      }
      std::string toSVG() const {
      return "<circle cx=\"" + to_string(_x) + "\" cy=\"" + to_string(_y) + "\" r=\"" + to_string(_r) +
             "\" stroke-width=\"" +  to_string(getStrokeWidth()) +
             "\" stroke=\"" + getStrokeColor() +
             "\" fill=\"" + getFillColor() +"\"/>" ; }
    private:
        double _x, _y, _r;
    };
#endif
