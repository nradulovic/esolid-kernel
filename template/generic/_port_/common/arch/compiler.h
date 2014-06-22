/*
 * This file is part of NUB RT Kernel.
 *
 * Copyright (C) 2010 - 2013 Nenad Radulovic
 *
 * NUB RT Kernel is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * NUB RT Kernel is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with NUB RT Kernel.  If not, see <http://www.gnu.org/licenses/>.
 *
 * web site:    http://github.com/nradulovic
 * e-mail  :    nenad.b.radulovic@gmail.com
 *//***********************************************************************//**
 * @file
 * @author  	Nenad Radulovic
 * @brief       Interface of Compiler port - Template
 * @addtogroup  template_compiler
 *********************************************************************//** @{ */

#ifndef COMPILER_H_
#define COMPILER_H_

/*=========================================================  INCLUDE FILES  ==*/

#include <stdint.h>
#include <stddef.h>

/*===============================================================  MACRO's  ==*/

/*------------------------------------------------------------------------*//**
 * @name        Compiler provided macros
 * @brief       Port interface macros and port specific macros
 * @details     These macros are used to ease the writing of ports. All macros
 *              prefixed with @b PORT_ are part of the port interface.
 * @{ *//*--------------------------------------------------------------------*/

/**@brief       C extension - make a function inline
 * @details     The point of making a function @c inline is to hint to the
 *              compiler that it is worth making some form of extra effort to
 *              call the function faster than it would otherwise - generally by
 *              substituting the code of the function into its caller. As well
 *              as eliminating the need for a call and return sequence, it might
 *              allow the compiler to perform certain optimizations between the
 *              bodies of both functions.
 */
#define PORT_C_INLINE                   inline

/**@brief       C extension - make a function inline - always
 * @details     Generally, functions are not inlined unless optimization is
 *              specified. For functions declared inline, this attribute inlines
 *              the function even if no optimization level was specified.
 */
#define PORT_C_INLINE_ALWAYS            inline

/**@brief       Omit function prologue/epilogue sequences
 * @details     This attribute will indicate that the specified function does
 *              not need prologue/epilogue sequences generated by the compiler.
 *              It is up to the programmer to provide these sequences. The only
 *              statements that can be safely included in naked functions are
 *              @c asm statements that do not have operands. All other
 *              statements, including declarations of local variables, @c if
 *              statements, and so forth, should be avoided. Naked functions
 *              should be used to implement the body of an assembly function,
 *              while allowing the compiler to construct the requisite function
 *              declaration for the assembler.
 */
#define PORT_C_NAKED

/**@brief       Provides function name for assert macros
 */
#define PORT_C_FUNC                     "unknown"

/**@brief       Declares a weak function
 * @details     The weak attribute causes the declaration to be emitted as a
 *              weak symbol rather than a global. This is primarily useful in
 *              defining library functions that can be overridden in user code,
 *              though it can also be used with non-function declarations.
 */
#define PORT_C_WEAK

/**@brief       This attribute specifies a minimum alignment (in bytes) for
 *              variables of the specified type.
 * @note        The alignment of any given struct or union type is required by
 *              the ISO C standard to be at least a perfect multiple of the
 *              lowest common multiple of the alignments of all of the members
 *              of the struct or union in question.
 */
#define PORT_C_ALIGNED(expr)

/**@brief       A standardized way of properly setting the value of HW register
 * @param       reg
 *              Register which will be written to
 * @param       mask
 *              The bit mask which will be applied to register and @c val
 *              argument
 * @param       val
 *              Value to be written into the register
 *
 */
#define PORT_HWREG_SET(reg, mask, val)                                          \
    do {                                                                        \
        portReg_T tmp;                                                          \
        tmp = (reg);                                                            \
        tmp &= ~(mask);                                                         \
        tmp |= ((mask) & (val));                                                \
        (reg) = tmp;                                                            \
    } while (0U)

/** @} *//*---------------------------------------------  C++ extern begin  --*/
#ifdef __cplusplus
extern "C" {
#endif

/*============================================================  DATA TYPES  ==*/

/*------------------------------------------------------------------------*//**
 * @name        Compiler provided data types
 * @brief       The compiler port must provide some C90 (C99) data types
 * @details     The compiler port must:
 *              - declare sets of integer types having specified widths,
 *              standard type definitions and shall define corresponding sets of
 *              macros.
 *
 *              Types are defined in the following categories:
 *                  - Integer types having certain exact widths
 *                  - Fastest integer types having at least certain specified
 *                      widths
 *                  - Integer types wide enough to hold pointers to objects
 *                  - standard type definitions
 *
 *              The following exact-width integer types are required:
 *              - int8_t
 *              - int16_t
 *              - int32_t
 *              - uint8_t
 *              - uint16_t
 *              - uint32_t
 *
 *              The following fastest minimum-width integer types are required:
 *              - int_fast8_t
 *              - int_fast16_t
 *              - int_fast32_t
 *              - uint_fast8_t
 *              - uint_fast16_t
 *              - uint_fast32_t
 *
 *              The following integer types capable of holding object pointers
 *              are required:
 *              - intptr_t
 *              - uintptr_t
 *
 *              The following standard type definitions are required:
 *              - NULL
 *              - ptrdiff_t
 *              - size_t
 * @{ *//*--------------------------------------------------------------------*/

/**@brief       Bool data type
 */
typedef enum boolType {
    TRUE = 1U,                                                                  /**< TRUE                                                   *///!< TRUE
    FALSE = 0U                                                                  /**< FALSE                                                  *///!< FALSE
} bool_T;

/** @} *//*-------------------------------------------------------------------*/
/*======================================================  GLOBAL VARIABLES  ==*/
/*===================================================  FUNCTION PROTOTYPES  ==*/
/*--------------------------------------------------------  C++ extern end  --*/
#ifdef __cplusplus
}
#endif

/*================================*//** @cond *//*==  CONFIGURATION ERRORS  ==*/
/** @endcond *//** @} *//******************************************************
 * END of arm-none-eabi-gcc.h
 ******************************************************************************/
#endif /* ARM_NONE_EABI_GCC_H_ */
