/* vim: set et ts=4 sw=4: */

/*
	SlurmCC

main.cpp: Program entry point

License: MIT License

Copyright 2023 J.R.Sharp

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include <iostream>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    std::cout << "SlurmCC (C) JRS 2024" << std::endl;

	if (argc == 1)
	{
		printUsage(argv[0]);
		exit(EXIT_FAILURE);
	}

	char *outputFile = nullptr;
	char *type = nullptr;
	char c;
	bool verbose = false;

	while ((c = getopt (argc, argv, "o:v")) != -1)
	switch (c)
	{
		case 'o':
			outputFile = strdup(optarg);
			break;
		case 'v':
			verbose = true;
			break;
		default:
			printUsage(argv[0]);
			exit(EXIT_FAILURE);
	}

	if (outputFile == nullptr)
		outputFile = strdup("a.out");

    std::string outputFileStr = outputFile;

    free(outputFile);

	if (optind == argc)
	{
		std::cout << "ERROR: no input files" << std::endl;
        exit(EXIT_FAILURE);	
    }

    std::string inputFileStr = argv[optind];

    // Create a lexer and a parser

    exit(EXIT_SUCCESS);
}
