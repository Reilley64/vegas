// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct A3dd00Info
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    char m_14;
};

struct FUN_00a3dd00_class
{
    void* m_p0;
    void* m_p1;
    void* m_p2;
    void* m_p3;
    void* m_p4;
    void* m_p5;
    A3dd00Info* m_p6;
    int FUN_00a3dd00(int& a, int& b, char& c);
};

// @fnv 0x00a3dd00
int FUN_00a3dd00_class::FUN_00a3dd00(int& a, int& b, char& c)
{
    int result = 0;
    A3dd00Info* p = m_p6;
    if (p)
    {
        a = p->m_08;
        b = p->m_10;
        c = p->m_14;
        result = p->m_0c;
    }
    else
    {
        a = result;
        b = result;
        c = (char)result;
    }
    return result;
}
