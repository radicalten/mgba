/* Copyright (c) 2013-2017 Jeffrey Pfau
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef M_CACHE_SET_H
#define M_CACHE_SET_H

#include "common.h"

CXX_GUARD_START

#include "bitmap-cache.h"
#include "map-cache.h"
#include "tile-cache.h"
#include "vector.h"

DECLARE_VECTOR(mMapCacheSet, struct mMapCache);
DECLARE_VECTOR(mBitmapCacheSet, struct mBitmapCache);
DECLARE_VECTOR(mTileCacheSet, struct mTileCache);

struct mCacheSet {
	struct mMapCacheSet maps;
	struct mBitmapCacheSet bitmaps;
	struct mTileCacheSet tiles;
};

void mCacheSetInit(struct mCacheSet*, size_t nMaps, size_t nBitmaps, size_t nTiles);
void mCacheSetDeinit(struct mCacheSet*);

void mCacheSetAssignVRAM(struct mCacheSet*, void* vram);

void mCacheSetWriteVRAM(struct mCacheSet*, uint32_t address);
void mCacheSetWritePalette(struct mCacheSet*, uint32_t entry, color_t color);

CXX_GUARD_END

#endif
