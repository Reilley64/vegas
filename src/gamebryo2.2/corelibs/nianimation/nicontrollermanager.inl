
#include "fnv/decl/FUN_00629ab0_shell.h"
#include "fnv/decl/SeqA34f20.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "nicontrollermanager_decls.h"
// @fnv 0x0047a510
NiFixedString* NiControllerManager::FindSequenceByName() { return DAT_011c61e0; }

// @fnv 0x0047b220
bool NiControllerManager::StopSequence(NiControllerSequence* sequence,float easeOut) { return sequence->Deactivate(easeOut,false); }
// @fnv 0x0047aab0
bool NiControllerManager::ActivateControllerSequence(NiControllerSequence* sequence,int priority,bool startOver,float weight,float easeIn,NiControllerSequence* sync) { return reinterpret_cast<::SeqA34f20 *>((sequence))->StartSequence((char)priority,startOver,weight,easeIn,(::SeqA34f20 *)(sync),false); }
// @fnv 0x0048fef0
void NiControllerManager::DeactivateAllSequences(float easeOut) {
 for(unsigned int i=0;i<((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&(sequences))->GetName()));++i) {
  NiControllerSequence* sequence=((::NiControllerSequence *)&(reinterpret_cast<::FUN_00629ab0_shell *>(&(sequences))->FUN_00629ab0(i)));
  StopSequence(sequence,easeOut);
 }
}
