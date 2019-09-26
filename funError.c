#include "monty.h"

/**
* funErrorGeneric - function error INT
* @text: text to print
*/
void funErrorGeneric(char *text)
{
	fprintf(stderr, "%s\n", text);
	exit(EXIT_FAILURE);
}

/**
* funErrorGenericCHAR - function error CHAR
* @text: text to print
* @nomFile: name of file
*/
void funErrorGenericCHAR(char *text, char *nomFile)
{
	fprintf(stderr, "%s %s\n", text, nomFile);
	exit(EXIT_FAILURE);
}

/**
* funErrorNoOPCODE - function error file contains an invalid instruction
* @numline: number of line¬
* @text: text to print
* @opcode: name of the operation
*/
void funErrorNoOPCODE(int numline, char *text, char *opcode)
{
	fprintf(stderr, "L%d: %s %s\n", numline, text, opcode);
	exit(EXIT_FAILURE);
}


/**
* funErrorGenericINT - function error INT
* @text: text to print
* @numLine: number of line
*/
void funErrorGenericINT(int numLine, char *text)
{
	fprintf(stderr, "L%u: %s\n", numLine, text);
	exit(EXIT_FAILURE);
}

