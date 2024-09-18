def bool_to_word(boolean):
    if boolean: return "Yes"
    return "No"

if __name__ == "__main__":
	test_cases = [True, False, True, False, True]
	for i, case in enumerate(test_cases):
		print(f"Test case {i+1}: {case} -> {bool_to_word(case)}")