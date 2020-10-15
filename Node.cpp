#include <Node.h>
#include <sstream>

string Node::toString()
{
  if(this != nullptr){
  string result;
  
  result = *name;

  return result;
  }
  else return " ";
  
}
string Node::toLeft()
{
  string leftOf;
  if(left != nullptr)
    {
  leftOf = left->toString();
  return leftOf;
    }
  else
    return "";
}
string Node::toRight()
{
  string rightOf;
  if(right != nullptr)
    {
  rightOf = right->toString();
  return rightOf;
    }
  else
    return "";
}
string Node::toUp()
{
  string upOf;
  if(up != nullptr)
    {
  upOf = up->toString();
  return upOf;
    }
  else
    return "";
}
string Node::toDown()
{
  string downOf;
  if(down != nullptr)
    {
  downOf = down->toString();
  return downOf;
    }
  else
    return "";
}


Node::~Node()
{
  delete name; name = NULL;
  //delete left;
  left = NULL;
  //delete right;
  right = NULL;
  //delete up;
  up = NULL;
  //delete down;
  down = NULL;
 
  }

