#include <iostream>
#include <iomanip>

//Taken from text book c++ for object oriented programming

void memError()
{
  std::cout << "Memory Allocation error";
  exit(1);
}

int main(void)
{
  int rows, columns, i, j;
  int** p2d;
  std::cout << "Enter a number of rows => ";
  std::cin >> rows;
  std::cout << "Enter a number of columns =>";
  std::cin >> columns;
  
  p2d = new int*[rows];
  if(!p2d)
    memError();
  for ( i = 0; i < rows; i++ )
  {
    p2d[i] = new int [columns];
    if(!p2d[i])
      memError();
  }
  std::cout << "\n***MULTIPLICATION TABLE***" << std::endl;
  for( i = 0; i < rows; i++ )
  {
    for ( j = 0; j< columns; j++)
    {
      p2d[i][j] = (i+1) * (j+1);
      std::cout << std::setw(5) << p2d[i][j];
    }
    std::cout << std::endl;
  }
  
  for ( i = 0; i < rows; i++ )
  {
    delete[] p2d[i];
  }
  delete[] p2d;
  return 0;
}
