#ifndef helper_HPP 
#define helper_HPP 

#include<limits>
#include<string>

  class helper 
{
  
  public:
    static int getInt(int);
    static int getInt(int, int);
    static int getInt(int, std::string);
    static int getInt(int, int, std::string);
    static int getInt(int, int, int, std::string);
    static std::string getString(int);
    static void splashScreen(std::string, int);
    static void newLine();
    static void newLine(int);
    static int menu(std::string, std::string);
    static int menu(std::string, std::string, std::string);
    static int menu(std::string, std::string, std::string,std::string);
    static int menu(std::string, std::string, std::string,std::string, std::string);
    static int menu(std::string, std::string, std::string,std::string, std::string, std::string);
    static bool isInBounds(int, int, int);
    static bool isInBounds(int, int);
    const int infinity = std::numeric_limits<int>::max();
    static void printArray(int*, int);
    static void fillArray(int*, int, int);
    static void printMessage(std::string, int);



			
};

#endif
