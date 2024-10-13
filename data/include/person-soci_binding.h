#ifndef PERSON_SOCI_BINDING_H_
#define PERSON_SOCI_BINDING_H_z

#include "../include/Person.h"
#include <soci/soci.h>

namespace soci
{
    template<>
    struct type_conversion<data::Person>
    {
        typedef soci::values base_type;

        static void from_base(soci::values const &v, indicator, data::Person &p)   
        {
            p.setPerson(
                v.get<int>("id"), 
                v.get<std::string>("name"), 
                v.get<std::string>("cpf"), 
                v.get<int>("age")
            );
        }

        static void to_base(const data::Person &p, soci::values &v, indicator &ind)
        {
            v.set("id", p.getId());
            v.set("name", p.getName());
            v.set("cpf", p.getCpf());
            v.set("age", p.getAge());

            ind = i_ok;
        }
    };
}

#endif