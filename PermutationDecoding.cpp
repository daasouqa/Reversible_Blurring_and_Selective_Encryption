//
// Created by Ines Benghezal on 01/12/2019.
//
// Copyright (c) 2019 Inès Benghezal. All rights reserved.
//

#include "Sources/ImageBase.cpp"
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    
    
    char cNomImgLue[250], cNomImgEcrite[250];
    int tailleBlock;
    
    if (argc != 4) {
        printf("Usage: ImageIn.ppm ImageOut.ppm TailleBlock\n");
        exit(1);
    }
    
    sscanf(argv[1], "%s", cNomImgLue);
    sscanf(argv[2], "%s", cNomImgEcrite);
    sscanf(argv[3], "%d", &tailleBlock);
    
    ImageBase ImgIn;
    ImgIn.load(cNomImgLue);
    ImageBase ImgOut(ImgIn.getWidth(), ImgIn.getHeight(), ImgIn.getColor());
    
    for (int i = 0; i < ImgIn.getHeight(); ++i) {
        for (int j = 0; j < ImgIn.getWidth(); ++j) {
            ImgOut[i * 3][j * 3 + 0] = ImgIn[i * 3][j * 3 + 0];
            ImgOut[i * 3][j * 3 + 1] = ImgIn[i * 3][j * 3 + 1];
            ImgOut[i * 3][j * 3 + 2] = ImgIn[i * 3][j * 3 + 2];
        }
    }
    
    for (int i = tailleBlock; i < ImgIn.getHeight() - tailleBlock; i += tailleBlock) {
        
        for (int j = tailleBlock; j < ImgIn.getWidth() - tailleBlock; j += tailleBlock) {
            
            for (int k = 0; k < tailleBlock; ++k) {
                for (int l = 0; l < tailleBlock; ++l) {
                    ImgOut[(i + k) * 3][(j + l) * 3 + 0] = ImgIn[(i + tailleBlock - 1 - k)*3][(j + tailleBlock - 1 - l) * 3 + 0];
                    ImgOut[(i + k) * 3][(j + l) * 3 + 1] = ImgIn[(i + tailleBlock - 1 - k)*3][(j + tailleBlock - 1 - l) * 3 + 1];
                    ImgOut[(i + k) * 3][(j + l) * 3 + 2] = ImgIn[(i + tailleBlock - 1 - k)*3][(j + tailleBlock - 1 - l) * 3 + 2];
                }
            }
        }
    }
    
    ImgOut.save(cNomImgEcrite);
}