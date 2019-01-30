#include "UHH2/common/include/JetCorrectionsSets.h"
#include <string>

//see https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookJetEnergyCorrections#GetTxtFiles how to get the txt files with jet energy corrections from the database

/* The idea of the following preprocessor directives is to simplify the creation of new JEC input files.
More details in UHH2/common/include/JetCorrectionsSets.h
*/

#define SET_NEWSTRING_DATA(tag,ver,jetCollection,sample,runName,Correction)                                                                                   \
std::string("JECDatabase/textFiles/")+#tag+#runName+"_V"+#ver+"_"+#sample+"/"+#tag+#runName+"_V"+#ver+"_"+#sample+"_"+#Correction+"_"+#jetCollection+".txt",  \

#define SET_NEWSTRING_MC(tag,ver,jetCollection,sample,Correction)                                                                           \
std::string("JECDatabase/textFiles/")+#tag+"_V"+#ver+"_"+#sample+"/"+#tag+"_V"+#ver+"_"+#sample+"_"+#Correction+"_"+#jetCollection+".txt",  \

#define SET_JECFILES_MC(tag,ver,jetCollection)					                                    \
const std::vector<std::string> JERFiles::tag##_V##ver##_L123_##jetCollection##_MC = {       \
  SET_NEWSTRING_MC(tag,ver,jetCollection,MC,L1FastJet)                                      \
  SET_NEWSTRING_MC(tag,ver,jetCollection,MC,L2Relative)                                     \
  SET_NEWSTRING_MC(tag,ver,jetCollection,MC,L3Absolute)                                     \
};                                                                                          \
const std::vector<std::string> JERFiles::tag##_V##ver##_L1RC_##jetCollection##_MC = {       \
  SET_NEWSTRING_MC(tag,ver,jetCollection,MC,L1RC)                                           \
};                                                                                          \
const std::vector<std::string> JERFiles::tag##_V##ver##_L1FastJet_##jetCollection##_MC = {  \
  SET_NEWSTRING_MC(tag,ver,jetCollection,MC,L1FastJet)                                      \
};                                                                                          \

#define SET_CORRECTION_DATA(tag,ver,jetCollection,runName,runCorrection)                                  \
const std::vector<std::string> JERFiles::tag##_V##ver##_##runName##_L123_##jetCollection##_DATA = {       \
  SET_NEWSTRING_DATA(tag,ver,jetCollection,DATA,runCorrection,L1FastJet)                                  \
  SET_NEWSTRING_DATA(tag,ver,jetCollection,DATA,runCorrection,L2Relative)                                 \
  SET_NEWSTRING_DATA(tag,ver,jetCollection,DATA,runCorrection,L3Absolute)                                 \
  SET_NEWSTRING_DATA(tag,ver,jetCollection,DATA,runCorrection,L2L3Residual)                               \
};                                                                                                        \
const std::vector<std::string> JERFiles::tag##_V##ver##_##runName##_L123_noRes_##jetCollection##_DATA = { \
  SET_NEWSTRING_DATA(tag,ver,jetCollection,DATA,runCorrection,L1FastJet)                                  \
  SET_NEWSTRING_DATA(tag,ver,jetCollection,DATA,runCorrection,L2Relative)                                 \
  SET_NEWSTRING_DATA(tag,ver,jetCollection,DATA,runCorrection,L3Absolute)                                 \
};                                                                                                        \
const std::vector<std::string> JERFiles::tag##_V##ver##_##runName##_L1RC_##jetCollection##_DATA = {       \
  SET_NEWSTRING_DATA(tag,ver,jetCollection,DATA,runCorrection,L1RC)                                       \
};                                                                                                        \
const std::vector<std::string> JERFiles::tag##_V##ver##_##runName##_L1FastJet_##jetCollection##_DATA = {  \
  SET_NEWSTRING_DATA(tag,ver,jetCollection,DATA,runCorrection,L1FastJet)                                  \
};                                                                                                        \

#define SET_JECFILES_DATA(tag,ver,jetCollection)  \
SET_CORRECTION_DATA(tag,ver,jetCollection,B,B)    \
SET_CORRECTION_DATA(tag,ver,jetCollection,C,C)    \
SET_CORRECTION_DATA(tag,ver,jetCollection,D,D)    \
SET_CORRECTION_DATA(tag,ver,jetCollection,E,E)    \
SET_CORRECTION_DATA(tag,ver,jetCollection,F,F)    \


#define SET_JECFILES_DATA_COMBINE_RUN_DE(tag,ver,jetCollection) \
SET_CORRECTION_DATA(tag,ver,jetCollection,B,B)                  \
SET_CORRECTION_DATA(tag,ver,jetCollection,C,C)                  \
SET_CORRECTION_DATA(tag,ver,jetCollection,D,DE)                 \
SET_CORRECTION_DATA(tag,ver,jetCollection,E,DE)                 \
SET_CORRECTION_DATA(tag,ver,jetCollection,F,F)                  \



#define SET_NEWSTRING_MC2016(tag,ver,jetCollection,sample,Correction)                                                                     \
std::string("JECDatabase/textFiles/")+#tag+"V"+#ver+"_"+#sample+"/"+#tag+"V"+#ver+"_"+#sample+"_"+#Correction+"_"+#jetCollection+".txt",  \

#define SET_JECFILES_MC2016(tag,ver,jetCollection)					                                \
const std::vector<std::string> JERFiles::tag##_V##ver##_L123_##jetCollection##_MC = {       \
  SET_NEWSTRING_MC2016(tag,ver,jetCollection,MC,L1FastJet)                                  \
  SET_NEWSTRING_MC2016(tag,ver,jetCollection,MC,L2Relative)                                 \
  SET_NEWSTRING_MC2016(tag,ver,jetCollection,MC,L3Absolute)                                 \
};                                                                                          \
const std::vector<std::string> JERFiles::tag##_V##ver##_L1RC_##jetCollection##_MC = {       \
  SET_NEWSTRING_MC2016(tag,ver,jetCollection,MC,L1RC)                                       \
};                                                                                          \
const std::vector<std::string> JERFiles::tag##_V##ver##_L1FastJet_##jetCollection##_MC = {  \
  SET_NEWSTRING_MC2016(tag,ver,jetCollection,MC,L1FastJet)                                  \
};                                                                                          \

/* Here we create the new vectors. The usage is the following:
SET_JECFILES_*( a tag to identify which JEC use ,version, jet collection used)
*/

SET_JECFILES_MC2016(Summer16_23Sep2016,4,AK4PFchs)
SET_JECFILES_MC(Fall17_17Nov2017,11,AK4PFchs)
SET_JECFILES_MC(Fall17_17Nov2017,24,AK4PFchs)
SET_JECFILES_MC(Fall17_17Nov2017,32,AK4PFchs)
SET_JECFILES_MC(Fall17_17Nov2017,32,AK4PFPuppi)
SET_JECFILES_MC(Fall17_17Nov2017,32,AK8PFchs)
SET_JECFILES_MC(Fall17_17Nov2017,32,AK8PFPuppi)

SET_JECFILES_DATA(Fall17_17Nov2017,11,AK4PFchs)
SET_JECFILES_DATA(Fall17_17Nov2017,24,AK4PFchs)
SET_JECFILES_DATA_COMBINE_RUN_DE(Fall17_17Nov2017,31,AK4PFchs)
SET_JECFILES_DATA_COMBINE_RUN_DE(Fall17_17Nov2017,32,AK4PFchs)
SET_JECFILES_DATA_COMBINE_RUN_DE(Fall17_17Nov2017,32,AK4PFPuppi)
SET_JECFILES_DATA_COMBINE_RUN_DE(Fall17_17Nov2017,32,AK8PFchs)
SET_JECFILES_DATA_COMBINE_RUN_DE(Fall17_17Nov2017,32,AK8PFPuppi)
SET_JECFILES_DATA(Fall17_09May2018,3,AK4PFchs)
