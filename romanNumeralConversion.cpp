#include <iostream>
#include <string>

int convertNumeral(std::string numeral)
{
    int numToReturn = 0;
    int len = numeral.length();

    for (int i = 0; i < len; i++)
    {
        //check the substrings and add the appropriate numerical values
        if (numeral.substr(i, 1) == "M") //1000
            numToReturn += 1000;
        else if (numeral.substr(i, 1) == "C") //100
            numToReturn += 100;
        else if (numeral.substr(i, 1) == "L") //50
                numToReturn += 50;
        else if (numeral.substr(i, 1) == "X") //10
            numToReturn += 10;
        else if (numeral.substr(i, 1) == "V") //5
                numToReturn += 5;
        else if (numeral.substr(i, 1) == "I") //1 is more complex:
        {
            //if it is the last char in the string
            if (i + 1 == len)
                numToReturn += 1;

            //if the next char is another "I"
            else if (numeral.substr(i + 1, 1) == "I")
                numToReturn += 1;

            //if the next char is "V"
            else if (numeral.substr(i + 1, 1) == "V")
            {
                numToReturn += 4;
                i++; //incrememnt an aditional time
            }

            //if the next char is "X"
            else if (numeral.substr(i + 1, 1) == "X")
            {
                numToReturn += 9;
                i++;
            }

            //if the next char is "L"
            else if (numeral.substr(i + 1, 1) == "L")
            {
                numToReturn += 49;
                i++;
            }

            //if the next char is "C"
            else if (numeral.substr(i + 1, 1) == "C")
            {
                numToReturn += 99;
                i++;
            }

            //if the next char is "M"
            else if (numeral.substr(i + 1, 1) == "M")
            {
                numToReturn += 999;
                i++;
            }

            //I could do this same checking for each other numeral (for example, VL for 45) but you get the idea already
        } 
    }

    return numToReturn;
}

int main()
{
    std::string first = "XVIII"; //  18
    std::string second = "LIV"; //   54
    std::string third = "MCLXIV"; // 1164
    std::string fourth = "IX"; //    9

    std::cout << convertNumeral(first) << std::endl;
    std::cout << convertNumeral(second) << std::endl;
    std::cout << convertNumeral(third) << std::endl;
    std::cout << convertNumeral(fourth) << std::endl;
}