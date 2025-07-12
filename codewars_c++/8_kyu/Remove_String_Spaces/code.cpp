#include <string>

std::string no_space(const std::string& x)
{
	int i = 0;
	int length = x.length();
	std::string result;
	while (i < length)
	{
		if (x[i] != ' ')
		{
			result += x[i];
		}
		i++;
	}
	return result;
}

#include <iostream>

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
	std::cerr << "Usage: " << argv[0] << " <string>" << std::endl;
	return 1;
  }
  std::string input = argv[1];
  std::string result = no_space(input);
  std::cout << "Result: " << result << std::endl;
  return 0;
}