#include "../src/vector.h"
#include "../src/bubble_sort.h"
#include "../src/polygon.h"
#include "../src/circle.h"
#include "../src/shape.h"

double const epsilon = 0.0001;
TEST(ShapeTest, Polygon)
{
  double a[] = {-1, 2};
  double c[] = {1, 0};
  double d[] = {1, 4};
  double e[] = {4, 0};
  double b[] = {4, 4};
  double f[] = {6, 2};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector w(c, 2);
  Vector x(d, 2);
  Vector y(e, 2);
  Vector z(f, 2);
  Vector arr[] = {u, v, w, x, y, z};
  Polygon *poly = new Polygon(arr, 6);
  ASSERT_NEAR(20, poly->area(), epsilon);
  ASSERT_NEAR(6 + 4 * sqrt(8), poly->perimeter(), epsilon);
}
TEST(ShapeTest, Circle)
{
  Circle *c = new Circle(5);
  ASSERT_NEAR(25 * M_PI, c->area(), epsilon);
  ASSERT_NEAR(10 * M_PI, c->perimeter(), epsilon);
}
TEST(ShapeTest, Shape)
{
  Shape *c = new Circle(5);
  ASSERT_NEAR(25 * M_PI, c->area(), epsilon);
  double a[] = {0, 0};
  double b[] = {0, 3};
  double d[] = {3, 0};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector w(d, 2);
  Vector arr[] = {u, v, w};
  Shape *poly = new Polygon(arr, 3);
  ASSERT_NEAR(4.5, poly->area(), epsilon);
  ASSERT_NEAR(10.2426, poly->perimeter(), epsilon);
}
TEST(FindTest, FindAll)
{
  double a[] = {-1, 2};
  double b[] = {4, 4};
  double c[] = {1, 0};
  double d[] = {1, 4};
  double e[] = {4, 0};
  double f[] = {6, 2};
  Vector u(a, 2);
  Vector v(b, 2);
  Vector w(c, 2);
  Vector x(d, 2);
  Vector y(e, 2);
  Vector z(f, 2);
  Vector arr1[] = {u, v, w};          //1
  Vector arr2[] = {u, v, w, x};       //3
  Vector arr3[] = {u, v, w, x, y};    //5
  Vector arr4[] = {u, v, w, x, y, z}; //6
  std::vector<Shape *> vec;
  vec.push_back(new Polygon(arr1, 3));
  vec.push_back(new Circle(2));
  vec.push_back(new Polygon(arr2, 4));
  vec.push_back(new Circle(0.5));
  vec.push_back(new Polygon(arr3, 5));
  vec.push_back(new Circle(1));
  vec.push_back(new Polygon(arr4, 6));
  std::vector<Shape *> result = findAll(vec.begin(), vec.end(), [](Shape *s) {
    return s->area() > 4 && s->area() < 20;
  });
  ASSERT_EQ(4, result.size());
  ASSERT_NEAR(7, result[0]->area(), epsilon);
  ASSERT_NEAR(12.5664, result[1]->area(), epsilon);
  ASSERT_NEAR(10, result[2]->area(), epsilon);
  ASSERT_NEAR(16, result[3]->area(), epsilon);
}