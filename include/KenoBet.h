#ifndef KENO_BET_H
#define KENO_BET_H

using number_type = unsigned short int; // <! data type for a keno hit.
using cash_type = float; // <! Defines the wage type in this application.
using set_of_numbers_type = std::vector< number_type >;

class KenoBet {
    public:
        //! Creates an empty Keno bet
        KenoBet() : m_wage(0) {};

        /*! Adds a number to the spots only if the number is not already there.
            @param spot_ The number we wish to include in the bet.
            @return T if number chosen is successfully inserted; F otherwise. */
        bool add_number( number_type spot_ );

    private:
        set_of_numbers_type m_spots; // <! The player's bet
        cash_type m_wage;            // <! The player's wage
};

#endif
