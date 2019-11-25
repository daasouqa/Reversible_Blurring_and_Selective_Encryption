//
// Created by Inès Benghezal on 25/11/19.
//
//
// Copyright (c) 2019 Inès Benghezal. All rights reserved.
//

#include "Sources/ImageBase.cpp"
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    
    
    char cNomImgLue[250], cNomImgEcrite[250], cNomMasque[250];
    
    if (argc != 2) {
        printf("Usage: ImageIn.ppm\n");
        exit(1);
    }
    
    sscanf(argv[1], "%s", cNomImgLue);
    
    ImageBase ImgIn;
    ImgIn.load(cNomImgLue);
    
    ofstream result;
    result.open("result.txt");
    
    for (int i = 0; i < ImgIn.getHeight(); ++i) {
        for (int j = 0; j < ImgIn.getWidth(); ++j) {
            result << std::to_string(ImgIn[i][j]) << std::endl;
        }
    }
    
    result.close();
    
}