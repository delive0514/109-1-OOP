#ifndef SVG_POLYGON
#define SVG_POLYGON
#include "svg_shape.h"
class SvgPolygon : public SvgShape {
  public:
    SvgPolygon(std::vector<double *> const & v): _v(v){
   }
    std::string toSVG() const {
      string result="";
      result += "<polygon points=\"";
      for(int i = 0; i < _v.size() ; i++){
        result += to_string(_v[i][0]);
        result += ' ';
        result += to_string(_v[i][1]);
        if(i<_v.size()-1){
          result += ' ';
        }
      }
      result +=  "\" stroke-width=\"" + to_string(getStrokeWidth()) + "\" stroke=\""
       + getStrokeColor() + "\" fill=\""  + getFillColor() + "\"/>";
      return result;
     }
  private:
    std::vector<double *> _v;
};

#endif
