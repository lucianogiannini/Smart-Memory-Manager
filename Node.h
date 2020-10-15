#include <string>

using namespace std;

 class Node
{
 public:
  string *name;
  Node *left;
  Node *right;
  Node *up;
  Node *down;
  
  string toString();
  string toLeft();
  string toRight();
  string toUp();
  string toDown();
    ~Node();
};
