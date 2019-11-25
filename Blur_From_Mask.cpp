//
// Created by Inès Benghezal on 18/11/19.
//
//
// Copyright (c) 2019 Inès Benghezal. All rights reserved.
//

#include "Sources/ImageBase.cpp"

using namespace std;

/* Function to reverse bits of num */
unsigned int reverseBits(unsigned int num)
{
    unsigned int  NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0, i, temp;
    
    for (i = 0; i < NO_OF_BITS; i++)
    {
        temp = (num & (1 << i));
        if(temp)
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
    }
    
    return reverse_num;
}

int main(int argc, char* argv[]) {
    
    
    char cNomImgLue[250], cNomImgEcrite[250], cNomMasque[250];
    
    if (argc != 4) {
        printf("Usage: ImageIn.ppm ImgOut.ppm Masque.ppm\n");
        exit(1);
    }
    
    sscanf(argv[1], "%s", cNomImgLue);
    sscanf(argv[2], "%s", cNomImgEcrite);
    sscanf(argv[3], "%s", cNomMasque);
    
    ImageBase ImgIn, mask;
    ImgIn.load(cNomImgLue);
    mask.load(cNomMasque);
    
    ImageBase ImgOut(ImgIn.getWidth(), ImgIn.getHeight(), ImgIn.getColor());
    
    for (int i = 0; i < ImgIn.getHeight(); ++i) {
        for (int j = 0; j < ImgIn.getWidth(); ++j) {
            if (mask[i * 3][j * 3] == 255) {
        
                ImgOut[i * 3][j * 3 + 0] = ImgIn[((i + 50) * 3) % ImgIn.getHeight()][((j + 50) * 3 + 0) % ImgIn.getWidth() ];
                ImgOut[i * 3][j * 3 + 1] = ImgIn[((i + 50) * 3) % ImgIn.getHeight()][((j + 50) * 3 + 1) % ImgIn.getWidth() ];
                ImgOut[i * 3][j * 3 + 2] = ImgIn[((i + 50) * 3) % ImgIn.getHeight()][((j + 50) * 3 + 2) % ImgIn.getWidth() ];
                
            } else {
                
                ImgOut[i * 3][j * 3 + 0] = ImgIn[i * 3][j * 3 + 0];
                ImgOut[i * 3][j * 3 + 1] = ImgIn[i * 3][j * 3 + 1];
                ImgOut[i * 3][j * 3 + 2] = ImgIn[i * 3][j * 3 + 2];
                
            }
        }
    }
    
    ImgOut.save(cNomImgEcrite);
}

