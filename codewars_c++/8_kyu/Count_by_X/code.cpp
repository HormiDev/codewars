
#include <vector>
#include <iostream>

std::vector<int> countBy(int x,int n){
	int i = 1;
	std::vector<int> result;

	while (i <= n) 
	{
		result.push_back(x * i);
		i++;
	}
	return {result};
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
	std::cerr << "Usage: " << argv[0] << " <x> <n>" << std::endl;
	return 1;
  }
  int x = std::stoi(argv[1]);
  int n = std::stoi(argv[2]);
  std::vector<int> result = countBy(x, n);
  int size = result.size();
  int i = 0;
  std::cout << "x = " << x << ", n = " << n << " --> [";
  while (i < size)
  {
		std::cout << result[i];
		if (i < size - 1)
			std::cout << ",";
		i++;
  }
  std::cout << "]" << std::endl;
  return 0;
}