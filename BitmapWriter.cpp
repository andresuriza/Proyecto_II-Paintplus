#include <iostream>

using namespace std;

/**
 * Stores the file header for the bitmap
 */
class BitmapFileHeader {
public:
    uint16_t fileHeaderType;
    uint32_t fileHeaderSize;
    uint32_t fileHeaderReserved;
    uint32_t fileHeaderOffBits;
};

/**
 * Stores the info header for the bitmap
 */
class BitmapInfoHeader {
public:
    uint32_t infoHeaderSize;
    uint32_t infoHeaderWidth;
    uint32_t infoHeaderHeight;
    uint16_t infoHeaderPlanes;
    uint16_t infoHeaderBitCount;
    uint32_t infoHeaderCompression;
    uint32_t infoHeaderImageSize;
    uint32_t infoHeaderXPixelsPerM;
    uint32_t infoHeaderYPixelsPerM;
    uint32_t infoHeaderColorsUsed;
    uint32_t infoHeaderColorsImportant;
};

/**
 * Class that contains function to write a BMP file based on a matrix with the info and file headers and the color
 * information
 */
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
    /**
     *
     * Writes data into the file and info headers, as well as creating an array for writing to a file
     *
     * @param outputFileName
     * @param width
     * @param height
     * @param rgbData
     */
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

    /**
     *
     * Writes the BMP file header data to a file
     *
     * @param outputFile
     * @param fileHeader
     */
    static void writeBMPHeader(FILE *outputFile, BitmapFileHeader *fileHeader)
    {
        fwrite(&fileHeader->fileHeaderType, sizeof(fileHeader->fileHeaderType), 1, outputFile);
        fwrite(&fileHeader->fileHeaderSize, sizeof(fileHeader->fileHeaderSize), 1, outputFile);
        fwrite(&fileHeader->fileHeaderReserved, sizeof(fileHeader->fileHeaderReserved), 1, outputFile);
        fwrite(&fileHeader->fileHeaderOffBits, sizeof(fileHeader->fileHeaderOffBits), 1, outputFile);
    }

    /**
     *
     * Writes the BMP info header data to a file
     *
     * @param outputFile
     * @param infoHeader
     */
    static void writeBMPInfoHeader(FILE *outputFile, BitmapInfoHeader *infoHeader)
    {
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

/**
 * Class that stores RGB data for colors and can store colors in certain index positions on a matrix
 */
class Painter
{
private:
    int width;
    int height;
    int rows;

    uint8_t red[3] = {255, 0, 0};
    uint8_t orange[3] = {255, 121, 11};
    uint8_t yellow[3] = {255, 239, 20};
    uint8_t lime[3] = {0, 255, 0};
    uint8_t green[3] = {2, 149, 2};
    uint8_t cyan[3] = {0, 255, 255};
    uint8_t scarlet[3] = {184, 0, 0};
    uint8_t brown[3] = {170, 85, 0};
    uint8_t gold[3] = {230, 199, 87};
    uint8_t pink[3] = {233, 66, 255};
    uint8_t black[3] = {0, 0, 0};
    uint8_t gray[3] = {81, 81, 81};
    uint8_t lightGray[3] = {159, 159, 159};
    uint8_t white[3] = {255, 255, 255};

    uint8_t** rgbMatrix;

public:
    /**
     * Constructor function
     *
     * @param width
     * @param height
     */
    Painter(int width, int height)
    {
        this->width = width;
        this->height = height;
        this->rows = width * height;
        rgbMatrix = new uint8_t* [rows];

        for (int i = 0; i < rows; i++)
        {
                rgbMatrix[i] = new uint8_t[3];
        }

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                rgbMatrix[row][col] = white[col];
            }
        }

    }

    /**
     *
     * Allows storing a certain colored pixel information on a matrix
     *
     * @param color
     * @param posX
     * @param posY
     */
    void Paint(const string& color, int posX, int posY)
    {
        int position = (posX * width) + (posY);

        for (int i = 0; i < 3; i++) {
            if (color == "black") {
                rgbMatrix[position][i] = black[i];
            }

            if (color == "white")
            {
                rgbMatrix[position][i] = white[i];
            }

            if (color == "red")
            {
                rgbMatrix[position][i] = red[i];
            }

            if (color == "green")
            {
                rgbMatrix[position][i] = green[i];
            }

            if (color == "lime") {
                rgbMatrix[position][i] = lime[i];
            }

            if (color == "cyan") {
                rgbMatrix[position][i] = cyan[i];
            }

            if (color == "scarlet") {
                rgbMatrix[position][i] = scarlet[i];
            }

            if (color == "brown") {
                rgbMatrix[position][i] = brown[i];
            }

            if (color == "gold") {
                rgbMatrix[position][i] = gold[i];
            }

            if (color == "pink") {
                rgbMatrix[position][i] = pink[i];
            }

            if (color == "gray") {
                rgbMatrix[position][i] = gray[i];
            }

            if (color == "lightGray") {
                rgbMatrix[position][i] = lightGray[i];
            }

            if (color == "orange")
            {
                rgbMatrix[position][i] = orange[i];
            }

            if (color == "yellow")
            {
                rgbMatrix[position][i] = yellow[i];
            }
        }
    }


    /**
     * Creates a matrix based on the RGB matrix data generated before in order to send it to the BMP writer class
     *
     * @param outputFileName
     */
    void GenerateImage(string* outputFileName)
    {
        BitmapWriter bw{};
        uint8_t rgbData[rows][3];

            for (int row = 0; row < rows; row++)
            {
                for (int col = 0; col < 3; col++)
                {
                    rgbData[row][col] = rgbMatrix[row][col];
                }
            }

        bw.write24BitBMP((const char *) outputFileName, width, height, (uint8_t*)(rgbData));
    }
};