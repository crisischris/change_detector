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
Mat IMG_compare(Mat image1,Mat image2);
int IMG_empty(Mat image1, std::string name);
void onWaitKey(Mat image, std::string name, int appendix);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, const char * argv[]) {
  srand(time(NULL));
  
  Mat trackImage;
  int min = 0;
  
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
      
      Mat newMat = IMG_compare(image1, image2);
      imshow("difference", newMat);
      onWaitKey(newMat, name2, 0);
      destroyAllWindows();
      break;
    }
      
    case 2:
    {
      std::cout << "sorry there are no options yet" << std::endl;
      
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
  std::vector<Point> hull;
  Scalar red = Scalar(0,0,255);

  int choice = helper::menu("Circle", "Outline", "Convex Hull");
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
        circle(image2, differences[i], 50, red);
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
      
    case 3:
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
      
      convexHull(differences, hull);
      int size = hull.size();
      for(int i = 0; i < size; i++)
      {
        int next = i+1;
        if(next == size)
          next = 0;
        line(image2, hull[i], hull[next], red);
      }
      
      break;
    }
  }
  return image2;
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
