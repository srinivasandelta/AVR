//==-- AVRTargetMachine.h - Define TargetMachine for AVR ---*- C++ -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the MSP430 specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//


#ifndef LLVM_TARGET_AVR__TARGETMACHINE_H
#define LLVM_TARGET_AVR_TARGETMACHINE_H

#include "AVRISelLowering.h"
#include "llvm/Target/TargetData.h"
#include "llvm/Target/TargetFrameLowering.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {

class AVRTargetMachine : public LLVMTargetMachine {
  const TargetData       DataLayout;       // Calculates type size & alignment
  AVRTargetLowering	 TLInfo;

public:
  AVRTargetMachine(const Target &T, StringRef TT,
                      StringRef CPU, StringRef FS, const TargetOptions &Options,
                      Reloc::Model RM, CodeModel::Model CM,
                      CodeGenOpt::Level OL);

  virtual const AVRTargetLowering* getTargetLowering() const {
    return &TLInfo;
  }

  virtual const TargetFrameLowering *getFrameLowering() const {
    return NULL;
  }
  virtual const TargetData *getTargetData() const     { return &DataLayout;}

  virtual const TargetRegisterInfo *getRegisterInfo() const {
    return NULL;
  }

}; 
} // end namespace llvm

#endif // LLVM_TARGET_MSP430_TARGETMACHINE_H
