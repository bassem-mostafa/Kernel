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

/**
 *  @file
 *
 *  @brief Platform Kernel
 */

// #############################################################################
// #### Control Include(s) #####################################################
// #############################################################################

// #############################################################################
// #### Control Macro(s) #######################################################
// #############################################################################

// #############################################################################
// #### File Guard #############################################################
// #############################################################################

/**
 *  @addtogroup Platform_Kernel
 *
 *  @note Default port is STUB if Unspecified
 *
 *  @{
 */

/**
 *  @defgroup Platform_Kernel_Variant Variant
 *
 *  @{
 *  @}
 */

#ifndef KERNEL_H_
    #define KERNEL_H_

    #ifdef __cplusplus
extern "C"
{
    #endif /* __cplusplus */

    // #############################################################################
    // #### Include(s) #############################################################
    // #############################################################################

    #include "Kernel_Port.h"

    // #############################################################################
    // #### Public Macro(s) ########################################################
    // #############################################################################

    // #############################################################################
    // #### Public Type(s) #########################################################
    // #############################################################################

    /**
     *  @brief Kernel Operation Status
     *
     *  @enum KERNEL_Status_t
     */
    typedef enum KERNEL_Status
    {
        KERNEL_Status_Success = 0,     ///< Success
        KERNEL_Status_ArgumentInvalid, ///< Argument Invalid
        KERNEL_Status_NotSupported,    ///< Not Supported
        KERNEL_Status_Error,           ///< General Error
        KERNEL_Status_Busy,            ///< Busy
        KERNEL_Status_Timeout,         ///< Timeout
    } KERNEL_Status_t;

    /**
     *  @brief Kernel Task Type
     *
     *  @struct KERNEL_Task
     */
    typedef struct KERNEL_Task
    {
        KERNEL_Status_t ( *Initialize )( void );   ///< Initialize API
        KERNEL_Status_t ( *Cycle )( void );        ///< Cycle API
        KERNEL_Status_t ( *DeInitialize )( void ); ///< DeInitialize API

        // Managed Internally
        LIST_Node_t Node;
    } KERNEL_Task_t;

    /**
     *  @brief KERNEL Callback Context
     */
    typedef void KERNEL_CallbackContext_t;

    /**
     *  @brief KERNEL Callback
     */
    typedef KERNEL_Status_t( KERNEL_Callback_t )( KERNEL_CallbackContext_t * Context );

    /**
     *  @brief KERNEL On State Change Configuration
     *
     *  @struct KERNEL_OnEnter_t
     */
    typedef struct KERNEL_OnPowerRequest
    {
        KERNEL_Callback_t * Callback;
    } KERNEL_OnPowerRequest_t;

    // #############################################################################
    // #### Public Method(s) #######################################################
    // #############################################################################

    /**
     *  @brief Initialize Kernel
     *
     *  @param[in] KERNELx Instance
     *
     *  @return KERNEL_Status_t
     */
    KERNEL_Status_t KERNEL_Initialize( KERNEL_t KERNELx );

    /**
     *  @brief Cycle Kernel and ALL Created Tasks
     *
     *  @note Created tasks are cycled in SAME ORDER of creation
     *
     *  @param[in] KERNELx Instance
     *
     *  @return KERNEL_Status_t
     */
    KERNEL_Status_t KERNEL_Cycle( KERNEL_t KERNELx );

    /**
     *  @brief DeInitialize Kernel
     *
     *  @param[in] KERNELx Instance
     *
     *  @return KERNEL_Status_t
     */
    KERNEL_Status_t KERNEL_DeInitialize( KERNEL_t KERNELx );

    /**
     *  @brief Get Kernel Power Mode
     *
     *  @param[in]  KERNELx   Instance
     *  @param[out] PowerMode Power Mode
     *
     *  @return KERNEL_Status_t
     */
    KERNEL_Status_t KERNEL_GetPowerMode( KERNEL_t KERNELx, KERNEL_PowerMode_t * PowerMode );

    /**
     *  @brief Set Kernel Power Mode
     *
     *  @param[in] KERNELx   Instance
     *  @param[in] PowerMode Power Mode
     *
     *  @return KERNEL_Status_t
     */
    KERNEL_Status_t KERNEL_SetPowerMode( KERNEL_t KERNELx, KERNEL_PowerMode_t PowerMode );

    /**
     *  @brief Get reset reason
     *
     *  @param[in] KERNELx Instance
     *  @param[out] ResetReason Reset Reason
     *
     *  @return KERNEL_Status_t
     */
    KERNEL_Status_t KERNEL_GetResetReason( KERNEL_t KERNELx, KERNEL_ResetReason_t * ResetReason );

    /**
     *  @brief Create and register Task into Kernel
     *
     *  @param[in] KERNELx Instance
     *  @param[in] Task Task
     *
     *  @return KERNEL_Status_t
     */
    KERNEL_Status_t KERNEL_TaskCreate( KERNEL_t KERNELx, KERNEL_Task_t * Task );

    /**
     *  @brief Delete and unregister Task from Kernel
     *
     *  @param[in] KERNELx Instance
     *  @param[in] Task Task
     *
     *  @return KERNEL_Status_t
     */
    KERNEL_Status_t KERNEL_TaskDestroy( KERNEL_t KERNELx, KERNEL_Task_t * Task );

    /**
     *  @brief Reset
     *
     *  @param[in] KERNELx Instance
     *
     *  @return KERNEL_Status_t
     */
    KERNEL_Status_t KERNEL_Reset( KERNEL_t KERNELx );

    /**
     *  @brief Enable clock
     *
     *  @param[in] KERNELx Instance
     *
     *  @return KERNEL_Status_t
     */
    KERNEL_Status_t KERNEL_ClockEnable( KERNEL_t KERNELx );

    /**
     *  @brief Disable ALL Interrupts
     *
     *  @param[in] KERNELx Instance
     *
     *  @return KERNEL_Status_t
     */
    KERNEL_Status_t KERNEL_InterruptDisable( KERNEL_t KERNELx );

    /**
     *  @brief Enable ALL Interrupts
     *
     *  @param[in] KERNELx Instance
     *
     *  @return KERNEL_Status_t
     */
    KERNEL_Status_t KERNEL_InterruptEnable( KERNEL_t KERNELx );

    // #############################################################################
    // #### Public Variable(s) #####################################################
    // #############################################################################

    /**
     *  @brief Version
     */
    extern const char KERNEL_VERSION[];

    // #############################################################################
    // #### File Guard #############################################################
    // #############################################################################

    #ifdef __cplusplus
} /* extern "C" */
    #endif /* __cplusplus */

#endif /* KERNEL_H_ */

/**
 *  @}
 */

// #############################################################################
// #### END OF FILE ############################################################
// #############################################################################
