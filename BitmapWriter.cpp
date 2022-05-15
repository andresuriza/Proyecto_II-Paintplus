#include <iostream>
#include <cstring>

class __attribute__((__packed__, aligned(1))) BitmapFileHeader {
public:
    uint16_t fileHeaderType;
    uint32_t fileHeaderSize;
    uint16_t fileHeaderReserved1;
    uint16_t fileHeaderReserved2;
    uint32_t fileHeaderOffBits;
};

class __attribute__((__packed__, aligned(1))) BitmapInfoHeader {
public:
    uint32_t infoHeaderSize = 40; // Size of InfoHeader = 40
    int32_t  infoHeaderWidth; // Bitmap width
    int32_t  infoHeaderHeight; // Bitmap height
    uint16_t infoHeaderPlanes = 1; // Number of Planes (=1)
    uint16_t infoHeaderBitCount = 24; /* Bits per Pixel
                                     1 = monochrome palette NumColors = 1
                                     4 = 4bit palletized. NumColors = 16
                                     8 = 8bit palletized. NumColors = 256
                                     16 = 16bit RGB
                                     24 = 24bit RGB
                                     */
    uint32_t infoHeaderCompression = 0; /*
                                        Type of compression
                                        0 = BI_RGB no compression
                                        */
    uint32_t infoHeaderImageSize;// (compressed) size of image
    int32_t  infoHeaderXPixelsPerM; // horizontal resolution
    int32_t  infoHeaderYPixelsPerM; // vertical resolution
    uint32_t infoHeaderColorsUsed; // number of actually used colors
    uint32_t infoHeaderColorsImportant; // number of important colors 0 = all
};

int main()
{
    //only width and height can be changed in this code:
    int width = 1920;
    int height = 1080;

    //int bitcount = 24;//<- 24-bit bitmap
    int width_in_bytes = ((width * 24 + 31) / 32) * 4;    //for padding
    uint32_t imagesize = width_in_bytes * height;   //total image size

    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    memcpy(&fileHeader, "BM", 2); //bitmap signature
    fileHeader.fileHeaderSize = sizeof(fileHeader) + sizeof (infoHeader) + imagesize; //total file size
    fileHeader.fileHeaderOffBits = sizeof(fileHeader) + sizeof (infoHeader);

    infoHeader.infoHeaderWidth = width;
    infoHeader.infoHeaderHeight = height;
    infoHeader.infoHeaderImageSize = imagesize;

    //prepare pixel data:
    unsigned char* buf = (unsigned char*) malloc(imagesize);

    for(int row = height - 1; row >= 0; row--)
    {
        for(int col = 0; col < width; col++)
        {
            buf[row * width_in_bytes + col * 3 + 0] = 255;//blue
            buf[row * width_in_bytes + col * 3 + 1] = 255;//red
            buf[row * width_in_bytes + col * 3 + 2] = 0;//green
        }
    }

    FILE *fout = fopen("test.bmp", "wb");
    fwrite(&fileHeader, sizeof(fileHeader), 1, fout);
    fwrite(&infoHeader, sizeof(infoHeader), 1, fout);
    fwrite((char*)buf, 1, imagesize, fout);
    fclose(fout);
    free(buf);

    return 0;
}
