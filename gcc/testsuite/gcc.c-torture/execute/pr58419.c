int printf(const char *, ...);

int a, g, i, k, *p; 
char b, e;
short c, h;
static short *d = &c;

char
foo (int p1, int p2)
{
  return p1 - p2;
}

int
bar ()
{
  short *q = &c;
  *q = 1;
  *p = 0;
  return 0;
}

int
main ()
{
  for (b = -22; b >= -29; b--)
    {
      short *l = &h;
      char *m = &e;
      *l = a;
      g = foo (*m = k && *d, 1 > i) || bar (); 
    }
  getpid();
  return 0;
}
