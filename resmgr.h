/*
 * Tyler Filla
 * CS 4760
 * Assignment 5
 */

#ifndef RESMGR_H
#define RESMGR_H

/**
 * A side value indicating a resource manager instance exists on the client side.
 */
#define RESMGR_SIDE_CLIENT 0

/**
 * A side value indicating a resource manager instance exists on the server side.
 */
#define RESMGR_SIDE_SERVER 1

typedef struct
{
    /** The executing side. */
    int side;

    /** Nonzero if currently running, otherwise zero. */
    int running;
} resmgr_s;

/**
 * Create a resource manager instance.
 */
#define resmgr_new(side) resmgr_construct(malloc(sizeof(resmgr_s)), side)

/**
 * Destroy a resource manager instance.
 */
#define resmgr_delete(resmgr) free(resmgr_destruct(resmgr))

/**
 * Construct a resource manager instance.
 *
 * @param resmgr The resource manager instance
 * @param side The executing side
 * @return The resource manager instance, constructed
 */
resmgr_s* resmgr_construct(resmgr_s* resmgr, int side);

/**
 * Destruct a resource manager instance.
 *
 * @param resmgr The resource manager instance
 * @return The resource manager, destructed
 */
resmgr_s* resmgr_destruct(resmgr_s* resmgr);

#endif // #ifndef RESMGR_H