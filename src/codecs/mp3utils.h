/*
  SDL_mixer:  An audio mixer library based on the SDL library
  Copyright (C) 1997-2019 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

/* This file supports reading of ID3 tags of MP3 files with libID3Tag */

#include "music.h"

#if defined(MUSIC_MP3_MAD) || defined(MUSIC_MP3_MPG123)
#define ENABLE_ALL_MP3_TAGS
#endif

#if defined(MUSIC_WAV) || defined(ENABLE_ALL_MP3_TAGS)
#define ENABLE_ID3V2_TAG
#endif

#ifdef ENABLE_ALL_MP3_TAGS
struct mp3file_t {
    SDL_RWops *src;
    Sint64 start, length, pos;
};

extern int mp3_read_tags(Mix_MusicMetaTags *out_tags, struct mp3file_t *fil, SDL_bool keep_id3v2);
#endif /* ENABLE_ALL_MP3_TAGS */

#ifdef ENABLE_ID3V2_TAG
extern int read_id3v2_from_mem(Mix_MusicMetaTags *out_tags, Uint8 *data, size_t length);
#endif

#ifdef ENABLE_ALL_MP3_TAGS
extern size_t MP3_RWread(struct mp3file_t *fil, void *ptr, size_t size, size_t maxnum);
extern Sint64 MP3_RWseek(struct mp3file_t *fil, Sint64 offset, int whence);
extern Sint64 MP3_RWtell(struct mp3file_t *fil);
#endif /* ENABLE_ALL_MP3_TAGS */

/* vi: set ts=4 sw=4 expandtab: */
