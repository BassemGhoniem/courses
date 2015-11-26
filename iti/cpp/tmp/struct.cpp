#include <iostream>

struct Complex {
  private :
    int real;
    int imag;
  public :
    Complex()
    {
      real = imag = 0;
    }
    Complex(int x, int y)
    {
      real = x;
      imag = y;
    }
    void setReal(int r)
    {
      real = r;
    }
    int getReal()
    {
      return real;
    }
};

int main()
{
  Complex c1, c2(5, 3);
  std::cout << c1.getReal() << std::endl;
  std::cout << c2.getReal() << std::endl;
}
