// Authors: Bianca Rodrigues Cesarino & Gustavo Batista de Araújo Gorgônio

#include "../include/KenoBet.h"
#include "../include/aux.h"
 
bool KenoBet::add_number( number_type spot_ ) {
    if (not member (m_spots, spot_)) {
        m_spots.push_back(spot_);
        return true;
    } else {
        return false;
    }
}

bool KenoBet::set_wage( cash_type wage_ ) {
    KenoBet::m_wage = wage_;
    if (m_wage > 0) return true;
    return false;
}

void KenoBet::reset() {
    m_wage = 0;
    m_spots.clear();
}

cash_type KenoBet::get_wage() const {
    return m_wage;
}

size_t KenoBet::size() const {
    return m_spots.size();
}

set_of_numbers_type KenoBet::get_hits( const set_of_numbers_type & hits_) const {
    set_of_numbers_type hits;

    for (auto i(0u); i < size(); ++i) {
        if (member (hits_, m_spots[i])) {
            hits.push_back(m_spots[i]);
        }
    }

    return hits;
}

set_of_numbers_type KenoBet::get_spots() const {
    return m_spots;
}
