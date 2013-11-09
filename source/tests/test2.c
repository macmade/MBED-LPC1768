
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

#include "tests.h"
#include "../XSE/XSE.h"

void test2( int ( * abort )( void ) )
{
    XSEBoardLedRef led1;
    XSEBoardLedRef led2;
    XSEBoardLedRef led3;
    XSEBoardLedRef led4;
    XSEAnalogInRef pot;
    
    led1 = XSEBoardLedGetLed( 1 );
    led2 = XSEBoardLedGetLed( 2 );
    led3 = XSEBoardLedGetLed( 3 );
    led4 = XSEBoardLedGetLed( 4 );
    pot  = XSEAnalogInCreate( XSEGetPinID( 17 ) );
    
    while( 1 )
    {
        if( abort() )
        {
            break;
        }
        
        XSEBoardLedSetStatus( led1, XSEStatusOn );
        XSEBoardLedSetStatus( led2, XSEStatusOn );
        XSEBoardLedSetStatus( led3, XSEStatusOn );
        XSEBoardLedSetStatus( led4, XSEStatusOn );
        
        XSEWait( XSEAnalogInGetFloatValue( pot ) );
        
        XSEBoardLedSetStatus( led1, XSEStatusOff );
        XSEBoardLedSetStatus( led2, XSEStatusOff );
        XSEBoardLedSetStatus( led3, XSEStatusOff );
        XSEBoardLedSetStatus( led4, XSEStatusOff );
        
        XSEWait( XSEAnalogInGetFloatValue( pot ) );
    }
}
