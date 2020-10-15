#include <iostream>
#include <Node.h>
#include <point.h>
#include <main.h>
#include <sstream>
#include <cstdlib>
#include <ctime>

void  start(Node *nodes[][10])
{
  int character = 0;

  for(int i=0;i < 10; i++)
    {
      for(int j=0; j < 10; j++)
	{
	  stringstream ss;
	  ss << character;
	  string s = ss.str();
	  nodes[i][j] = new Node();
	  nodes[i][j]->name = new string(s);
	  character += 1;
	  // cout <<  nodes[i][j]->toString() <<  endl;
	}
	    
    }

  /*   for(int i = 0; i < 10; i++)
    {
      cout << nodes[i][0]->toString() << " " << nodes[i][1]->toString() << " " << nodes[i][2]->toString() << " " << nodes[i][3]->toString() << " " << nodes[i][4]->toString() << " " << nodes[i][5]->toString() << " " << nodes[i][6]->toString() << " " << nodes[i][7]->toString() << " " << nodes[i][8]->toString() << " " << nodes[i][9]->toString() << " " << endl;
      }*/

  for(int i = 0; i < 10; i++)
    {
      for(int j = 0; j < 10; j++)
	{
	  if(j-1 >= 0 && j-1 < 10)
	    {
	      nodes[i][j]->left = nodes[i][j-1];
	    }
	  else
	    {
	      nodes[i][j]->left = NULL;
	    }
	  if(j+1 >= 0 && j+1 < 10)
	    {
	      nodes[i][j]->right = nodes[i][j+1];
	    }
	  else
	    {
	      nodes[i][j]->right = NULL;
	    }
	  if(i-1 >= 0 &&  i-1 < 10)
	    {
	      nodes[i][j]->up = nodes[i-1][j];
	    }
	  else
	    {
	      nodes[i][j]->up = NULL;
	    }
	  if(i+1 >= 0 && i+1 < 10)
	    {
	      nodes[i][j]->down = nodes[i+1][j];
	    }
	  else
	    {
	      nodes[i][j]->down = NULL;
	    }
	  
	}
    }
}
void printNodeLinks(Node *node)
{
  if(node != nullptr)
    {
      cout << "This is the name of the node: " << node->toString() << endl;
    }
  if(node->left != nullptr)
    {
      cout << "This is the node on the left: " << node->toLeft() << endl;
    }
  if(node->right != nullptr)
    {
      cout << "This is the node on the right: " << node->toRight() << endl;
    }
  if(node->up != nullptr)
    {
      cout << "This is the node on the top: " << node->toUp() << endl;
    }
  if(node->down != nullptr)
    {
      cout << "This is the node on the bottom: " << node->toDown() << endl;
    }
 

}
void printNodes(Node *n[][10])
{
  for(int i = 0; i < 10; i++)
    {
      for(int j = 0; j < 10; j++)
	{
	  if(n[i][j] != nullptr)
	    {
	      cout << n[i][j]->toString() << " ";
	    }
	  else
	    cout << " " << " ";
	}
      cout << endl;
    }
  //cout << "This is 'n' the address of nodes[][]" << n << endl;
  //	cout << "This is '*n' the address of nodes[][] on the heap: " << *n << endl;
  //	cout << "This is '&n' the address of nodes[][] on the stack: " << &n << endl;
  
}

Node * findNode(Node *a, Node *nodes[][10])
{
  for(int i = 0; i < 10; i++)
    {
      for(int j = 0; j < 10; j++)
	{
	  if(!nodes[i][j])
	    {
	      if(nodes[i][j]->name == a->name)
		{
		  return nodes[i][j];
		}
	    }
	}
    }
  return nullptr;

}
bool isEmpty(Node *nodes[][10])
{
  for(int i = 0; i < 10; i++)
    {
      for(int j = 0; j < 10; j++)
	{
	  if(nodes[i][j] != NULL)
	    return false;
	}
    }
  return true;
}
void deleteRun(int random, int random2, Node *nodes[][10])
{
  if(nodes[random][random2] != nullptr)
    {
      Node *left1 = nodes[random][random2]->left;//findNode(nodes[random][random2]->left,nodes);
      Node *right1 = nodes[random][random2]->right;//findNode(nodes[random][random2]->right,nodes);
      if(left1 != nullptr && right1 != nullptr)
	{
	  left1->right = right1;
	 right1->left = left1;
	}
      else if(left1 == nullptr && right1 == nullptr)
	{
	  nodes[random][random2]->left = NULL;
	  nodes[random][random2]->right = NULL;
	}
      else if(left1 == nullptr)
	{
	  right1->left = NULL;
	}
      else if(right1 == nullptr)
	{
	  left1->right = NULL;
	}
      Node *up1 = nodes[random][random2]->up;//findNode(nodes[random][random2]->up,nodes);
      Node *down1 = nodes[random][random2]->down;//findNode(nodes[random][random2]->down,nodes);
      if(up1 != nullptr && down1 != nullptr)
	{
	  up1->down = down1;
	  down1->left = up1;
	}
      else if(up1 == nullptr && down1 == nullptr)
	{
	  nodes[random][random2]->up = NULL;
	  nodes[random][random2]->down = NULL;
	}
      else if(up1 == nullptr)
	{
	  down1->up = NULL;
	}
      else if(down1 == nullptr)
	{
	  up1->down = NULL;
	}

    }
   delete nodes[random][random2];
    nodes[random][random2] = NULL;
}


int main(void)
  {
     srand(static_cast<unsigned int>(time(0)));
      
    Node *nodesptr[10][10];
    start(nodesptr);
    cout << "This is the address of nodes[][]" << nodesptr << endl;
    string d = "d";
    int counter = 0;
    bool empty = false;
     while(!empty)
       {
    //while (d == "d" || d == "D")
    //{
	 //cout << "Enter d to delete a random node" << endl;
      //cin >> d;
      printNodes(nodesptr);
    
       int max = 10;
       int r = rand()%max;
       int r2 = rand()%max;
       cout << "random: " << r << " random2: " << r2 << endl;
       cout << "Node number deleted: " << nodesptr[r][r2]->toString() << endl;
       deleteRun(r,r2,nodesptr);
       empty = isEmpty(nodesptr);
       
    }
    printNodes(nodesptr);
    // delete nodesptr;
  return 1;
  
  }

	 

