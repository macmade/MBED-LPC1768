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

#include "XSERuntime.h"
#include "XSETimer.h"
#include "XSEBoardLed.h"
#include "XSEDigitalIn.h"
#include "XSEDigitalOut.h"
#include "XSEAnalogIn.h"
#include "XSEAnalogOut.h"

static XSEClassInfo * __classes    = NULL;
static size_t         __classCount = 0;
static size_t         __classAlloc = 0;
static int            __inited     = 0;

typedef struct
{
    size_t         retainCount;
    XSEClassInfo * classInfo;
}
__XSEAllocInfo;

static __XSEAllocInfo * __XSEGetAllocInfo( void * mem );
static __XSEAllocInfo * __XSEGetAllocInfo( void * mem )
{
    char * cp;
    
    if( mem == NULL )
    {
        return NULL;
    }
    
    cp  = ( char * )mem;
    cp -= sizeof( __XSEAllocInfo );
    
    return ( __XSEAllocInfo * )cp;
}

void * XSEAlloc( size_t size )
{
    __XSEAllocInfo * allocInfo;
    char           * cp;
    
    allocInfo = ( __XSEAllocInfo * )calloc( sizeof( __XSEAllocInfo ) + size, 1 );
    
    if( allocInfo == NULL )
    {
        return NULL;
    }
    
    allocInfo->retainCount  = 1;
    cp                      = ( char * )allocInfo;
    cp                     += sizeof( __XSEAllocInfo );
    
    return ( void * )cp;
}

void * XSERetain( void * mem )
{
    __XSEAllocInfo * allocInfo;
    
    allocInfo = __XSEGetAllocInfo( mem );
    
    if( allocInfo == NULL )
    {
        return NULL;
    }
    
    allocInfo->retainCount++;
    
    return mem;
}

void XSERelease( void * mem )
{
    __XSEAllocInfo * allocInfo;
    
    allocInfo = __XSEGetAllocInfo( mem );
    
    if( allocInfo == NULL )
    {
        return;
    }
    
    allocInfo->retainCount--;
    
    if( allocInfo->retainCount == 0 )
    {
        if( allocInfo->classInfo->destructor != NULL )
        {
            allocInfo->classInfo->destructor( mem );
        }
        
        free( allocInfo );
    }
}

void XSEInit( void )
{
    if( __inited == 1 )
    {
        return;
    }
    
    __inited = 1;
    
    XSETimerGetTypeID();
    XSEBoardLedGetTypeID();
    XSEDigitalInGetTypeID();
    XSEDigitalOutGetTypeID();
    XSEAnalogInGetTypeID();
    XSEAnalogOutGetTypeID();
}

XSETypeID XSERegisterClass( XSEClassInfo info )
{
    if( __classes == NULL )
    {
        __classAlloc = 10;
        __classes    = ( XSEClassInfo * )calloc( sizeof( XSEClassInfo ), __classAlloc );
        
        if( __classes == NULL )
        {
            return 0;
        }
    }
    
    if( __classCount == __classAlloc )
    {
        __classAlloc += 10;
        __classes     = ( XSEClassInfo * )realloc( __classes, sizeof( XSEClassInfo ) * __classAlloc );
    }
    
    __classes[ __classCount ] = info;
    
    __classCount++;
    
    return __classCount;
}

XSETypeRef XSECreateInstance( XSETypeID typeID )
{
    XSEClassInfo   * classInfo;
    __XSEAllocInfo * allocInfo;
    XSETypeRef       object;
    
    if( typeID > __classCount || typeID == 0 )
    {
        return NULL;
    }
    
    classInfo = &( __classes[ typeID - 1 ] );
    object    = XSEAlloc( classInfo->instanceSize );
    
    if( object == NULL )
    {
        return NULL;
    }
    
    allocInfo            = __XSEGetAllocInfo( object );
    allocInfo->classInfo = classInfo;
    
    if( classInfo->constructor != NULL )
    {
        classInfo->constructor( object );
    }
    
    return object;
}

XSETypeID XSEGetTypeID( XSETypeRef object )
{
    __XSEAllocInfo * allocInfo;
    size_t           i;
    
    allocInfo = __XSEGetAllocInfo( object );
    
    if( allocInfo == NULL )
    {
        return 0;
    }
    
    for( i = 0; i < __classCount; i++ )
    {
        if( allocInfo->classInfo == &( __classes[ i ] ) )
        {
            return i + 1;
        }
    }
    
    return 0;
}
