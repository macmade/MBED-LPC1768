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
#include "XSEAnalogOut.h"

struct __XSEAnalogOut
{
    AnalogOut * aout;
};

static XSETypeID __TypeID  = 0;

static void __XSEAnalogOutConstructor( XSEAnalogOutRef aout );
static void __XSEAnalogOutDestructor( XSEAnalogOutRef aout );

XSETypeID XSEAnalogOutGetTypeID( void )
{
    XSEClassInfo info;
    
    if( __TypeID > 0 )
    {
        return __TypeID;
    }
    
    info.instanceSize = sizeof( struct __XSEAnalogOut );
    info.constructor  = ( XSEClassConstructor )__XSEAnalogOutConstructor;
    info.destructor   = ( XSEClassDestructor  )__XSEAnalogOutDestructor;
    
    __TypeID = XSERegisterClass( info );
    
    return __TypeID;
}

static void __XSEAnalogOutConstructor( XSEAnalogOutRef aout )
{}

static void __XSEAnalogOutDestructor( XSEAnalogOutRef aout )
{
    if( aout == NULL )
    {
        return;
    }
    
    delete( aout->aout );
}

XSEAnalogOutRef XSEAnalogOutCreate( unsigned int pinID )
{
    XSEAnalogOutRef aout;
    
    aout = ( XSEAnalogOutRef )XSECreateInstance( XSEAnalogOutGetTypeID() );
        
    if( aout != NULL )
    {
        aout->aout = new AnalogOut( ( PinName )pinID );
    }
    
    return aout;
}

float XSEAnalogOutGetFloatValue( XSEAnalogOutRef aout )
{
    if( aout == NULL )
    {
        return 0;
    }
    
    return aout->aout->read();
}

void  XSEAnalogOutSetValue( XSEAnalogOutRef aout, unsigned short value )
{
    if( aout == NULL )
    {
        return;
    }
    
    aout->aout->write_u16( value );
}

void  XSEAnalogOutSetFloatValue( XSEAnalogOutRef aout, float value )
{
    if( aout == NULL )
    {
        return;
    }
    
    aout->aout->write( value );
}
