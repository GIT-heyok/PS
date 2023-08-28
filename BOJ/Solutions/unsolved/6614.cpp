#include <stdio.h>
#include <string.h>
#include <math.h>

static inline int zaok (double x)
{
  return ((x)>=0?(int)((x)+0.5):(int)((x)-0.5));
}

#define HSIZE 51

static const char face[HSIZE][HSIZE + 2] =
 {
    "@XXXXXXXXX@XXXXXXXXX@XXXXXXXXX@XXXXXXXXX@XXXXXXXXX@\n",
    "X                                                 X\n",
    "X                       1 2                       X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "@                                                 @\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "@                                                 @\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X 9                      *                      3 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "@                                                 @\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "@                                                 @\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                                                 X\n",
    "X                        6                        X\n",
    "X                                                 X\n",
    "@XXXXXXXXX@XXXXXXXXX@XXXXXXXXX@XXXXXXXXX@XXXXXXXXX@\n"
 };
static char buffer[HSIZE][HSIZE + 2];

static void
getpos (int angle, int i, int *x, int *y, int *var)
{
  if (90 < angle && angle < 270)
    {
      *x = i;
      *y = zaok (i * tan ((180 - angle) * M_PI/360));
      *var = *y;
    }
  else if (270 <= angle && angle < 450)
    {
      *y = -i;
      *x = zaok (i * tan ((360 - angle) * M_PI/360));
      *var = *x;
    }
  else if (450 <= angle && angle < 630)
    {
      *x = -i;
      *y = zaok (i * tan ((angle-540) * M_PI/360));
      *var = *y;
    }
  else
    {
      *y = i;
      *x = zaok (i * tan (angle * M_PI/360));
      *var = *x;
    }
}

static char
detchar (int angle, int samep, int samen)
{
  if (samep && samen)
    return ((90 < angle && angle < 270) || (450 < angle && angle < 630)) ? '-' : '|';
  else if (samep || samen)
    return 'o';
  else
    return ((0 < angle && angle < 180) || (360 < angle && angle < 540)) ? '/' : '\\';
}

static void
segment (int angle, int length)
{
  int i, x, y, ch, lch = 0, nch;

  angle %= 720;

  for (i = 1; ; i++)
    {
      getpos (angle, i + 1, &x, &y, &nch);
      getpos (angle, i, &x, &y, &ch);

      if (x * x + y * y > length * length)
        return;

      buffer[25 - y][25 + x] = detchar (angle, lch == ch, nch == ch);

      lch = ch;
    }
}

int main(void)
{
  int h, m, i;
  while (scanf ("%d:%d", &h, &m) == 2)
    {
      memcpy (buffer, face, sizeof (face));
      segment (60 * h + m, 15);
      segment (12 * m, 21);

      for (i = 0; i < HSIZE; i++)
        printf ("%s", buffer[i]);
      printf ("\n");
    }
  return 0;
}