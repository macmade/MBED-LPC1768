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
#include "XSEFunctions.h"

void XSEWait( float seconds )
{
    wait( seconds );
}

unsigned int XSEGetPinID( unsigned int pinNumber )
{
    switch( pinNumber )
    {
        case 5:     return ( unsigned int )p5;
        case 6:     return ( unsigned int )p6;
        case 7:     return ( unsigned int )p7;
        case 8:     return ( unsigned int )p8;
        case 9:     return ( unsigned int )p9;
        case 10:    return ( unsigned int )p10;
        case 11:    return ( unsigned int )p11;
        case 12:    return ( unsigned int )p12;
        case 13:    return ( unsigned int )p13;
        case 14:    return ( unsigned int )p14;
        case 15:    return ( unsigned int )p15;
        case 16:    return ( unsigned int )p16;
        case 17:    return ( unsigned int )p17;
        case 18:    return ( unsigned int )p18;
        case 19:    return ( unsigned int )p19;
        case 20:    return ( unsigned int )p20;
        case 21:    return ( unsigned int )p21;
        case 22:    return ( unsigned int )p22;
        case 23:    return ( unsigned int )p23;
        case 24:    return ( unsigned int )p24;
        case 25:    return ( unsigned int )p25;
        case 26:    return ( unsigned int )p26;
        case 27:    return ( unsigned int )p27;
        case 28:    return ( unsigned int )p28;
        case 29:    return ( unsigned int )p29;
        case 30:    return ( unsigned int )p30;
        
        default:    break;
    }
    
    return 0;
}
