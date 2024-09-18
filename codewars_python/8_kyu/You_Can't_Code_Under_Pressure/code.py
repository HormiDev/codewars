def double_integer(i):
    return i*2


if __name__ == "__main__":
	test_cases = [2, 3, 4, 5, 6]
	for i, case in enumerate(test_cases):
		print(f"Test case {i+1}: {case} -> {double_integer(case)}")