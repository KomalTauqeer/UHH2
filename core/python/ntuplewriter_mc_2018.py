import FWCore.ParameterSet.Config as cms
from UHH2.core.ntuple_generator import generate_process  # use CMSSW type path for CRAB


"""NTuple config for 2018 MC datasets.

You should try and put any centralised changes in generate_process(), not here.
"""


process = generate_process(year="2018", useData=False)

# Please do not commit changes to source filenames - used for consistency testing
process.source.fileNames = cms.untracked.vstring([
    '/store/mc/RunIIFall17MiniAOD/QCD_Pt-15to7000_TuneCP5_Flat_13TeV_pythia8/MINIAODSIM/94X_mc2017_realistic_v10-v1/50000/00197229-2FDD-E711-9070-0025904AC2C4.root'
])
process.maxEvents = cms.untracked.PSet(input=cms.untracked.int32(500))
process.options.wantSummary = cms.untracked.bool(True)

with open('pydump_mc_2018.py', 'w') as f:
    f.write(process.dumpPython())
