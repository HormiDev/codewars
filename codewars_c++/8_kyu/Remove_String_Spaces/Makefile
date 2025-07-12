
all:
	@echo "Compiling code..."
	@c++ code.cpp -o "$(notdir $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST)))))".out -Wall -Wextra -Wpedantic -Werror -lm
	@echo "Done."

fclean:
	@echo "Cleaning up..."
	@rm -f *.out
	@echo "Done."