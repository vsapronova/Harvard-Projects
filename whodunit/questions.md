# Questions

## What's `stdint.h`?

The <stdint.h> header shall declare sets of integer types having specified widths, and shall define corresponding sets of macros.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

We define an our own integer type variable with a specific width.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE - 1 byte;
DWORD - 4 byte;
LONG - 4 byte;
WORD - 2 byte;

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

Metadata. Information like an image's height and width.

## What's the difference between `bfSize` and `biSize`?

bfSize is supposed to be the size of the entire new image, pixels, padding, and both headers, while biSizeImage is the size of the image minus both headers.

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in `copy.c`?

If file might not exist.

## Why is the third argument to `fread` always `1` in our code?

Because you always read in the code one byte at a time.

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

fseek() is used to move file pointer associated with a given file to a specific position.

## What is `SEEK_CUR`?

It moves file pointer position to given location.
