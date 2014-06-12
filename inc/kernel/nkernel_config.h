/*
 * This file is part of nKernel.
 *
 * Copyright (C) 2010 - 2013 Nenad Radulovic
 *
 * nKernel is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * nKernel is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with nKernel.  If not, see <http://www.gnu.org/licenses/>.
 *
 * web site:    http://github.com/nradulovic
 * e-mail  :    nenad.b.radulovic@gmail.com
 *//***********************************************************************//**
 * @file
 * @author  	Nenad Radulovic
 * @brief   	Kernel Configuration settings
 * @addtogroup  kern
 *********************************************************************//** @{ */
/**@defgroup    kern_cfg Configuration
 * @brief       Kernel Configuration settings
 * @{ *//*--------------------------------------------------------------------*/

#if !defined(KERNEL_CFG_H__)
#define KERNEL_CFG_H__

/*=========================================================  INCLUDE FILES  ==*/
/*===============================================================  DEFINES  ==*/
/** @cond */

/** @endcond */
/*==============================================================  SETTINGS  ==*/

/**@brief       Enable/disable Debug module
 * @details     Possible values:
 *              - 0 - All debug options are disabled
 *              - 1 - Debug options can be enabled individually
 */
#if !defined(CONFIG_DEBUG)
# define CONFIG_DEBUG                  0
#endif

/**@brief       Enable/disable API arguments validation
 * @details     Possible values:
 *              - 0 - API validation is disabled
 *              - 1 - API validation is enabled
 *
 * @note        This option is enabled only if @ref CONFIG_DEBUG is enabled, too.
 */
#if !defined(CONFIG_API_VALIDATION)
# define CONFIG_API_VALIDATION          1
#endif

/**@brief       Enable/disable internal checks
 * @details     Possible values:
 *              - 0 - API validation is disabled
 *              - 1 - API validation is enabled
 *
 * @note        This option is enabled only if @ref CONFIG_DEBUG is enabled, too.
 */
#if !defined(CONFIG_ASSERT_INTERNAL)
# define CONFIG_ASSERT_INTERNAL         1
#endif

/*------------------------------------------------------------------------*//**
 * @name        Kernel configuration options and settings
 * @{ *//*--------------------------------------------------------------------*/

/**@brief       Scheduler priority levels
 * @details     Possible values:
 *              - Min: 3 (three priority levels)
 *              - Max: 256
 */
#if !defined(CONFIG_PRIORITY_LEVELS)
# define CONFIG_PRIORITY_LEVELS             8u
#endif

/**@brief       Scheduler Round-Robin time quantum
 */
#if !defined(CFG_SCHED_TIME_QUANTUM)
# define CFG_SCHED_TIME_QUANTUM         10u
#endif

/**@brief       Enable/disable scheduler power savings mode
 * @details     Possible values are:
 *              - 0u - power saving is disabled
 *              - 1u - power saving is enabled
 */
#if !defined(CFG_SCHED_POWER_SAVE)
# define CFG_SCHED_POWER_SAVE           1u
#endif

/**@brief       System timer adaptive mode
 * @details     Possible values are:
 *              - 0u - adaptive mode is disabled
 *              - 1u - adaptive mode is enabled
 */
#if !defined(CFG_SYSTMR_ADAPTIVE_MODE)
# define CFG_SYSTMR_ADAPTIVE_MODE       0u
#endif

/**@brief       The frequency of system timer tick event
 * @note        This setting is valid only if configuration option
 *              @ref CONFIG_SYSTIMER_CLOCK_FREQ is properly set in port
 *              configuration file cpu_cfg.h
 */
#if !defined(CFG_SYSTMR_EVENT_FREQUENCY)
# define CFG_SYSTMR_EVENT_FREQUENCY     100ul
#endif

/**@brief       The size of the system timer tick event counter
 * @details     Possible values are:
 *              - 0u - 8 bit counter
 *              - 1u - 16 bit counter
 *              - 2u - 32 bit counter
 */
#if !defined(CFG_SYSTMR_TICK_TYPE)
# define CFG_SYSTMR_TICK_TYPE           2u
#endif

/** @} *//*---------------------------------------------------------------*//**
 * @name        Kernel pre hooks
 * @{ *//*--------------------------------------------------------------------*/

/**@brief       System timer event hook function
 */
#if !defined(CFG_HOOK_PRE_SYSTMR_EVENT)
# define CFG_HOOK_PRE_SYSTMR_EVENT      0u
#endif

/**@brief       Pre kernel initialization hook function
 */
#if !defined(CFG_HOOK_PRE_KERN_INIT)
# define CFG_HOOK_PRE_KERN_INIT         0u
#endif

/**@brief       Post kernel initialization hook function
 */
#if !defined(CFG_HOOK_PORT_KERN_INIT)
# define CFG_HOOK_POST_KERN_INIT        0u
#endif

/**@brief       Pre kernel start hook function
 */
#if !defined(CFG_HOOK_PRE_KERN_START)
# define CFG_HOOK_PRE_KERN_START        0u
#endif

/**@brief       Post thread initialization hook function
 */
#if !defined(CFG_HOOK_POST_THD_INIT)
# define CFG_HOOK_POST_THD_INIT         0u
#endif

/**@brief       Pre thread termination hook function
 */
#if !defined(CFG_HOOK_PRE_THD_TERM)
# define CFG_HOOK_PRE_THD_TERM          0u
#endif

/**@brief       Pre idle hook function
 */
#if !defined(CFG_HOOK_PRE_IDLE)
# define CFG_HOOK_PRE_IDLE              0u
#endif

/**@brief       Post idle hook function
 */
#if !defined(CFG_HOOK_POST_IDLE)
# define CFG_HOOK_POST_IDLE             0u
#endif

/**@brief       Pre context switch hook function
 */
#if !defined(CFG_HOOK_PRE_CTX_SW)
# define CFG_HOOK_PRE_CTX_SW            0u
#endif

/** @} *//*-------------------------------------------------------------------*/
/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/

#if ((CONFIG_DEBUG != 1) && (CONFIG_DEBUG != 0))
# error "nKernel RT Kernel: Configuration option CONFIG_DEBUG is out of range."
#endif

#if ((CONFIG_API_VALIDATION != 1) && (CONFIG_API_VALIDATION != 0))
# error "nKernel RT Kernel: Configuration option CONFIG_DEBUG_API_VALIDATION is out of range."
#endif

#if ((CONFIG_ASSERT_INTERNAL != 1) && (CONFIG_ASSERT_INTERNAL != 0))
# error "nKernel RT Kernel: Configuration option CONFIG_DEBUG_INTERNAL_CHECK is out of range."
#endif

#if (CONFIG_DEBUG == 0) || defined(NDEBUG)
# undef  CONFIG_DEBUG
# define CONFIG_DEBUG                   0
# undef  CONFIG_API_VALIDATION
# define CONFIG_API_VALIDATION          0
# undef  CONFIG_ASSERT_INTERNAL
# define CONFIG_ASSERT_INTERNAL         0
#endif

#if ((3u > CONFIG_PRIORITY_LEVELS) || (256u < CONFIG_PRIORITY_LEVELS))
# error "nKernel RT Kernel: Configuration option CFG_SCHED_PRIO_LVL is out of range."
#endif

#if ((1u != CFG_SCHED_POWER_SAVE) && (0u != CFG_SCHED_POWER_SAVE))
# error "nKernel RT Kernel: Configuration option CFG_SCHED_POWER_SAVE is out of range."
#endif

#if ((1u != CFG_SYSTMR_ADAPTIVE_MODE) && (0u != CFG_SYSTMR_ADAPTIVE_MODE))
# error "nKernel RT Kernel: Configuration option CFG_SYSTMR_ADAPTIVE_MODE is out of range."
#endif

#if ((0u == CFG_SCHED_POWER_SAVE) && (1u == CFG_SYSTMR_ADAPTIVE_MODE))
# error "nKernel RT Kernel: Configuration option CFG_SCHED_PRIO_LVL must be enabled when CFG_SYSTMR_ADAPTIVE_MODE is enabled, too."
#endif

#if ((1u != CFG_HOOK_PRE_SYSTMR_EVENT) && (0u != CFG_HOOK_PRE_SYSTMR_EVENT))
# error "nKernel RT Kernel: Configuration option CFG_HOOK_PRE_SYSTMR_EVENT is out of range."
#endif

#if ((1u != CFG_HOOK_PRE_KERN_INIT) && (0u != CFG_HOOK_PRE_KERN_INIT))
# error "nKernel RT Kernel: Configuration option CFG_HOOK_PRE_KERN_INIT is out of range."
#endif

#if ((1u != CFG_HOOK_POST_KERN_INIT) && (0u != CFG_HOOK_POST_KERN_INIT))
# error "nKernel RT Kernel: Configuration option CFG_HOOK_POST_KERN_INIT is out of range."
#endif

#if ((1u != CFG_HOOK_PRE_KERN_START) && (0u != CFG_HOOK_PRE_KERN_START))
# error "nKernel RT Kernel: Configuration option CFG_HOOK_PRE_KERN_START is out of range."
#endif

#if ((1u != CFG_HOOK_POST_THD_INIT) && (0u != CFG_HOOK_POST_THD_INIT))
# error "nKernel RT Kernel: Configuration option CFG_HOOK_POST_THD_INIT is out of range."
#endif

#if ((1u != CFG_HOOK_PRE_THD_TERM) && (0u != CFG_HOOK_PRE_THD_TERM))
# error "nKernel RT Kernel: Configuration option CFG_HOOK_PRE_THD_TERM is out of range."
#endif

#if ((1u != CFG_HOOK_PRE_THD_TERM) && (0u != CFG_HOOK_PRE_THD_TERM))
# error "nKernel RT Kernel: Configuration option CFG_HOOK_PRE_THD_TERM is out of range."
#endif

#if ((1u != CFG_HOOK_PRE_IDLE) && (0u != CFG_HOOK_PRE_IDLE))
# error "nKernel RT Kernel: Configuration option CFG_HOOK_PRE_IDLE is out of range."
#endif

#if ((1u != CFG_HOOK_PRE_CTX_SW) && (0u != CFG_HOOK_PRE_CTX_SW))
# error "nKernel RT Kernel: Configuration option CFG_HOOK_PRE_CTX_SW is out of range."
#endif

#if (0u > CFG_SYSTMR_TICK_TYPE) || (2u < CFG_SYSTMR_TICK_TYPE)
# error "nKernel RT Kernel: Configuration option CFG_SYSTMR_TICK_TYPE is out of range."
#endif

/** @endcond *//** @} *//******************************************************
 * END of kernel_cfg.h
 ******************************************************************************/
#endif /* KERNEL_CFG_H__ */