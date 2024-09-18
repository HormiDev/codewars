def remove_exclamation_marks(s):
    return s.replace('!', '')

if __name__ == "__main__":
	test_strings = [
		"Hello World!",
		"No exclamations here",
		"Wow! Such excitement!!",
		"Python is fun!!!",
		"!!!"
	]
	
	for s in test_strings:
		print(f"Original: {s} -> Without exclamations: {remove_exclamation_marks(s)}")
