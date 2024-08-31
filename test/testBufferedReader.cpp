/* vim: set et ts=4 sw=4: */

/*
	$PROJECT

$FILE: $DESC

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

#include <gtest/gtest.h>

#include <cstdio>
#include <iostream>
#include <string>
#include <ostream>
#include <sstream>
#include <fstream>
#include <BufferedReader.h>

TEST(BufferedReader, TestRead)
{
    // Create a temporary file
    std::string tmp_name = std::tmpnam(nullptr);

    std::ofstream fout(tmp_name.c_str());

    ASSERT_EQ(true, fout.is_open());
   
    std::stringstream ss;

    for (int i = 0; i < 65536; i++)
    {
        fout << std::to_string(i) << std::endl;
        ss << std::to_string(i) << std::endl;
    }  

    fout.close();

    BufferedReader buf(tmp_name);

    int c;
    int idx = 0;

    const std::string str = ss.str();

    while ((c = buf.readChar()) != EOF)
    {
        ASSERT_EQ(c, str[idx++]);
    } 

    //std::cout << "Idx: " << idx << std::endl;

    ASSERT_EQ(idx, 382106);

    // Unlink the temporary file

    ASSERT_EQ(std::remove(tmp_name.c_str()), 0);
}

