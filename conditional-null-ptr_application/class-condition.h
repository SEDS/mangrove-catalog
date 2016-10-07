// Custom code

#ifndef _CLASS_CONDITION_H_
#define _CLASS_CONDITION_H_

class ClassCondition {
public:
	// Initialize the private variable to 1 (true).
	ClassCondition(void);

	// Perform a test on the private variable.
	void test(void);

private:
	int alwaysTrue_;
};

#endif