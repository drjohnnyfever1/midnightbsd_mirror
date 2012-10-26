/*
 * dremf() wrapper for remainderf().
 *
 * Written by J.T. Conklin, <jtc@wimsey.com>
 * Placed into the Public Domain, 1994.
 */
/* $MidnightBSD$ */

#include "math.h"
#include "math_private.h"

float
dremf(float x, float y)
{
	return remainderf(x, y);
}
