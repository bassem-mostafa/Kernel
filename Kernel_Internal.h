// #############################################################################
// #### Copyright ##############################################################
// #############################################################################

/*
 * Copyright 2024 BaSSeM
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

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

#ifndef KERNEL_INTERNAL_H_
    #define KERNEL_INTERNAL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "KERNEL_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    #ifndef KERNEL_TIM
        #define KERNEL_TIM PLATFORM_DEFAULT_TIM
    #endif

    #ifndef KERNEL_LOG
        #define KERNEL_LOG PLATFORM_DEFAULT_LOG
    #endif

    #define KERNEL_NAME       "KERNEL"
    #define KERNEL_LOG_PREFIX UTIL_StringConcatenateConstant( KERNEL_NAME, "> " )

    #ifdef DEBUG
        #define KERNEL_Raw( Level, Format, ... ) LOG_Raw( KERNEL_LOG, Level, Format, ##__VA_ARGS__ )
        #define KERNEL_Trace( Format, ... )      LOG_Trace( KERNEL_LOG, UTIL_StringConcatenateConstant( KERNEL_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define KERNEL_Debug( Format, ... )      LOG_Debug( KERNEL_LOG, UTIL_StringConcatenateConstant( KERNEL_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define KERNEL_Info( Format, ... )       LOG_Info( KERNEL_LOG, UTIL_StringConcatenateConstant( KERNEL_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define KERNEL_Warning( Format, ... )    LOG_Warning( KERNEL_LOG, UTIL_StringConcatenateConstant( KERNEL_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define KERNEL_Error( Format, ... )      LOG_Error( KERNEL_LOG, UTIL_StringConcatenateConstant( KERNEL_LOG_PREFIX, Format ), ##__VA_ARGS__ )
        #define KERNEL_Fatal( Format, ... )      LOG_Fatal( KERNEL_LOG, UTIL_StringConcatenateConstant( KERNEL_LOG_PREFIX, Format ), ##__VA_ARGS__ )
    #else
        #define KERNEL_Raw( Level, Format, ... )
        #define KERNEL_Trace( Format, ... )
        #define KERNEL_Debug( Format, ... )
        #define KERNEL_Info( Format, ... )
        #define KERNEL_Warning( Format, ... )
        #define KERNEL_Error( Format, ... )
        #define KERNEL_Fatal( Format, ... )
    #endif

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    typedef struct KERNEL_Instance_Context KERNEL_Instance_Context_t;

    typedef struct KERNEL_Instance
    {
        KERNEL_Instance_Context_t * Context;
    } KERNEL_Instance_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    // The following APIs MUST be provided by the port
    KERNEL_Status_t KERNEL_Instance_Initialize( KERNEL_Instance_t * Instance );
    KERNEL_Status_t KERNEL_Instance_Cycle( KERNEL_Instance_t * Instance );
    KERNEL_Status_t KERNEL_Instance_DeInitialize( KERNEL_Instance_t * Instance );

    KERNEL_Status_t KERNEL_Instance_TaskCreate( KERNEL_Instance_t * Instance, KERNEL_Task_t * Task );
    KERNEL_Status_t KERNEL_Instance_TaskDestroy( KERNEL_Instance_t * Instance, KERNEL_Task_t * Task );

    KERNEL_Status_t KERNEL_Instance_Reset( KERNEL_Instance_t * Instance );
    KERNEL_Status_t KERNEL_Instance_ClockEnable( KERNEL_Instance_t * Instance );
    KERNEL_Status_t KERNEL_Instance_InterruptDisable( KERNEL_Instance_t * Instance );
    KERNEL_Status_t KERNEL_Instance_InterruptEnable( KERNEL_Instance_t * Instance );

    // TODO Add More APIs

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* KERNEL_INTERNAL_H_ */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
