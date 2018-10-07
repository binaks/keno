#ifndef KENO_BET_H
#define KENO_BET_H

using number_type = unsigned short int; // <! data type for a keno hit.
using cash_type = float; // <! Defines the wage type in this application.
using set_of_numbers_type = std::vector< number_type >;

class KenoBet {
    public:
        //! Creates an empty Keno bet
        KenoBet() : m_wage(0) {};
    private:
        set_of_numbers_type m_spots; // <! The player's bet
        cash_type m_wage;            // <! The player's wage
};

#endif
