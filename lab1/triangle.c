/*
 * helloworld.c  -- Mikel Matticoli
 */

#include <stdio.h>
#include <math.h>

/*
 * Struct representing a point in a 2D cartesian coordinate system
 *
 * @param x X-coordinate of the Point
 * @param y Y-coordinate of the Point
 */
typedef struct {
  char *name;
  float x;
  float y;
} Point;

/*
 * Prompts user to enter x and y coordinates, and returns the resulting Point
 *
 * @param name the label of the requested point in the prompt
 */
Point getPoint(char *name) {
  printf("Enter the x- and y-coordinates of point %s:\t", name);
  Point p;
  p.name = name;
  scanf("%f %f", &p.x, &p.y);
  return p;
}

/*
 * Returns distance between two points using distance formula
 *
 * @param a First point
 * @param b Second point
 */
float getDistance(Point a, Point b) {
  return sqrt( ((b.x - a.x) * (b.x - a.x)) + ((b.y - a.y) * (b.y - a.y)) );
}

/*
 * Returns circumference of a triangle (float)
 *
 * @param a Point A of triangle
 * @param b Point B of triangle
 * @param c Point C of triangle
 */
float getTriangleCircumference(Point a, Point b, Point c) {
  return getDistance(a,b) + getDistance(b,c) + getDistance(c,a);
}

/*
 * Returns area of a triangle (float)
 *
 * @param a Point A of triangle
 * @param b Point B of triangle
 * @param c Point C of triangle
 */
float getTriangleArea(Point a, Point b, Point c) {
  float ab = getDistance(a, b),
        bc = getDistance(b, c),
        ca = getDistance(c, a);
  float s = (ab + bc + ca) / 2;
  return sqrt(s * (s - ab) * (s - bc) * (s - ca));
}

/*
 * Prints the distance between two points
 *
 * @param a Any Point
 * @param b Any Point
 */
void printDistance(Point a, Point b) {
  printf("Length of %s%s is %.3f\n\r", a.name, b.name, getDistance(a, b));
}

/*
 *
 *
 */
int main(void) {
  Point a = getPoint("A");
  Point b = getPoint("B");
  Point c = getPoint("C");

  printDistance(a, b);
  printDistance(b, c);
  printDistance(c, a);

  printf("Circumference is %.3f\n\r", getTriangleCircumference(a, b, c));
  printf("Area is %.3f\n\r", getTriangleArea(a, b, c));

  return 0;
}
