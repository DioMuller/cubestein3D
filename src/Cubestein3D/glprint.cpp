#include "glprint.h"
#include <stdio.h>    //  Standard Input\Output C Library
#include <stdarg.h>   //  To use functions with variables arguments
#include <stdlib.h>   //  for malloc
#include <glut.h>  //  Include GLUT, OpenGL, and GLU libraries

void printw(float x, float y, float z, void* font, const char* format, ...)
{
	va_list args;   //  Variable argument list
	int len;        // String length
	int i;          //  Iterator
	char * text;    // Text

	//  Initialize a variable argument list
	va_start(args, format);

	//  Return the number of characters in the string referenced the list of arguments.
	// _vscprintf doesn't count terminating '\0' (that's why +1)
	len = _vscprintf(format, args) + 1;

	//  Allocate memory for a string of the specified size
	text = (char*) malloc(len * sizeof(char));

	//  Write formatted output using a pointer to the list of arguments
	vsprintf_s(text, len, format, args);

	//  End using variable argument list
	va_end(args);

	//  Specify the raster position for pixel operations.
	glRasterPos3f(x, y, z);

	//  Draw the characters one by one
	for (i = 0; text[i] != '\0'; i++)
		glutBitmapCharacter(font, text[i]);

	//  Free the allocated memory for the string
	free(text);
}