#ifndef DataFormats_SiStripDigi_SiStripRawDigi_H
#define DataFormats_SiStripDigi_SiStripRawDigi_H

#include "DataFormats/Common/interface/traits.h"
#include "boost/cstdint.hpp"

/** 
    @brief A Digi for the silicon strip detector, containing only adc
    information, and suitable for storing raw hit information. NOTA
    BENE: these digis use the DetSetVector, but the public inheritence
    from edm::DoNotSortUponInsertion ensures that the digis are NOT
    sorted by the DetSetVector::post_insert() method. The strip
    position is therefore inferred from the position of the digi
    within its container (the DetSet private vector).
*/
class SiStripRawDigi : public edm::DoNotSortUponInsertion {
  
 public:

  SiStripRawDigi( const uint16_t& adc ) : adc_(adc) {;}

  SiStripRawDigi() : adc_(0) {;}
  ~SiStripRawDigi() {;}
  
  inline const uint16_t& adc() const;
  
  /** Not used! (even if implementation is required). */
  inline bool operator< ( const SiStripRawDigi& other ) const;
  
 private:
  
  uint16_t adc_;
  
};

// inline methods 
const uint16_t& SiStripRawDigi::adc() const {  return adc_; }
bool SiStripRawDigi::operator< ( const SiStripRawDigi& other ) const { return ( this->adc() < other.adc() ); }

#endif // DataFormats_SiStripDigi_SiStripRawDigi_H

