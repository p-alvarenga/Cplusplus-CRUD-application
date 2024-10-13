#include "../include/DAL.h"

namespace data
{
    namespace db
    {
        DAL::DAL() 
        {
            dao_inst = new DAO();
        }

        data::Person DAL::getPersonById(int &_id)
        {
            return dao_inst->selectPersonById(_id);
        }

        data::Person DAL::getPersonByCpf(std::string &_cpf)
        {
            return dao_inst->selectPersonByCpf(_cpf);
        }

        int DAL::deletePersonById(int &_id)
        {
            return dao_inst->removePersonById(_id);
        }

        std::vector<data::Person> DAL::getAll()
        {
            return dao_inst->selectAll();
        }

        unsigned DAL::addPerson(data::Person &_person)
        {
            return dao_inst->insertPerson(_person);
        }

        unsigned DAL::updatePerson(data::Person &p)
        {
            return dao_inst->updatePersonById(p);
        }
    }
}