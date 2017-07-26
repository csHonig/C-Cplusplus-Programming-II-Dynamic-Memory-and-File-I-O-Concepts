void TestDeclarations()
{
    void *vp = 0;
    int fcnA(int val);
    float (**ppa)[9];
    float (**&rppa)[9] = ppa;
    ppa = (float (**)[9])vp;
  }
