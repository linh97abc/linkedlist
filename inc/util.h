#ifndef __UTIL_H__
#define __UTIL_H__

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
#define HEADER_DECALRE_BEGIN extern "C" {
#define HEADER_DECALRE_END }
#else
#define HEADER_DECALRE_BEGIN
#define HEADER_DECALRE_END
#endif

HEADER_DECALRE_BEGIN

#define UTIL_PRIMITIVE_CAT(a, ...) a##__VA_ARGS__
#define UTIL_CAT(a, ...) UTIL_PRIMITIVE_CAT(a, __VA_ARGS__)

/**
 * @brief Get a pointer to a structure containing the element
 *
 * Example:
 *
 *	struct foo {
 *		int bar;
 *	};
 *
 *	struct foo my_foo;
 *	int *ptr = &my_foo.bar;
 *
 *	struct foo *container = CONTAINER_OF(ptr, struct foo, bar);
 *
 * Above, @p container points at @p my_foo.
 *
 * @param ptr pointer to a structure element
 * @param type name of the type that @p ptr is an element of
 * @param field the name of the field within the struct @p ptr points to
 * @return a pointer to the structure that contains @p ptr
 */
#define CONTAINER_OF(ptr, type, field) \
	((type *)(((char *)(ptr)) - offsetof(type, field)))

/**
 * @brief Value of @p x rounded up to the next multiple of @p align,
 *        which must be a power of 2.
 */
#define ROUND_UP(x, align)                                   \
	(((uintptr_t)(x) + ((uintptr_t)(align) - 1)) & \
	 ~((uintptr_t)(align) - 1))

/**
 * @brief Value of @p x rounded down to the previous multiple of @p
 *        align, which must be a power of 2.
 */
#define ROUND_DOWN(x, align)                                 \
	((uintptr_t)(x) & ~((uintptr_t)(align) - 1))
    
HEADER_DECALRE_END

#endif
