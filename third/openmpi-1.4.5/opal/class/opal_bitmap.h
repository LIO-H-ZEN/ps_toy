/* -*- Mode: C; c-basic-offset:4 ; -*- */
/*
 * Copyright (c) 2004-2005 The Trustees of Indiana University and Indiana
 *                         University Research and Technology
 *                         Corporation.  All rights reserved.
 * Copyright (c) 2004-2007 The University of Tennessee and The University
 *                         of Tennessee Research Foundation.  All rights
 *                         reserved.
 * Copyright (c) 2004-2005 High Performance Computing Center Stuttgart, 
 *                         University of Stuttgart.  All rights reserved.
 * Copyright (c) 2004-2005 The Regents of the University of California.
 *                         All rights reserved.
 * Copyright (c) 2007      Cisco Systems, Inc.  All rights reserved.
 * $COPYRIGHT$
 * 
 * Additional copyrights may follow
 * 
 * $HEADER$
 *
 */

/** @file
 *
 *  A bitmap implementation. The bits start off with 0, so this bitmap
 *  has bits numbered as bit 0, bit 1, bit 2 and so on. This bitmap
 *  has auto-expansion capabilities, that is once the size is set
 *  during init, it can be automatically expanded by setting the bit
 *  beyond the current size. But note, this is allowed just when the
 *  bit is set -- so the valid functions are set_bit and
 *  find_and_set_bit. Other functions like clear, if passed a bit
 *  outside the initialized range will result in an error.
 *
 */

#ifndef OPAL_BITMAP_H
#define OPAL_BITMAP_H

#include "opal_config.h"

#include <string.h>

#include "opal/class/opal_object.h"

BEGIN_C_DECLS

struct opal_bitmap_t {
    opal_object_t super; /**< Subclass of opal_object_t */
    unsigned char *bitmap; /**< The actual bitmap array of characters */
    int array_size;  /**< The actual array size that maintains the bitmap */
};

typedef struct opal_bitmap_t opal_bitmap_t;

OPAL_DECLSPEC OBJ_CLASS_DECLARATION(opal_bitmap_t);

/**
 * Initializes the bitmap and sets its size. This must be called
 * before the bitmap can be actually used
 *
 * @param  bitmap The input bitmap (IN)
 * @param  size   The initial size of the bitmap in terms of bits (IN)
 * @return OPAL error code or success
 *
 */
OPAL_DECLSPEC int opal_bitmap_init (opal_bitmap_t *bm, int size);


/**
 * Set a bit of the bitmap. If the bit asked for is beyond the current
 * size of the bitmap, then the bitmap is extended to accomodate the
 * bit
 *
 * @param  bitmap The input bitmap (IN)
 * @param  bit    The bit which is to be set (IN)
 * @return OPAL error code or success
 *
 */
OPAL_DECLSPEC int opal_bitmap_set_bit(opal_bitmap_t *bm, int bit); 


/**
 * Clear/unset a bit of the bitmap. If the bit is beyond the current
 * size of the bitmap, an error is returned
 *
 * @param  bitmap The input bitmap (IN)
 * @param  bit    The bit which is to be cleared (IN)
 * @return OPAL error code if the bit is out of range, else success
 *
 */
OPAL_DECLSPEC int opal_bitmap_clear_bit(opal_bitmap_t *bm, int bit);


/**
  * Find out if a bit is set in the bitmap
  *
  * @param  bitmap  The input bitmap (IN)
  * @param  bit     The bit which is to be checked (IN)
  * @return true    if the bit is set
  *         false   if the bit is not set OR the index
  *                 is outside the bounds of the provided
  *                 bitmap
  *
  */
OPAL_DECLSPEC bool opal_bitmap_is_set_bit(opal_bitmap_t *bm, int bit);


/**
 * Find the first clear bit in the bitmap and set it
 *
 * @param  bitmap     The input bitmap (IN)
 * @param  position   Position of the first clear bit (OUT)

 * @return err        OPAL_SUCCESS on success
 */
OPAL_DECLSPEC int opal_bitmap_find_and_set_first_unset_bit(opal_bitmap_t *bm, 
                                                           int *position); 


/**
 * Clear all bits in the bitmap
 *
 * @param bitmap The input bitmap (IN)
 * @return OPAL error code if bm is NULL
 * 
 */
OPAL_DECLSPEC int opal_bitmap_clear_all_bits(opal_bitmap_t *bm);


/**
 * Set all bits in the bitmap
 * @param bitmap The input bitmap (IN)
 * @return OPAL error code if bm is NULL
 *
 */
OPAL_DECLSPEC int opal_bitmap_set_all_bits(opal_bitmap_t *bm);


/**
 * Gives the current size (number of bits) in the bitmap. This is the
 * legal (accessible) number of bits
 *
 * @param bitmap The input bitmap (IN)
 * @return OPAL error code if bm is NULL
 *
 */
static inline int opal_bitmap_size(opal_bitmap_t *bm)
{
    return (NULL == bm) ? 0 : (bm->array_size * ((int) (sizeof(char) * 8)));
}

END_C_DECLS

#endif
