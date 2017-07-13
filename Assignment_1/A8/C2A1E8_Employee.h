#ifndef C2A1E8_EMPLOYEE_H

/*
 * Name: Krishna Ram Budhathoki, UCSD-ID: U07256570
 * email: krishna.budhathoki@gmail.com
 * course: C/C++ Programming II : Dynamic Memory and File I/O Concepts
 * Section ID: 124134,Instructor: Raymond L. Mitchell, Jr., M.S
 * Date: 7/12/2017
 * File Name: C2A1E8_Employee.h
 * OS: window 7
 * Compiler: g++ (GCC) 6.3.0
 *
 * Class Type Employee is defined. Most of the member functions are also defined
 * Function overloading is implemented for functions name Set and Get
 *
 * DO NOT COPY OR RESTATE MY INSTRUCTIONS IN THE TITLE BLOCK.
 */
#define C2A1E8_EMPLOYEE_H
class Employee
{
private:
    char *name;
    int age;
    float raise;
    double salary;
public:
    void Set(const char *ch);
    void Set(int l_age = 25)
    {
        age = l_age;
    }
    void Set(const float &l_raise)
    {
        raise = l_raise;
    }
    void Set(const double *l_salary)
    {
        salary = *l_salary;
    }
    char *Get(char **address) const
    {
        *address = name;
        return name;
    }
    int Get(int &l_age) const
    {
        l_age = age;
        return age;
    }
    float &Get(float &l_raise) const
    {
        l_raise = raise;
        return l_raise;
    }
    inline  double Get(double *l_salary) const;
};

inline double Employee::Get(double *l_salary) const
{
    *l_salary = salary;
    return salary;
}
#endif
