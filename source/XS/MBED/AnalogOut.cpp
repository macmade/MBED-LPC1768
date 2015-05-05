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
        
        class AnalogOut::IMPL
        {
            public:
                
                IMPL( int n ): pin( n )
                {
                    analogout_init
                    (
                        &( this->analog ),
                        static_cast< PinName >( n )
                    );
                }
                
                IMPL( const IMPL & o ): pin( o.pin )
                {
                    analogout_init
                    (
                        &( this->analog ),
                        static_cast< PinName >( o.pin )
                    );
                }
                
                int   pin;
                dac_t analog;
        };
        
        #pragma GCC diagnostic pop
        
        AnalogOut::AnalogOut( int n ): impl( new IMPL( n ) )
        {}
        
        AnalogOut::AnalogOut( const AnalogOut & o ): impl( new IMPL( *( o.impl ) ) )
        {}
        
        AnalogOut::AnalogOut( AnalogOut && o )
        {
            this->impl = std::move( o.impl );
            o.impl     = nullptr;
        }
        
        AnalogOut::~AnalogOut( void )
        {
            delete this->impl;
        }
        
        AnalogOut & AnalogOut::operator =( AnalogOut o )
        {
            swap( *( this ), o );
            
            return *( this );
        }
        
        AnalogOut & AnalogOut::operator =( float v )
        {
            this->Write( v );
            
            return *( this );
        }
        
        AnalogOut & AnalogOut::operator =( uint16_t v )
        {
            this->WriteUInt16( v );
            
            return *( this );
        }
        
        AnalogOut::operator float( void )
        {
            return this->Read();
        }
        
        AnalogOut::operator uint16_t( void )
        {
            return this->ReadUInt16();
        }
        
        float AnalogOut::Read( void )
        {
            return analogout_read( &( this->impl->analog ) );
        }
        
        uint16_t AnalogOut::ReadUInt16( void )
        {
            return analogout_read_u16( &( this->impl->analog ) );
        }
        
        void AnalogOut::Write( float v )
        {
            analogout_write( &( this->impl->analog ), v );
        }
        
        void AnalogOut::WriteUInt16( uint16_t v )
        {
            analogout_write( &( this->impl->analog ), v );
        }
        
        void swap( AnalogOut & o1, AnalogOut & o2 )
        {
            using std::swap;
            
            swap( o1.impl, o2.impl );
        }
    }
}
