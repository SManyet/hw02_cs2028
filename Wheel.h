#ifndef WHEEL_H
#define WHEEL_H

class Wheel {
    private:
        int maxVal;

    public:
        Wheel();
        Wheel(int);
        int spin();
        int getMaxVal();        
};
#endif
