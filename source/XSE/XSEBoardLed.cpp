/*******************************************************************************
 * Copyright (c) 2009, Jean-David Gadina - www.xs-labs.com
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *  -   Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *  -   Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *  -   Neither the name of 'Jean-David Gadina' nor the names of its
 *      contributors may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/

/* $Id$ */

#include "mbed.h"
#include "XSEBoardLed.h"
#include "XSEDigitalOut.h"
#include "XSEFunctions.h"

struct __XSEBoardLed
{
    XSEDigitalOutRef dout;
    unsigned int     ledID;
};

static XSETypeID      __TypeID  = 0;
static XSEBoardLedRef __Led1    = NULL;
static XSEBoardLedRef __Led2    = NULL;
static XSEBoardLedRef __Led3    = NULL;
static XSEBoardLedRef __Led4    = NULL;

static void __XSEBoardLedConstructor( XSEBoardLedRef led );
static void __XSEBoardLedDestructor( XSEBoardLedRef led );

XSETypeID XSEBoardLedGetTypeID( void )
{
    XSEClassInfo info;
    
    if( __TypeID > 0 )
    {
        return __TypeID;
    }
    
    info.instanceSize = sizeof( struct __XSEBoardLed );
    info.constructor  = ( XSEClassConstructor )__XSEBoardLedConstructor;
    info.destructor   = ( XSEClassDestructor  )__XSEBoardLedDestructor;
    
    __TypeID = XSERegisterClass( info );
    
    return __TypeID;
}

void XSEBoardLedTest( void )
{
    XSEBoardLedRef led1;
    XSEBoardLedRef led2;
    XSEBoardLedRef led3;
    XSEBoardLedRef led4;
    float          delay;
    
    led1 = XSEBoardLedGetLed( 1 );
    led2 = XSEBoardLedGetLed( 2 );
    led3 = XSEBoardLedGetLed( 3 );
    led4 = XSEBoardLedGetLed( 4 );
    
    delay = 0.05;
    
    XSEBoardLedSetStatus( led1, XSEStatusOff );
    XSEBoardLedSetStatus( led2, XSEStatusOff );
    XSEBoardLedSetStatus( led3, XSEStatusOff );
    XSEBoardLedSetStatus( led4, XSEStatusOff );
    
    XSEBoardLedSetStatus( led1, XSEStatusOn );
    wait( delay );
    XSEBoardLedSetStatus( led1, XSEStatusOff );
    
    XSEBoardLedSetStatus( led2, XSEStatusOn );
    wait( delay );
    XSEBoardLedSetStatus( led2, XSEStatusOff );
    
    XSEBoardLedSetStatus( led3, XSEStatusOn );
    wait( delay );
    XSEBoardLedSetStatus( led3, XSEStatusOff );
    
    XSEBoardLedSetStatus( led4, XSEStatusOn );
    wait( delay );
    XSEBoardLedSetStatus( led4, XSEStatusOff );
    
    XSEBoardLedSetStatus( led3, XSEStatusOn );
    wait( delay );
    XSEBoardLedSetStatus( led3, XSEStatusOff );
    
    XSEBoardLedSetStatus( led2, XSEStatusOn );
    wait( delay );
    XSEBoardLedSetStatus( led2, XSEStatusOff );
    
    XSEBoardLedSetStatus( led1, XSEStatusOn );
    wait( delay );
    XSEBoardLedSetStatus( led1, XSEStatusOff );
}

void XSEBoardLedBlinkAll( float delay, unsigned int times )
{
    XSEBoardLedSetStatus( XSEBoardLedGetLed( 1 ), XSEStatusOff );
    XSEBoardLedSetStatus( XSEBoardLedGetLed( 2 ), XSEStatusOff );
    XSEBoardLedSetStatus( XSEBoardLedGetLed( 3 ), XSEStatusOff );
    XSEBoardLedSetStatus( XSEBoardLedGetLed( 4 ), XSEStatusOff );
    
    while( times-- )
    {
        XSEBoardLedSetStatus( XSEBoardLedGetLed( 1 ), XSEStatusOn );
        XSEBoardLedSetStatus( XSEBoardLedGetLed( 2 ), XSEStatusOn );
        XSEBoardLedSetStatus( XSEBoardLedGetLed( 3 ), XSEStatusOn );
        XSEBoardLedSetStatus( XSEBoardLedGetLed( 4 ), XSEStatusOn );
        XSEWait( delay );
        XSEBoardLedSetStatus( XSEBoardLedGetLed( 1 ), XSEStatusOff );
        XSEBoardLedSetStatus( XSEBoardLedGetLed( 2 ), XSEStatusOff );
        XSEBoardLedSetStatus( XSEBoardLedGetLed( 3 ), XSEStatusOff );
        XSEBoardLedSetStatus( XSEBoardLedGetLed( 4 ), XSEStatusOff );
        XSEWait( delay );
    }
}

XSEBoardLedRef XSEBoardLedGetLed( unsigned int ledID )
{
    XSEBoardLedRef led;
    PinName        pin;
    
    led = NULL;
    
    switch( ledID )
    {
        case 1:  led = __Led1; pin = LED1; break;
        case 2:  led = __Led2; pin = LED2; break;
        case 3:  led = __Led3; pin = LED3; break;
        case 4:  led = __Led4; pin = LED4; break;
        
        default: return NULL;
    }
    
    if( led == NULL )
    {
        led = ( XSEBoardLedRef )XSECreateInstance( XSEBoardLedGetTypeID() );
        
        if( led != NULL )
        {
            led->ledID = ledID;
            led->dout  = XSEDigitalOutCreate( pin );
            
            switch( ledID )
            {
                case 1:  __Led1 = led; break;
                case 2:  __Led2 = led; break;
                case 3:  __Led3 = led; break;
                case 4:  __Led4 = led; break;
                
                default: return NULL;
            }
        }
    }
    
    return led;
}

static void __XSEBoardLedConstructor( XSEBoardLedRef led )
{
    ( void )led;
}

static void __XSEBoardLedDestructor( XSEBoardLedRef led )
{
    if( led == NULL )
    {
        return;
    }
    
    XSERelease( led->dout );
}

unsigned int XSEBoardLedGetID( XSEBoardLedRef led )
{
    if( led == NULL )
    {
        return 0;
    }
    
    return led->ledID;
}

XSEStatus XSEBoardLedGetStatus( XSEBoardLedRef led )
{
    if( led == NULL )
    {
        return XSEStatusUnknown;
    }
    
    return XSEDigitalOutGetStatus( led->dout );
}


void XSEBoardLedSetStatus( XSEBoardLedRef led, XSEStatus status )
{
    if( led == NULL )
    {
        return;
    }
    
    XSEDigitalOutSetStatus( led->dout, status );
}


void XSEBoardLedToggle( XSEBoardLedRef led )
{
    if( led == NULL )
    {
        return;
    }
    
    XSEDigitalOutToggle( led->dout );
}

void XSEBoardLedBlink( XSEBoardLedRef led, float delay, unsigned int times )
{
    XSEBoardLedSetStatus( led, XSEStatusOff );
    
    while( times-- )
    {
        XSEBoardLedSetStatus( led, XSEStatusOn );
        XSEWait( delay );
        XSEBoardLedSetStatus( led, XSEStatusOff );
        XSEWait( delay );
    }
}
