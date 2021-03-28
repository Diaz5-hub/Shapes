//
//  main.cpp
//  Shapes
//
//  Created by Alexander Diaz on 3/28/21.
//Copyright 2021 © Alexander Diaz. All rights reserved.

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


enum class Shapes
{
    FILLED, HALF_RIGHT, CHECKERBOARD,
    STRIPES, X, UPPER_TRI
};

enum class Colors
{
    Black, White
};

typedef struct {

    Colors color;

}pixel;

void fillVector(vector <pixel>& p, int npixels, pixel var);
void CreateShape(vector < pixel >& p, int npixels, Shapes shape);
void Draw(vector < pixel > p);

int main() {

    vector<pixel> v;
    vector<pixel>& refVector = v;
    int height = 8, width = 8;
    int pixels = height * width;
    Shapes choice;
    string decide = " ";
    

    while (decide != "Q") {

        cout << "Enter in a shape to draw: " << endl << "FILLED, HALF_RIGHT, CHECKERBOARD \nSTRIPES, X\
 or UPPER_RIGHT_TRIANGLE. Enter Q to exit" << std::endl;
        cin >> decide;

        if (decide == "FILLED") {
            choice = Shapes::FILLED;
        }
        else if (decide == "HALF_RIGHT") {
            choice = Shapes::HALF_RIGHT;
        }
        else if (decide == "CHECKERBOARD") {
            choice = Shapes::CHECKERBOARD;
        }
        else if (decide == "STRIPES") {
            choice = Shapes::STRIPES;
        }
        else if (decide == "X") {
            choice = Shapes::X;
        }
        else if (decide == "UPPER_RIGHT_TRIANGLE") {
            choice = Shapes::UPPER_TRI;
        }


            CreateShape(refVector, pixels, choice);

            Draw(v);

            v.clear();
        }
        cout << "Goodbye\n";
    }
  




void fillVector(std::vector <pixel>& p, int npixels, pixel var) {
    for (size_t i = 0; i < npixels; i++) {
        p.push_back(var);
    }
}

void CreateShape(std::vector < pixel >& p, int npixels, Shapes shape) {

    pixel info;
    Colors White;

    if (shape == Shapes::FILLED) {
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {

                info.color = Colors::White;
                p.push_back(info);
            }
        }

    }
    // END OF FILLED
    else if (shape == Shapes::CHECKERBOARD) {
        for (int i = 1; i <= 8; i++){
            for (int j = 1; j <= 8; j++){

                if (i % 2 > 0){  // check if odd row
                  //for odd rows, odd columns get filled
                    if (j % 2 > 0) {// j is columns
                        info.color = Colors::White;
                        p.push_back(info);
                    }
                    else{
                        info.color = Colors::Black;
                        p.push_back(info);
                    }
                }
                else if (i % 2 == 0){
                  if ( j % 2 == 0){
                    info.color = Colors::White;
                    p.push_back(info);
                  }
                  else{
                    info.color = Colors::Black;
                    p.push_back(info);
              
                  }
                  
                }
            }
        }
    }
// End OF CHECKERBOARD

    else if (shape == Shapes::STRIPES) {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++)

                if (i % 2 != 0) {
                    info.color = Colors::White;
                    p.push_back(info);

                }
                else {
                    info.color = Colors::Black;
                    p.push_back(info);
                }
        }

    }
    //END OF STRIPES
    else if (shape == Shapes::HALF_RIGHT) {
        for (int i = 1; i <= 8; i++)
        {

            for (int j = 1; j <= 8; j++)
            {
                if (j >= 5) {

                    info.color = Colors::White;
                    p.push_back(info);

                }
                else {

                    info.color = Colors::Black;
                    p.push_back(info);
                }
            }

        }
    }
    //END OF HALFRIGHT
    else if (shape == Shapes::UPPER_TRI) {
        for (int i= 1; i <= 8; i++){
            for (int j=1; j <= 8; j++){
                if (i == 1) {
                    info.color = Colors::White;
                    p.push_back(info);
                }
                else if (i == 2){
                    
                    if(j <= 8 && j > 1){
                        info.color = Colors::White;
                        p.push_back(info);
                    }
                    else{
                    info.color = Colors::Black;
                    p.push_back(info);
                    }
                }
                else if(i == 3){
                  
                    if (j <= 8 && j > 2){
                      info.color = Colors::White;
                      p.push_back(info);
                    }
                    else{
                    info.color = Colors::Black;
                    p.push_back(info);
                }
                }
                else if (i == 4){
    
                    if (j<= 8 && j > 3){
                        info.color = Colors::White;
                        p.push_back(info);
                    }
                    else{
                    info.color = Colors::Black;
                    p.push_back(info);
                    }
                }
                else if (i == 5){
                     
                    if (j <= 8 && j > 4) {
                          info.color = Colors::White;
                          p.push_back(info);
                      }
                      else{
                      info.color = Colors::Black;
                      p.push_back(info);
                }
                }
                else if(i == 6){
                  if (j <= 8 && j > 5) {
                        info.color = Colors::White;
                        p.push_back(info);
                    }
                    else{
                        info.color = Colors::Black;
                    p.push_back(info);
                }
              }
                else if (i == 7){
                    if (j <= 8 && j > 6){
                      info.color = Colors::White;
                      p.push_back(info);
                    }
                    else{
                    info.color = Colors::Black;
                    p.push_back(info);
                }
                }
                else if (i == 8){
                  if (j <= 8 && j > 7) {
                      info.color = Colors::White;
                      p.push_back(info);
                    }
                    else {
                      info.color = Colors::Black;
                      p.push_back(info);
                }
                }
                   
                }
            }
          
    }
// END OF UPPER RIGHT TRIANGLE
    else if (shape == Shapes::X){
        for (int i = 1; i <= 8; i++){
            for (int j = 1; j <= 8; j++){
                if (i == 1) {
                    if (j == 1 || j == 8){
                  
                      info.color = Colors::White;
                      p.push_back(info);
                    }
                    else{
                      info.color = Colors::Black;
                      p.push_back(info);
                    }
                }// EOD row 1
                else if (i == 2){
                   if (j == 2 || j == 7){
                        info.color = Colors::White;
                        p.push_back(info);
                    }
                    else{
                        info.color = Colors::Black;
                        p.push_back(info);
                      }
                  }
                else if (i == 3){
                  if (j == 3 || j == 6){
                    info.color = Colors::White;
                    p.push_back(info);
                    }
                    else{
                    info.color = Colors::Black;
                    p.push_back(info);
                    }
                }
                else if (i == 4){
                  if (j == 4 || j == 5){
                    info.color = Colors::White;
                    p.push_back(info);
                  }
                  else{
                    info.color = Colors::Black;
                    p.push_back(info);
                  }
                }
                  else if(i == 5){
                    if (j == 4 || j == 5){
                        info.color = Colors::White;
                    p.push_back(info);
                    }
                    else{
                    info.color = Colors::Black;
                    p.push_back(info);
                    }
                  }
                else if (i == 6){
                  if (j == 3 || j == 6){
                    info.color = Colors::White;
                    p.push_back(info);
                  }
                  else{
                    info.color = Colors::Black;
                    p.push_back(info);
                  }
                }
                else if ( i == 7){
                  if (j == 2 || j == 7){
                    info.color = Colors::White;
                    p.push_back(info);
                  }
                  else{
                  info.color = Colors::Black;
                  p.push_back(info);
                  }
                }
                else if ( i == 8){
                  if (j == 1 || j == 8){
                    info.color = Colors::White;
                    p.push_back(info);
                    }
                  else{
                  info.color = Colors::Black;
                  p.push_back(info);
                  }
                }
                
              } // end of the j for loop
        }//end of the i for loop
    }// end of X
   
    
}
  
    
void Draw(std::vector < pixel > p){
    int half = sqrt(p.size());

    for (size_t i = 1; i < p.size()+1; i++) {

      //if (i % half == 0) {
      //  std::cout << std::endl;
      //}
      if (p.at(i - 1).color == Colors::Black) {
        std::cout << "   ";
        if (i % half == 0) {
        std::cout << std::endl;
        }
      }
      else if (p.at(i - 1).color == Colors::White) {
        std::cout << "|||";
        
        if (i % half == 0) {
        std::cout << std::endl;
        }

      }
    }
}


