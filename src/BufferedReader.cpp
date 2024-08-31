/* vim: set et ts=4 sw=4: */

/*
	slurmCC

bufferedReader.cpp: Buffer file reads

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

#include <BufferedReader.h>
#include <stdexcept>

BufferedReader::BufferedReader(const std::string& fname)  :
    m_bufferPos(0),
    m_bufferSize(kBUF_SIZE),
    m_charactersInBuffer(0)
{

    m_file = fopen(fname.c_str(), "r");
    if (m_file == NULL) throw std::runtime_error("Could not open file");

}

BufferedReader::~BufferedReader()
{
    fclose(m_file);
}

int BufferedReader::tryReloadBuffer()
{
    if (m_charactersInBuffer == 0)
    {
        m_bufferPos = 0;
        m_charactersInBuffer = fread(m_buffer, 1, sizeof(m_buffer), m_file);
        if (m_charactersInBuffer <= 0)
            return EOF;
    }
 
    return 0;
}

int BufferedReader::readChar()
{
    if (tryReloadBuffer() == EOF) return EOF;
   
    char c = m_buffer[m_bufferPos];
    m_bufferPos++;
    m_charactersInBuffer--;

    return c;
}

int BufferedReader::peekChar()
{
    if (tryReloadBuffer() == EOF) return EOF;
   
    char c = m_buffer[m_bufferPos];

    return c;
}



