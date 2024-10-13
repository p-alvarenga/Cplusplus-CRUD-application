#ifndef PERSON_H_
#define PERSON_H_

#include <string>

namespace data
{
    class Person 
    {     
        private:
            int age, id;
            std::string name, cpf;

        public:
            Person(const int &_id, const std::string &_name, const std::string &_cpf, const int &_age);
            Person();

            void setPerson(const int &_id, const std::string &_name, const std::string &_cpf, const int &_age);

            int getAge() const;
            int getId() const;
            std::string getName() const;
            std::string getCpf() const;

            void setId(int _id);

            bool operator!=(Person const &p2)
            {
                return !(id == p2.getId() && name == p2.getName() && cpf == p2.getCpf() && age == p2.getAge());
            }

            ~Person() {;} 
    };
}


#endif