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
#include "XSEAnalogIn.h"

struct __XSEAnalogIn
{
    AnalogIn * ain;
};

static XSETypeID __TypeID  = 0;

static void __XSEAnalogInConstructor( XSEAnalogInRef ain );
static void __XSEAnalogInDestructor( XSEAnalogInRef ain );

XSETypeID XSEAnalogInGetTypeID( void )
{
    XSEClassInfo info;
    
    if( __TypeID > 0 )
    {
        return __TypeID;
    }
    
    info.instanceSize = sizeof( struct __XSEAnalogIn );
    info.constructor  = ( XSEClassConstructor )__XSEAnalogInConstructor;
    info.destructor   = ( XSEClassDestructor  )__XSEAnalogInDestructor;
    
    __TypeID = XSERegisterClass( info );
    
    return __TypeID;
}

static void __XSEAnalogInConstructor( XSEAnalogInRef ain )
{}

static void __XSEAnalogInDestructor( XSEAnalogInRef ain )
{
    if( ain == NULL )
    {
        return;
    }
    
    delete( ain->ain );
}

XSEAnalogInRef XSEAnalogInCreate( unsigned int pinID )
{
    XSEAnalogInRef ain;
    
    ain = ( XSEAnalogInRef )XSECreateInstance( XSEAnalogInGetTypeID() );
        
    if( ain != NULL )
    {
        ain->ain = new AnalogIn( ( PinName )pinID );
    }
    
    return ain;
}

unsigned short XSEAnalogInGetValue( XSEAnalogInRef ain )
{
    if( ain == NULL )
    {
        return 0;
    }
    
    return ain->ain->read_u16();
}

float XSEAnalogInGetFloatValue( XSEAnalogInRef ain )
{
    if( ain == NULL )
    {
        return 0;
    }
    
    return ain->ain->read();
}
