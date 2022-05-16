#include <iostream>

using namespace std;

class BitmapFileHeader {
public:
    uint16_t fileHeaderType;      // Header field used to identify the BMP. Must be set to 'B','M' (0x42 0x4d).
    uint32_t fileHeaderSize;      // Size of the complete file (Header + InfoHeader + PixelData) in bytes.
    uint32_t fileHeaderReserved;  // Reserved. Must be set to zero.
    uint32_t fileHeaderOffBits;   // Number of bytes until the pixel data starts (counted from the file-start). Always
                                  // 54
};

class BitmapInfoHeader {
public:
    uint32_t infoHeaderSize;          // The size of the info header in bytes (40).
    uint32_t infoHeaderWidth;         // The Bitmap width in pixels.
    uint32_t infoHeaderHeight;        // The Bitmap height in pixels.
    uint16_t infoHeaderPlanes;        // The number of color planes. Must be set to one.
    uint16_t infoHeaderBitCount;      // The number of bits per pixel (color depth).
    uint32_t infoHeaderCompression;   // The compression method being used (zero equals no compression).
    uint32_t infoHeaderImageSize;     // The size of the raw bitmap data. Zero is fine.
    uint32_t infoHeaderXPixelsPerM; // Horizontal resolution of the image. Zero is fine.
    uint32_t infoHeaderYPixelsPerM; // Vertical   resolution of the image. Zero is fine.
    uint32_t infoHeaderColorsUsed;       // Number of colors in the color paletter.
    uint32_t infoHeaderColorsImportant;  // Number of important colors used. Zero equals every color is important.
};

class BitmapWriter {
private:
    uint8_t overhead;
    BitmapInfoHeader bitmapInfoHeader;
    BitmapFileHeader bitmapFileHeader;
    uint32_t i;
    uint32_t row;
    uint32_t column;
    uint32_t overhead_i;
    uint8_t* pixels;

public:
    void write24BitBMP(const char *outputFileName, uint32_t width, uint32_t height, const uint8_t *rgbData) {
        FILE* outputFile = fopen(outputFileName, "wb");

        if ((3 * width % 4)) {overhead = 4 - 3 * width % 4;}
        else {overhead = 0;}

        bitmapFileHeader.fileHeaderType = 0x4d42; // 'MB' as HEX, little endian will store this as 'BM'.
        bitmapFileHeader.fileHeaderSize = (54 + (3 * width + overhead) * height);
        bitmapFileHeader.fileHeaderReserved = 0;
        bitmapFileHeader.fileHeaderOffBits = 54;

        bitmapInfoHeader.infoHeaderSize = 40;
        bitmapInfoHeader.infoHeaderWidth = width;
        bitmapInfoHeader.infoHeaderHeight = height;
        bitmapInfoHeader.infoHeaderPlanes = 1;
        bitmapInfoHeader.infoHeaderBitCount = 24;
        bitmapInfoHeader.infoHeaderCompression = 0;
        bitmapInfoHeader.infoHeaderImageSize = (3 * width + overhead) * height;
        bitmapInfoHeader.infoHeaderXPixelsPerM = 0;
        bitmapInfoHeader.infoHeaderYPixelsPerM = 0;
        bitmapInfoHeader.infoHeaderColorsUsed = 0;
        bitmapInfoHeader.infoHeaderColorsImportant = 0;

        writeBMPHeader(outputFile, &bitmapFileHeader);
        writeBMPInfoHeader(outputFile, &bitmapInfoHeader);

        pixels = new uint8_t[(3 * width + overhead) * height];

        for (row = height, i = 0; row > 0; row--) {
            for (column = 0; column < width; column++) {
                pixels[i++] = rgbData[3 * width * (row - 1) + 3 * column + 2];
                pixels[i++] = rgbData[3 * width * (row - 1) + 3 * column + 1];
                pixels[i++] = rgbData[3 * width * (row - 1) + 3 * column];
            }
            for (overhead_i = 0; overhead_i < overhead; overhead_i++) {
                pixels[i++] = 0;
            }
        }

        fwrite(pixels, (3 * width + overhead) * height, 1, outputFile);

        delete[] pixels;
        fclose(outputFile);
    }

    static void writeBMPHeader(FILE *outputFile, BitmapFileHeader *fileHeader) {
        fwrite(&fileHeader->fileHeaderType, sizeof(fileHeader->fileHeaderType), 1, outputFile);
        fwrite(&fileHeader->fileHeaderSize, sizeof(fileHeader->fileHeaderSize), 1, outputFile);
        fwrite(&fileHeader->fileHeaderReserved, sizeof(fileHeader->fileHeaderReserved), 1, outputFile);
        fwrite(&fileHeader->fileHeaderOffBits, sizeof(fileHeader->fileHeaderOffBits), 1, outputFile);
    }

    static void writeBMPInfoHeader(FILE *outputFile, BitmapInfoHeader *infoHeader) {
        fwrite(&infoHeader->infoHeaderSize, sizeof(infoHeader->infoHeaderSize), 1,
               outputFile);
        fwrite(&infoHeader->infoHeaderWidth, sizeof(infoHeader->infoHeaderWidth), 1,
               outputFile);
        fwrite(&infoHeader->infoHeaderHeight, sizeof(infoHeader->infoHeaderHeight), 1,
               outputFile);
        fwrite(&infoHeader->infoHeaderPlanes, sizeof(infoHeader->infoHeaderPlanes), 1,
               outputFile);
        fwrite(&infoHeader->infoHeaderBitCount, sizeof(infoHeader->infoHeaderBitCount), 1,
               outputFile);
        fwrite(&infoHeader->infoHeaderCompression, sizeof(infoHeader->infoHeaderCompression), 1,
               outputFile);
        fwrite(&infoHeader->infoHeaderImageSize, sizeof(infoHeader->infoHeaderImageSize), 1,
               outputFile);
        fwrite(&infoHeader->infoHeaderXPixelsPerM, sizeof(infoHeader->infoHeaderXPixelsPerM), 1,
               outputFile);
        fwrite(&infoHeader->infoHeaderYPixelsPerM, sizeof(infoHeader->infoHeaderYPixelsPerM), 1,
               outputFile);
        fwrite(&infoHeader->infoHeaderColorsUsed, sizeof(infoHeader->infoHeaderColorsUsed), 1,
               outputFile);
        fwrite(&infoHeader->infoHeaderColorsImportant, sizeof(infoHeader->infoHeaderColorsImportant), 1,
               outputFile);
    }
};

/*
    auto* outputFileName = (string *) "creeper.bmp";

    uint8_t rbgMatrix[36][3] = {
            {0, 0, 0}, {0,0, 0},{0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}};

    rbgMatrix[0][1] = 255;
    rbgMatrix[1][1] = 255;
    rbgMatrix[2][1] = 255;
    rbgMatrix[3][1] = 255;
    rbgMatrix[4][1] = 255;
    rbgMatrix[5][1] = 255;
    rbgMatrix[8][1] = 255;
    rbgMatrix[9][1] = 255;
    rbgMatrix[14][1] = 255;
    rbgMatrix[15][1] = 255;
    rbgMatrix[18][1] = 255;
    rbgMatrix[19][1] = 255;
    rbgMatrix[22][1] = 255;
    rbgMatrix[23][1] = 255;
    rbgMatrix[24][1] = 255;
    rbgMatrix[29][1] = 255;
    rbgMatrix[30][1] = 255;
    rbgMatrix[32][1] = 255;
    rbgMatrix[33][1] = 255;
    rbgMatrix[35][1] = 255;

    BitmapWriter bw{};
    bw.write24BitBMP((const char *)outputFileName, 6, 6, (uint8_t*) (rbgMatrix));

    return 0;
*/