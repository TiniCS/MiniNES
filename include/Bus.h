#ifndef __Bus_H__
#define __Bus_H__

typedef char bit8;
typedef short bit16;

class DataBus
{
public:
    void setData(bit8& d) { m_data = d; }
    bit8 data() const { return m_data; }
private:
    bit8 m_data;
};

class ControlBus
{
private:
    bit8 m_data;
};

class AddressBus
{
private:
    bit16 m_data;
};

#endif