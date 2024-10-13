#ifndef DAO_H_
#define DAO_H_

#include <soci/soci.h>
#include <soci/mysql/soci-mysql.h>
#include <vector>

#include <iostream>

#include "./Person.h"
#include "./person-soci_binding.h"

namespace data
{
    namespace db
    {
        class DAO 
        {
            private:
                const std::string connection_string = "db=TEST_DB user=pdr0alva password=pdr0alva host=localhost"; 
                soci::session db_session;

            public:
                DAO();
                
                data::Person selectPersonById(int &_id);
                data::Person selectPersonByCpf(std::string &_cpf);

                int removePersonById(int &_id);
                //void removeAllPersonByName(std::string &_name);
                int updatePersonById(data::Person &p);

                std::vector<data::Person> selectAll();

                unsigned insertPerson(data::Person &_person); 
        
                ~DAO() {;}
        };
    }
}


#endif