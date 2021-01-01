#pragma once

// This is coin interface
class Coin 
{
    public :
        virtual void updateCount(int offset)=0;
        virtual int getCount()=0;
};
