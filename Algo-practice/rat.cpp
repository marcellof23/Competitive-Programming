#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000

//the point in the maze (with coordinate)
int Maze[6][6] = {
    {1, 1, 1, 1, 1, 1}, {1, 0, 0, 0, 1, 1}, {1, 0, 1, 0, 0, 1}, {1, 0, 0, 0, 1, 1}, {1, 1, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1}};

typedef struct
{
  int x;
  int y;
  int pre;
} Point;

//Create stack for the maze
typedef struct
{
  Point *data[MAXSIZE];
  int top;
} Stack;

/*Stack's Routine*/
//Funtion to initialize the stack
int InitStack(Stack *s)
{
  s->top = -1;
  return 0;
}

//Functio to destroy the stack
int DisposeStack(Stack *s)
{
  free(s);
  return 0;
}
//Function to know whther the stack is empty
int IsEmpty(Stack *s)
{
  if (s->top == -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
//Function to know whether the stack is full
int IsFull(Stack *s)
{
  if (s->top == MAXSIZE - 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
//Function to get the top value
int Top(Stack *s, Point *b)
{
  if (IsEmpty(s))
  {
    printf("Stack is empty\n");
    return 0;
  }
  else
  {
    b = s->data[s->top];
    return 0;
  }
}
//to insert a point in stack
int Push(Stack *s, Point *b)
{
  if (IsFull(s))
  {
    printf("The stack is full");
    return 0;
  }
  else
  {
    s->top++;
    s->data[s->top] = b;
  }
  return 1;
}

//to delete a point in stack
int Pop(Stack *s, Point *b)
{
  if (IsEmpty(s))
  {
    printf("The stack is empty\n");
    return 0;
  }
  else
  {
    b = s->data[s->top];
    s->top--;
    return 1;
  }
}

//Solution funtion
//(x,y) is the original point
//(xe,ye) is the ending point

int Solution(int x, int y, int xe, int ye)
{
  Stack S;
  Point path[MAXSIZE], e, E;
  Point ShortPath[MAXSIZE];

  int di = 0, x1 = 0, y1 = 0, i = 0, j = 0;
  int k = 0, fun = 0;
  int m = 0, lm = 0, n = 0, op = 0;
  int minlen = MAXSIZE;
  int js = 0, tp = 0;

  //initializing the stack
  InitStack(&S);
  e.x = x;
  e.y = y;
  e.pre = -1;
  Push(&S, &e);
  Maze[x][y] = -1;
  while (!IsEmpty(&S))
  {
    Top(&S, &e);
    i = e.x;
    j = e.y;
    di = e.pre;

    if (i == xe && j == ye)
    {
      k = 0;
      tp = S.top;
      for (js = 0; js <= tp; js++)
      {
        S.top = js;

        ShortPath[n] = path[op];
      }

      if (tp + 1 < minlen)
      {
        for (S.top = 0, n = 0; n <= tp; n++, S.top++)
        {
          ShortPath[n] = *S.data[S.top];
        }
        S.top = tp;
        minlen = tp + 1;
      }
      Maze[i][j] = 0;
      Pop(&S, &e);
      Top(&S, &e);
      i = e.x;
      j = e.y;
      di = e.pre;
    }
    fun = 0;
    while (di < 4 && fun != 1)
    {
      di++;
      switch (di)
      {
      case 0:
        x1 = i - 1;
        y1 = j;
        break;
      case 1:
        x1 = i;
        y1 = j + 1;
        break;
      case 2:
        x1 = j + 1;
        y1 = j;
        break;
      case 3:
        x1 = i;
        y1 = j - 1;
        break;
      }
      if (Maze[x1][y1] == 0)
      {
        fun = 1;
      }
    }
    if (fun == 1)
    {
      S.data[S.top]->pre = di;
      e.x = x1;
      e.y = y1;
      e.pre = -1;
      Push(&S, &e);
      Maze[x1][y1] = -1;
    }
    else
    {
      Pop(&S, &e);
      Maze[e.x][e.y] = 0;
    }
  }
  printf("The shortest path in a maze is %d: \n", minlen);
  for (n = 0; n < minlen; n++)
  {
    printf("(%d, %d)->", ShortPath[n].x, ShortPath[n].y);
  }
  DisposeStack(&S);

  return 0;
}

//Driver
int main()
{

  Solution(1, 1, 4, 4);
  return 0;
}