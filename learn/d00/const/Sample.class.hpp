#include <iostream>

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {
    
public:

    float const pi;
    int         qd;

    Sample(float const f);
    ~Sample(void);

    void bar(void) const;

};  // do not forget the ; at the end of the class


#endif