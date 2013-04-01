/*                    The Quest Operating System
 *  Copyright (C) 2005-2012  Richard West, Boston University
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * The function prototypes are taken from Linux, the implementation of
 * the functions are Quest specific, below is the copyright from
 * include/linux/dmapool.h
 *
 *include/linux/dmapool.h
 *
 * Allocation pools for DMAable (coherent) memory. 
 *
 * This file is licensed under  the terms of the GNU General Public 
 * License version 2. This program is licensed "as is" without any 
 * warranty of any kind, whether express or implied.
 */


#ifndef _DMA_POOL_H_
#define _DMA_POOL_H_

#include "types.h"
#include "arch/i386.h"
#include "mem/mem.h"


#define DMA_POOL_NUM_PAGE_TABLES ((uint32)1)

/* The dma pool "grows" down, always ending right next to the malloc
   pool */

#define DMA_POOL_LAST_PAGE_TABLE ((uint32)(MALLOC_POOL_START_PAGE_TABLE - 1))
#define DMA_POOL_START_PAGE_TABLE					\
  ((uint32)(MALLOC_POOL_LAST_PAGE_TABLE - MALLOC_POOL_NUM_PAGE_TABLES + 1))

typedef struct dma_pool {
} dma_pool_t;

struct dma_pool* dma_pool_create(const char *name,
				 size_t size, size_t align, size_t alloc);

void *dma_pool_alloc(struct dma_pool *pool, 
		     phys_addr_t *dma_handle);

void dma_pool_free(struct dma_pool *pool, void *vaddr,
		   phys_addr_t addr);

void dma_pool_destroy(struct dma_pool *pool);


#endif //_DMA_POOL_H_

/* 
 * Local Variables:
 * indent-tabs-mode: nil
 * mode: C
 * c-file-style: "gnu"
 * c-basic-offset: 2
 * End: 
 */
