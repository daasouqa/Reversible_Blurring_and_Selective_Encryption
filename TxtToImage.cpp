//
// Created by Inès Benghezal on 25/11/19.
//
//
// Copyright (c) 2019 Inès Benghezal. All rights reserved.
//


#include "Sources/ImageBase.cpp"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    
    
    char cNomImgLue[250], cNomImgEcrite[250];
    int height, width;
    
    if (argc != 5) {
        printf("Usage: file.txt height width ImageOut\n");
        exit(1);
    }
    
    sscanf(argv[1], "%s", cNomImgLue);
    sscanf(argv[2], "%d", &height);
    sscanf(argv[3], "%d", &width);
    sscanf(argv[4], "%s", cNomImgEcrite);
    
    string line;
    ifstream myfile (cNomImgLue);
    if (myfile.is_open()) {
        string h, w;
        getline(myfile, h);
        height = stoi(h);
        getline(myfile, w);
        width = stoi(w);
        std::cout << "Height = " << height << " | Width = " << width << std::endl;
        ImageBase ImgOut(width, height, true);
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                getline(myfile, line);
                int lineChar = stoi(line);
                ImgOut[i * 3][j * 3 + 0] = lineChar;
                getline(myfile, line);
                lineChar = stoi(line);
                ImgOut[i * 3][j * 3 + 1] = lineChar;
                getline(myfile, line);
                lineChar = stoi(line);
                ImgOut[i * 3][j * 3 + 2] = lineChar;
            }
        }
        ImgOut.save(cNomImgEcrite);
        myfile.close();
    } else cout << "Unable to open file";
    
}