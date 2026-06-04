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

        UTIL_UNUSED( KERNEL_Context );
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

        UTIL_UNUSED( KERNEL_Context );
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

        UTIL_UNUSED( KERNEL_Context );
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Method(s) #######################################################
// #############################################################################

KERNEL_Status_t KERNEL_Initialize( KERNEL_t KERNELx )
{
    KERNEL_Status_t Status = KERNEL_Status_Success;
    KERNEL_Status_t KERNEL_Status = KERNEL_Status_Success;

    do
    {
        KERNEL_Trace( "%s( KERNELx=%d )", __FUNCTION__, KERNELx );

        if ( ( Status = KERNEL_Context_Initialize( ) ) != KERNEL_Status_Success )
        {
            break;
        }

        KERNEL_t KERNEL_start = ( KERNELx == KERNEL_All ? KERNEL_Null : KERNELx );
        KERNEL_t KERNEL_end = ( KERNELx == KERNEL_All ? KERNEL_Count : KERNELx + 1 );
        for ( KERNEL_t KERNEL_x = KERNEL_start; KERNEL_x < KERNEL_end; ++KERNEL_x )
        {
            if ( ( KERNEL_Status = KERNEL_Port_Initialize( KERNEL_x ) ) != KERNEL_Status_Success )
            {
                Status = KERNEL_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_Cycle( KERNEL_t KERNELx )
{
    KERNEL_Status_t Status = KERNEL_Status_Success;
    KERNEL_Status_t KERNEL_Status = KERNEL_Status_Success;

    do
    {
        KERNEL_Trace( "%s( KERNELx=%d )", __FUNCTION__, KERNELx );

        if ( ( Status = KERNEL_Context_Cycle( ) ) != KERNEL_Status_Success )
        {
            break;
        }

        KERNEL_t KERNEL_start = ( KERNELx == KERNEL_All ? KERNEL_Null : KERNELx );
        KERNEL_t KERNEL_end = ( KERNELx == KERNEL_All ? KERNEL_Count : KERNELx + 1 );
        for ( KERNEL_t KERNEL_x = KERNEL_start; KERNEL_x < KERNEL_end; ++KERNEL_x )
        {
            if ( ( KERNEL_Status = KERNEL_Port_Cycle( KERNEL_x ) ) != KERNEL_Status_Success )
            {
                Status = KERNEL_Status;
            }
        }
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_DeInitialize( KERNEL_t KERNELx )
{
    KERNEL_Status_t Status = KERNEL_Status_Success;
    KERNEL_Status_t KERNEL_Status = KERNEL_Status_Success;

    do
    {
        KERNEL_Trace( "%s( KERNELx=%d )", __FUNCTION__, KERNELx );

        KERNEL_t KERNEL_start = ( KERNELx == KERNEL_All ? KERNEL_Null : KERNELx );
        KERNEL_t KERNEL_end = ( KERNELx == KERNEL_All ? KERNEL_Count : KERNELx + 1 );
        for ( KERNEL_t KERNEL_x = KERNEL_start; KERNEL_x < KERNEL_end; ++KERNEL_x )
        {
            if ( ( KERNEL_Status = KERNEL_Port_DeInitialize( KERNEL_x ) ) != KERNEL_Status_Success )
            {
                Status = KERNEL_Status;
            }
        }

        if ( ( Status = KERNEL_Context_DeInitialize( ) ) != KERNEL_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_GetResetReason( KERNEL_t KERNELx, KERNEL_ResetReason_t * ResetReason )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;

    do
    {
        KERNEL_Trace( "%s( KERNELx=%d, ResetReason=%p )", __FUNCTION__, KERNELx, ResetReason );

        if ( ResetReason == NULL )
        {
            Status = KERNEL_Status_ArgumentInvalid;
            break;
        }

        Status = KERNEL_Port_GetResetReason( KERNELx, ResetReason );
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_InterruptDisable( KERNEL_t KERNELx )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;

    do
    {
        KERNEL_Trace( "%s( KERNELx=%d )", __FUNCTION__, KERNELx );

        Status = KERNEL_Port_InterruptDisable( KERNELx );
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_InterruptEnable( KERNEL_t KERNELx )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;

    do
    {
        KERNEL_Trace( "%s( KERNELx=%d )", __FUNCTION__, KERNELx );

        Status = KERNEL_Port_InterruptEnable( KERNELx );
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_Reset( KERNEL_t KERNELx )
{
    KERNEL_Status_t Status = KERNEL_Status_Success;

    do
    {
        KERNEL_Trace( "%s( KERNELx=%d )", __FUNCTION__, KERNELx );

        Status = KERNEL_Port_Reset( KERNELx );
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_ClockEnable( KERNEL_t KERNELx )
{
    KERNEL_Status_t Status = KERNEL_Status_Success;

    do
    {
        KERNEL_Trace( "%s( KERNELx=%d )", __FUNCTION__, KERNELx );

        Status = KERNEL_Port_ClockEnable( KERNELx );
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_GetPowerState( KERNEL_t KERNELx, KERNEL_PowerState_t * PowerState )
{
    KERNEL_Status_t Status = KERNEL_Status_Success;

    do
    {
        KERNEL_Trace( "%s( KERNELx=%d, PowerState=%p )", __FUNCTION__, KERNELx, PowerState );

        if ( ( Status = KERNEL_Port_GetPowerState( KERNELx, PowerState ) ) != KERNEL_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_SetPowerState( KERNEL_t KERNELx, KERNEL_PowerState_t PowerState )
{
    KERNEL_Status_t Status = KERNEL_Status_Success;

    do
    {
        KERNEL_Trace( "%s( KERNELx=%d, PowerState=%d )", __FUNCTION__, KERNELx, PowerState );

        if ( ( Status = KERNEL_Port_SetPowerState( KERNELx, PowerState ) ) != KERNEL_Status_Success )
        {
            break;
        }
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_TaskCreate( KERNEL_t KERNELx, KERNEL_Task_t * Task )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;

    do
    {
        KERNEL_Trace( "%s( KERNELx=%d, Task=%p )", __FUNCTION__, KERNELx, Task );

        if ( Task == NULL )
        {
            Status = KERNEL_Status_ArgumentInvalid;
            break;
        }

        Status = KERNEL_Port_TaskCreate( KERNELx, Task );
    }
    while ( 0 );

    return Status;
}

KERNEL_Status_t KERNEL_TaskDestroy( KERNEL_t KERNELx, KERNEL_Task_t * Task )
{
    KERNEL_Status_t Status = KERNEL_Status_Error;

    do
    {
        KERNEL_Trace( "%s( KERNELx=%d, Task=%p )", __FUNCTION__, KERNELx, Task );

        if ( Task == NULL )
        {
            Status = KERNEL_Status_ArgumentInvalid;
            break;
        }

        Status = KERNEL_Port_TaskDestroy( KERNELx, Task );
    }
    while ( 0 );

    return Status;
}

// #############################################################################
// #### Public Variable(s) #####################################################
// #############################################################################

const char KERNEL_VERSION[] = "0.0.0.v20260604-1909";

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
