def solution(string):
	return string[::-1]

if __name__ == "__main__":
	test_string = "hola mundo"
	reversed_string = solution(test_string)
	print(f"Original: {test_string}")
	print(f"Reversed: {reversed_string}")