// Juliet CWE665_Improper_Initialization__char_cat_21.c
// Structure: return-local-param

char * helper(char * data)
{
	// Tool C FP: none
	// Tool B FP: none
	// Tool A FP: (error) Pointer to local array variable returned.
    return data;
}


int main(void)
{
    char * data;
    char dataBuffer[10];
    data = dataBuffer;
    data = helper(data);
    return 0;
}