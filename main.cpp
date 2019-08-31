//  main.cpp
//  openCVtest
//
//  Created by Chris Nelson on 8/17/19.
//  Copyright © 2019 Chris Nelson. All rights reserved.


#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <time.h>
#include "helper.hpp"

using namespace cv;

//prototypes
void IMG_encrypt(Mat* image, std::string cypher, int encrypt);
Mat IMG_shift(Mat image, int shift1, int shift2, int xIncrement, int yIncrement);
void IMG_GIF(Mat image, std::string name, int iterations, int color1, int color2, int color3);
Mat IMG_compare(Mat image1,Mat image2);
int IMG_empty(Mat image1, std::string name);
Mat IMG_change(Mat image);

void onWaitKey(Mat image, std::string name, int appendix);




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, const char * argv[]) {
  srand(time(NULL));
  
  helper::splashScreen("   openCV   ",0);
  int choice = helper::menu("Compare Images", "Change Image");
  
  switch (choice) {
    case 1:
    {
      Mat image1,image2;
      
      std::string name1, name2, imageLocation1, imageLocation2;
      
      //wrap all input into compare.
      std::cout << "Enter in location of first image" << std::endl;
      std::cin >> name1;
      imageLocation1 = "/Users/chrisnelson/Documents/pictures/compare/"+name1;
      image1 = imread(imageLocation1);
      
      if(IMG_empty(image1, name1))
        return 0;

      std::cout << "Enter in location of second image" << std::endl;
      std::cin >> name2;
      imageLocation2 = "/Users/chrisnelson/Documents/pictures/compare/"+name2;
      image2 = imread(imageLocation2);
      
      if(IMG_empty(image2, name2))
        return 0;
      
      /*
      std::cout << "DEBUG amount of rows image1: " << image1.rows << std::endl;
      std::cout << "DEBUG amount of cols image1: " << image1.cols << std::endl;
      
      std::cout << "DEBUG amount of rows image2: " << image2.rows << std::endl;
      std::cout << "DEBUG amount of cols image2: " << image2.cols << std::endl;
      */
      
      Mat newMat = IMG_compare(image1, image2);
      imshow("difference", newMat);
      onWaitKey(newMat, name2, 0);
      destroyAllWindows();
      break;
    }
      
    case 2:
    {
      //wrap all input into change.
      
      break;
    }
  }
  return 0;
}


/*********************************************************************************************
This function compares the given images and logs a true of false string
*********************************************************************************************/
Mat IMG_compare(Mat image1, Mat image2)
{
  std::vector<Point> differences;

  int choice = helper::menu("Circle", "Outline");
  switch(choice)
  {
    case 1:
    {

      //manipulate picture
      for(int y=0; y<image1.rows; y++)
      {
        for(int x=0; x<image1.cols; x++)
        {
          
          Vec3b currPix1 = image1.at<Vec3b>(Point(x,y));
          Vec3b currPix2 = image2.at<Vec3b>(Point(x,y));
          
          Point center = Point(x,y);
          
          //color
          if(currPix1 != currPix2)
          {
            if(!(currPix1[0]+10 > currPix2[0] && currPix1[0]-10 < currPix2[0]))
            {
              if(!(currPix1[1]+10 > currPix2[1] && currPix1[1]-10 < currPix2[1]))
              {
                if(!(currPix1[2]+10 > currPix2[1] && currPix1[2]-10 < currPix2[2]))
                {
                  //std::cout << currPix1 << " : " << currPix2 << std::endl;
                  differences.push_back(center);
                }
              }
            }
          }
        }
      }
      
      int size = differences.size();
      for(int i = 0; i < size; i++)
      {
        circle(image2, differences[i], 50, Scalar(0,0,255));
        differences.pop_back();
      }
          break;
    }
      
    case 2:
    {
      //manipulate picture
      for(int y=0; y<image1.rows; y++)
      {
        for(int x=0; x<image1.cols; x++)
        {
          Vec3b currPix1 = image1.at<Vec3b>(Point(x,y));
          Vec3b currPix2 = image2.at<Vec3b>(Point(x,y));
          
          Point center = Point(x,y);
          
          if(currPix1 != currPix2)
          {
            if(!(currPix1[0]+10 > currPix2[0] && currPix1[0]-10 < currPix2[0]))
            {
              if(!(currPix1[1]+10 > currPix2[1] && currPix1[1]-10 < currPix2[1]))
              {
                if(!(currPix1[2]+10 > currPix2[1] && currPix1[2]-10 < currPix2[2]))
                {
                  //std::cout << currPix1 << " : " << currPix2 << std::endl;
                  differences.push_back(center);
                }
              }
            }
          }
        }
      }
      
      int size = differences.size();
      for(int i = 0; i < size; i++)
      {
        Vec3b currPix = image2.at<Vec3b>(differences[i]);
        currPix[0] = 0;
        currPix[1] = 0;
        currPix[2] = 255;
        image2.at<Vec3b>(differences[i]) = currPix;
        differences.pop_back();
      }
      break;
    }
  }
  return image2;
}


/*********************************************************************************************
This function changes specific pixels.  Test function
*********************************************************************************************/
Mat IMG_change(Mat image)
{
  Vec3b color;
  color[0] = 255;
  color[1] = 0;
  color[2] = 0;
  
  int rows = image.rows-1;
  int cols = image.cols-1;
  
  for(int i = 0; i < 6; i++)
  {
    image.at<Vec3b>(Point(rand()%rows, rand()%cols)) = color;
  }
  return image;
}


/*********************************************************************************************
This function waits for a user input to either quit or save the image.
*********************************************************************************************/
void onWaitKey(Mat image, std::string name, int appendix)
{
  char key = 0;
  
  while(key != 'q')
  {
    //what do we want to do?
    key = (char)waitKey();
    
    if(key == 's')
    {
      for(int i = 0; i < 4; i++)
      {
        name.pop_back();
      }
      std::string outName;
      std::cout << "enter desired name" << std::endl;
      std::cin >> outName;
      const std::string output = "/Users/chrisnelson/Documents/pictures/compare/"+ outName + ".jpg";
      imwrite(output, image);
      std::cout << outName << " saved" << std::endl;
      key = 'q';
    }
    
    else if(key == 'q')
      std::cout << "quiting" << std::endl;
  }
}


/*********************************************************************************************
This function waits for a user input to either quit or save the image.
*********************************************************************************************/
int IMG_empty(Mat image1, std::string name)
{
  if(image1.empty())
  {
    std::cout << "could not find image " + name + " - exiting" << std::endl;
    return 1;
  }
  else
    return 0;
}


/*********************************************************************************************
 This function "encrypts" the image.  Currently, it just swaps the current pixel with
 acompletely random pixel elsewhere, so not decryptable yet I will try to make this a cypher
 later on so with the right key, it is decrytable
 *********************************************************************************************/
void IMG_encrypt(Mat* image, std::string cypher, int encrypt)
{
  int yPos = 0;
  int xPos = 0;
  int debug_rows = image->rows;
  int debug_cols = image->cols;
  
  unsigned int counter = 0;
  
  //encrypt
  if(encrypt)
  {
    //manipulate the x
    //first round
    for(int y =0; y < image->rows; y++)
    {
      for(int x = 0; x < image->cols; x++)
      {
        // get pixel
        xPos = (image->cols-1) - (x+int(cypher[counter]));
        //int yPos = 0;
        if(xPos < 0)
        {
          xPos = xPos + (image->cols-1);
        }
        assert(xPos > -1);
        assert(xPos < image->cols);
        
        
        Vec3b currPix = image->at<Vec3b>(Point(x,y));
        Vec3b targetPix = image->at<Vec3b>(Point(xPos,y));
        Vec3b tempPix = currPix;
        
        image->at<Vec3b>(Point(x,y)) = targetPix;
        image->at<Vec3b>(Point(xPos,y)) = tempPix;
        
        counter++;
        if(counter == cypher.size())
          counter = 0;
      }
    }
    
    counter = 0;
    
    //manipulate the y
    for(int y = 0; y < image->rows; y++)
    {
      for(int x = 0; x < image->cols; x++)
      {
        // get pixel
        yPos = (image->rows-1) - (y+int(cypher[y%cypher.size()]));
        //int yPos = 0;
        if(yPos < 0)
        {
          yPos = yPos + (image->rows-1);
        }
        
        Vec3b currPix = image->at<Vec3b>(Point(x,y));
        Vec3b targetPix = image->at<Vec3b>(Point(x,yPos));
        Vec3b tempPix = currPix;
        
        image->at<Vec3b>(Point(x,y)) = targetPix;
        image->at<Vec3b>(Point(x,yPos)) = tempPix;
        
        counter++;
        if(counter == cypher.size())
          counter = 0;
      }
    }
  }
  
  //decrypt
  else
  {
    std::cout << "we are decrypting" << std::endl;
    counter = 0;
    //manipulate the y
    for(int y = image->rows-1; y > 0; y--)
    {
      for(int x = image->cols-1; x > 0; x--)
      {
        // get pixel
        yPos = (image->rows-1) - (y+int(cypher[y%cypher.size()]));
        //int yPos = 0;
        if(yPos < 0)
        {
          yPos = yPos + (image->rows-1);
        }
        assert(xPos > -1);
        assert(xPos < image->cols);
        
        Vec3b currPix = image->at<Vec3b>(Point(x,y));
        Vec3b targetPix = image->at<Vec3b>(Point(x,yPos));
        Vec3b tempPix = currPix;
        
        image->at<Vec3b>(Point(x,y)) = targetPix;
        image->at<Vec3b>(Point(x,yPos)) = tempPix;
        
        counter++;
        if(counter == cypher.size())
          counter = 0;
      }
    }
    
    counter = 0;
    
    //manipulate the x
    //first round
    for(int y = image->rows-1; y > 0; y--)
    {
      for(int x = image->cols-1; x > 0; x--)
      {
        // get pixel
        xPos = (image->cols-1) - (x+int(cypher[counter]));
        //int yPos = 0;
        if(xPos < 0)
        {
          xPos = xPos + (image->cols-1);
        }
        assert(xPos > -1);
        assert(xPos < image->cols);
        
        
        Vec3b currPix = image->at<Vec3b>(Point(x,y));
        Vec3b targetPix = image->at<Vec3b>(Point(xPos,y));
        Vec3b tempPix = currPix;
        
        image->at<Vec3b>(Point(x,y)) = targetPix;
        image->at<Vec3b>(Point(xPos,y)) = tempPix;
        
        counter++;
        if(counter == cypher.size())
          counter = 0;
      }
    }
  }
}

/*********************************************************************************************
 This function shifts the image in the x and y by user inputed constants
 *********************************************************************************************/
Mat IMG_shift(Mat image, int shift1, int shift2, int xIncrement, int yIncrement)
{
  //manipulate picture
  for(int y=0; y<image.rows; y +=yIncrement)
  {
    
    // get pixel
    int yPos = y;
    
    //calc the y pos
    if(yPos+shift2 > image.rows-1)
      yPos = image.rows - (yPos+shift2);
    else
      yPos+=shift2;
    
    for(int x=0; x<image.cols*2; x += xIncrement)
    {
      // get pixel
      int xPos = x;
      
      Vec3b color = image.at<Vec3b>(Point(x,y));
      // Vec3b temp;
      
      //calc the x pos
      if(xPos+shift1 > image.cols-1)
        xPos = (image.cols-1) - (xPos+shift1);
      else
        xPos+=shift1;
      
      color = image.at<Vec3b>(Point(xPos,yPos));
      color[0] = color[0]+50;
      color[1] = color[1]+75;
      color[2] = color[2]+25;
      image.at<Vec3b>(Point(x,y)) = color;
      // image.at<Vec3b>(Point(x,y)) = image.at<Vec3b>(Point(xPos,yPos));
      
      //image.at<Vec3b>(Point(x,y)) = temp;
      
    }
  }
  return image;
}

/*********************************************************************************************
 This function shifts the image in the x and y by user inputed constants
 *********************************************************************************************/
void IMG_GIF(Mat image, std::string name, int iterations, int color0, int color1, int color2)
{
  int counter = 0;
  
  //manipulate picture
  for(int i = 0; i < iterations; i++)
  {
    for(int y=0;y<image.rows;y++)
    {
      for(int x=0;x<image.cols;x++)
      {
        // get pixel
        Vec3b color = image.at<Vec3b>(Point(x,y));
        color[0]+=color0;
        color[1]+=color1;
        color[2]+=color2;
        if(color[0] > 255)
        {
          color[0] = color[0]-255;
        }
        if(color[1] > 255)
        {
          color[1] = color[1]-255;
        }
        if(color[2] > 255)
        {
          color[2] = color[2]-255;
        }
        image.at<Vec3b>(Point(x,y)) = color;
      }
    }
    
    {
      std::string output = "/Users/chrisnelson/Documents/PROJECTS/IMG_OUTPUTS/GIFS/" + name + "_" + std::to_string(counter) + ".jpg";
      std::cout << output << std::endl;
      imwrite(output, image);
      std::cout << "image saved" << std::endl;
      counter++;
    }
  }
}









/*********************************************************************************************
 move this or make it into seperate program
 *********************************************************************************************/
//
//  std::string imageName;
//  std::string imageName1;
//  std::string imageName2;
//  std::string cypher;
//  Mat image, image1, image2;
//  bool decrypt = false;
//  bool encrypt = false;

/*********************************************************************************************
 input handling
 *********************************************************************************************/

//  if(argc == 3)
//  {
//    encrypt = true;
//    std::cout << "you've selected an image through command line and the cypher" << std::endl;
//    imageName1 = argv[1];
//    imageName1 = argv[1];
//
//    cypher = argv[2];
//    image = imread(imageName);
//  }
//
//  else if(argc == 4)
//  {
//    decrypt = true;
//    std::cout << "you've selected an image through command line and the cypher" << std::endl;
//    imageName = argv[1];
//    cypher = argv[2];
//    image = imread(imageName);
//  }
//  else
//  {
//    std::cout << "please designate one image file as an argument" << std::endl;
//    std::cout << "using hard-coded images" << std::endl;
//    imageName1 = "/Users/chrisnelson/Documents/pictures/roar.jpg";
//    imageName2 = "/Users/chrisnelson/Documents/pictures/roar_changed.jpg";
//
//    image1 = imread(imageName1);
//    image2 = imread(imageName2);
//  }





/*********************************************************************************************
 body of program
 *********************************************************************************************/

/*
 if(encrypt)
 {
 //encrypt the image
 std::cout << "encrypting" << std::endl;
 //image = IMG_encrypt(image,cypher,1);
 IMG_encrypt(&image,cypher,1);
 
 }
 else
 {
 //decrypt the image
 std::cout << "decrypting" << std::endl;
 //image = IMG_encrypt(image,cypher,0);
 IMG_encrypt(&image,cypher,0);
 
 }
 */

//modify specific pixel
//  Mat diff = IMG_change(image1);

//shift the image
//image = IMG_shift(image,125,55, 1, 2);

//GIF the image
//IMG_GIF(image, "transformer_cat", 25, 10, 20, 30);

//compare the images
//  Mat diff = IMG_compare(image1,image2);

//show the image
//  imshow("current window", diff);
//save or delete the image
//  onWaitKey(diff, imageName2, 0);

//  destroyAllWindows();
