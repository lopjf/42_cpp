#include <iostream>

// Ad-hoc Polymorphisme

#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {
    
public:

    Sample(void);
    ~Sample(void);

	// function overload
    void bar(char const c) const;
    void bar(int const n) const;
    void bar(float const z) const;
    void bar(Sample const & i) const;

};


#endif