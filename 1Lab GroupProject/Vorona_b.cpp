#include "shared_types.h"

unique_ptr<Result> calculateB(shared_ptr<const InputData> data)
{
    (void)data;
    return make_unique<Result>(Result{ 0.0, 0.0 });
}