// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2025 BaSSeM
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

// #############################################################################
// #### Description ############################################################
// #############################################################################

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

#include "Platform.h"

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

#ifndef DEBUG
    #define DEBUG
#endif

#ifdef DEBUG
    #undef DEBUG
#endif

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### Include(s) #############################################################
// #############################################################################

#include "Kernel.h"
#include "Kernel_Internal.h"

// #############################################################################
// #### Private Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### Private Type(s) ########################################################
// #############################################################################

typedef struct KERNEL_Context
{
    KERNEL_Instance_t Instance;
} KERNEL_Context_t;

// #############################################################################
// #### Private Method(s) Prototype ############################################
// #############################################################################

static KERNEL_Status_t KERNEL_Context_Initialize( void );
static KERNEL_Status_t KERNEL_Context_Cycle( void );
static KERNEL_Status_t KERNEL_Context_DeInitialize( void );

// #############################################################################
// #### Private Variable(s) ####################################################
// #############################################################################

static KERNEL_Context_t KERNEL_Context;

// #############################################################################
// #### Private Method(s) ######################################################
// #############################################################################

static KERNEL_Status_t KERNEL_Context_Initialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Success;

    do
    {
        KERNEL_Trace( "%s( void )", __FUNCTION__ );
    }
    while ( 0 );

    return Status;
}

static KERNEL_Status_t KERNEL_Context_Cycle( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Success;

    do
    {
        KERNEL_Trace( "%s( void )", __FUNCTION__ );
    }
    while ( 0 );

    return Status;
}

static KERNEL_Status_t KERNEL_Context_DeInitialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Success;

    do
    {
        KERNEL_Trace( "%s( void )", __FUNCTION__ );
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

KERNEL_Status_t KERNEL_Initialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Success;

    do
    {
        KERNEL_Trace( "%s( void )", __FUNCTION__ );

        if ( ( Status = KERNEL_Context_Initialize( ) ) != KERNEL_Status_Success )
        {
            break;
        }

        if ( ( Status = KERNEL_Instance_Initialize( &KERNEL_Context.Instance ) ) != KERNEL_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_Cycle( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Success;

    do
    {
        KERNEL_Trace( "%s( void )", __FUNCTION__ );

        if ( ( Status = KERNEL_Context_Cycle( ) ) != KERNEL_Status_Success )
        {
            break;
        }

        if ( ( Status = KERNEL_Instance_Cycle( &KERNEL_Context.Instance ) ) != KERNEL_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_DeInitialize( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Success;

    do
    {
        KERNEL_Trace( "%s( void )", __FUNCTION__ );

        if ( ( Status = KERNEL_Instance_DeInitialize( &KERNEL_Context.Instance ) ) != KERNEL_Status_Success )
        {
            break;
        }

        if ( ( Status = KERNEL_Context_DeInitialize( ) ) != KERNEL_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_GetResetReason( KERNEL_ResetReason_t * ResetReason )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;

    do
    {
        KERNEL_Trace( "%s( ResetReason=%p )", __FUNCTION__, ResetReason );

        if ( ResetReason == NULL )
        {
            Status = KERNEL_Status_ArgumentInvalid;
            break;
        }

        Status = KERNEL_Instance_GetResetReason( &KERNEL_Context.Instance, ResetReason );
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_TaskCreate( KERNEL_Task_t * Task )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;

    do
    {
        KERNEL_Trace( "%s( Task=%p )", __FUNCTION__, Task );

        if ( Task == NULL )
        {
            Status = KERNEL_Status_ArgumentInvalid;
            break;
        }

        Status = KERNEL_Instance_TaskCreate( &KERNEL_Context.Instance, Task );
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_TaskDestroy( KERNEL_Task_t * Task )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;

    do
    {
        KERNEL_Trace( "%s( Task=%p )", __FUNCTION__, Task );

        if ( Task == NULL )
        {
            Status = KERNEL_Status_ArgumentInvalid;
            break;
        }

        Status = KERNEL_Instance_TaskDestroy( &KERNEL_Context.Instance, Task );
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_Reset( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Success;

    do
    {
        KERNEL_Trace( "%s( void )", __FUNCTION__ );

        Status = KERNEL_Instance_Reset( &KERNEL_Context.Instance );
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_ClockEnable( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Success;

    do
    {
        KERNEL_Trace( "%s( void )", __FUNCTION__ );

        Status = KERNEL_Instance_ClockEnable( &KERNEL_Context.Instance );
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_InterruptDisable( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;

    do
    {
        KERNEL_Trace( "%s( void )", __FUNCTION__ );

        Status = KERNEL_Instance_InterruptDisable( &KERNEL_Context.Instance );
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_InterruptEnable( void )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;

    do
    {
        KERNEL_Trace( "%s( void )", __FUNCTION__ );

        Status = KERNEL_Instance_InterruptEnable( &KERNEL_Context.Instance );
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char KERNEL_VERSION[] = "0.0.0.v20260517-1631";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
