#pragma once


/* This file define 'printing' modules, which print event content on cout.
 * They are probably only useful for debugging, e.g. by dumping muon collections
 * before and after running a cleaner, etc.
 */

#include "UHH2/core/include/AnalysisModule.h"
#include "UHH2/core/include/Event.h"

class MuonPrinter: public uhh2::AnalysisModule {
public:
    explicit MuonPrinter(const std::string & name = "");
    virtual bool process(uhh2::Event & event) override;
private:
    std::string name;
};

class ElectronPrinter: public uhh2::AnalysisModule {
public:
    explicit ElectronPrinter(const std::string & name = "");
    virtual bool process(uhh2::Event & event) override;
    static void print(std::ostream & out, const Electron & ele, const uhh2::Event & event);
private:
    std::string name;
};

class GenParticlesPrinter: public uhh2::AnalysisModule {
public:
    GenParticlesPrinter(uhh2::Context &){}
    virtual bool process(uhh2::Event & event) override;
};

class JetPrinter: public uhh2::AnalysisModule {
public:
    explicit JetPrinter(const std::string & name_, double ptmin_): name(name_), ptmin(ptmin_){}
    virtual bool process(uhh2::Event & event) override;
private:
    std::string name;
    double ptmin;
};

class GenJetPrinter: public uhh2::AnalysisModule {
public:
    explicit GenJetPrinter(const std::string & name_, double ptmin_): name(name_), ptmin(ptmin_){}
    virtual bool process(uhh2::Event & event) override;
private:
    std::string name;
    double ptmin;
};

class TopJetPrinter: public uhh2::AnalysisModule {
public:
    explicit TopJetPrinter(const std::string & name_, double ptmin_): name(name_), ptmin(ptmin_){}
    virtual bool process(uhh2::Event & event) override;
private:
    std::string name;
    double ptmin;
};

class GenTopJetPrinter: public uhh2::AnalysisModule {
public:
    explicit GenTopJetPrinter(const std::string & name_, double ptmin_): name(name_), ptmin(ptmin_){}
    virtual bool process(uhh2::Event & event) override;
private:
    std::string name;
    double ptmin;
};
