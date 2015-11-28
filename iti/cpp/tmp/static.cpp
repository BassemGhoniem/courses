#include <iostream>
using namespace std;
class Point {
  private :
    int x, y;
    static int count;
  public :
    Point(){
      x = y = 0;
      count++;
    }
    Point(int x, int y) {
      this->x = x;
      this->y = y;
      count++;
    }
    static int getCount () {
      return count;
    }
};
int Point::count = 0;
int main() {
  Point p;
  cout << p.getCount() << endl;
  Point p2(3, 5);
  cout << p.getCount() << endl;
  cout << Point::getCount() << endl;
}
