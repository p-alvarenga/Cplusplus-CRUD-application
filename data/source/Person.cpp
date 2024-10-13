#include "../include/Person.h"

namespace data
{
    Person::Person(const int &_id, const std::string &_name, const std::string &_cpf, const int &_age)
    {
        this->setPerson(_id, _name, _cpf, _age);
    }

    Person::Person(): id(-1), age(0) {;}

    void Person::setPerson(const int &_id, const std::string &_name, const std::string &_cpf, const int &_age)
    {
        id = _id;
        name = _name;
        cpf = _cpf;
        age = _age;

        return;
    }

    int Person::getAge() const { return age; }
    int Person::getId() const { return id; }
    std::string Person::getName() const { return name; }
    std::string Person::getCpf() const { return cpf; }

    void Person::setId(int _id)
    {
        this -> id = _id;

        return;
    }
}