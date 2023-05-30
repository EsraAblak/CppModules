#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>

class Bureaucrat
{
    const std::string name;
    int grade;

    public:
    Bureaucrat(std::string name,int grade);

    Bureaucrat();
    Bureaucrat(const Bureaucrat &copyB);
    Bureaucrat &operator = (const Bureaucrat &copyB);
    ~Bureaucrat();

    const std::string &getName() const;
    int getGrade();
    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : std::exception
    {
        virtual const char* what() const throw()
        {
            return "Grade Too High";
        }
    };

    class GradeTooLowException : std::exception
    {
        virtual const char* what() const throw()
        {
            return "Grade Too Low";
        }
    };
};

std::ostream& operator<<(std::ostream &out,Bureaucrat &str);

#endif