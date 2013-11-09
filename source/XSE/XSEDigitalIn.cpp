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
#include "XSEDigitalIn.h"
#include "XSETimer.h"
#include "XSEFunctions.h"

struct __XSEDigitalIn
{
    DigitalIn  * din;
};

static XSETypeID __TypeID  = 0;

static void __XSEDigitalInConstructor( XSEDigitalInRef din );
static void __XSEDigitalInDestructor( XSEDigitalInRef din );

XSETypeID XSEDigitalInGetTypeID( void )
{
    XSEClassInfo info;
    
    if( __TypeID > 0 )
    {
        return __TypeID;
    }
    
    info.instanceSize = sizeof( struct __XSEDigitalIn );
    info.constructor  = ( XSEClassConstructor )__XSEDigitalInConstructor;
    info.destructor   = ( XSEClassDestructor  )__XSEDigitalInDestructor;
    
    __TypeID = XSERegisterClass( info );
    
    return __TypeID;
}

static void __XSEDigitalInConstructor( XSEDigitalInRef din )
{}

static void __XSEDigitalInDestructor( XSEDigitalInRef din )
{
    if( din == NULL )
    {
        return;
    }
    
    delete( din->din );
}

XSEDigitalInRef XSEDigitalInCreate( unsigned int pinID )
{
    XSEDigitalInRef din;
    
    din = ( XSEDigitalInRef )XSECreateInstance( XSEDigitalInGetTypeID() );
        
    if( din != NULL )
    {
        din->din = new DigitalIn( ( PinName )pinID );
    }
    
    return din;
}

XSEStatus XSEDigitalInGetStatus( XSEDigitalInRef din )
{
    if( din == NULL )
    {
        return XSEStatusUnknown;
    }
    
    return ( din->din->read() == 1 ) ? XSEStatusOn : XSEStatusOff;
}

unsigned int XSEDigitalInGetNumberOfStatusChanges( XSEDigitalInRef din, float timeout )
{
    XSETimerRef  timer;
    unsigned int press;
    
    press = 0;
    
    if( XSEDigitalInGetStatus( din ) == XSEStatusOn )
    {
        press++;
        
        while( XSEDigitalInGetStatus( din ) == XSEStatusOn )
        {
            XSEWait( 0.1 );
        }
        
        timer  = XSETimerCreate();
        
        XSETimerStart( timer );
        
        while( XSETimerGetSeconds( timer ) < timeout )
        {
            if( XSEDigitalInGetStatus( din ) == XSEStatusOn )
            {
                press++;
                
                while( XSEDigitalInGetStatus( din ) == XSEStatusOn )
                {
                    XSEWait( 0.1 );
                }
                
                XSETimerReset( timer );
            }
        }
    }
    
    return press;
}
