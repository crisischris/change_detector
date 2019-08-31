/******************************************************************************
** Author: Chris Nelson 
** Date: /4/2019-present  
** Description: This is my helper class.  for clarity, I have wrapped the
** methods in the class "helper" and declared them static to use freely.
** This will be a continually growing file as the needs arise 
******************************************************************************/

#include<iostream>
#include"helper.hpp"
#include<limits>
#include<string>




//****************************************************************************
//this function will take a user input, and make sure that it is
//and integer.  If prompt is neccesary, use argument 1 
//if user enters a double, double will be floored to an int.
//****************************************************************************
int helper::getInt(int prompt)
{
  //citation: stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-
  //and-cin-ignore-after-reading-input
  int in;

  if(prompt == 1)
  {
    std::cout << "Enter a valid integer" << std::endl;
  }
  std::cin >> in;

  //this catches non integer inputs such as chars
  while(!std::cin.good())
  {
    std::cout << "that is not a valid input, enter a valid integer" << std::endl; 
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> in;
  }
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return in;
}




//****************************************************************************
//this function will take a user input, and make sure that it is
//and integer.  If prompt is neccesary, use argument 1 
//if user enters a double, double will be floored to an int.
//****************************************************************************
int helper::getInt(int prompt, std::string stringIn)
{
  //citation: stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-
  //and-cin-ignore-after-reading-input
  int in;

  if(prompt == 1)
  {
    std::cout << stringIn << std::endl;
  }
  std::cin >> in;

  //this catches non integer inputs such as chars
  while(!std::cin.good())
  {
    std::cout << "that is not a valid input, enter a valid integer" << std::endl; 
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> in;
  }
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return in;
}






//****************************************************************************
//this function will take a user input, and make sure that it is
//and integer.  If prompt is neccesary, use argument 1 
//if user enters a double, double will be floored to an int.
//this overlaod requires a minimum integer 
//****************************************************************************
int helper::getInt(int prompt, int min, std::string stringIn)
{
  //citation: stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-
  //and-cin-ignore-after-reading-input
  int in;

  if(prompt == 1)
  {
    std::cout << stringIn << std::endl;
  }

  std::cin >> in;
  while(!isInBounds(min, in))
  {
    std::cout << "that is not a valid input, enter a valid integer" << std::endl; 
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> in;
  }

  //this catches non integer inputs such as chars
  while(!std::cin.good())
  {
    std::cout << "that is not a valid input, enter a valid integer" << std::endl; 
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> in;
  }
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return in;
}




//****************************************************************************
//this function will take a user input, and make sure that it is
//and integer.  If prompt is neccesary, use argument 1 
//if user enters a double, double will be floored to an int.
//this overlaod makes sure the int is within a designated range
//****************************************************************************
int helper::getInt(int prompt, int min, int max, std::string stringIn)
{
  int in;

  if(prompt == 1)
  {
    std::cout << stringIn << std::endl;
  }

  std::cin >> in;
  while(!isInBounds(min, max, in))
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> in;
  }

  //this catches non integer inputs such as chars
  while(!std::cin.good())
  {
    std::cout << "that is not a valid input, enter a valid integer" << std::endl; 
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> in;
  }
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return in;
}

//****************************************************************************
//this function will take a user input, and make sure that it is
//and integer.  It also takes a min and max integer  
//****************************************************************************
int helper::getInt(int min, int max)
{
  int in;

  std::cin >> in;
  while(!isInBounds(min, max, in))
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> in;
  }

  //this catches non integer inputs such as chars
  while(!std::cin.good())
  {
    std::cout << "that is not a valid input, enter a valid integer" << std::endl; 
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> in;
  }
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return in;
}





//this function retreives a string from the user
std::string helper::getString(int prompt)
{
  if(prompt == 1)
  {
    std::cout << "Enter a string" << std::endl;
  }

  std::string name;
	std::getline(std::cin, name);  

  return name;
}




//****************************************************************************
//this function prints to console a demarcation to visually show the user 
//that hey have started the program.  It takes a string parameter and 
//inserts the name into the middle of the splash screen. 
//****************************************************************************
void helper::splashScreen(std::string name, int size)
{
  int number;
  helper::newLine(3);

  //odd number of stars for odd name length
  if(size == 1)
  {
    number = 59;
  }
  //even number of stars for even name length
  else
  {
    number = 60;
  }
  for(int i = 0; i < 2; i++)
  {
    if(i == 1)
    {
      int offset = (number - name.length()) / 2;
      
      for(int k  = 0; k < offset; k++)
      {
        std::cout << "*";
      } 
      std::cout << name;

      for(int f = 0; f < offset; f++)
      {
        std::cout << "*";
      }  
      std::cout << std::endl;
    }

    for(int j =0; j < number; j++)
    {
      std::cout << "*";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl << std::endl << std::endl;
}




//****************************************************************************
//this function simply prints a new line. I got tired of writting it
//longways.
//****************************************************************************
void helper::newLine()
{
  std::cout << std::endl;
}




//****************************************************************************
//this function is an overload of the newLine.  It takes an int and
//prints to console a user defined amount of new lines  
//****************************************************************************
void helper::newLine(int amount)
{
  for(int i = 0; i < amount; i++)
  {
    std::cout << std::endl;
  }
}





//****************************************************************************
//this funciton takes (2) string arguments, and displays them
//in a menu format.  It then returns the user inputted option.
//****************************************************************************
int helper::menu(std::string first, std::string second)
{
  std::cout << "1: " << first << std::endl;
  std::cout << "2: " << second << std::endl;
  helper::newLine();
  int out = helper::getInt(0);
  while(out > 2 || out < 1)
  {
    out = helper::getInt(1);
  }
  return out;
}  




//****************************************************************************
//this funciton takes (3) string arguments, and displays them
//in a menu format.  It then returns the user inputted option.
//****************************************************************************
int helper::menu(std::string first, std::string second, std::string third)
{
  std::cout << "1: " << first << std::endl;
  std::cout << "2: " << second << std::endl;
  std::cout << "3: " << third << std::endl;

  helper::newLine();
  int out = helper::getInt(0);
  while(out > 3 || out < 1)
  {
    out = helper::getInt(1);
  }
  return out; 
}




//****************************************************************************
//this funciton takes (4) string arguments, and displays them
//in a menu format.  It then returns the user inputted option.
//****************************************************************************
int helper::menu(std::string first, std::string second, std::string third, std::string forth)
{
  std::cout << "1: " << first << std::endl;
  std::cout << "2: " << second << std::endl;
  std::cout << "3: " << third << std::endl;
  std::cout << "4: " << forth << std::endl;

  helper::newLine();
  int out = helper::getInt(0);
  while(out > 4 || out < 1)
  {
    out = helper::getInt(1);
  }
  return out; 
}

//****************************************************************************
//this funciton takes (4) string arguments, and displays them
//in a menu format.  It then returns the user inputted option.
//****************************************************************************
int helper::menu(std::string first, std::string second, std::string third, std::string forth, std::string fifth)
{
  std::cout << "1: " << first << std::endl;
  std::cout << "2: " << second << std::endl;
  std::cout << "3: " << third << std::endl;
  std::cout << "4: " << forth << std::endl;
  std::cout << "5: " << fifth << std::endl;

  helper::newLine();
  int out = helper::getInt(0);
  while(out > 5 || out < 1)
  {
    out = helper::getInt(1);
  }
  return out; 
}

//****************************************************************************
//this funciton takes (5) string arguments, and displays them
//in a menu format.  It then returns the user inputted option.
//****************************************************************************
int helper::menu(std::string first, std::string second, std::string third, std::string forth, std::string fifth,
                 std::string sixth)
{
  std::cout << "1: " << first << std::endl;
  std::cout << "2: " << second << std::endl;
  std::cout << "3: " << third << std::endl;
  std::cout << "4: " << forth << std::endl;
  std::cout << "5: " << fifth << std::endl;
  std::cout << "6: " << sixth << std::endl;

  helper::newLine();
  int out = helper::getInt(0);
  while(out > 6 || out < 1)
  {
    out = helper::getInt(1);
  }
  return out; 
}

//****************************************************************************
//this fucntion determins if the target integer is within
//the bounds of the min and max integers - inclusive.
//it returns a bool.
//****************************************************************************
bool helper::isInBounds(int min, int max, int target)
{
  if(target < min || target > max)
  {
    std::cout << "integer not in bounds" << std::endl;
    return false;
  }
  else
  {
    return true;
  }
}




//****************************************************************************


//****************************************************************************
bool helper::isInBounds(int min, int target)
{
  if(target < min)
  {
    std::cout << "integer too small" << std::endl;
    return false;
  }
  else
  {
    return true;
  }
}



//****************************************************************************


//****************************************************************************
void helper::printArray(int* array, int size)
{
  for(int i = 0; i < size; i++)
  {
    std::cout << array[i] << std::endl;
  } 
}



//****************************************************************************


//****************************************************************************
void helper::fillArray(int* array, int size, int content)
{
  for(int i = 0; i < size; i++)
  {
    array[i] = content;
  } 
}



//****************************************************************************


//****************************************************************************
void helper::printMessage(std::string in, int amount)
{
  std::cout << in;
  helper::newLine(amount);
}

















