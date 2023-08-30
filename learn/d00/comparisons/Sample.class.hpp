#include <iostream>

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {
    
public:

    Sample(int v);
    ~Sample(void);

    int getFoo(void) const;
    int compare(Sample *other) const;

private:

    int _foo;

};


#endif