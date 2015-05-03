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
#include <XS/MBED/Platform.h>

namespace XS
{
    namespace MBED
    {
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wpadded"
        
        class DigitalOut::IMPL
        {
            public:
                
                IMPL( int n, int v ): pin( n ), value( v )
                {
                    gpio_init_out_ex
                    (
                        &( this->gpio ),
                        static_cast< PinName >( n ),
                        v
                    );
                }
                
                IMPL( const IMPL & o ): pin( o.pin ), value( o.value )
                {
                    gpio_init_out_ex
                    (
                        &( this->gpio ),
                        static_cast< PinName >( o.pin ),
                        o.value
                    );
                }
                
                gpio_t gpio;
                int    pin;
                int    value;
        };
        
        #pragma GCC diagnostic pop
        
        DigitalOut::DigitalOut( int n, int v ): impl( new IMPL( n, v ) )
        {}
        
        DigitalOut::DigitalOut( const DigitalOut & o ): impl( new IMPL( *( o.impl ) ) )
        {}
        
        DigitalOut::DigitalOut( DigitalOut && o )
        {
            this->impl = std::move( o.impl );
            o.impl     = nullptr;
        }
        
        DigitalOut::~DigitalOut( void )
        {
            delete this->impl;
        }
        
        DigitalOut & DigitalOut::operator =( DigitalOut o )
        {
            swap( *( this ), o );
            
            return *( this );
        }
        
        DigitalOut & DigitalOut::operator =( int v )
        {
            this->Write( v );
            
            return *( this );
        }
        
        DigitalOut::operator int( void ) const
        {
            return this->Read();
        }
        
        bool DigitalOut::IsConnected( void ) const
        {
            return gpio_is_connected( &( this->impl->gpio ) );
        }
        
        int DigitalOut::Read( void ) const
        {
            return gpio_read( &( this->impl->gpio ) );
        }
        
        void DigitalOut::Write( int v )
        {
            gpio_write( &( this->impl->gpio ), v );
        }
        
        void swap( DigitalOut & o1, DigitalOut & o2 )
        {
            using std::swap;
            
            swap( o1.impl, o2.impl );
        }
    }
}
