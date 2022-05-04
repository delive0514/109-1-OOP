#ifndef SVG_SHAPE
#define SVG_SHAPE
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class SvgShape {
  public:
      SvgShape(){
        setStroke(0,"black");
        setFillColor("black");
      }
      void setFillColor(std::string fillColor) {
        _fillColor = fillColor ;
      }
      void setStroke(double strokeWidth, std::string strokeColor) {
        _strokeColor = strokeColor;
        _strokeWidth = strokeWidth;
      }
      virtual std::string toSVG() const = 0;
      virtual ~SvgShape(){

      }
  protected:
    double getStrokeWidth() const{
      return _strokeWidth;
    }
    string getFillColor() const{
      return _fillColor;
    }
    string getStrokeColor()const{
      return _strokeColor;
    }
  private:
    double _strokeWidth;
    std::string _fillColor, _strokeColor;
  };
void setSvgShapeStyle(SvgShape * shape, double strokeWidth, std::string strokeColor, std::string fillColor){
  shape->setStroke(strokeWidth, strokeColor);
  shape->setFillColor(fillColor);
}
std::string makeSvgOutput(int width, int height, std::vector<SvgShape *> const & shape){
string s = "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\""+ to_string(width) +"\" height=\""+ to_string(height) +"\" viewBox=\"0 0 100 100\">";
for(int i = 0; i<shape.size() ; i++){
  s+= shape[i]->toSVG();
}
s += "</svg>";

return s;

}

#endif
