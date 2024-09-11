
all:
	@echo "Compiling code..."
	@cc code.c -o "$(notdir $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST)))))".out 
	@echo "Done."

fclean:
	@echo "Cleaning up..."
	@rm -f *.out
	@echo "Done."