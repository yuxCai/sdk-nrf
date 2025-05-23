/*
 * Copyright (c) 2017-2021, Arm Limited. All rights reserved.
 * Copyright (c) 2023 Cypress Semiconductor Corporation (an Infineon company)
 * or an affiliate of Cypress Semiconductor Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */
#ifndef __TFM_NS_INTERFACE_H__
#define __TFM_NS_INTERFACE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "tfm_veneers.h"

typedef int32_t (*veneer_fn) (uint32_t arg0, uint32_t arg1,
                              uint32_t arg2, uint32_t arg3);

/**
 * \brief NS interface, veneer function dispatcher
 *
 * \details This function implements the dispatching mechanism for the
 *          desired veneer function, to be called with the parameters
 *          described from arg0 to arg3.
 *
 * \note    NSPE can use default implementation of this function or implement
 *          this function according to NS specific implementation and actual
 *          usage scenario.
 *
 * \param[in] fn   Function pointer to the veneer function desired
 * \param[in] arg0 Argument 0 of fn
 * \param[in] arg1 Argument 1 of fn
 * \param[in] arg2 Argument 2 of fn
 * \param[in] arg3 Argument 3 of fn
 *
 * \return Returns the same return value of the requested veneer function
 *
 * \note This API must ensure the return value is from the veneer function.
 *       Other unrecoverable errors must be considered as fatal error and should
 *       not return.
 */
int32_t tfm_ns_interface_dispatch(veneer_fn fn,
                                  uint32_t arg0, uint32_t arg1,
                                  uint32_t arg2, uint32_t arg3);

/**
 * \brief NS interface initialization function
 *
 * \details This function initializes TF-M NS interface.
 *
 * \note    NSPE can use default implementation of this function or implement
 *          this function according to NS specific implementation and actual
 *          usage scenario.
 *
 * \return `OS_WRAPPER_SUCCESS` on success or `OS_WRAPPER_ERROR` on error
 */
uint32_t tfm_ns_interface_init(void);

#ifdef __cplusplus
}
#endif

#endif /* __TFM_NS_INTERFACE_H__ */
