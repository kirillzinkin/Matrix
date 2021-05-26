#include <iostream>
#include "Matrix.h"

int main()
{
  TMatrix<int> a(5), b(5), c(5);
  int i, j;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++)
    {
      a[i][j] = i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }
  c = a + b;
  std::cout << "Matrix a = " << std::endl << a << std::endl;
  std::cout << "Matrix b = " << std::endl << b << std::endl;
  std::cout << "Matrix c = a + b" << std::endl << c << std::endl;
  a.file();
  b.file();
  c.file();
}
