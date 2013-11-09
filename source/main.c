
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

#include "XSE/XSE.h"
#include "tests/tests.h"

typedef void ( * __TestFunc )( int ( * abort )( void ) );

static volatile int    __running = 0;
static XSEDigitalInRef __button  = NULL;
static __TestFunc      __tests[] =
{
    test1,
    test2,
    test3
};

static int __abort( void );
static int __abort( void )
{
    if( XSEDigitalInGetStatus( __button ) == XSEStatusOn )
    {
        return 1;
    }
    
    return 0;
}

int main( void )
{
    unsigned int    press;
    XSEAnalogOutRef signal;
    
    __running = 1;
    
    XSEInit();
    XSEBoardLedTest();
    
    __button = XSEDigitalInCreate( XSEGetPinID( 20 ) );
    signal   = XSEAnalogOutCreate( XSEGetPinID( 18 ) );
    
    XSEAnalogOutSetFloatValue( signal, 0 );
    XSERelease( signal );
    
    while( __running == 1 )
    {
        press = XSEDigitalInGetNumberOfStatusChanges( __button, 0.5 );
        
        if( press > 0 && press <= sizeof( __tests ) / sizeof( __TestFunc ) )
        {
            XSEBoardLedBlinkAll( 0.2, press );
            XSEWait( 0.5 );
            
            __tests[ press - 1 ]( __abort );
            
            XSEWait( 0.5 );
            XSEBoardLedTest();
        }
    }
    
    XSERelease( __button );
    
    return 0;
}