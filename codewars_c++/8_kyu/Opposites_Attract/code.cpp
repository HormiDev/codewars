#include <string>

bool lovefunc(int f1, int f2) {
  if((f1 % 2 == 0 && f2 % 2 != 0) || (f1 % 2 != 0 && f2 % 2 == 0))
    return true;
  return false;
}

#include <iostream>

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
	std::cerr << "Usage: " << argv[0] << " <n1> <n2>" << std::endl;
	return 1;
  }
  int n1 = std::stoi(argv[1]);
  int n2 = std::stoi(argv[2]);
  if (lovefunc(n1, n2))
	std::cout << "Result: true" << std::endl;
  else
	std::cout << "Result: false" << std::endl;
  return 0;
}