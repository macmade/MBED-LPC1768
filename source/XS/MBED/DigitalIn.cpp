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
        
        class DigitalIn::IMPL
        {
            public:
                
                IMPL( int n, PinMode m ): pin( n ), mode( m )
                {
                    gpio_init_in_ex
                    (
                        &( this->gpio ),
                        static_cast< PinName >( n ),
                        this->GetPlatformPinMode( m )
                    );
                }
                
                IMPL( const IMPL & o ): pin( o.pin ), mode( o.mode )
                {
                    gpio_init_in_ex
                    (
                        &( this->gpio ),
                        static_cast< PinName >( o.pin ),
                        this->GetPlatformPinMode( o.mode )
                    );
                }
                
                ::PinMode GetPlatformPinMode( PinMode m )
                {
                    switch( m )
                    {
                        case PinModePullNone:   return ::PullNone;
                        case PinModePullDown:   return ::PullDown;
                        case PinModePullUp:     return ::PullUp;
                        case PinModeOpenDrain:  return ::OpenDrain;
                        case PinModeRepeater:   return ::Repeater;
                        default:                return ::PullDefault;
                    }
                }
                
                gpio_t  gpio;
                int     pin;
                PinMode mode;
        };
        
        #pragma GCC diagnostic pop
        
        DigitalIn::DigitalIn( int n, PinMode m ): impl( new IMPL( n, m ) )
        {}
        
        DigitalIn::DigitalIn( const DigitalIn & o ): impl( new IMPL( *( o.impl ) ) )
        {}
        
        DigitalIn::DigitalIn( DigitalIn && o )
        {
            this->impl = std::move( o.impl );
            o.impl     = nullptr;
        }
        
        DigitalIn::~DigitalIn( void )
        {
            delete this->impl;
        }
        
        DigitalIn & DigitalIn::operator =( DigitalIn o )
        {
            swap( *( this ), o );
            
            return *( this );
        }
        
        DigitalIn::operator int( void ) const
        {
            return this->Read();
        }
        
        bool DigitalIn::IsConnected( void ) const
        {
            return gpio_is_connected( &( this->impl->gpio ) );
        }
        
        int DigitalIn::Read( void ) const
        {
            return gpio_read( &( this->impl->gpio ) );
        }
        
        PinMode DigitalIn::GetPinMode( void ) const
        {
            return this->impl->mode;
        }
        
        void DigitalIn::SetPinMode( PinMode m )
        {
            gpio_mode( &( this->impl->gpio ), this->impl->GetPlatformPinMode( m ) );
        }
        
        void swap( DigitalIn & o1, DigitalIn & o2 )
        {
            using std::swap;
            
            swap( o1.impl, o2.impl );
        }
    }
}
