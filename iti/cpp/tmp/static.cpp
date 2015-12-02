#include <iostream>
using namespace std;
class Point {
  private :
    int x, y;
    static int count;
  public :
    Point(){
      cout << "default Called" << endl;
      x = y = 0;
      count++;
    }
    Point(int x, int y) {
    cout << "paramaterized called" << endl;
      this->x = x;
      this->y = y;
      count++;
    }
    static int getCount () {
      return count;
    }
};
int Point::count = 0;
class Line {
    private:
        Point start, end;
    public:
        Line(){
        }
        Line(int x1, int y1, int x2, int y2){
        
        }
};
        
int main() {
//  Point p;
    Line l1, l2(1, 2, 3, 4);
 // cout << p.getCount() << endl;
 // Point p2(3, 5);
 // cout << p.getCount() << endl;
 // cout << Point::getCount() << endl;
}
