#include "../include/DAO.h"

namespace data
{
    namespace db
    {
        DAO::DAO()
        {
            db_session = soci::session(soci::mysql, connection_string);
        }
    
        data::Person DAO::selectPersonById(int &_id)
        {
            data::Person person;

            db_session << "SELECT * FROM People WHERE id=:id", soci::use(_id), soci::into(person);
 
            return person;
        }

        data::Person DAO::selectPersonByCpf(std::string &_cpf)
        {
            data::Person person;

            db_session << "SELECT * FROM People WHERE cpf=:cpf", soci::use(_cpf);
 
            return person;
        }

        int DAO::removePersonById(int &_id)
        {
            try
            {
                db_session << "DELETE FROM People WHERE id=:id", soci::use(_id);
            }
            catch (const soci::mysql_soci_error &e)
            {
                return e.err_num_;
            }
        
            return 200;
        }

        int DAO::updatePersonById(data::Person &p)
        {   
            data::Person return_p;

            try 
            {
                db_session << "UPDATE People SET name=:name, cpf=:cpf, age=:age WHERE id=:id", soci::use(p);
            }
            catch (soci::mysql_soci_error &e)
            {
                std::cout << "\n\n" << e.what() << "\n\n";
                return e.err_num_;
            }
             
            return 200;
        }

        std::vector<data::Person> DAO::selectAll()
        {
            std::vector<data::Person> p_set;

            try 
            {
                soci::rowset<data::Person> row_set = (db_session.prepare << "SELECT * FROM People");

                for (auto const& row : row_set)
                    p_set.push_back(row);
            
            }
            catch (const std::exception &e)
            {
                std::cerr << "> MYSQL EXCEPTION: " << e.what() << "\n";
            }

            return p_set;
        }

        unsigned DAO::insertPerson(data::Person &_person)
        {
            try 
            {
                db_session << "INSERT INTO People(name, cpf, age) VALUES(:name, :cpf, :age)", soci::use(_person);
            }            
            catch (soci::mysql_soci_error err)
            {
                return (err.err_num_);
            }

            return 200;
        }
    }
}