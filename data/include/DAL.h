#ifndef DAL_H_
#define DAL_H_

#include "./DAO.h"
#include "./Person.h"

namespace data
{
    namespace db
    {
        class DAL 
        {
            private:
                DAO *dao_inst;

            public:
                DAL();
                
                data::Person getPersonById(int &_id);
                data::Person getPersonByCpf(std::string &_cpf);
                int deletePersonById(int &_id);
                std::vector<data::Person> getAll();
                unsigned addPerson(data::Person &_person);
                unsigned updatePerson(data::Person &p);
        };
    }
}

#endif