#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"

//tests functions throughout the program
int main()
{
  std::cout << get_east_storage("05/10/2018") << std::endl;
  std::cout << get_east_storage("07/21/2018") << std::endl;

  std::cout << get_min_east() << std::endl;
  std::cout << get_max_east() << std::endl;

  std::cout << compare_basins("01/10/2018") << std::endl;
  std::cout << compare_basins("09/10/2018") << std::endl;

  reverse_order("05/10/2018","05/15/2018");
  reverse_order("07/10/2018","08/05/2018");

  return 0;
}
