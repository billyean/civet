//
// Created by haibo on 8/2/23.
//
#include <vector>

class Context;

enum OperatorState {
  SCHEDULED,
  RUNNING,
  CANCELLED,
  SUCCEED,
  FAILED
};

template <class Input, class Output>
class CancellableOperator {
public:
  void execute_not_cancelled(Input& input, Output& output, Context& context) {
    if (!cancel_) {
      execute(input, output, context);
    }
  }

  void cancel() {
    cancel_ = true;
  }
protected:
  virtual void execute(Input& input, Output& output, Context& context) = 0;
private:
  bool cancel_;
  OperatorState operatorState_;
};

template <class Morsel>
class Sinker : CancellableOperator<std::vector<Morsel>, std::vector<Morsel>> {  // Last operator in pipeline
};

template <class Morsel>
class SingleOp : CancellableOperator<Morsel, Morsel> {                          // Parallelized operator in pipeline
};

template <class Morsel>
class SourceOp : CancellableOperator<void, std::vector<Morsel>> {               // Source node operator in pipeline, usually it's I/O
};

template <class Morsels>
class Sourcer : CancellableOperator<Morsels, Morsels> {                         // Source operator to get data prepared for the whole pipeline, eg, data copy
};
