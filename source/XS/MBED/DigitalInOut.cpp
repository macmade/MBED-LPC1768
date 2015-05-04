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
        
        class DigitalInOut::IMPL
        {
            public:
                
                IMPL( int n, PinDirection d, PinMode m, int v ): pin( n ), direction( d ), mode( m ), value( v )
                {
                    gpio_init_inout
                    (
                        &( this->gpio ),
                        static_cast< PinName >( n ),
                        this->GetPlatformPinDirection( d ),
                        this->GetPlatformPinMode( m ),
                        v
                    );
                }
                
                IMPL( const IMPL & o ): pin( o.pin ), direction( o.direction ), mode( o.mode ), value( o.value )
                {
                    gpio_init_inout
                    (
                        &( this->gpio ),
                        static_cast< PinName >( o.pin ),
                        this->GetPlatformPinDirection( o.direction ),
                        this->GetPlatformPinMode( o.mode ),
                        o.value
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
                
                ::PinDirection GetPlatformPinDirection( PinDirection d )
                {
                    switch( d )
                    {
                        case PinDirectionInput:     return ::PIN_INPUT;
                        case PinDirectionOutput:    return ::PIN_OUTPUT;
                        default:                    return ::PIN_INPUT;
                    }
                }
                
                gpio_t       gpio;
                int          pin;
                PinDirection direction;
                PinMode      mode;
                int          value;
        };
        
        #pragma GCC diagnostic pop
        
        DigitalInOut::DigitalInOut( int n, PinDirection d, PinMode m, int v ): impl( new IMPL( n, d, m, v ) )
        {}
        
        DigitalInOut::DigitalInOut( const DigitalInOut & o ): impl( new IMPL( *( o.impl ) ) )
        {}
        
        DigitalInOut::DigitalInOut( DigitalInOut && o )
        {
            this->impl = std::move( o.impl );
            o.impl     = nullptr;
        }
        
        DigitalInOut::~DigitalInOut( void )
        {
            delete this->impl;
        }
        
        DigitalInOut & DigitalInOut::operator =( DigitalInOut o )
        {
            swap( *( this ), o );
            
            return *( this );
        }
        
        DigitalInOut & DigitalInOut::operator =( int v )
        {
            this->Write( v );
            
            return *( this );
        }
        
        DigitalInOut::operator int( void ) const
        {
            return this->Read();
        }
        
        bool DigitalInOut::IsConnected( void ) const
        {
            return gpio_is_connected( &( this->impl->gpio ) );
        }
        
        int DigitalInOut::Read( void ) const
        {
            return gpio_read( &( this->impl->gpio ) );
        }
        
        void DigitalInOut::Write( int v )
        {
            gpio_write( &( this->impl->gpio ), v );
        }
        
        PinMode DigitalInOut::GetPinMode( void ) const
        {
            return this->impl->mode;
        }
        
        void DigitalInOut::SetPinMode( PinMode m )
        {
            gpio_mode( &( this->impl->gpio ), this->impl->GetPlatformPinMode( m ) );
        }
        
        PinDirection DigitalInOut::GetPinDirection( void ) const
        {
            return this->impl->direction;
        }
        
        void DigitalInOut::SetPinDirection( PinDirection d )
        {
            gpio_dir( &( this->impl->gpio ), this->impl->GetPlatformPinDirection( d ) );
        }
        
        void DigitalInOut::Input( void )
        {
            this->SetPinDirection( PinDirectionInput );
        }
        
        void DigitalInOut::Output( void )
        {
            this->SetPinDirection( PinDirectionOutput );
        }
        
        void swap( DigitalInOut & o1, DigitalInOut & o2 )
        {
            using std::swap;
            
            swap( o1.impl, o2.impl );
        }
    }
}
