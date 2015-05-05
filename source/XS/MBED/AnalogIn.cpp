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

#include <XS/MBED.h>
#include <XS/MBED/PLatform.h>

namespace XS
{
    namespace MBED
    {
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wpadded"
        
        class AnalogIn::IMPL
        {
            public:
                
                IMPL( int n ): pin( n )
                {
                    analogin_init
                    (
                        &( this->analog ),
                        static_cast< PinName >( n )
                    );
                }
                
                IMPL( const IMPL & o ): pin( o.pin )
                {
                    analogin_init
                    (
                        &( this->analog ),
                        static_cast< PinName >( o.pin )
                    );
                }
                
                int        pin;
                analogin_t analog;
        };
        
        #pragma GCC diagnostic pop
        
        AnalogIn::AnalogIn( int n ): impl( new IMPL( n ) )
        {}
        
        AnalogIn::AnalogIn( const AnalogIn & o ): impl( new IMPL( *( o.impl ) ) )
        {}
        
        AnalogIn::AnalogIn( AnalogIn && o )
        {
            this->impl = std::move( o.impl );
            o.impl     = nullptr;
        }
        
        AnalogIn::~AnalogIn( void )
        {
            delete this->impl;
        }
        
        AnalogIn & AnalogIn::operator =( AnalogIn o )
        {
            swap( *( this ), o );
            
            return *( this );
        }
        
        AnalogIn::operator float( void )
        {
            return this->Read();
        }
        
        AnalogIn::operator uint16_t( void )
        {
            return this->ReadUInt16();
        }
        
        float AnalogIn::Read( void )
        {
            return analogin_read( &( this->impl->analog ) );
        }
        
        uint16_t AnalogIn::ReadUInt16( void )
        {
            return analogin_read_u16( &( this->impl->analog ) );
        }
        
        void swap( AnalogIn & o1, AnalogIn & o2 )
        {
            using std::swap;
            
            swap( o1.impl, o2.impl );
        }
    }
}
