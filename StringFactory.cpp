#include "StringFactory.hpp"


bool StringFactory::isInString(string searchString, char charToFind)
{
    for(int i = 0; i < searchString.length(); i++)
    {
        if(searchString[i] == charToFind)
        {
            return true;
        }
    }
    return false;
}

Queue* StringFactory::split(string s, string delims)
{
    
    Queue* answerQ = new Queue();
    string temp = "";
    for(int i = 0; i < s.length(); i++)
    {
        if(isInString(delims, s[i]))
        {
            answerQ->enqueue(temp);
            answerQ->enqueue((string)"" + s[i]);
            temp = "";
        }
        else
        {
            temp = temp + s[i];
        }
    }
    answerQ->enqueue(temp);
    return answerQ;
}