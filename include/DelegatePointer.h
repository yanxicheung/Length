#ifndef HFB7CE5DF_5761_44E0_B0D2_9AFBDB1E7D01
#define HFB7CE5DF_5761_44E0_B0D2_9AFBDB1E7D01
#include <iostream>
using namespace std;
template<typename T>
struct DelegatePointer
{
    DelegatePointer(const T&pointer,bool shouldDelete = false)
    :m_pointer(pointer),
     m_shouldDelete(shouldDelete){}

    T operator->()const
    {
        return m_pointer;
    }

    T operator*()const
    {
        return m_pointer;
    }

    ~DelegatePointer()
    {
        if(m_shouldDelete) {delete m_pointer;cout<<"delete"<<endl;}
    }
private:
    DelegatePointer(const DelegatePointer&p);
    DelegatePointer & operator=(const DelegatePointer&p);
private:
    T m_pointer;
    const bool m_shouldDelete;
};

#endif /* HFB7CE5DF_5761_44E0_B0D2_9AFBDB1E7D01 */
