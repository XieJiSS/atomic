/*
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * Copyright (c) 2014 Andrey Semashev
 */
/*!
 * \file   atomic/detail/caps_gcc_atomic.hpp
 *
 * This header defines feature capabilities macros
 */

#ifndef BOOST_ATOMIC_DETAIL_CAPS_GCC_ATOMIC_HPP_INCLUDED_
#define BOOST_ATOMIC_DETAIL_CAPS_GCC_ATOMIC_HPP_INCLUDED_

#include <boost/atomic/detail/config.hpp>
#include <boost/atomic/detail/int_sizes.hpp>
#include <boost/atomic/detail/hwcaps_gcc_x86.hpp>
#include <boost/atomic/detail/hwcaps_gcc_arm.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#if defined(BOOST_ATOMIC_DETAIL_X86_HAS_CMPXCHG16B) && (defined(BOOST_HAS_INT128) || !defined(BOOST_NO_ALIGNMENT))
#define BOOST_ATOMIC_INT128_LOCK_FREE 2
#else
#define BOOST_ATOMIC_INT128_LOCK_FREE 0
#endif

#if __GCC_ATOMIC_LLONG_LOCK_FREE == 2
#define BOOST_ATOMIC_LLONG_LOCK_FREE 2
#else
#define BOOST_ATOMIC_LLONG_LOCK_FREE BOOST_ATOMIC_INT128_LOCK_FREE
#endif

#if __GCC_ATOMIC_LONG_LOCK_FREE == 2
#define BOOST_ATOMIC_LONG_LOCK_FREE 2
#else
#define BOOST_ATOMIC_LONG_LOCK_FREE BOOST_ATOMIC_LLONG_LOCK_FREE
#endif

#if __GCC_ATOMIC_INT_LOCK_FREE == 2
#define BOOST_ATOMIC_INT_LOCK_FREE 2
#else
#define BOOST_ATOMIC_INT_LOCK_FREE BOOST_ATOMIC_LONG_LOCK_FREE
#endif

#if __GCC_ATOMIC_SHORT_LOCK_FREE == 2
#define BOOST_ATOMIC_SHORT_LOCK_FREE 2
#else
#define BOOST_ATOMIC_SHORT_LOCK_FREE BOOST_ATOMIC_INT_LOCK_FREE
#endif

#if __GCC_ATOMIC_CHAR_LOCK_FREE == 2
#define BOOST_ATOMIC_CHAR_LOCK_FREE 2
#else
#define BOOST_ATOMIC_CHAR_LOCK_FREE BOOST_ATOMIC_SHORT_LOCK_FREE
#endif

#if __GCC_ATOMIC_POINTER_LOCK_FREE == 2
#define BOOST_ATOMIC_POINTER_LOCK_FREE 2
#else
#define BOOST_ATOMIC_POINTER_LOCK_FREE 0
#endif


#define BOOST_ATOMIC_INT8_LOCK_FREE BOOST_ATOMIC_CHAR_LOCK_FREE

#if BOOST_ATOMIC_DETAIL_SIZEOF_SHORT == 2
#define BOOST_ATOMIC_INT16_LOCK_FREE BOOST_ATOMIC_SHORT_LOCK_FREE
#elif BOOST_ATOMIC_DETAIL_SIZEOF_INT == 2
#define BOOST_ATOMIC_INT16_LOCK_FREE BOOST_ATOMIC_INT_LOCK_FREE
#elif BOOST_ATOMIC_DETAIL_SIZEOF_LONG == 2
#define BOOST_ATOMIC_INT16_LOCK_FREE BOOST_ATOMIC_LONG_LOCK_FREE
#elif BOOST_ATOMIC_DETAIL_SIZEOF_LLONG == 2
#define BOOST_ATOMIC_INT16_LOCK_FREE BOOST_ATOMIC_LLONG_LOCK_FREE
#else
#define BOOST_ATOMIC_INT16_LOCK_FREE 0
#endif

#if BOOST_ATOMIC_DETAIL_SIZEOF_SHORT == 4
#define BOOST_ATOMIC_INT32_LOCK_FREE BOOST_ATOMIC_SHORT_LOCK_FREE
#elif BOOST_ATOMIC_DETAIL_SIZEOF_INT == 4
#define BOOST_ATOMIC_INT32_LOCK_FREE BOOST_ATOMIC_INT_LOCK_FREE
#elif BOOST_ATOMIC_DETAIL_SIZEOF_LONG == 4
#define BOOST_ATOMIC_INT32_LOCK_FREE BOOST_ATOMIC_LONG_LOCK_FREE
#elif BOOST_ATOMIC_DETAIL_SIZEOF_LLONG == 4
#define BOOST_ATOMIC_INT32_LOCK_FREE BOOST_ATOMIC_LLONG_LOCK_FREE
#else
#define BOOST_ATOMIC_INT32_LOCK_FREE 0
#endif

#if BOOST_ATOMIC_DETAIL_SIZEOF_SHORT == 8
#define BOOST_ATOMIC_INT64_LOCK_FREE BOOST_ATOMIC_SHORT_LOCK_FREE
#elif BOOST_ATOMIC_DETAIL_SIZEOF_INT == 8
#define BOOST_ATOMIC_INT64_LOCK_FREE BOOST_ATOMIC_INT_LOCK_FREE
#elif BOOST_ATOMIC_DETAIL_SIZEOF_LONG == 8
#define BOOST_ATOMIC_INT64_LOCK_FREE BOOST_ATOMIC_LONG_LOCK_FREE
#elif BOOST_ATOMIC_DETAIL_SIZEOF_LLONG == 8
#define BOOST_ATOMIC_INT64_LOCK_FREE BOOST_ATOMIC_LLONG_LOCK_FREE
#else
#define BOOST_ATOMIC_INT64_LOCK_FREE 0
#endif


#if __GCC_ATOMIC_WCHAR_T_LOCK_FREE == 2
#define BOOST_ATOMIC_WCHAR_T_LOCK_FREE 2
#elif BOOST_ATOMIC_DETAIL_SIZEOF_WCHAR_T == 8
#define BOOST_ATOMIC_WCHAR_T_LOCK_FREE BOOST_ATOMIC_INT64_LOCK_FREE
#elif BOOST_ATOMIC_DETAIL_SIZEOF_WCHAR_T == 4
#define BOOST_ATOMIC_WCHAR_T_LOCK_FREE BOOST_ATOMIC_INT32_LOCK_FREE
#elif BOOST_ATOMIC_DETAIL_SIZEOF_WCHAR_T == 2
#define BOOST_ATOMIC_WCHAR_T_LOCK_FREE BOOST_ATOMIC_INT16_LOCK_FREE
#elif BOOST_ATOMIC_DETAIL_SIZEOF_WCHAR_T == 1
#define BOOST_ATOMIC_WCHAR_T_LOCK_FREE BOOST_ATOMIC_INT8_LOCK_FREE
#else
#define BOOST_ATOMIC_WCHAR_T_LOCK_FREE 0
#endif

#define BOOST_ATOMIC_CHAR32_T_LOCK_FREE BOOST_ATOMIC_INT32_LOCK_FREE
#define BOOST_ATOMIC_CHAR16_T_LOCK_FREE BOOST_ATOMIC_INT16_LOCK_FREE

#define BOOST_ATOMIC_THREAD_FENCE 2
#define BOOST_ATOMIC_SIGNAL_FENCE 2

#endif // BOOST_ATOMIC_DETAIL_CAPS_GCC_ATOMIC_HPP_INCLUDED_
