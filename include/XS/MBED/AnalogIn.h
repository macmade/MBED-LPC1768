/*******************************************************************************
 * The MIT License (MIT)
 * 
 * Copyright (c) 2015 Jean-David Gadina - www.xs-labs.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
*******************************************************************************/

#ifndef XS_MBED_ANALOG_IN_H
#define XS_MBED_ANALOG_IN_H

#include <XS/MBED.h>

namespace XS
{
    namespace MBED
    {
        class AnalogIn
        {
            public:
                
                AnalogIn( int n );
                AnalogIn( const AnalogIn & o );
                AnalogIn( AnalogIn && o );
                
                virtual ~AnalogIn( void );
                
                AnalogIn & operator =( AnalogIn o );
                
                operator float( void );
                operator uint16_t( void );
                
                float    Read( void );
                uint16_t ReadUInt16( void );
                
                friend void swap( AnalogIn & o1, AnalogIn & o2 );
                
            private:
                
                class  IMPL;
                IMPL * impl;
        };
    }
}

#endif /* XS_MBED_ANALOG_IN_H */
