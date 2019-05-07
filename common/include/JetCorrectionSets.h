#pragma once

#include <vector>
#include <string>

/* namespace to define useful filename constants & functions to be used for jet energy corrections */

namespace JERFiles{

  /**
   * There are 2 ways to get access to JEC sets, needed for *JetEnergyCorrector class:
   * - use the JECFiles_[DATA|MC]() functions
   * - a C++ variable, defined below with the DEFINE_* macros,
   *   and created in the cxx file with the SET_* macros
   * The 1st option is preferred in user analysis code, as it is more flexible
   * (e.g. one can use variables to change all JEC versions
   *  for different jet collections simultaneously)
   * The 2nd option just uses the output of the 1st option, and is the reason for
   * all the preprocessor commands. These are kept only for backwards-compatibility.
   */
  const std::string JECPathStringData(const std::string & tag, const std::string & ver, const std::string & jetCollection, const std::string & runName, const std::string & Correction);
  const std::vector<std::string> JECFiles_DATA(const std::string & tag, const std::string & ver, const std::string & runName, const std::string & jetCollection, const std::vector<std::string> levels);

  const std::string JECPathStringMC(const std::string & tag, const std::string & ver, const std::string & jetCollection, const std::string & Correction);
  const std::vector<std::string> JECFiles_MC(const std::string & tag, const std::string & ver, const std::string & jetCollection, const std::vector<std::string> levels);

  #define DEFINE_CORRECTION_MC(tag,ver,jetCollection,Correction)                            \
  extern const std::vector<std::string> tag##_V##ver##_##Correction##_##jetCollection##_MC; \

  #define DEFINE_CORRECTION_DATA2016(tag,ver,jetCollection,Correction)	\
  extern const std::vector<std::string> tag##_V##ver##_B_##Correction##_##jetCollection##_DATA;   \
  extern const std::vector<std::string> tag##_V##ver##_C_##Correction##_##jetCollection##_DATA;   \
  extern const std::vector<std::string> tag##_V##ver##_D_##Correction##_##jetCollection##_DATA;   \
  extern const std::vector<std::string> tag##_V##ver##_E_##Correction##_##jetCollection##_DATA;   \
  extern const std::vector<std::string> tag##_V##ver##_F_##Correction##_##jetCollection##_DATA;   \
  extern const std::vector<std::string> tag##_V##ver##_G_##Correction##_##jetCollection##_DATA;   \
  extern const std::vector<std::string> tag##_V##ver##_H_##Correction##_##jetCollection##_DATA;   \

  #define DEFINE_CORRECTION_DATA2017(tag,ver,jetCollection,Correction)	\
  extern const std::vector<std::string> tag##_V##ver##_B_##Correction##_##jetCollection##_DATA;   \
  extern const std::vector<std::string> tag##_V##ver##_C_##Correction##_##jetCollection##_DATA;   \
  extern const std::vector<std::string> tag##_V##ver##_D_##Correction##_##jetCollection##_DATA;   \
  extern const std::vector<std::string> tag##_V##ver##_E_##Correction##_##jetCollection##_DATA;   \
  extern const std::vector<std::string> tag##_V##ver##_F_##Correction##_##jetCollection##_DATA;   \

  #define DEFINE_CORRECTION_DATA2018(tag,ver,jetCollection,Correction)	\
  extern const std::vector<std::string> tag##_V##ver##_A_##Correction##_##jetCollection##_DATA;   \
  extern const std::vector<std::string> tag##_V##ver##_B_##Correction##_##jetCollection##_DATA;   \
  extern const std::vector<std::string> tag##_V##ver##_C_##Correction##_##jetCollection##_DATA;   \
  extern const std::vector<std::string> tag##_V##ver##_D_##Correction##_##jetCollection##_DATA;   \


  #define DEFINE_JECFILES_MC(tag,ver,jetCollection)     \
  DEFINE_CORRECTION_MC(tag,ver,jetCollection,L123)      \
  DEFINE_CORRECTION_MC(tag,ver,jetCollection,L1RC)      \
  DEFINE_CORRECTION_MC(tag,ver,jetCollection,L1FastJet) \

  #define DEFINE_JECFILES_DATA2016(tag,ver,jetCollection)       \
  DEFINE_CORRECTION_DATA2016(tag,ver,jetCollection,L123)        \
  DEFINE_CORRECTION_DATA2016(tag,ver,jetCollection,L1RC)        \
  DEFINE_CORRECTION_DATA2016(tag,ver,jetCollection,L1FastJet)   \
  DEFINE_CORRECTION_DATA2016(tag,ver,jetCollection,L123_noRes)  \

  #define DEFINE_JECFILES_DATA2017(tag,ver,jetCollection)       \
  DEFINE_CORRECTION_DATA2017(tag,ver,jetCollection,L123)        \
  DEFINE_CORRECTION_DATA2017(tag,ver,jetCollection,L1RC)        \
  DEFINE_CORRECTION_DATA2017(tag,ver,jetCollection,L1FastJet)   \
  DEFINE_CORRECTION_DATA2017(tag,ver,jetCollection,L123_noRes)  \

  #define DEFINE_JECFILES_DATA2018(tag,ver,jetCollection)       \
  DEFINE_CORRECTION_DATA2018(tag,ver,jetCollection,L123)        \
  DEFINE_CORRECTION_DATA2018(tag,ver,jetCollection,L1RC)        \
  DEFINE_CORRECTION_DATA2018(tag,ver,jetCollection,L1FastJet)   \
  DEFINE_CORRECTION_DATA2018(tag,ver,jetCollection,L123_noRes)  \

  /* Here we define the new vectors. The usage is the following:
  DEFINE_JECFILES_*( a tag to identify which JEC use ,version, jet collection used)
  */

  //2016, official Moriond19
  DEFINE_JECFILES_MC(Summer16_07Aug2017,11,AK4PFchs)
  DEFINE_JECFILES_MC(Summer16_07Aug2017,11,AK4PFPuppi)
  DEFINE_JECFILES_MC(Summer16_07Aug2017,11,AK8PFchs)
  DEFINE_JECFILES_MC(Summer16_07Aug2017,11,AK8PFPuppi)
  DEFINE_JECFILES_DATA2016(Summer16_07Aug2017,11,AK4PFchs)
  DEFINE_JECFILES_DATA2016(Summer16_07Aug2017,11,AK4PFPuppi)
  DEFINE_JECFILES_DATA2016(Summer16_07Aug2017,11,AK8PFchs)
  DEFINE_JECFILES_DATA2016(Summer16_07Aug2017,11,AK8PFPuppi)
  //2016, JERC legacy studies
  DEFINE_JECFILES_MC(Summer16_07Aug2017,20,AK4PFchs)
  DEFINE_JECFILES_DATA2016(Summer16_07Aug2017,20,AK4PFchs)

  //2017, official Moriond19
  DEFINE_JECFILES_MC(Fall17_17Nov2017,32,AK4PFchs)
  DEFINE_JECFILES_MC(Fall17_17Nov2017,32,AK4PFPuppi)
  DEFINE_JECFILES_MC(Fall17_17Nov2017,32,AK8PFchs)
  DEFINE_JECFILES_MC(Fall17_17Nov2017,32,AK8PFPuppi)
  DEFINE_JECFILES_DATA2017(Fall17_17Nov2017,32,AK4PFchs)
  DEFINE_JECFILES_DATA2017(Fall17_17Nov2017,32,AK4PFPuppi)
  DEFINE_JECFILES_DATA2017(Fall17_17Nov2017,32,AK8PFchs)
  DEFINE_JECFILES_DATA2017(Fall17_17Nov2017,32,AK8PFPuppi)

  //2018, official Moriond19
  DEFINE_JECFILES_MC(Autumn18,8,AK4PFchs)
  DEFINE_JECFILES_MC(Autumn18,8,AK4PFPuppi)
  DEFINE_JECFILES_MC(Autumn18,8,AK8PFchs)
  DEFINE_JECFILES_MC(Autumn18,8,AK8PFPuppi)
  DEFINE_JECFILES_DATA2018(Autumn18,8,AK4PFchs)
  DEFINE_JECFILES_DATA2018(Autumn18,8,AK4PFPuppi)
  DEFINE_JECFILES_DATA2018(Autumn18,8,AK8PFchs)
  DEFINE_JECFILES_DATA2018(Autumn18,8,AK8PFPuppi)

  //2018, temporary version
  DEFINE_JECFILES_MC(Autumn18,4,AK4PFchs)
  DEFINE_JECFILES_MC(Autumn18,4,AK4PFPuppi)
  DEFINE_JECFILES_MC(Autumn18,4,AK8PFchs)
  DEFINE_JECFILES_MC(Autumn18,4,AK8PFPuppi)
  DEFINE_JECFILES_DATA2018(Autumn18,4,AK4PFchs)
  DEFINE_JECFILES_DATA2018(Autumn18,4,AK4PFPuppi)
  DEFINE_JECFILES_DATA2018(Autumn18,4,AK8PFchs)
  DEFINE_JECFILES_DATA2018(Autumn18,4,AK8PFPuppi)

  //2018, temporary version
  DEFINE_JECFILES_MC(Autumn18,7,AK4PFchs)
  DEFINE_JECFILES_MC(Autumn18,7,AK4PFPuppi)
  DEFINE_JECFILES_MC(Autumn18,7,AK8PFchs)
  DEFINE_JECFILES_MC(Autumn18,7,AK8PFPuppi)
  DEFINE_JECFILES_DATA2018(Autumn18,7,AK4PFchs)
  DEFINE_JECFILES_DATA2018(Autumn18,7,AK4PFPuppi)
  DEFINE_JECFILES_DATA2018(Autumn18,7,AK8PFchs)
  DEFINE_JECFILES_DATA2018(Autumn18,7,AK8PFPuppi)

}
