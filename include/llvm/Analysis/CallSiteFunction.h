#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Analysis/InlineCost.h"
namespace llvm {
	class CallSiteFunction: public FunctionPass{
		protected:
			Function *F;
			LoopInfo *LI;
			friend class llvm::InlineCostAnalysis;
		public:
			static char ID;
			CallSiteFunction() : FunctionPass(ID){}
			void setFunction(Function *f);
			void setLoopInfo(LoopInfo *li);
			virtual bool runOnFunction(Function &F);
	};
	char CallSiteFunction::ID = 0;
	static RegisterPass<CallSiteFunction> X("callsitefunction", "Call site function!");
	bool CallSiteFunction::runOnFunction(Function &F){
		this->F = &F;
		LI = &getAnalysis<LoopInfo>();
	}
	void CallSiteFunction::setFunction(Function *f){
		this->F = f;
	}
	void CallSiteFunction::setLoopInfo(LoopInfo *li){
		this->LI = li;
	}

}
