// ==================================================== //
// ORIGINAL CODE FOR "LOOP FLAG" FALSE POSITIVE PATTERN //
// ==================================================== //

// Note: This is just a snippet--it will not compile by itself.

// Validate the original expression to be sure it does not contain two consecutive numbers.
// Returns boolean value to indicate whether validation was successful.
bool Calculator::validate_infix(const std::string & infix) {
    std::istringstream input(infix);

    // Boolean variable to indicate if last token was a number.
    bool lastTokenNumber = false;

    // Step through each token to see if there are two consecutive numbers.
    // If so, then the expression is not valid.
    while (!input.eof()) {
        std::string token;
        input >> token;
        int num;
        // Attempt conversion to int.
        try {
            int num = std::stoi(token);
        } catch (std::invalid_argument) {
            // Not an int -- no need to worry -- continue to next token.
            lastTokenNumber = false;
            continue;
        }
        // If last token was also a number, invalid expression.
        if (lastTokenNumber) {
            // Tool C FP: Unreachable Data Flow. The highlighted code will not execute under any circumstances.
            //   This may be because of:
            //     (1) A function call that does not return
            //     (2) A test whose result is always the same (look for a preceding Redundant Condition warning)
            //     (3) A crashing bug (look for a preceding Null Pointer Dereference or Division By Zero warning)
            return false;
        }
        lastTokenNumber = true;
    }
    return true;
}