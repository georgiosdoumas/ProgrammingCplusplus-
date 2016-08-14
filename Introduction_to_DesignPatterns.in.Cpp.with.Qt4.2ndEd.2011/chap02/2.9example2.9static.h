class Thing 
{
public:
    Thing(int a, int b);
    ~Thing();
    void display() const ;  //for implementations-definitions, look file 2.9example2.10static.cpp
    static void showCount();
private:
    int m_First, m_Second;
    static int s_Count;     //counts existing Things
};
