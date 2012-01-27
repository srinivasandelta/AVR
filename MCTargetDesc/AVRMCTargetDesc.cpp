//===-- AVRMCTargetDesc.cpp - AVR Target Descriptions -----*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides AVR specific target descriptions.
//
//===----------------------------------------------------------------------===//

#include "AVRMCAsmInfo.h"
#include "AVRMCTargetDesc.h"
#include "llvm/MC/MCCodeGenInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_REGINFO_MC_DESC
#include "AVRGenRegisterInfo.inc"
using namespace llvm;
/*
#define GET_INSTRINFO_MC_DESC
#include "AVRGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "MSP430GenSubtargetInfo.inc"



static MCInstrInfo *createMSP430MCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitMSP430MCInstrInfo(X);
  return X;
}

static MCRegisterInfo *createMSP430MCRegisterInfo(StringRef TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitMSP430MCRegisterInfo(X, MSP430::PCW);
  return X;
}

static MCSubtargetInfo *createMSP430MCSubtargetInfo(StringRef TT, StringRef CPU,
                                                    StringRef FS) {
  MCSubtargetInfo *X = new MCSubtargetInfo();
  InitMSP430MCSubtargetInfo(X, TT, CPU, FS);
  return X;
}

*/
static MCCodeGenInfo *createAVRCCodeGenInfo(StringRef TT, Reloc::Model RM,
                                                CodeModel::Model CM,
                                                CodeGenOpt::Level OL) {
  MCCodeGenInfo *X = new MCCodeGenInfo();
  X->InitMCCodeGenInfo(RM, CM, OL);
  return X;
}

/*
static MCInstPrinter *createMSP430MCInstPrinter(const Target &T,
                                                unsigned SyntaxVariant,
                                                const MCAsmInfo &MAI,
                                                const MCSubtargetInfo &STI) {
  if (SyntaxVariant == 0)
    return new MSP430InstPrinter(MAI);
  return 0;
}

*/
extern "C" void LLVMInitializeAVRTargetMC() {
  //  Register the MC asm info.
  RegisterMCAsmInfo<AVRMCAsmInfo> X(TheAVRTarget);

  // Register the MC codegen info.
  TargetRegistry::RegisterMCCodeGenInfo(TheAVRTarget,
                                        createAVRCCodeGenInfo);

  // Register the MC instruction info.
  //TargetRegistry::RegisterMCInstrInfo(TheMSP430Target, createMSP430MCInstrInfo);

  // Register the MC register info.
  //TargetRegistry::RegisterMCRegInfo(TheMSP430Target,
                                    // createMSP430MCRegisterInfo);

  // Register the MC subtarget info.
  //TargetRegistry::RegisterMCSubtargetInfo(TheMSP430Target, createMSP430MCSubtargetInfo);

  // Register the MCInstPrinter.
  //TargetRegistry::RegisterMCInstPrinter(TheMSP430Target, createMSP430MCInstPrinter);
}
